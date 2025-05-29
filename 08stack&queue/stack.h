/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-26 19:36:22
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-29 13:13:14
 */
#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <list>
#include <deque>

namespace yzq
{
	template <class T, class Container = std::deque<T>>
	class stack
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
			_con.pop_back();
		}

		const T &top()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

}
