//
//	author: SongZihui-sudo
//	date:	2022-6-14
//	about:	MerkleTree write by cpp
//
#include "MerkleTree.h"
#include <vector>
#include <string>
#include <memory>
#include <thread>

#define NUM_THREADS 5

using std::shared_ptr;
using std::vector;
using std::thread;

// Some Test
int main() {
	vector<int> input = { 0,1,2,3,4,5,6,7,8 };
	MerkleTree<int>* mt = new MerkleTree<int>(input);
	/*
	*				hash12
	*			/				\
	*			hash10				hash11
	*			/		\			|
	*		hash7      hash8		hash9
	*		/\			/\			|
	*   hash1 hash2 hash4 hash5	hash6
	*	/\   /\		/\		/\		|
	*	0 1  2 3    4 5		6 7		8
	*/
	input = { 9, 1,2,3,4,5,6,7,8 };
	MerkleTree<int>* mt2 = new MerkleTree<int>(input);
	// search different node
	shared_ptr<Node<int>> ret = mt->searchNode(mt2->getRoot());
	// add node
	mt->addNode(9);
	// remove node
	mt->removeNode(8);
	// MT to a vector array
	vector<MTreeNode<int>> res;
	mt->toArray(res);
	// Multithreading test
	thread mtthread1(&MerkleTree<int>::addNode, mt, 1);
	thread mtthread2(&MerkleTree<int>::addNode, mt, 2);
	thread mtthread3(&MerkleTree<int>::removeNode, mt, 7);
	thread mtthread4(&MerkleTree<int>::removeNode, mt, 8);	
	mtthread1.join();
	mtthread2.join();
	mtthread3.join();
	mtthread4.join();
	mt->toArray(res);
	return 0;
}