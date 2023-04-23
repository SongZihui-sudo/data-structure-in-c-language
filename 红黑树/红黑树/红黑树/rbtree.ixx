export module rbtree;
import std.core;

namespace ministd
{
	export enum node_color
	{
		BLACK = 0,
		RAD
	};

	export struct node 
	{
		node() = default;
		~node() = default;
		node* m_left;
		node* m_right;
		void* m_value;
		std::string m_key;
	};

	export class Rbtree 
	{
	public:
		Rbtree(std::initializer_list<void*> args) {};
		virtual ~Rbtree()
		{
			delete this->m_root;
			this->m_root = nullptr;
			this->m_num = 0;
		}

	public:
		int insert(void* _val) { return 0; };
		int remove(std::string _key) { return 0; };
		int remove(void* _val) { return 0; }
		struct node get(std::string _key) const { return node(); }
		struct node get(void* _val) const { return node(); }
		int replace(std::string _key, void* _val) { return 0; }
		int replace(void* _ptr, void* _cur) { return 0; }
		bool empty() { return false; }

	public:
		node operator[](std::string _key) const { return node(); };
		int operator<<(void*) { return 0; };

	private:
		int rotate_left(struct node* _cur) { return 0; };
		int rotate_right(struct node* _cur) { return 0; };

	private:
		struct node* m_root;
		size_t m_num;
	};
}

