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
using namespace std;

namespace yzq
{
	template<class T, class Container = deque<T>>
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

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	void test_queue1()
	{
		queue<int> q;
		//queue<int, list<int>> q;
		//queue<int, vector<int>> q; // ������vector���� û��pop_front
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << "-";
			cout << q.size() << " ";
			q.pop();
		}
		cout << endl;
	}

	template <class T>
	struct less
	{
		bool operator()(const T& x, const T& y) const //֧��const�������
		{
			return x < y;
		}
	};

	template <class T>
	struct greater
	{
		bool operator()(const T& x, const T& y) const
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

	// Container��Ҫ֧���������
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		Compare _comFunc;
		Container _con;
	public:
		priority_queue(const Compare& comFunc = Compare()) // ȱʡ������Compare�����Լ��Ĺ��캯�����
			:_comFunc(comFunc)
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last
			, const Compare& comFunc = Compare())
			: _comFunc(comFunc)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// ����������Ҫ���� ÿ��һ�����µ���
			// �����һ����Ҷ�ӽڵ㿪ʼ
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}
		}

		// �ײ��Ǹ��ѣ�Ĭ���Ǵ��
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			// parentʼ��>=0��������parent�ж� (0-1)/2 = 0
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (_comFunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					// ���º��ӡ�����
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				// �ж��Һ����Ƿ���� 
				// ע������Һ���Խ��
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && _comFunc(_con[child], _con[child + 1]))
				{
					++child;
				}
				//if (_con[parent] < _con[child])
				if (_comFunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			// ����������Ҫ��������
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDown(0); //�Ӹ��ڵ㿪ʼ����
		}

		const T& top()
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

	void test_priority_queue2()
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		//priority_queue<int> pq;
		//priority_queue<int, vector<int>, bool(*)(int, int)> pq(ComIntGreater);
		pq.push(2);
		pq.push(5);
		pq.push(1);
		pq.push(6);
		pq.push(8);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

	void test_priority_queue3()
	{
		int a[] = { 1,3,4,2,1,6 };
		// �������ȼ����п��ٽ��ѣ�Ĭ�ϴ��
		//priority_queue<int> pq(a, a + 6);
		priority_queue<int, vector<int>, greater<int>> pq(a, a + 6);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}

