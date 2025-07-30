/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-06-13 20:18:46
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-07-30 15:34:57
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <time.h>
#include <stack>
#include <queue>
#include <memory>
#include <cstddef>
#include <cstdio>
#include <cstdint>
#include "set.h"
#include "map.h"
#include <set>
#include "AVLTree.h"

void test_set3()
{
	std::set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	// set本来就会自动去重

	std::cout << s.erase(3) << std::endl;  // 1 返回删除元素数量
	std::cout << s.erase(30) << std::endl; // 0

	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 1 2 4 5

	std::set<int>::iterator pos = s.find(3);
	if (pos != s.end())
		// 传的参数是迭代器
		s.erase(pos); // 如果直接删除不存在的元素 会报错

	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 1 2 4 5

	int x;
	while (std::cin >> x)
	{
		std::set<int>::iterator pos = s.find(x);
		if (pos != s.end())
		{
			s.erase(pos);
			std::cout << "删除" << x << "成功" << std::endl;
		}
		else
		{
			std::cout << x << "不在set中" << std::endl;
		}

		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}

void test_set5()
{
	std::set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	// 返回>= val的位置迭代器  3返回3位置  6返回7位置
	// std::set<int>::iterator lowIt = s.lower_bound(3); // 存在
	// lowIt = s.lower_bound(6); // 不存在
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 要求删除>=x的所有值
	std::cout << "删除>=4的所有值" << std::endl;
	int x = 4;
	std::set<int>::iterator lowIt = s.lower_bound(x);
	s.erase(lowIt, s.end());

	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_set7()
{
	// 创建multiset并插入元素
	std::multiset<int> s;
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

	// 输出初始状态
	std::cout << "初始multiset（自动排序）: ";
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 统计并删除元素1
	std::cout << "\n元素1的数量: " << s.count(1) << std::endl;
	std::cout << "删除元素1的数量: " << s.erase(1) << std::endl;

	// 输出删除后的状态
	std::cout << "删除元素1后的multiset: ";
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 查找并遍历元素3 find返回的是中序的第一个3
	auto pos = s.find(3);
	if (pos != s.end())
	{
		std::cout << "\n从第一个3开始的元素: ";
		while (pos != s.end())
		{
			std::cout << *pos << " ";
			++pos;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\n未找到元素3" << std::endl;
	}
}

void test_map1()
{
	// 创建字典map并插入数据
	std::map<std::string, std::string> dict;

	// 利用pair的构造函数插入数据
	dict.insert(std::pair<std::string, std::string>("sort", "排序")); // 匿名对象
	std::pair<std::string, std::string> kv("insert", "插入");
	dict.insert(kv);

	// make_pair函数模板
	dict.insert(std::make_pair("left", "左边"));

	// C++11初始化列表插入
	dict.insert({"right", "右边"});

	// 输出插入后的字典内容（迭代器遍历）
	std::cout << "【迭代器遍历map】" << std::endl;
	std::map<std::string, std::string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// std::cout << it->first << " : " << it->second << std::endl;
		// 这里本质其实是it.operator->()->first 也可以显示的写出来
		std::cout << it.operator->()->first << " : " << it.operator->()->second << std::endl;
		++it;
	}
	std::cout << std::endl;

	// 范围for遍历map
	std::cout << "【范围for遍历map】" << std::endl;
	for (const auto &pair : dict)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
	std::cout << std::endl;

	// C++17支持的结构化绑定遍历
	std::cout << "【C++17支持的结构化绑定遍历】" << std::endl;
	for (const auto &[key, value] : dict)
	{
		std::cout << key << " : " << value << std::endl;
	}
	std::cout << std::endl;

	// 演示operator[]访问（若键不存在则插入默认值）
	std::cout << "【operator[]访问】" << std::endl;
	std::cout << "dict[\"sort\"] = " << dict["sort"] << std::endl;
	std::cout << "dict[\"new_key\"] = " << dict["new_key"] << std::endl; // 插入新键值对

	std::cout << "插入new_key后的map：" << std::endl;
	for (const auto &pair : dict)
	{
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}

void test_map2()
{
	std::string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};

	std::map<std::string, int> countMap;
	for (auto &str : arr)
	{
		std::pair<std::map<std::string, int>::iterator, bool> ret = countMap.insert(std::make_pair(str, 1));
		// 插入成功的话就无需做多余处理
		// 遇到重复key则表示的是插入失败
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

	for (const auto &kv : countMap)
	{
		std::cout << kv.first << ":" << kv.second << std::endl;
	}
	// 苹果:6
	// 西瓜:3
	// 香蕉:2
}

void test_map3()
{
	std::map<std::string, int> scores;

	// 插入新元素（键不存在）
	scores["Alice"] = 90; // 等价于：先插入{"Alice", 0}，再赋值为90

	// 访问已有元素
	std::cout << scores["Alice"] << std::endl; // 输出：90

	// 自增操作（存在则修改，不存在则初始化为0再自增）
	scores["Bob"]++;
	std::cout << scores["Bob"] << std::endl; // 输出：1

	// 检查插入副作用
	if (scores.find("Charlie") != scores.end())
	{
		std::cout << "Charlie exists!" << std::endl;
	}
	else
	{
		int val = scores["Charlie"];						  // 强制插入默认值0
		std::cout << "Charlie's score: " << val << std::endl; // 输出：0
	}
}

void test_AVLTree1()
{
	// int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	yzq::AVLTree<int, int> tree;
	for (auto e : a)
	{
		tree.Insert(std::make_pair(e, e));
	}

	tree.InOrder();
	// 验证是否是AVL树
	std::cout << "IsBalanceTree: " << tree.IsBalanceTree() << std::endl;
}

void test_AVLTree_LargeRandomData()
{
	const size_t N = 200000;
	std::vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(rand() + i);
	}

	yzq::AVLTree<int, int> tree;
	for (auto e : v)
	{
		tree.Insert(std::make_pair(e, e));
	}
	// std::boolalpha 用于设置输出布尔值时以文本形式（true 或 false）显示。
	std::cout << "\nTest Large Random Data - Is AVL Tree: " << std::boolalpha << tree.IsBalanceTree() << std::endl;
	std::cout << "Tree Height: " << tree.Height() << std::endl;
	std::cout << "Tree Node size: " << tree.size() << std::endl;
}

void test_AVLTree_OrderedInsertion()
{
	const size_t N = 10000;
	yzq::AVLTree<int, int> tree;
	for (size_t i = 1; i <= N; ++i)
	{
		tree.Insert(std::make_pair(i, i));
	}

	std::cout << "\nTest Ordered Insertion - Is AVL Tree: " << std::boolalpha << tree.IsBalanceTree() << std::endl;
	std::cout << "Tree Height: " << tree.Height() << std::endl;
}

void test_AVLTree_DuplicateInsertion()
{
	yzq::AVLTree<int, int> tree;
	std::vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

	for (auto e : v)
	{
		bool inserted = tree.Insert(std::make_pair(e, e));
		if (!inserted)
		{
			std::cout << "Duplicate key " << e << " not inserted" << std::endl;
		}
	}

	std::cout << "\nTest Duplicate Insertion - InOrder Traversal: ";
	tree.InOrder();
	std::cout << "Is AVL Tree: " << std::boolalpha << tree.IsBalanceTree() << std::endl;
}

void test_AVLTree_HeightCalculation()
{
	yzq::AVLTree<int, int> tree;
	int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	for (auto e : a)
	{
		tree.Insert(std::make_pair(e, e));
	}

	int expectedHeight = 4;
	int actualHeight = tree.Height();
	std::cout << "\nTest Height Calculation - Expected: " << expectedHeight << ", Actual: " << actualHeight << std::endl;
	assert(expectedHeight == actualHeight);
}

void TestRBTree1()
{
	// int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a[] = {30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1};
	yzq::RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.levelOrder();
	t.InOrder();
	t.Height();
}

void TestRBTree2()
{
	const size_t N = 1024 * 1024;
	std::vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		// v.push_back(rand());
		v.push_back(i);
	}

	yzq::RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(std::make_pair(e, e));
	}
	std::cout << "节点数量：" << t.size() << std::endl;

	std::cout << "是否平衡? " << t.IsValidRBTree() << std::endl;
	t.Height();

	// t.InOrder();
}

void test_std_set1()
{
	std::cout << "=== 测试 std::set 基本功能 ===" << std::endl;

	// 1. 测试插入和去重
	std::set<int> s;
	std::cout << "插入数据: 8, 6, 11, 5, 6(重复), 7, 10, 13, 12, 15" << std::endl;
	s.insert(8);
	s.insert(6);
	s.insert(11);
	s.insert(5);
	s.insert(6); // 重复元素，应该不会被插入
	s.insert(7);
	s.insert(10);
	s.insert(13);
	s.insert(12);
	s.insert(15);

	// 2. 测试迭代器遍历（有序输出）
	std::cout << "迭代器遍历结果（应该是有序的）: ";
	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// 3. 测试范围for循环
	std::cout << "范围for循环遍历结果: ";
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 4. 测试查找功能
	std::cout << "\n=== 测试查找功能 ===" << std::endl;
	auto find_it = s.find(7);
	if (find_it != s.end())
	{
		std::cout << "找到元素 7: " << *find_it << std::endl;
	}
	else
	{
		std::cout << "未找到元素 7" << std::endl;
	}

	find_it = s.find(100);
	if (find_it != s.end())
	{
		std::cout << "找到元素 100: " << *find_it << std::endl;
	}
	else
	{
		std::cout << "未找到元素 100（预期结果）" << std::endl;
	}

	// 5. 测试插入返回值
	std::cout << "\n=== 测试插入返回值 ===" << std::endl;
	std::pair<std::set<int>::iterator, bool> insert_result = s.insert(20);
	if (insert_result.second)
	{
		std::cout << "成功插入新元素 20" << std::endl;
	}
	else
	{
		std::cout << "元素 20 已存在，插入失败" << std::endl;
	}

	insert_result = s.insert(7); // 重复插入
	if (insert_result.second)
	{
		std::cout << "成功插入新元素 7" << std::endl;
	}
	else
	{
		std::cout << "元素 7 已存在，插入失败（预期结果）" << std::endl;
	}

	std::cout << "\n最终set内容: ";
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

// 添加一个测试自定义set的函数
void test_my_set1()
{
	std::cout << "=== 测试自定义 yzq::set ===" << std::endl;

	yzq::set<int> my_set;
	std::cout << "插入数据到自定义set: 3, 1, 4, 1, 5, 9, 2, 6" << std::endl;

	my_set.insert(3);
	my_set.insert(1);
	my_set.insert(4);
	my_set.insert(1); // 重复
	my_set.insert(5);
	my_set.insert(9);
	my_set.insert(2);
	my_set.insert(6);

	std::cout << "自定义set遍历结果: ";
	for (auto it = my_set.begin(); it != my_set.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 测试范围for循环
	std::cout << "范围for循环遍历结果: ";
	for (auto e : my_set)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 测试查找
	auto find_it = my_set.find(5);
	if (find_it != my_set.end())
	{
		std::cout << "在自定义set中找到元素 5" << std::endl;
	}

	find_it = my_set.find(10);
	if (find_it == my_set.end())
	{
		std::cout << "在自定义set中未找到元素 10（预期结果）" << std::endl;
	}
}

void test_my_map1()
{
	yzq::map<std::string, int> m;
	m.insert(std::make_pair("111", 1));
	m.insert(std::make_pair("555", 5));
	m.insert(std::make_pair("333", 3));
	m.insert(std::make_pair("222", 2));
	m.insert(std::make_pair("999", 9));

	std::cout << "\n自定义map遍历结果: " << std::endl;
	yzq::map<std::string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		std::cout << it->first << ":" << it->second << std::endl;
		++it;
	}
	std::cout << std::endl;
	for (auto kv : m)
	{
		std::cout << kv.first << ":" << kv.second << std::endl;
	}
	std::cout << std::endl;
}

void test_my_map2()
{
	std::string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};
	yzq::map<std::string, int> countMap;
	for (auto &str : arr)
	{
		// 没有key就插入，有key就返回次数并++
		// 这里的[]重载函数，返回的是val的引用，所以可以直接++
		countMap[str]++;
	}
	for (const auto &kv : countMap)
		std::cout << kv.first << " : " << kv.second << std::endl;
	// 苹果 : 6
	// 西瓜 : 3
	// 香蕉 : 2
}

void test_my_map3()
{
	yzq::map<std::string, std::string> dict;
	dict["insert"];
	dict["insert"] = "";
	dict["left"] = "";
}

int main()
{
	// test_AVLTree1();
	// test_AVLTree_LargeRandomData();
	// test_AVLTree_OrderedInsertion();
	// test_AVLTree_DuplicateInsertion();
	// test_AVLTree_HeightCalculation();

	// TestRBTree1();
	// TestRBTree2();

	test_my_set1();
	test_my_map1();
	test_my_map2();
	test_my_map3();
	return 0;
}