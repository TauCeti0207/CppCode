/*
 * @Description: 测试自定义unordered_map的功能
 * @Author: tauceti0207
 * @Date: 2025-01-15
 */
#include "MyUnorderedMap.h"
#include <iostream>
#include <string>

void test_unordered_map()
{
	std::cout << "=== 测试自定义unordered_map ===" << std::endl;

	// 创建一个int到string的unordered_map
	yzq::unordered_map<int, std::string> mp;

	// 测试插入功能
	std::cout << "\n1. 测试插入功能：" << std::endl;
	std::pair<yzq::unordered_map<int, std::string>::iterator, bool> result1 = mp.insert({1, "one"});
	std::pair<yzq::unordered_map<int, std::string>::iterator, bool> result2 = mp.insert({2, "two"});
	std::pair<yzq::unordered_map<int, std::string>::iterator, bool> result3 = mp.insert({3, "three"});
	std::pair<yzq::unordered_map<int, std::string>::iterator, bool> result4 = mp.insert({1, "duplicate"}); // 重复插入

	std::cout << "插入 {1, \"one\"}: " << (result1.second ? "成功" : "失败") << std::endl;
	std::cout << "插入 {2, \"two\"}: " << (result2.second ? "成功" : "失败") << std::endl;
	std::cout << "插入 {3, \"three\"}: " << (result3.second ? "成功" : "失败") << std::endl;
	std::cout << "重复插入 {1, \"duplicate\"}: " << (result4.second ? "成功" : "失败") << std::endl;

	std::cout << "\n哈希桶内容：" << std::endl;
	mp.Print();

	// 测试size和empty
	std::cout << "\n2. 测试容量相关功能：" << std::endl;
	std::cout << "当前大小: " << mp.size() << std::endl;
	std::cout << "是否为空: " << (mp.empty() ? "是" : "否") << std::endl;

	// 测试查找功能
	std::cout << "\n3. 测试查找功能：" << std::endl;
	auto it1 = mp.find(1);
	auto it2 = mp.find(2);
	auto it3 = mp.find(4); // 不存在的键

	std::cout << "查找键 1: " << (it1 != mp.end() ? ("找到，值为 \"" + it1->second + "\"") : "未找到") << std::endl;
	std::cout << "查找键 2: " << (it2 != mp.end() ? ("找到，值为 \"" + it2->second + "\"") : "未找到") << std::endl;
	std::cout << "查找键 4: " << (it3 != mp.end() ? ("找到，值为 \"" + it3->second + "\"") : "未找到") << std::endl;

	// 测试下标操作符
	std::cout << "\n4. 测试下标操作符：" << std::endl;
	std::cout << "mp[1] = " << mp[1] << std::endl;
	std::cout << "mp[2] = " << mp[2] << std::endl;
	mp[4] = "four"; // 插入新元素
	std::cout << "mp[4] = " << mp[4] << " (新插入)" << std::endl;
	std::cout << "插入后大小: " << mp.size() << std::endl;

	// 测试迭代器遍历
	std::cout << "\n5. 测试迭代器遍历：" << std::endl;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		// it->first += 'c';
		it->second += 'c';
		std::cout << "键: " << it->first << ", 值: " << it->second << std::endl;
	}

	// 测试范围for循环
	std::cout << "\n6. 测试范围for循环：" << std::endl;
	for (const auto &pair : mp)
	{
		std::cout << "键: " << pair.first << ", 值: " << pair.second << std::endl;
	}

	// 测试删除功能
	std::cout << "\n7. 测试删除功能：" << std::endl;
	bool erase1 = mp.erase(2);
	bool erase2 = mp.erase(5); // 不存在的键

	std::cout << "删除键 2: " << (erase1 ? "成功" : "失败") << std::endl;
	std::cout << "删除键 5: " << (erase2 ? "成功" : "失败") << std::endl;
	std::cout << "删除后大小: " << mp.size() << std::endl;

	// 再次遍历查看删除效果
	std::cout << "\n8. 删除后的内容：" << std::endl;
	for (const auto &pair : mp)
	{
		std::cout << "键: " << pair.first << ", 值: " << pair.second << std::endl;
	}

	// 测试count接口
	std::cout << "\n9. 测试count接口：" << std::endl;
	std::cout << "count(1): " << mp.count(1) << std::endl;
	std::cout << "count(2): " << mp.count(2) << " (已删除)" << std::endl;
	std::cout << "count(5): " << mp.count(5) << " (不存在)" << std::endl;

	// 测试at接口
	std::cout << "\n10. 测试at接口：" << std::endl;
	try
	{
		std::cout << "mp.at(1) = " << mp.at(1) << std::endl;
		std::cout << "mp.at(4) = " << mp.at(4) << std::endl;
		std::cout << "尝试访问不存在的键mp.at(5)..." << std::endl;
		std::cout << mp.at(5) << std::endl; // 这里会抛出异常
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "捕获异常: " << e.what() << std::endl;
	}

	// 测试哈希表信息
	std::cout << "\n11. 测试哈希表信息：" << std::endl;
	std::cout << "桶数量: " << mp.bucket_count() << std::endl;
	std::cout << "负载因子: " << mp.load_factor() << std::endl;

	// 测试清空功能
	std::cout << "\n12. 测试清空功能：" << std::endl;
	mp.clear();
	std::cout << "清空后大小: " << mp.size() << std::endl;
	std::cout << "清空后是否为空: " << (mp.empty() ? "是" : "否") << std::endl;
	std::cout << "清空后负载因子: " << mp.load_factor() << std::endl;
}
