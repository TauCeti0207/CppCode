#include "stack.h"
#include "queue.h"
#include "list.h"
#include "vector.h"
namespace std
{
	void test_stack1()
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		while (!s.empty())
		{
			cout << s.top() << "-";
			cout << s.size() << " ";
			s.pop();
		}
		cout << endl;
	}

	void test_queue1()
	{
		queue<int> q;
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

	void test_priority_queue1()
	{
		// priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq;
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

	void test_funtional()
	{
		std::vector<int> v;
		v.push_back(2);
		v.push_back(1);
		v.push_back(5);
		v.push_back(3);
		v.push_back(4);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// less
		sort(v.begin(), v.end());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl; // 1 2 3 4 5

		// 这里需要传的是greater对象，为了简便直接传个匿名对象
		sort(v.begin(), v.end(), greater<int>());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// 指向数组的原生指针，本身就是天然的迭代器
		int a[] = {1, 3, 7, 5, 3, 2, 1};
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(a, a + 7);
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(a, a + 7, greater<int>());
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// 商品
	struct Goods
	{
		string _name;
		double _price;
		size_t _saleNum;
		//...

		/*bool operator<(const Goods& g) const
		{
			return _price < g._price;
		}*/
	};

	struct LessPrice
	{
		bool operator()(const Goods &g1, const Goods &g2) const
		{
			return g1._price < g2._price;
		}
	};

	struct GreaterPrice
	{
		bool operator()(const Goods &g1, const Goods &g2) const
		{
			return g1._price > g2._price;
		}
	};

	struct LessSaleNum
	{
		bool operator()(const Goods &g1, const Goods &g2) const
		{
			return g1._saleNum < g2._saleNum;
		}
	};

	struct GreaterSaleNum
	{
		bool operator()(const Goods &g1, const Goods &g2) const
		{
			return g1._saleNum > g2._saleNum;
		}
	};

	void test_funtional2()
	{
		Goods gds[4] = {{"苹果", 2.1, 1000}, {"香蕉", 3.0, 200}, {"橙子", 2.2, 300}, {"菠萝", 1.5, 50}};
		// sort(gds, gds + 4); // 默认是用的operator<进行比较，需要我们手动实现一个
		sort(gds, gds + 4, LessPrice());
		sort(gds, gds + 4, GreaterPrice());
		sort(gds, gds + 4, LessSaleNum());
		sort(gds, gds + 4, GreaterSaleNum());
	}

	class Solution
	{
	public:
		int evalRPN(vector<string> &tokens)
		{
			stack<int> st;
			for (const auto &str : tokens)
			{
				// 遇到操作数入栈，遇到操作符，取连续2个暂定数据运算，运算结果继续入栈
				if (str == "+" || str == "-" || str == "*" || str == "/")
				{
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					if (str == "+")
						st.push(left + right);
					else if (str == "-")
						st.push(left - right);
					else if (str == "*")
						st.push(left * right);
					else if (str == "/")
						st.push(left / right);
				}
				else
				{
					st.push(stoi(str));
				}
			}
			return st.top();
		}
	};

	void test_priority_queue3()
	{
		int a[] = {1, 3, 4, 2, 1, 6};
		// 借助优先级队列快速建堆，默认大堆
		std::priority_queue<int> pq(a, a + 6);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

	void testOP()
	{
		srand(time(0));
		const int N = 10000000;
		vector<int> v;
		v.reserve(N);

		deque<int> dq1;
		deque<int> dq2;

		for (int i = 0; i < N; ++i)
		{
			auto e = rand();
			v.push_back(e);
			dq1.push_back(e);
			dq2.push_back(e);
		}

		int begin1 = clock();
		sort(v.begin(), v.end());
		int end1 = clock();

		int begin2 = clock();
		sort(dq1.begin(), dq1.end());
		int end2 = clock();

		printf("vector Sort:%d\n", end1 - begin1);
		printf("deque Sort:%d\n", end2 - begin2);
	}

	void testOP2()
	{
		srand(time(0));
		const int N = 10000000;
		vector<int> v;
		v.reserve(N);

		deque<int> dq1;
		deque<int> dq2;

		for (int i = 0; i < N; ++i)
		{
			auto e = rand();
			v.push_back(e);
			dq1.push_back(e);
			dq2.push_back(e);
		}

		int begin1 = clock();
		sort(v.begin(), v.end());
		int end1 = clock();

		int begin2 = clock();
		// 拷贝给vector，排序后再拷贝回来，对比效率
		vector<int> copy(dq1.begin(), dq1.end());
		sort(copy.begin(), copy.end());
		dq1.assign(copy.begin(), copy.end());
		int end2 = clock();

		printf("vector Sort:%d\n", end1 - begin1);
		printf("deque Sort:%d\n", end2 - begin2);
	}
}

int main()
{
	////std::test_queue1();
	// string str[] = { "4", "13", "5", "/", "+" };
	// vector<string> strArr(str, str + 5);
	// int ret = Solution().evalRPN(strArr);
	// cout << ret << endl;

	// yzq::test_priority_queue3();
	// std::test_priority_queue3();
	// std::testOP2();
	// yzq::test_list8();
	// yzq::test_priority_queue3();
	return 0;
}
