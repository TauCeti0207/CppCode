
#include <iostream>
#include <string>
#include "MyUnorderedSet.h"

void test_unordered_set()
{
	std::cout << "=== 测试自定义unordered_set ===" << std::endl;

	// 创建一个unordered_set
	yzq::unordered_set<int> s;

	std::cout << "\n1. 测试插入功能：" << std::endl;
	std::cout << "插入 1: " << (s.insert(1).second ? "成功" : "失败") << std::endl;
	std::cout << "插入 2: " << (s.insert(2).second ? "成功" : "失败") << std::endl;
	std::cout << "插入 3: " << (s.insert(3).second ? "成功" : "失败") << std::endl;
	std::cout << "重复插入 1: " << (s.insert(1).second ? "成功" : "失败") << std::endl;

	std::cout << "\n哈希桶内容：" << std::endl;
	s.Print();

	std::cout << "\n2. 测试容量相关功能：" << std::endl;
	std::cout << "当前大小: " << s.size() << std::endl;
	std::cout << "是否为空: " << (s.empty() ? "是" : "否") << std::endl;

	std::cout << "\n3. 测试查找功能：" << std::endl;
	auto it1 = s.find(1);
	std::cout << "查找键 1: " << (it1 != s.end() ? "找到" : "未找到") << std::endl;
	auto it2 = s.find(2);
	std::cout << "查找键 2: " << (it2 != s.end() ? "找到" : "未找到") << std::endl;
	auto it4 = s.find(4);
	std::cout << "查找键 4: " << (it4 != s.end() ? "找到" : "未找到") << std::endl;

	std::cout << "\n4. 测试迭代器遍历：" << std::endl;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		std::cout << "值: " << *it << std::endl;
	}

	std::cout << "\n5. 测试范围for循环：" << std::endl;
	for (const auto &value : s)
	{
		std::cout << "值: " << value << std::endl;
	}

	std::cout << "\n6. 测试删除功能：" << std::endl;
	std::cout << "删除键 2: " << (s.erase(2) ? "成功" : "失败") << std::endl;
	std::cout << "删除键 5: " << (s.erase(5) ? "成功" : "失败") << std::endl;
	std::cout << "删除后大小: " << s.size() << std::endl;

	std::cout << "\n7. 删除后的内容：" << std::endl;
	for (const auto &value : s)
	{
		std::cout << "值: " << value << std::endl;
	}

	std::cout << "\n8. 测试count接口：" << std::endl;
	std::cout << "count(1): " << s.count(1) << std::endl;
	std::cout << "count(2): " << s.count(2) << " (已删除)" << std::endl;
	std::cout << "count(5): " << s.count(5) << " (不存在)" << std::endl;

	std::cout << "\n9. 测试哈希表信息：" << std::endl;
	std::cout << "桶数量: " << s.bucket_count() << std::endl;
	std::cout << "负载因子: " << s.load_factor() << std::endl;

	std::cout << "\n10. 测试清空功能：" << std::endl;
	s.clear();
	std::cout << "清空后大小: " << s.size() << std::endl;
	std::cout << "清空后是否为空: " << (s.empty() ? "是" : "否") << std::endl;
	std::cout << "清空后负载因子: " << s.load_factor() << std::endl;

	std::cout << "\n=== unordered_set测试完成 ===" << std::endl;
}

void test_unordered_set_string()
{
	std::cout << "\n\n=== 测试字符串unordered_set ===" << std::endl;

	yzq::unordered_set<std::string> s;

	std::cout << "\n1. 测试字符串插入：" << std::endl;
	s.insert("apple");
	s.insert("banana");
	s.insert("cherry");
	s.insert("apple"); // 重复插入

	std::cout << "插入后大小: " << s.size() << std::endl;

	std::cout << "\n2. 遍历字符串set：" << std::endl;
	yzq::unordered_set<std::string>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = "s"; // 编译错误，const_iterator不支持修改
		std::cout << *it << " ";
		++it;
	}

	std::cout << "\n3. 测试字符串查找：" << std::endl;
	std::cout << "查找 'apple': " << (s.find("apple") != s.end() ? "找到" : "未找到") << std::endl;
	std::cout << "查找 'orange': " << (s.find("orange") != s.end() ? "找到" : "未找到") << std::endl;

	std::cout << "\n=== 字符串unordered_set测试完成 ===" << std::endl;
}