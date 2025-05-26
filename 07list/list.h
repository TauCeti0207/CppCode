#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <time.h>
#include <assert.h>

namespace yzq
{
	// 这个list_node类默认全部开放，因此用 struct 定义
	template <class T>
	struct list_node
	{
		list_node<T> *_next;
		list_node<T> *_prev;
		T _data;

		// T() 是一种值初始化（value initialization）表达式，用于创建 T 类型的临时对象并初始化为其默认值。
		list_node(const T &val = T())
			: _next(nullptr), _prev(nullptr), _data(val)
		{
		}
	};

	// T：值类型（Value Type） Ref：引用类型（Reference Type）T& 或 const T&。
	// Ptr：指针类型（Pointer Type） T* 或 const T*。
	// 这里只是模板，具体类型得由实例化时传参决定
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self; // 方便后面修改T

		Node *_node;
		// 一个节点的指针即可构造一个迭代器
		__list_iterator(Node *node)
			: _node(node)
		{
		}

		// 不需要写析构，节点不属于迭代器，不需要迭代器去释放。系统自己生成的就够用了，啥也不干
		// 拷贝构造和赋值重载 默认生成的浅拷贝就可以了 it = lt.begin();
		// 要的就是浅拷贝，反正都是指向链表的指针
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
			// 等价于
			// return &_node->_data;
		}

		self &operator++() // 前置++
		{
			_node = _node->_next;
			return *this;
		}

		// 后置 ++ 通过占位参数 int 来与前置 ++ 区分，该参数在调用时无需显式传递，仅用于语法标识。
		// 后置 ++ 返回旧值的副本（值返回），而前置 ++ 返回自增后的当前对象引用。
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self &operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self &it)
		{
			return _node != it._node;
		}

		bool operator==(const self &it)
		{
			return _node == it._node;
		}
	};

	template <class T>
	class list
	{
		typedef list_node<T> Node;

	private:
		Node *_head;
		size_t _size;

	public:
		typedef __list_iterator<T, T &, T *> iterator;
		typedef __list_iterator<T, const T &, const T *> const_iterator;

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			// 构造一个匿名对象，再传值返回
			// 构造再拷贝构造会被优化成直接构造 其实就是 C++ 的 返回值优化（RVO, Return Value Optimization）
			// 现代编译器会自动优化掉拷贝构造，直接在返回值位置构造对象
			// 调用 begin() 前，调用者的栈帧中已为返回的 iterator 对象分配空间。
			// begin() 执行时，编译器将 it 直接构造在调用者的返回值空间中，而非被调函数的栈帧内。
			// 这样无需创建临时对象 tmp，也不调用拷贝构造函数。

			/*等价
			iterator it(_head->_next);
			return it;*/
			return iterator(_head->_next);

			// 也可以直接这么写，单参数隐式类型转换，但不推荐
			// 可读性问题：return _head->_next 掩盖了返回值的真实类型（iterator），可能让调用者误解。
			// 潜在风险：如果后续迭代器构造函数添加了 explicit 关键字，隐式转换会失效。
			// return _head->_next;
		}

		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		/*
		// lt2(lt1)  传统写法
		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : lt)
			{
				push_back(e);
			}
		}
		*/

		void empty_init()
		{
			// 这里 Node() 会调用list_node构造函数完成初始化
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(list<T> &lt)
		{
			// 只需要换头指针和_size
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// 现代写法 拷贝构造 lt2(lt1)
		list(const list<T> &lt)
		{
			empty_init(); // 不能用随机值和别人交换，得初始化一下自己才行
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		// 用n个val个构造
		list(int n, const T &val = T())
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// 赋值重载 现代写法 lt2 = lt1
		list<T> &operator=(list<T> lt)
		{
			swap(lt);
			return *this;
			// lt是临时对象，换完之后，出作用域，析构的时候还得释放掉lt2原来的空架子
		}

		// 析构函数要清理全部资源
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		// clear 是不清除头节点
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				// erase返回的就是删除节点的下一个
				it = erase(it);
			}
		}

		// push_back 就是在end()前面插入
		void push_back(const T &x)
		{
			/*
			Node* tail = _head->_prev;
			Node* newNode = new Node(x);
			// _head tail newNode
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
			*/
			// 复用insert
			insert(end(), x);
		}

		// push_front 就是在begin()前面插入
		void push_front(const T &x)
		{
			insert(begin(), x);
		}

		// pop_back 是删除 end()前一个的元素
		void pop_back()
		{
			erase(--end());
		}

		// pop_front 是删除 begin()位置的元素
		void pop_front()
		{
			erase(begin());
		}

		// 插在pos之前
		// list 的迭代器insert 理论上没有迭代器失效的问题
		iterator insert(iterator pos, const T &val)
		{
			Node *newNode = new Node(val);
			Node *cur = pos._node;
			Node *prev = cur->_prev;
			// prev newNode cur
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;
			++_size;

			return iterator(newNode);
		}

		// erase 之后的迭代器 pos 会失效，因此返回值返回一个迭代器指向 erase后一个迭代器
		iterator erase(iterator pos)
		{
			assert(pos != end());
			// prev cur next
			Node *cur = pos._node;
			Node *prev = cur->_prev;
			Node *next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;
			--_size;
			return iterator(next);
		}

		bool empty() const
		{
			return _size == 0;
		}
	};

}
