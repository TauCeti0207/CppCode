#pragma once
#include "HashTable.h"
#include "MyUnorderedSet.h"
#include "MyUnorderedMap.h"
#include <iostream>
#include <string>


void test_const_iterator()
{
    std::cout << "=== 测试const迭代器 ===" << std::endl;
    
    // 测试unordered_set的const迭代器
	yzq::unordered_set<int> us;
	us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    
   std::cout << "MyUnorderedSet中的元素（使用const迭代器遍历）: ";
   const yzq::unordered_set<int> &const_us = us;
   for (auto it = const_us.begin(); it != const_us.end(); ++it)
   {
	   std::cout << *it << " ";
   }
   std::cout << std::endl;
    
    // 测试unordered_map的const迭代器
    yzq::unordered_map<std::string, int> um;
    um.insert(std::make_pair("apple", 1));
    um.insert(std::make_pair("banana", 2));
    um.insert(std::make_pair("orange", 3));
    
    std::cout << "MyUnorderedMap中的元素（使用const迭代器遍历）: ";
    const yzq::unordered_map<std::string, int>& const_um = um;
    for (auto it = const_um.begin(); it != const_um.end(); ++it)
    {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;
    
    std::cout << "const迭代器测试完成！" << std::endl;
}

int main()
{
    test_const_iterator();
    return 0;
}