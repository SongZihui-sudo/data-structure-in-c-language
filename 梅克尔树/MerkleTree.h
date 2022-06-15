//
//	author: SongZihui-sudo
//	date:	2022-6-14
//	about:	MerkleTree write by cpp
//
#pragma
#ifndef _MerkleTree_h
#define _MerkleTree_h

#include <memory>
#include <vector>
#include <deque>
#include <mutex>

std::mutex mtx;
using std::deque;
using std::hash;
using std::vector;
using std::shared_ptr;

// MerkleTree Node
template <class T>
class Node {
public:
	// init
	Node() noexcept {
		this->left = nullptr;
		this->right = nullptr;
		this->data = 0;
	}

	// overload !=
	bool operator !=(shared_ptr <Node<T>>& cur) noexcept {
		if (this->data != cur->data) {
			return true;
		}
	}

	// overload ==
	bool operator ==(shared_ptr <Node<T>>& cur) noexcept {
		if (this->data == cur->data) {
			return true;
		}
	}

	// overload =
	void operator =(shared_ptr <Node<T>>& cur) noexcept {
		this->data = cur->data;
		this->left = cur->left;
		this->right = cur->right;
	}
public:
	size_t data;
	shared_ptr<Node<T>> left;
	shared_ptr<Node<T>> right;
};

template <typename T>
using MTreeNode = shared_ptr<Node<T>>;

// MerkleTree
template <class T>
class MerkleTree {
public:
	// init
	MerkleTree(vector<T> data) noexcept {
		this->data = data;
		// init removetable
		for (size_t i = 0; i < this->data.size(); i++) {
			this->removeIndex.push_back(-1);
		}
		// build tree
		this->root = this->treeUpdate();
	}

	// destory
	~MerkleTree() noexcept {
		// free pointer
		this->root.reset();
	}
public:
	// hash
	int hashCalculation(T data) {
		size_t ret = hash<T>()(data);
		return ret;
	}

	// get root
	shared_ptr<Node<T>> getRoot() {
		return this->root;
	}

	// add
	void addNode(T cur) {
		mtx.lock();
		this->data.push_back(cur);
		this->removeIndex.push_back(-1);
		mtx.unlock();
		this->root = this->treeUpdate();
	}

	// remove
	void removeNode(T cur) {
		size_t i = 0;
		size_t j = 0;
		mtx.lock();
		while (j < this->data.size()) {
			if (this->data[i] == cur) {
				this->removeIndex[i] = i;
			}
			else if (this->data[j] == cur) {
				this->removeIndex[j] = j;
			}
			i++;
			j += 2;	
		}
		this->root = this->treeUpdate();
		mtx.unlock();
		
	}

	// search
	MTreeNode<T> searchNode(MTreeNode<T> input) {
		MTreeNode<T> this_cur = this->root;
		MTreeNode<T> input_cur = input;
		if (this_cur == input) {
			return this->root;
		}
		while (input->left && this_cur->left) {
			if (this_cur->left != input_cur->left) {
				this_cur = this_cur->left;
				input = input->left;
			}
			else if (this_cur->right != input_cur->right) {
				this_cur = this_cur->right;
				input = input->right;
			}
		}
		return this_cur;
	}

	//	MT to Array
	void toArray(vector<MTreeNode<T>> & ret) {
		deque<MTreeNode<T>> save;
		save.push_back(this->root);
		while (true) {
			bool bit = false;
			for (auto i : save) {
				if (!i) {
					bit = true;
					break;
				}
				ret.push_back(i->left);
				ret.push_back(i->right);
				save.pop_front();
				save.push_back(i->left);
				save.push_back(i->right);
			}
			if (bit) {
				break;
			}
		}
	}
private:
	// root
	MTreeNode<T> root;
	// data
	vector<T> data;
	// remove
	vector<int> removeIndex;
private:
	// update
	MTreeNode<T> treeUpdate() {
		deque <MTreeNode<T>> arr;
		// data to node
		for (size_t i = 0; i < this->data.size(); i++) {
			bool bit = false;
			if (this->removeIndex[i] != -1) {
				continue;
			}
			MTreeNode<T> newNode(new Node<T>);
			newNode->data = this->hashCalculation(this->data[i]);
			arr.push_back(newNode);
		}
		int end = arr.size();
		// build the tree
		while (end != 1) {
			int i = 1;
			size_t j = 0;
			while (i < end) {
				//creat new node
				MTreeNode<T> newNode(new Node<T>);
				newNode->data = arr[i]->data ^ arr[i - 1]->data;
				newNode->left = arr[i - 1];
				newNode->right = arr[i];
				arr[i] = arr[i - 1] = 0;
				//stack protection
				arr[j] = newNode;
				i += 2;
				j += 1;
			}
			if (end % 2 == 0) {
				end = end / 2;
			}
			else {
				MTreeNode<T> newNode(new Node<T>);
				newNode->data = arr[end - 1]->data;
				newNode->right = nullptr;
				newNode->left = arr[end - 1];
				end = (end - 1) / 2 + 1;
				arr[end - 1] = newNode;
			}
		}
		return arr[0];
	}
};

#endif // !MerkleTree_h