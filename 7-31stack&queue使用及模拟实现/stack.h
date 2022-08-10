#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <list>
#include <deque>
using namespace std;

namespace yzq
{
	template<class T, class Container = deque<T>>
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

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	void test_stack1()
	{
		//stack<int> s;
		//stack<int, vector<int>> s;
		//stack<int, list<int>> s;
		stack<int, string> s; // string�ڲ���char ���ܻᷢ�����ݽض�
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(128); // ����127�ͻ�ض� -128
		s.push(255); // -1
		s.push(256); // 0

		while (!s.empty())
		{
			cout << s.top() << "-";
			cout << s.size() << " ";
			s.pop();
		}
		cout << endl;
	}
}

