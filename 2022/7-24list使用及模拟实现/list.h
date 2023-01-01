#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <time.h>
#include <assert.h>
using namespace std;


namespace yzq
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self; // 方便后面修改T

		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}

		// 不需要写析构，节点不属于迭代器，不需要迭代器去释放。系统自己生成的就够用了，啥也不干
		// 拷贝构造和赋值重载 默认生成的浅拷贝就可以了 it = lt.begin();

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
			// 等价于
			//return &_node->_data;
		}

		self operator++() //前置++
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int) //后置++
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self operator--()
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

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

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
			// 构造再拷贝构造优化成直接构造
			/*等价
			iterator it(_head->_next);
			return it;*/
			return iterator(_head->_next);

			// 也可以直接这么写，单参数隐式类型转换
			//return _head->_next;
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
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(list<T>& lt)
		{
			// 只需要换头指针就行
			std::swap(_head, lt._head);
		}

		//现代写法 拷贝构造
		list(const list<T>& lt)
		{
			empty_init(); //不能用随机值和别人交换，得初始化一下自己才行
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		//赋值重载 lt2 = lt1
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		// lt是临时对象，换完之后，出作用域，析构的时候还得释放掉lt2原来的空架子

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				// erase返回的就是删除节点的下一个
				it = erase(it);
			}
		}

		void push_back(const T& x)
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

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// 插在pos之前
		iterator insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			// prev newNode cur
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;

			return iterator(newNode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			// prev cur next
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return iterator(next);
		}

	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct AA
	{
		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
		int _a1;
		int _a2;
	};

	void test_list2()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));
		lt.push_back(AA(4, 4));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			// err *it返回的是节点的data，data是val，val是T()
			// 也就是这里返回的是AA 自定义类型不支持流操作的
			//cout << *it << " ";

			// 如果我们不想自己去写流操作的重载
			// 因为_a1 _a2都是公有的
			//cout <<  (*it)._a1 << "-" << (*it)._a2 << " ";
			cout << it->_a1 << "-" << it->_a2 << " ";
			++it;
		}
		cout << endl;
	}

	void print_list(const list<int>& l)
	{
		list<int>::const_iterator cit = l.begin();
		while (cit != l.end())
		{
			//*cit = 1; // const对象不允许修改，调用的也是const版本迭代器
			cout << *cit << " ";
			++cit;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		print_list(lt);
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(1);
		lt.push_front(2);
		lt.push_front(3);
		lt.push_front(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_front();
		lt.pop_front();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		// 要求在偶数前面插入这个数*10
		auto it1 = lt.begin();
		while (it1 != lt.end())
		{
			if (*it1 % 2 == 0)
			{
				lt.insert(it1, *it1 * 10);
			}
			++it1;
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list6()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		// 删除所有的偶数
		auto it1 = lt.begin();
		while (it1 != lt.end())
		{
			if (*it1 % 2 == 0)
			{
				it1 = lt.erase(it1);
			}
			else
			{
				++it1;
			}
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list7()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int> lt1(lt); // 我们不写，默认生成的完成浅拷贝，指向同一个头，析构时会析构2次，崩溃。

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(20);

		lt1 = lt2;

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}


