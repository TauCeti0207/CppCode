/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-23 01:05:14
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
#include "my_vector.h"

void test1()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

// 模板函数：打印任意类型的vector
template <typename T>
void printVector(const std::vector<T> &v, const std::string &name)
{
	std::cout << name << ": ";
	for (const auto &element : v)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void test_vector1()
{
	try
	{
		// 测试整数向量
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		printVector(v1, "v1");

		// 测试双精度浮点数向量
		std::vector<double> v2;
		v2.push_back(1.1);
		v2.push_back(2.2);
		v2.push_back(3.3);
		printVector(v2, "v2");

		// 测试字符串向量
		std::vector<std::string> v3;
		v3.push_back("李白");
		v3.push_back("杜甫");
		v3.push_back("苏轼");
		v3.push_back("白居易");
		printVector(v3, "v3");

		// 使用n个value初始化
		std::vector<int> v4(10, 5);
		printVector(v4, "v4");

		// 使用迭代器范围初始化
		std::vector<std::string> v5(++v3.begin(), --v3.end());
		printVector(v5, "v5");

		// 从字符串构造字符向量
		std::string s = "hello world";
		std::vector<char> v6(s.begin(), s.end());
		printVector(v6, "v6");

		// 验证容器属性
		std::cout << "\n容器属性验证:" << std::endl;
		std::cout << "v1 大小: " << v1.size() << ", 容量: " << v1.capacity() << std::endl;
		std::cout << "v2 大小: " << v2.size() << ", 容量: " << v2.capacity() << std::endl;
		std::cout << "v3 大小: " << v3.size() << ", 容量: " << v3.capacity() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "异常: " << e.what() << std::endl;
	}
}

void test_vector2()
{
	try
	{
		// 初始化向量
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		// 1. 下标+[] 遍历（修改元素）
		std::cout << "1. 下标遍历：";
		for (size_t i = 0; i < v.size(); ++i)
		{
			v[i] += 1;				  // 每个元素+1
			std::cout << v[i] << " "; // 输出: 2 3 4 5
		}
		std::cout << std::endl;

		// 2. 迭代器遍历（修改元素）
		std::cout << "2. 迭代器遍历：";
		for (auto it = v.begin(); it != v.end(); ++it)
		{							 // 使用auto简化类型
			*it -= 1;				 // 每个元素-1
			std::cout << *it << " "; // 输出: 1 2 3 4
		}
		std::cout << std::endl;

		// 3. 范围for遍历（修改元素）
		std::cout << "3. 范围for遍历：";
		for (auto &e : v)
		{						   // 使用引用允许修改元素
			e += 1;				   // 每个元素+1
			std::cout << e << " "; // 输出: 2 3 4 5
		}
		std::cout << std::endl;

		// 4. 反向迭代器遍历（只读）
		std::cout << "4. 反向迭代器遍历：";
		for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
		{
			std::cout << *rit << " "; // 输出: 5 4 3 2
		}
		std::cout << std::endl;

		// 5. const迭代器（防止修改）
		std::cout << "5. const迭代器遍历：";
		const std::vector<int> &cv = v; // 创建const引用
		for (auto cit = cv.begin(); cit != cv.end(); ++cit)
		{
			// *cit = 0;  // 错误：不能通过const迭代器修改
			std::cout << *cit << " "; // 输出: 2 3 4 5
		}
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void test_vector4()
{
	try
	{
		std::cout << std::setw(50) << std::setfill('=') << "" << std::endl;
		std::cout << std::setw(25) << std::setfill(' ') << "vector 扩容测试" << std::setw(25) << "" << std::endl;
		std::cout << std::setw(50) << std::setfill('=') << "" << std::endl;

		// 默认扩容测试
		std::cout << "\n[测试1] 默认扩容策略：\n";
		std::vector<int> v1;
		size_t capacity1 = v1.capacity();
		size_t resize_count1 = 0;

		std::cout << std::left << std::setw(10) << "元素数"
				  << std::setw(15) << "容量"
				  << std::setw(15) << "扩容次数"
				  << std::setw(15) << "内存利用率" << std::endl;
		std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;

		for (int i = 0; i <= 100; ++i)
		{
			if (i < 100)
				v1.push_back(i); // 最后一次循环仅用于输出最终状态
			if (capacity1 != v1.capacity())
			{
				capacity1 = v1.capacity();
				++resize_count1;
				if (i < 10)
				{ // 前10个元素详细输出
					std::cout << std::left << std::setw(10) << i
							  << std::setw(15) << capacity1
							  << std::setw(15) << resize_count1
							  << std::fixed << std::setprecision(2)
							  << std::setw(15) << (double)i / capacity1 * 100 << "%" << std::endl;
				}
				else if (i == 100)
				{ // 最终状态
					std::cout << std::left << std::setw(10) << i
							  << std::setw(15) << capacity1
							  << std::setw(15) << resize_count1
							  << std::fixed << std::setprecision(2)
							  << std::setw(15) << (double)i / capacity1 * 100 << "%" << std::endl;
				}
			}
		}

		// 使用reserve的测试
		std::cout << "\n[测试2] 使用 reserve(100) 预分配空间：\n";
		std::vector<int> v2;
		v2.reserve(100);
		size_t capacity2 = v2.capacity();
		size_t resize_count2 = 0;

		std::cout << std::left << std::setw(10) << "元素数"
				  << std::setw(15) << "容量"
				  << std::setw(15) << "扩容次数"
				  << std::setw(15) << "内存利用率" << std::endl;
		std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;

		for (int i = 0; i <= 100; ++i)
		{
			if (i < 100)
				v2.push_back(i);
			if (capacity2 != v2.capacity())
			{
				capacity2 = v2.capacity();
				++resize_count2;
				std::cout << std::left << std::setw(10) << i
						  << std::setw(15) << capacity2
						  << std::setw(15) << resize_count2
						  << std::fixed << std::setprecision(2)
						  << std::setw(15) << (double)i / capacity2 * 100 << "%" << std::endl;
			}
		}

		// 效率对比
		std::cout << "\n[测试结果对比]\n";
		std::cout << "默认扩容策略：总扩容次数=" << resize_count1
				  << "，最终容量=" << v1.capacity()
				  << "，内存浪费=" << (v1.capacity() - 100) * sizeof(int) << "字节\n";
		std::cout << "使用reserve(100)：总扩容次数=" << resize_count2
				  << "，最终容量=" << v2.capacity()
				  << "，内存浪费=" << (v2.capacity() - 100) * sizeof(int) << "字节\n";

		// 用户自定义测试
		char choice;
		std::cout << "\n是否进行自定义扩容测试？(y/n): ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			size_t custom_size;
			std::cout << "请输入预分配大小: ";
			std::cin >> custom_size;

			std::vector<int> v3;
			v3.reserve(custom_size);
			size_t capacity3 = v3.capacity();
			size_t resize_count3 = 0;

			std::cout << "\n[自定义测试] reserve(" << custom_size << "):\n";
			for (int i = 0; i <= 100; ++i)
			{
				if (i < 100)
					v3.push_back(i);
				if (capacity3 != v3.capacity())
				{
					capacity3 = v3.capacity();
					++resize_count3;
					std::cout << "插入 " << i << " 个元素后扩容至: " << capacity3 << std::endl;
				}
			}
			std::cout << "自定义策略：总扩容次数=" << resize_count3
					  << "，最终容量=" << v3.capacity() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "异常: " << e.what() << std::endl;
	}
}

void test_vector5()
{
	// 创建一个整数向量
	std::vector<int> countV;
	std::cout << "初始状态: size=" << countV.size()
			  << ", capacity=" << countV.capacity() << std::endl;

	// 1. 使用resize调整大小为10，初始值为1
	countV.resize(10, 1);
	std::cout << "resize(10, 1): size=" << countV.size()
			  << ", capacity=" << countV.capacity() << " | ";
	for (auto e : countV)
		std::cout << e << " ";
	std::cout << std::endl;

	// 2. 缩小大小为5，丢弃超出的元素
	countV.resize(5);
	std::cout << "resize(5): size=" << countV.size()
			  << ", capacity=" << countV.capacity() << " | ";
	for (auto e : countV)
		std::cout << e << " ";
	std::cout << std::endl;

	// 3. 扩大大小为8，新元素用10填充
	countV.resize(8, 10);
	std::cout << "resize(8, 10): size=" << countV.size()
			  << ", capacity=" << countV.capacity() << " | ";
	for (auto e : countV)
		std::cout << e << " ";
	std::cout << std::endl;

	// 4. 扩大大小为12，新元素用默认值0填充
	countV.resize(12);
	std::cout << "resize(12): size=" << countV.size()
			  << ", capacity=" << countV.capacity() << " | ";
	for (auto e : countV)
		std::cout << e << " ";
	std::cout << std::endl;
}

void test_vector6()
{
	try
	{
		std::vector<int> foo;

		// 预分配100个元素的空间（容量=100，大小=0）
		foo.reserve(100);
		std::cout << "reserve(100) 后: "
				  << "size=" << foo.size() << ", "
				  << "capacity=" << foo.capacity() << std::endl;

		// 调整大小为10个元素（容量=100，大小=10）
		foo.resize(10);
		std::cout << "resize(10) 后: "
				  << "size=" << foo.size() << ", "
				  << "capacity=" << foo.capacity() << std::endl;

		// 收缩容量以匹配大小（容量=10，大小=10）
		foo.shrink_to_fit();
		std::cout << "shrink_to_fit() 后: "
				  << "size=" << foo.size() << ", "
				  << "capacity=" << foo.capacity() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "异常: " << e.what() << std::endl;
	}
}

void test_vector7()
{
	try
	{
		// 初始化向量
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		// 在头部连续插入元素
		v.insert(v.begin(), -1); // 插入后: [-1, 1, 2, 3, 4]
		v.insert(v.begin(), -2); // 插入后: [-2, -1, 1, 2, 3, 4]
		v.insert(v.begin(), -3); // 插入后: [-3, -2, -1, 1, 2, 3, 4]
		std::cout << "连续头部插入后: ";
		for (auto e : v)
			std::cout << e << " ";
		std::cout << std::endl;

		// 在指定位置插入元素（索引7，即末尾后一个位置）
		v.insert(v.begin() + 7, 300); // 插入后: [-3, -2, -1, 1, 2, 3, 4, 300]
		std::cout << "在索引7插入后: ";
		for (auto e : v)
			std::cout << e << " ";
		std::cout << std::endl;

		// 连续删除头部元素
		v.erase(v.begin()); // 删除后: [-2, -1, 1, 2, 3, 4, 300]
		v.erase(v.begin()); // 删除后: [-1, 1, 2, 3, 4, 300]
		std::cout << "连续头部删除后: ";
		for (auto e : v)
			std::cout << e << " ";
		std::cout << std::endl;

		// 删除区间 [begin+1, begin+4)，即删除索引1,2,3的元素
		v.erase(v.begin() + 1, v.begin() + 4); // 删除后: [-1, 4, 300]
		std::cout << "删除区间后: ";
		for (auto e : v)
			std::cout << e << " ";
		std::cout << std::endl;

		// 查找300，在 300 前面插入 这是算法库提供的 find
		std::vector<int>::iterator it = std::find(v.begin(), v.end(), 300);
		if (it != v.end())
		{
			v.insert(it, 100); // // 插入后: [-1, 4, 100, 300]
		}
		for (auto e : v)
			std::cout << e << " ";
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "异常: " << e.what() << std::endl;
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * @brief 生成杨辉三角的函数
 * @param numRows 要生成杨辉三角的行数，由调用者传入指定生成的规模
 * @param returnSize 指向一个整数的指针，函数通过它返回生成的杨辉三角的总行数
 * @param returnColumnSizes 指向一个整数指针的指针，函数通过它返回一个数组，数组中每个元素表示杨辉三角对应行的元素个数
 * @return 返回一个指向指针的指针，即动态分配的二维数组，用于存储生成的杨辉三角
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	// 为存储杨辉三角每一行的指针数组分配内存，指针数组的大小为numRows，每个指针指向一行数据
	int **ret = (int **)malloc(sizeof(int *) * numRows);
	if (ret == NULL)
	{
		// 内存分配失败处理，可根据实际情况添加更完善的错误提示
		perror("malloc for ret failed");
		return NULL;
	}
	// 将生成的杨辉三角的总行数通过returnSize指针返回给调用者
	*returnSize = numRows;
	// 为存储每一行元素个数的数组分配内存，数组大小为numRows
	*returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
	if (*returnColumnSizes == NULL)
	{
		// 内存分配失败处理，释放之前已分配的ret内存，避免内存泄漏
		free(ret);
		perror("malloc for returnColumnSizes failed");
		return NULL;
	}
	// 遍历杨辉三角的每一行
	for (int i = 0; i < numRows; ++i)
	{
		// 为当前行分配内存，每一行元素个数为i + 1
		ret[i] = (int *)malloc(sizeof(int) * (i + 1));
		if (ret[i] == NULL)
		{
			// 内存分配失败处理，释放之前已分配的当前行之前的行内存以及returnColumnSizes内存，避免内存泄漏
			for (int j = 0; j < i; ++j)
			{
				free(ret[j]);
			}
			free(*returnColumnSizes);
			perror("malloc for ret[i] failed");
			return NULL;
		}
		// 记录当前行的元素个数，通过returnColumnSizes数组返回给调用者
		(*returnColumnSizes)[i] = i + 1;
		// 杨辉三角每一行的首尾元素都为1
		ret[i][0] = ret[i][i] = 1;
		// 计算当前行中间的元素，其值等于上一行对应两个元素之和
		for (int j = 1; j < i; ++j)
		{
			ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
	}
	// 返回存储杨辉三角的二维数组
	return ret;
}

void test_generate()
{
	int returnSize;			// 用于接收总行数
	int *returnColumnSizes; // 用于接收每行的元素个数
	int **triangle = generate(5, &returnSize, &returnColumnSizes);

	// 输出杨辉三角
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%d ", triangle[i][j]);
		}
		printf("\n");
	}

	// 释放内存（关键！避免内存泄漏）
	for (int i = 0; i < returnSize; i++)
	{
		free(triangle[i]); // 释放每行
	}
	free(triangle);			 // 释放二维数组
	free(returnColumnSizes); // 释放列大小数组
}

void test_vector8()
{
	yzq::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_vector9()
{
	yzq::vector<int *> v;
	v.resize(10);
	yzq::vector<std::string> v2;
	// 单参数构造函数隐式类型转换
	v2.resize(10, "hello");

	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	for (auto e : v2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_vector10()
{
	// 要求：在所有的偶数前面插入一个20
	yzq::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	yzq::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.insert(it, 20);
			++it;
		}
		++it;
	}
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_vector11()
{
	yzq::vector<std::string> v1;
	v1.push_back("hello1");
	v1.push_back("hello2");
	v1.push_back("hello3");
	v1.push_back("hello4");
	v1.push_back("hello5");
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_vector12()
{
	yzq::vector<yzq::vector<int>> v1;
	v1.push_back(yzq::vector<int>(1));
	v1.push_back(yzq::vector<int>(2));
	v1.push_back(yzq::vector<int>(3));
	v1.push_back(yzq::vector<int>(4));
	v1.push_back(yzq::vector<int>(5));
}

// 辅助函数：打印vector信息
template <typename T>
void printVectorInfo(const yzq::vector<T> &vec, const std::string &name)
{
	std::cout << "Vector " << name << ": size = " << vec.size()
			  << ", capacity = " << vec.capacity() << std::endl;
	std::cout << "Content: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;
}

// 测试默认构造函数
void testDefaultConstructor()
{
	std::cout << "=== Testing Default Constructor ===" << std::endl;
	yzq::vector<int> v;
	printVectorInfo(v, "v");

	assert(v.size() == 0);
	assert(v.capacity() == 0);
	std::cout << "Default constructor test passed!" << std::endl
			  << std::endl;
}

// 测试带初始值的构造函数
void testInitialValueConstructor()
{
	std::cout << "=== Testing Initial Value Constructor ===" << std::endl;
	yzq::vector<int> v(5, 100);
	printVectorInfo(v, "v");

	assert(v.size() == 5);
	assert(v.capacity() >= 5);
	for (size_t i = 0; i < v.size(); ++i)
	{
		assert(v[i] == 100);
	}
	std::cout << "Initial value constructor test passed!" << std::endl
			  << std::endl;
}

// 测试迭代器构造函数
void testIteratorConstructor()
{
	std::cout << "=== Testing Iterator Constructor ===" << std::endl;
	yzq::vector<int> v1(3, 200);
	yzq::vector<int> v2(v1.begin(), v1.end());
	printVectorInfo(v2, "v2");

	assert(v2.size() == 3);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		assert(v2[i] == 200);
	}
	std::cout << "Iterator constructor test passed!" << std::endl
			  << std::endl;
}

// 测试拷贝构造函数
void testCopyConstructor()
{
	std::cout << "=== Testing Copy Constructor ===" << std::endl;
	yzq::vector<int> v1(4, 300);
	yzq::vector<int> v2(v1);
	printVectorInfo(v2, "v2");

	assert(v2.size() == 4);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		assert(v2[i] == 300);
	}
	std::cout << "Copy constructor test passed!" << std::endl
			  << std::endl;
}

// 测试赋值运算符
void testAssignmentOperator()
{
	std::cout << "=== Testing Assignment Operator ===" << std::endl;
	yzq::vector<int> v1(5, 400);
	yzq::vector<int> v2;
	v2 = v1;
	printVectorInfo(v2, "v2");

	assert(v2.size() == 5);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		assert(v2[i] == 400);
	}
	std::cout << "Assignment operator test passed!" << std::endl
			  << std::endl;
}

// 测试push_back和pop_back
void testPushPopBack()
{
	std::cout << "=== Testing Push_back and Pop_back ===" << std::endl;
	yzq::vector<int> v;

	// 测试push_back
	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
		std::cout << "After push_back(" << i << "): ";
		printVectorInfo(v, "v");
	}

	// 测试pop_back
	for (int i = 0; i < 3; ++i)
	{
		v.pop_back();
		std::cout << "After pop_back(): ";
		printVectorInfo(v, "v");
	}

	assert(v.size() == 2);
	assert(v[0] == 0 && v[1] == 1);
	std::cout << "Push_back and Pop_back tests passed!" << std::endl
			  << std::endl;
}

// 测试reserve和resize
void testReserveResize()
{
	std::cout << "=== Testing Reserve and Resize ===" << std::endl;
	yzq::vector<int> v;

	// 测试reserve
	v.reserve(10);
	std::cout << "After reserve(10): ";
	printVectorInfo(v, "v");
	assert(v.capacity() >= 10);

	// 测试resize扩大
	v.resize(7, 500);
	std::cout << "After resize(7, 500): ";
	printVectorInfo(v, "v");
	assert(v.size() == 7);
	for (size_t i = 0; i < v.size(); ++i)
	{
		assert(v[i] == 500);
	}

	// 测试resize缩小
	v.resize(3);
	std::cout << "After resize(3): ";
	printVectorInfo(v, "v");
	assert(v.size() == 3);

	std::cout << "Reserve and Resize tests passed!" << std::endl
			  << std::endl;
}

// 测试insert和erase
void testInsertErase()
{
	std::cout << "=== Testing Insert and Erase ===" << std::endl;
	yzq::vector<int> v(3, 600);

	// 测试insert
	v.insert(v.begin(), 500);
	std::cout << "After insert at begin: ";
	printVectorInfo(v, "v");

	v.insert(v.end(), 700);
	std::cout << "After insert at end: ";
	printVectorInfo(v, "v");

	assert(v.size() == 5);
	assert(v[0] == 500 && v[1] == 600 && v[2] == 600 && v[3] == 600 && v[4] == 700);

	// 测试erase
	v.erase(v.begin() + 1);
	std::cout << "After erase at position 1: ";
	printVectorInfo(v, "v");

	assert(v.size() == 4);
	assert(v[0] == 500 && v[1] == 600 && v[2] == 600 && v[3] == 700);

	std::cout << "Insert and Erase tests passed!" << std::endl
			  << std::endl;
}

// 测试const迭代器
void testConstIterator()
{
	std::cout << "=== Testing Const Iterator ===" << std::endl;
	const yzq::vector<int> v(3, 700);

	std::cout << "Const vector content: ";
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
		// *it = 800; // 应无法编译，因为是const迭代器
	}
	std::cout << std::endl
			  << std::endl;

	std::cout << "Const iterator test passed!" << std::endl
			  << std::endl;
}

// 测试clear
void testClear()
{
	std::cout << "=== Testing Clear ===" << std::endl;
	yzq::vector<int> v(5, 800);
	std::cout << "Before clear: ";
	printVectorInfo(v, "v");

	v.clear();
	std::cout << "After clear: ";
	printVectorInfo(v, "v");

	assert(v.size() == 0);
	std::cout << "Clear test passed!" << std::endl
			  << std::endl;
}

// 测试swap
void testSwap()
{
	std::cout << "=== Testing Swap ===" << std::endl;
	yzq::vector<int> v1(3, 900);
	yzq::vector<int> v2(5, 1000);

	std::cout << "Before swap:" << std::endl;
	printVectorInfo(v1, "v1");
	printVectorInfo(v2, "v2");

	v1.swap(v2);

	std::cout << "After swap:" << std::endl;
	printVectorInfo(v1, "v1");
	printVectorInfo(v2, "v2");

	assert(v1.size() == 5 && v2.size() == 3);
	std::cout << "Swap test passed!" << std::endl
			  << std::endl;
}

void test_vector13()
{
	testDefaultConstructor();
	testInitialValueConstructor();
	testIteratorConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testPushPopBack();
	testReserveResize();
	testInsertErase();
	testConstIterator();
	testClear();
	testSwap();

	std::cout << "All tests passed successfully!" << std::endl;
}

void test_vector14()
{
	yzq::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	yzq::vector<int> v2(v);
	for (auto e : v2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	test_vector14();
	return 0;
}
