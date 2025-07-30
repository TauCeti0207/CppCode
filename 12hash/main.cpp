/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-06-13 20:18:46
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-09-01 14:55:55
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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <iomanip> // 用于格式化输出
#include "MyUnorderedMap.h"
#include "MyUnorderedSet.h"

// 测试 unordered_set 的基本用法，并与 set 进行对比
void test_set1()
{
	// 1. 初始化与插入：unordered_set 是无序、不重复的键值集合
	std::unordered_set<int> us; // 底层基于哈希表实现，插入/查找效率 O(1) 平均情况
	// 插入元素（重复元素会被自动过滤）
	us.insert(2);
	us.insert(3);
	us.insert(1);
	us.insert(2); // 重复插入，实际不会生效
	us.insert(5);
	us.insert(4);

	std::cout << "=== unordered_set 基本操作演示 ===" << std::endl;

	// 2. 遍历方式：仅支持正向迭代器（无反向迭代器，因无序存储）
	std::cout << "1. 迭代器遍历（无序）：";
	auto it = us.begin();
	while (it != us.end())
	{
		std::cout << *it << " "; // 输出顺序与插入顺序无关（哈希映射结果）
		++it;
	}
	std::cout << std::endl;

	std::cout << "2. 范围 for 遍历（无序）：";
	for (auto e : us)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 3. 常用成员函数
	std::cout << "3. 集合大小：" << us.size() << std::endl; // 输出 5（去重后共5个元素）
	std::cout << "4. 判断是否为空：" << (us.empty() ? "空" : "非空") << std::endl;

	// 4. 查找元素（核心优势：哈希查找效率高）
	int target = 3;
	auto find_it = us.find(target); // 返回指向目标的迭代器，未找到则返回 end()
	if (find_it != us.end())
	{
		std::cout << "5. 找到元素 " << target << std::endl;
	}
	else
	{
		std::cout << "5. 未找到元素 " << target << std::endl;
	}

	// 5. 统计元素出现次数（因不允许重复，结果只能是 0 或 1）
	std::cout << "6. 元素 2 出现的次数：" << us.count(2) << std::endl;	 // 输出 1
	std::cout << "   元素 10 出现的次数：" << us.count(10) << std::endl; // 输出 0

	// 6. 删除元素
	us.erase(5); // 删除值为 5 的元素
	std::cout << "7. 删除元素 5 后遍历：";
	for (auto e : us)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 7. 清空集合
	us.clear();
	std::cout << "8. 清空集合后大小：" << us.size() << std::endl; // 输出 0

	// 对比：与 set（有序集合）的差异
	std::cout << "\n=== 与 set（有序集合）的对比 ===" << std::endl;
	std::set<int> s; // 底层基于红黑树实现，自动按 key 排序，插入/查找效率 O(log n)
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(2); // 同样去重
	s.insert(5);

	std::cout << "set 遍历（自动排序）：";
	for (auto e : s)
	{
		std::cout << e << " "; // 输出：1 2 3 5（按升序排列）
	}
	std::cout << std::endl;

	// set 支持反向迭代器
	std::cout << "set 反向遍历：";
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		std::cout << *rit << " "; // 输出：5 3 2 1（按降序排列）
		++rit;
	}
	std::cout << std::endl;

	// 总结：unordered_set 与 set 的选择场景
	std::cout << "\n=== 总结 ===" << std::endl;
	std::cout << "1. unordered_set：无序，哈希表实现，适合频繁插入/查找，不支持排序和反向迭代" << std::endl;
	std::cout << "2. set：自动按 key 排序，红黑树实现，适合需要有序遍历的场景，支持反向迭代" << std::endl;
}

void test_op()
{
	const int n = 1000000;
	std::cout << "\n=== 性能测试开始 ===" << std::endl;
	std::cout << "测试数据规模: " << n << " 个随机整数" << std::endl;

	// 准备测试数据
	std::cout << "\n[1/4] 正在生成随机数据..." << std::flush;
	std::vector<int> v;
	v.reserve(n);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < n; ++i)
	{
		// v.push_back(std::rand()); // 存在大量重复数据
		v.push_back(std::rand() + i); // 重复数据较少
	}
	std::cout << "完成" << std::endl;

	// 插入性能测试
	std::cout << "\n[2/4] 测试插入性能..." << std::endl;

	std::cout << "  - std::set 插入中..." << std::flush;
	std::clock_t begin1 = std::clock();
	std::set<int> s;
	for (auto e : v)
	{
		s.insert(e);
	}
	std::clock_t end1 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_set 插入中..." << std::flush;
	std::clock_t begin2 = std::clock();
	std::unordered_set<int> us;
	for (auto e : v)
	{
		us.insert(e);
	}
	std::clock_t end2 = std::clock();
	std::cout << "完成" << std::endl;

	// 查找性能测试
	std::cout << "\n[3/4] 测试查找性能..." << std::endl;

	std::cout << "  - std::set 查找中..." << std::flush;
	std::clock_t begin3 = std::clock();
	for (auto e : v)
	{
		s.find(e);
	}
	std::clock_t end3 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_set 查找中..." << std::flush;
	std::clock_t begin4 = std::clock();
	for (auto e : v)
	{
		us.find(e);
	}
	std::clock_t end4 = std::clock();
	std::cout << "完成" << std::endl;

	// 删除性能测试
	std::cout << "\n[4/4] 测试删除性能..." << std::endl;

	std::cout << "  - 复制数据..." << std::flush;
	std::vector<int> elements(s.begin(), s.end());
	std::set<int> s_copy = s;
	std::unordered_set<int> us_copy = us;
	std::cout << "完成" << std::endl;

	std::cout << "  - std::set 删除中..." << std::flush;
	std::clock_t begin5 = std::clock();
	for (auto e : elements)
	{
		s_copy.erase(e);
	}
	std::clock_t end5 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_set 删除中..." << std::flush;
	std::clock_t begin6 = std::clock();
	for (auto e : elements)
	{
		us_copy.erase(e);
	}
	std::clock_t end6 = std::clock();
	std::cout << "完成" << std::endl;

	// 计算耗时（毫秒）
	double insert_set = (end1 - begin1) * 1000.0 / CLOCKS_PER_SEC;
	double insert_us = (end2 - begin2) * 1000.0 / CLOCKS_PER_SEC;
	double find_set = (end3 - begin3) * 1000.0 / CLOCKS_PER_SEC;
	double find_us = (end4 - begin4) * 1000.0 / CLOCKS_PER_SEC;
	double erase_set = (end5 - begin5) * 1000.0 / CLOCKS_PER_SEC;
	double erase_us = (end6 - begin6) * 1000.0 / CLOCKS_PER_SEC;

	// 输出结果表格
	std::cout << "\n=== 测试结果汇总 ===" << std::endl;
	std::cout << "有效元素数量: " << s.size() << " / " << n
			  << " (" << std::fixed << std::setprecision(2)
			  << (s.size() * 100.0 / n) << "%)" << std::endl;

	std::cout << std::left << std::setw(20) << "操作类型"
			  << std::setw(15) << "std::set"
			  << std::setw(15) << "std::unordered_set"
			  << std::setw(15) << "性能比" << std::endl;
	std::cout << std::string(65, '-') << std::endl;

	std::cout << std::left << std::setw(20) << "插入耗时 (ms):"
			  << std::setw(15) << std::fixed << std::setprecision(2) << insert_set
			  << std::setw(15) << insert_us
			  << std::setw(15) << std::fixed << std::setprecision(2) << (insert_set / insert_us) << "x" << std::endl;

	std::cout << std::left << std::setw(20) << "查找耗时 (ms):"
			  << std::setw(15) << find_set
			  << std::setw(15) << find_us
			  << std::setw(15) << (find_set / find_us) << "x" << std::endl;

	std::cout << std::left << std::setw(20) << "删除耗时 (ms):"
			  << std::setw(15) << erase_set
			  << std::setw(15) << erase_us
			  << std::setw(15) << (erase_set / erase_us) << "x" << std::endl;

	// 性能分析
	std::cout << "\n=== 性能分析 ===" << std::endl;
	if (insert_us < insert_set)
	{
		std::cout << "✓ 插入操作：unordered_set 比 set 快 "
				  << std::fixed << std::setprecision(2)
				  << (insert_set / insert_us) << " 倍" << std::endl;
	}
	else
	{
		std::cout << "✗ 插入操作：set 比 unordered_set 快 "
				  << std::fixed << std::setprecision(2)
				  << (insert_us / insert_set) << " 倍（异常情况，可能哈希冲突严重）" << std::endl;
	}

	if (find_us < find_set)
	{
		std::cout << "✓ 查找操作：unordered_set 比 set 快 "
				  << std::fixed << std::setprecision(2)
				  << (find_set / find_us) << " 倍" << std::endl;
	}
	else
	{
		std::cout << "✗ 查找操作：set 比 unordered_set 快 "
				  << std::fixed << std::setprecision(2)
				  << (find_us / find_set) << " 倍（异常情况，可能哈希冲突严重）" << std::endl;
	}

	if (erase_us < erase_set)
	{
		std::cout << "✓ 删除操作：unordered_set 比 set 快 "
				  << std::fixed << std::setprecision(2)
				  << (erase_set / erase_us) << " 倍" << std::endl;
	}
	else
	{
		std::cout << "✗ 删除操作：set 比 unordered_set 快 "
				  << std::fixed << std::setprecision(2)
				  << (erase_us / erase_set) << " 倍（异常情况，可能哈希冲突严重）" << std::endl;
	}

	std::cout << "\n=== 使用建议 ===" << std::endl;
	std::cout << "- 若需要元素有序性或频繁范围查询，建议选择 std::set" << std::endl;
	std::cout << "- 若追求极致插入/查找/删除性能（不关心顺序），建议选择 std::unordered_set" << std::endl;
	std::cout << "====================================\n"
			  << std::endl;
}

void test_hash_table1()
{
	int a[] = {20, 5, 8, 99999, 10, 30, 50};
	// HashTable<int, int, DefaultHash<int>> ht;
	closeHash::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert(std::make_pair(e, e));
	}

	ht.Print();
	std::cout << std::endl;
	std::cout << "测试扩容：" << std::endl;
	// 测试扩容
	ht.Insert(std::make_pair(15, 15));
	ht.Insert(std::make_pair(5, 5));
	ht.Insert(std::make_pair(15, 15));

	ht.Print();

	if (ht.Find(50))
	{
		std::cout << "找到了50" << std::endl;
	}

	if (ht.Find(10))
	{
		std::cout << "找到了10" << std::endl;
	}

	ht.Erase(10);
	ht.Erase(10);

	ht.Print();

	if (ht.Find(50))
	{
		std::cout << "找到了50" << std::endl;
	}

	if (ht.Find(10))
	{
		std::cout << "找到了10" << std::endl;
	}
}

void test_hash_table2()
{
	std::string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};

	std::string s1("苹果");
	std::string s2("果苹");
	std::string s3("果果");
	std::string s4("萍果");

	std::string s5("abcd");
	std::string s6("bcad");
	std::string s7("aadd");

	closeHash::StringHashFunc hf;
	std::cout << "=== 字符串哈希值计算 ===" << std::endl;
	std::cout << "苹果的哈希值: " << hf(s1) << std::endl;
	std::cout << "果苹的哈希值: " << hf(s2) << std::endl;
	std::cout << "果果的哈希值: " << hf(s3) << std::endl;
	std::cout << "萍果的哈希值: " << hf(s4) << std::endl
			  << std::endl;

	std::cout << "abcd的哈希值: " << hf(s5) << std::endl;
	std::cout << "bcad的哈希值: " << hf(s6) << std::endl;
	std::cout << "aadd的哈希值: " << hf(s7) << std::endl
			  << std::endl;

	std::cout << "=== 哈希表插入与查找操作 ===" << std::endl;
	// yzq::HashTable<std::string, int, yzq::StringHashFunc> countHT;
	closeHash::HashTable<std::string, int> countHT;

	for (auto &str : arr)
	{
		auto ret = countHT.Find(str);
		if (ret)
		{
			ret->_kv.second++;
			std::cout << "[更新计数] " << str << " 的计数变为: " << ret->_kv.second << std::endl;
		}
		else
		{
			countHT.Insert(std::make_pair(str, 1));
		}
	}

	countHT.Print();
}

void TestHashBucket1()
{
	int a[] = {20, 5, 8, 99999, 10, 30, 50};
	HashBucket::HashTable<int, int> ht;
	if (ht.Find(10))
	{
		std::cout << "找到了10" << std::endl;
	}

	for (auto e : a)
	{
		ht.Insert(std::make_pair(e, e));
	}

	// test expand capacity
	ht.Insert(std::make_pair(15, 15));
	ht.Insert(std::make_pair(5, 5));
	ht.Insert(std::make_pair(15, 15));
	ht.Insert(std::make_pair(25, 15));
	ht.Insert(std::make_pair(35, 15));
	ht.Insert(std::make_pair(45, 15));
}

void TestHashBucket2()
{
	std::string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};
	// HashTable<string, int, StringHash> countHT;
	HashBucket::HashTable<std::string, int> countHT; // 缺省

	for (auto &str : arr)
	{
		auto ret = countHT.Find(str);
		if (ret)
		{
			ret->_kv.second++;
		}
		else
		{
			countHT.Insert(make_pair(str, 1));
		}
	}

	// 对应类型配一个仿函数，仿函数对象实现把key对象转换成映射的整数
	// HashTable<Date, int, DateHash> countHT;
	// HashTable<Student, int, StudentHash> countHT;

	// 需要手动实现深拷贝
	HashBucket::HashTable<std::string, int> copy(countHT);
	HashBucket::HashTable<std::string, int> copy2;
	copy2.Insert(std::make_pair("abcd", 1234));
	copy2.Insert(std::make_pair("acd", 1234));
	copy2.Insert(std::make_pair("cd", 1234));

	copy2 = copy; // 赋值重载必须得是已经有的对象才能叫赋值重载
}

void test_op2()
{
	const int n = 1000000;
	std::cout << "\n=== 性能测试开始 ===" << std::endl;
	std::cout << "测试数据规模: " << n << " 个随机整数" << std::endl;

	// 准备测试数据 - 使用字符串作为键（更贴近实际使用场景）
	std::cout << "\n[1/4] 正在生成随机数据..." << std::flush;
	std::vector<std::string> v;
	v.reserve(n);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < n; ++i)
	{
		// 生成随机字符串作为键（格式：前缀+随机数）
		v.push_back("key_" + std::to_string(std::rand() + i));
	}
	std::cout << "完成" << std::endl;

	// 插入性能测试
	std::cout << "\n[2/4] 测试插入性能..." << std::endl;

	std::cout << "  - std::map 插入中..." << std::flush;
	std::clock_t begin1 = std::clock();
	std::map<std::string, int> m;
	for (auto &e : v)
	{
		m.insert({e, 1});
	}
	std::clock_t end1 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_map 插入中..." << std::flush;
	std::clock_t begin2 = std::clock();
	std::unordered_map<std::string, int> um;
	for (auto &e : v)
	{
		um.insert({e, 1});
	}
	std::clock_t end2 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - 自定义HashTable 插入中..." << std::flush;
	std::clock_t begin3 = std::clock();
	HashBucket::HashTable<std::string, int> countHT;
	for (auto &e : v)
	{
		countHT.Insert({e, 1});
	}
	std::clock_t end3 = std::clock();
	std::cout << "完成" << std::endl;

	// 查找性能测试
	std::cout << "\n[3/4] 测试查找性能..." << std::endl;

	std::cout << "  - std::map 查找中..." << std::flush;
	std::clock_t begin4 = std::clock();
	for (auto &e : v)
	{
		m.find(e);
	}
	std::clock_t end4 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_map 查找中..." << std::flush;
	std::clock_t begin5 = std::clock();
	for (auto &e : v)
	{
		um.find(e);
	}
	std::clock_t end5 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - 自定义HashTable 查找中..." << std::flush;
	std::clock_t begin6 = std::clock();
	for (auto &e : v)
	{
		countHT.Find(e);
	}
	std::clock_t end6 = std::clock();
	std::cout << "完成" << std::endl;

	// 删除性能测试
	std::cout << "\n[4/4] 测试删除性能..." << std::endl;

	std::cout << "  - 复制数据..." << std::flush;
	std::vector<std::string> elements;
	elements.reserve(m.size());
	for (auto &pair : m)
	{
		elements.push_back(pair.first);
	}

	std::map<std::string, int> m_copy = m;
	std::unordered_map<std::string, int> um_copy = um;
	HashBucket::HashTable<std::string, int> ht_copy = countHT;
	std::cout << "完成" << std::endl;

	std::cout << "  - std::map 删除中..." << std::flush;
	std::clock_t begin7 = std::clock();
	for (auto &e : elements)
	{
		m_copy.erase(e);
	}
	std::clock_t end7 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - std::unordered_map 删除中..." << std::flush;
	std::clock_t begin8 = std::clock();
	for (auto &e : elements)
	{
		um_copy.erase(e);
	}
	std::clock_t end8 = std::clock();
	std::cout << "完成" << std::endl;

	std::cout << "  - 自定义HashTable 删除中..." << std::flush;
	std::clock_t begin9 = std::clock();
	for (auto &e : elements)
	{
		ht_copy.Erase(e);
	}
	std::clock_t end9 = std::clock();
	std::cout << "完成" << std::endl;

	// 计算耗时（毫秒）
	double insert_map = (end1 - begin1) * 1000.0 / CLOCKS_PER_SEC;
	double insert_um = (end2 - begin2) * 1000.0 / CLOCKS_PER_SEC;
	double insert_ht = (end3 - begin3) * 1000.0 / CLOCKS_PER_SEC;

	double find_map = (end4 - begin4) * 1000.0 / CLOCKS_PER_SEC;
	double find_um = (end5 - begin5) * 1000.0 / CLOCKS_PER_SEC;
	double find_ht = (end6 - begin6) * 1000.0 / CLOCKS_PER_SEC;

	double erase_map = (end7 - begin7) * 1000.0 / CLOCKS_PER_SEC;
	double erase_um = (end8 - begin8) * 1000.0 / CLOCKS_PER_SEC;
	double erase_ht = (end9 - begin9) * 1000.0 / CLOCKS_PER_SEC;

	// 输出结果表格
	std::cout << "\n=== 测试结果汇总 ===" << std::endl;
	std::cout << "有效元素数量: " << m.size() << " / " << n
			  << " (" << std::fixed << std::setprecision(2)
			  << (m.size() * 100.0 / n) << "%)" << std::endl;

	std::cout << std::left << std::setw(20) << "操作类型"
			  << std::setw(15) << "std::map"
			  << std::setw(15) << "std::unordered_map"
			  << std::setw(15) << "自定义HashTable"
			  << std::setw(15) << "HT/UM性能比" << std::endl;
	std::cout << std::string(80, '-') << std::endl;

	std::cout << std::left << std::setw(20) << "插入耗时 (ms):"
			  << std::setw(15) << std::fixed << std::setprecision(2) << insert_map
			  << std::setw(15) << insert_um
			  << std::setw(15) << insert_ht
			  << std::setw(15) << std::fixed << std::setprecision(2) << (insert_ht / insert_um) << "x" << std::endl;

	std::cout << std::left << std::setw(20) << "查找耗时 (ms):"
			  << std::setw(15) << find_map
			  << std::setw(15) << find_um
			  << std::setw(15) << find_ht
			  << std::setw(15) << (find_ht / find_um) << "x" << std::endl;

	std::cout << std::left << std::setw(20) << "删除耗时 (ms):"
			  << std::setw(15) << erase_map
			  << std::setw(15) << erase_um
			  << std::setw(15) << erase_ht
			  << std::setw(15) << (erase_ht / erase_um) << "x" << std::endl;

	countHT.hashTablesInfo();
}

void test_my_unordered_map1()
{
	yzq::unordered_map<std::string, int> um;
	um.Insert(std::make_pair("111", 1));
	um.Insert(std::make_pair("555", 5));
	um.Insert(std::make_pair("333", 3));
	um.Insert(std::make_pair("222", 2));
	um.Insert(std::make_pair("999", 9));

	// std::cout << "\n自定义map遍历结果: " << std::endl;
	// yzq::map<std::string, int>::iterator it = m.begin();
	// while (it != m.end())
	// {
	// 	std::cout << it->first << ":" << it->second << std::endl;
	// 	++it;
	// }
	// std::cout << std::endl;
	// for (auto kv : m)
	// {
	// 	std::cout << kv.first << ":" << kv.second << std::endl;
	// }
	// std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	test_set1();
	// test_op();
	// test_hash_table2();
	// TestHashBucket2();
	// test_op2();
	// test_my_unordered_map1();
	return 0;
}
