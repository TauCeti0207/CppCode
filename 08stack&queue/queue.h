#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <assert.h>
#include <deque>
#include <time.h>
#include <algorithm>
#include "Date.h"

namespace yzq
{
	template <class T, class Container = std::deque<T>>
	class queue
	{
	public:
		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

		void push(const T &val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T &front()
		{
			return _con.front();
		}

		const T &back()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	template <class T>
	struct less
	{
		bool operator()(const T &x, const T &y) const // 支持const对象调用
		{
			return x < y;
		}
	};

	// 针对Date*类型进行类模板特化
	template <>
	struct less<yzq::Date *>
	{
		bool operator()(const yzq::Date *d1, const yzq::Date *d2) const // 支持const对象调用
		{
			return *d1 < *d2;
		}
	};

	template <class T>
	struct greater
	{
		bool operator()(const T &x, const T &y) const
		{
			return x > y;
		}
	};

	bool ComIntLess(int x, int y)
	{
		return x < y;
	}

	bool ComIntGreater(int x, int y)
	{
		return x > y;
	}

	// Container需要支持随机访问
	template <class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		Compare _comFunc;
		Container _con;

	public:
		priority_queue(const Compare &comFunc = Compare()) // 缺省参数是Compare调用自己的构造函数完成
			: _comFunc(comFunc)
		{
		}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last, const Compare &comFunc = Compare())
			: _comFunc(comFunc),
			  _con(first, last)
		{
			// while (first != last)
			// {
			// 	_con.push_back(*first);
			// 	++first;
			// }

			// 插完数据需要建堆 每插一个往下调整
			// 从最后一个非叶子节点开始
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}

		// 底层是个堆，默认是大堆
		void adjust_up(int child)
		{
			int parent = (child - 1) / 2;
			// parent始终>=0，不能用parent判断 (0-1)/2 = 0
			// child=0就结束了
			while (child > 0)
			{
				// if (_con[child] > _con[parent])
				if (_comFunc(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					// 更新孩子、父亲
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(int parent)
		{
			size_t child = parent * 2 + 1;
			// child 不超过堆的范围就继续
			while (child < _con.size())
			{
				// 判断右孩子是否更大 注意避免右孩子越界
				// if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				if (child + 1 < _con.size() && _comFunc(_con[child], _con[child + 1]))
				{
					++child;
				}
				// 孩子大于父亲就换到上面 大根堆
				// if (_con[child] > _con[parent])
				if (_comFunc(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T &x)
		{
			_con.push_back(x);
			// 插完数据需要调整建堆
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			assert(!_con.empty());
			// 交换首尾数据
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0); // 从根节点开始调整
		}

		const T &top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	};
}
