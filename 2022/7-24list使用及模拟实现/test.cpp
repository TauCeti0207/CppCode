#include "list.h"

namespace std
{
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
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		// 反向迭代器
		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			*rit -= 1;
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

		for (auto& e : lt)
		{
			e += 1;
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

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

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.sort();
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestOP()
	{
		srand(time(0));
		const int N = 10000000;
		vector<int> v;
		v.reserve(N);

		list<int> lt;

		for (int i = 0; i < N; ++i)
		{
			v.push_back(rand());
			lt.push_back(v[i]);
		}

		int begin1 = clock();
		sort(v.begin(), v.end());
		int end1 = clock();

		int begin2 = clock();
		//sort(lt.begin(), lt.end());
		lt.sort();
		int end2 = clock();

		printf("vector Sort:%d\n", end1 - begin1);
		printf("list Sort:%d\n", end2 - begin2);
	}
	
	void TestOP2()
	{
		srand(time(0));
		const int N = 10000000;
		vector<int> v;
		v.reserve(N);

		list<int> lt1;
		list<int> lt2;

		for (int i = 0; i < N; ++i)
		{
			auto e = rand();
			lt1.push_back(e);
			lt2.push_back(e);
		}

		// 拷贝到vector排序，排完以后再拷贝回来
		int begin1 = clock();
		for (auto e : lt1)
		{
			v.push_back(e);
		}
		sort(v.begin(), v.end());
		size_t i = 0;
		for (auto& e : lt1)
		{
			e = v[i++];
		}
		int end1 = clock();

		// 链表2单独排序，对比效率
		int begin2 = clock();
		lt2.sort();
		int end2 = clock();

		printf("vector Sort:%d\n", end1 - begin1);
		printf("list Sort:%d\n", end2 - begin2);
	}
}



int main()
{
	yzq::test_list7();
	return 0;
}