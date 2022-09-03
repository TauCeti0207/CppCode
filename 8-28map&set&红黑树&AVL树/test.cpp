#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include "AVLTree.h"
#include "RedBlueTree.h"
#include "set.h"
#include "map.h"
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);

	// 排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1; // 普通迭代器和const迭代器都是不允许修改的
		cout << *it << " ";
		++it;
	}
	cout << endl; // 1 2 3 4 5

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 3 4 5
}

void test_set2()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	set<int>::iterator pos = s.find(2);  // O(logN)
	if (pos != s.end())
	{
		cout << "set.find找到了" << endl;
	}
	else
	{
		cout << "set.find找不到" << endl;
	}
	// set.find找到了

	pos = find(s.begin(), s.end(), 20); // O(N) 算法里的查找是暴力查找
	if (pos != s.end())
	{
		cout << "全局find找到了" << endl;
	}
	else
	{
		cout << "全局find找不到" << endl;
	}
	// 全局find找不到
}

void test_set3()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	cout << s.erase(3) << endl; // 1 成功删除
	cout << s.erase(30) << endl; // 0

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 4 5

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
		s.erase(pos); // 如果直接删除不存在的元素 会报错 

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 4 5

	int x;
	while (cin >> x)
	{
		set<int>::iterator pos = s.find(x);
		if (pos != s.end())
		{
			s.erase(pos);
			cout << "删除" << x << "成功" << endl;
		}
		else
		{
			cout << x << "不在set中" << endl;
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	/*if (s.count(5))
	{
		cout << "5在" << endl;
	}

	if (s.find(5) != s.end())
	{
		cout << "5在" << endl;
	}*/
}

void test_set4()
{
	std::set<int> myset;

	// set some initial values:
	for (int i = 1; i < 5; ++i) myset.insert(i * 3);    // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.count(i) != 0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.find(i) != myset.end())
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}

	/*0 is not an element of myset.
	1 is not an element of myset.
	2 is not an element of myset.
	3 is an element of myset.
	4 is not an element of myset.
	5 is not an element of myset.
	6 is an element of myset.
	7 is not an element of myset.
	8 is not an element of myset.
	9 is an element of myset.

	0 is not an element of myset.
	1 is not an element of myset.
	2 is not an element of myset.
	3 is an element of myset.
	4 is not an element of myset.
	5 is not an element of myset.
	6 is an element of myset.
	7 is not an element of myset.
	8 is not an element of myset.
	9 is an element of myset.*/
}

void test_set5()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	// 返回>= val得位置迭代器  3返回3位置  6 返回7位置
	//set<int>::iterator lowIt = s.lower_bound(3); // 存在
	//lowIt = s.lower_bound(6); // 不存在
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 要求删除>=x的所有值
	int x;
	cin >> x;
	set<int>::iterator lowIt = s.lower_bound(x);
	s.erase(lowIt, s.end());

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set6()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 返回>x位置的迭代器  -》 都是返回 7位置的迭代器
	//set<int>::iterator upIt = s.upper_bound(5);  // 存在
	//upIt = s.upper_bound(6); // 不存在

	// 删除x <=  <= y的区间 删除 [x,y]
	int x, y;
	cin >> x >> y;
	auto leftIt = s.lower_bound(x);  // [
	auto rightIt = s.upper_bound(y); // )
	s.erase(leftIt, rightIt);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set7()
{
	multiset<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// 排序 
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10; /err
		cout << *it << " ";
		++it;
	}
	cout << endl; // 1 1 1 2 2 3 3 3 3 3 4 5

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 1 1 2 2 3 3 3 3 3 4 5

	cout << s.count(1) << endl; // 3 返回1的个数
	cout << s.erase(1) << endl; // 3
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 2 2 3 3 3 3 3 4 5

	// 多个x的话，find返回中序第一个x
	// 只有中序第一个3开始 才能遍历所有的3 左根右
	auto pos = s.find(3);
	while (pos != s.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl; // 3 3 3 3 3 4 5
}

void test_map1()
{
	map<string, string> dict;

	// 利用 pair 的构造函数插入数据
	dict.insert(pair<string, string>("sort", "排序")); // 匿名对象
	pair<string, string> kv("insert", "插入");
	dict.insert(kv);

	// make_pair 函数模板
	auto ret1 = dict.insert(make_pair("left", "左边"));
	auto ret2 = dict.insert(make_pair("left", "剩余"));

	dict["operator"] = "重载"; // 插入+修改
	dict["left"] = "左边、剩余"; // 修改
	dict["erase"];  // 插入
	cout << dict["left"] << endl; // 查找


	// C++11 才支持
	//dict.insert({ "right", "右边" });

	// 遍历
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " "; // it->operator*()
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl; // 省略了一个 ->
		++it;
	}
	cout << endl;

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(str);
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//		//it->first++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}

	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	//pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));
	//	auto ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//		// ret里有一个first和secon
	//		// first 是指向map的迭代器（指针）
	//		// secon 是 bool 类型
	//	}
	//}

	map<string, int> countMap;
	for (auto& str : arr)
	{
		countMap[str]++; // 等价于countMap.operator[](str)++
		// 第一次插入是 k不在map中，默认构造的value是0，然后立刻++变成1了
		// 第二次再插入相同str，value继续++
	}

	for (const auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	//苹果:6
	//西瓜:3
	//香蕉:2
}

//mapped_type& operator[] (const key_type& k)
//{
//	pair<map<key_type, mapped_type>::iterator, bool> ret = insert(make_pair(k, mapped_type()));
//
//	//return (*(ret.first)).second; // 等价
//	return ret.first->second;
//}

void test_map3()
{
	multimap<string, string> dict;
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));
	dict.insert(make_pair("left", "左边")); // 存完全一样的value也是可以的
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("string", "线"));
	dict.insert(make_pair("string", "细绳"));
	dict.insert(make_pair("string", "一系列事件"));

	/*string str;
	while (cin >> str)
	{

		auto pos = dict.find(str);
		if (pos != dict.end())
		{
			cout << "找到了 " << pos->first << ":" << pos->second << endl;
		}
		else
			cout << "找不到 " << endl;

	}*/

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	//left:左边
	//left : 剩余
	//left : 左边
	//string : 字符串
	//string : 线
	//string : 细绳
	//string : 一系列事件
}

void test_wakatime_box()
{
	for (size_t i = 0; i < 100; ++i) {
		cout << i+1 << " "; // output 1~100
	}
	cout << endl;
}

int main()
{
	//test_set7();
	//test_map3();
	//yzq::TestAVLTree3();
	//bit_homework::TestAVLTree();
	//TestRBTree2();
	//yzq::test_map1();
	//yzq::test_map2();
	//yzq::test_map3();
	test_wakatime_box();
	return 0;
}