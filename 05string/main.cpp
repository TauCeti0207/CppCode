/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-21 20:28:55
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
#include "string.h"

void test1()
{
	std::string str = "abcdefg";
	for (auto c : str)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	std::cout << str << std::endl;

	// std::cin >> str;
	std::cout << str << std::endl;

	std::string str2 = str;
	str2 += str;
	std::cout << str2 << std::endl;

	std::cout << str + str2 << std::endl;
}

void test2()
{
	std::string str = "hello world";
	std::string::iterator it = str.begin();
	// while(it < str.end()) // 这里可以这么用但不建议，不通用，这只适合底层是连续物理空间的容器
	while (it != str.end())
	{
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	// 可读可写，修改迭代器指向的元素
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		*it += 1;
	}
	std::cout << str << std::endl;
}

void test3()
{
	std::string str = "hello";
	std::string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		std::cout << *rit << " "; // o l l e h
		++rit;
	}
	std::cout << std::endl;
}

void StringTest9(const std::string &rs)
{
	std::string::const_reverse_iterator rit = rs.rbegin();
	// 这种太长的类型，其实就可以用auto自动推导类型
	auto rit2 = rs.rbegin();
	while (rit != rs.rend())
	{
		// (*rit) += 1; // err 不能修改常量迭代器指向的元素
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
}

void test4()
{
	std::string s1 = "hello world";
	StringTest9(s1);
}

void printVec(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(const std::list<int> &lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test5()
{
	std::vector<int> vec = {1, 2, 3};
	std::list<int> lst = {4, 5, 6};
	printVec(vec);
	printList(lst);
}

void test6()
{
	std::string s1("123456");
	for (auto e : s1)
	{
		std::cout << e << " "; // 1 2 3 4 5 6
	}
	std::cout << std::endl;
}

void test7()
{
	std::string s1("123456");
	for (auto &e : s1)
	{
		e += 1;
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test8()
{
	std::cout << std::string::npos << std::endl; // 输出 18446744073709551615（64位系统）
	std::cout << (size_t)-1 << std::endl;		 // 同样输出 18446744073709551615
	std::cout << SIZE_MAX << std::endl;			 // 18446744073709551615
}

void test9()
{
	std::string s;
	s = {'h', 'e', 'l', 'l', 'o'}; // s 变为 "hello"
	std::cout << s << std::endl;
}

void test10()
{
	std::string s1;
	std::string s2 = "hello world";
	std::cout << s1.max_size() << std::endl; // 9223372036854775799
	std::cout << s2.max_size() << std::endl; // 9223372036854775799
	//  64 位有符号整数的最大值（即 2⁶³ - 1）
	std::cout << s1.size() << std::endl;	 // 0
	std::cout << s2.size() << std::endl;	 // 11
	std::cout << s1.capacity() << std::endl; // 22
	std::cout << s2.capacity() << std::endl; // 22

	s2.clear();
	std::cout << s2.size() << std::endl; // 0
	std::cout << s2 << std::endl;
	std::cout << s2.capacity() << std::endl; // 22
}

void test11()
{
	// 验证多久扩容一次
	std::string s;
	size_t sz = s.capacity();
	std::cout << "初始容量为：" << sz << std::endl;
	std::cout << "插入数据: \n";
	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test12()
{
	// 创建空字符串并记录初始容量
	std::string s;
	size_t currentCapacity = s.capacity();

	std::cout << "=== 字符串扩容测试 ===\n";
	std::cout << "初始状态: "
			  << "size=" << s.size()
			  << ", capacity=" << currentCapacity << "\n\n";

	std::cout << "插入数据时的扩容点:\n";
	std::cout << std::setw(6) << "字符数" << " | "
			  << std::setw(8) << "旧容量" << " | "
			  << std::setw(8) << "新容量" << " | "
			  << "扩容倍数\n";
	std::cout << "---------------------------------\n";

	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');

		// 当容量发生变化时记录并输出
		if (currentCapacity != s.capacity())
		{
			size_t oldCapacity = currentCapacity;
			currentCapacity = s.capacity();

			// 计算扩容倍数（保留两位小数）
			// 通过 static_cast<double>() 将其中一个操作数转换为 double，强制编译器执行浮点数除法
			double growthFactor = static_cast<double>(currentCapacity) / oldCapacity;

			std::cout << std::setw(6) << i + 1 << " | "
					  << std::setw(6) << oldCapacity << " | "
					  << std::setw(6) << currentCapacity << " | "
					  << std::fixed << std::setprecision(2) << growthFactor << "x\n";
		}
	}

	std::cout << "\n最终状态: "
			  << "size=" << std::setw(4) << s.size()
			  << ", capacity=" << std::setw(4) << s.capacity() << "\n";
}

void test13()
{
	std::string s("hello world");
	std::cout << "size=" << s.size() << ", capacity=" << s.capacity() << "\n";
	s.reserve(100);
	std::cout << "size=" << s.size() << ", capacity=" << s.capacity() << "\n";
	s.reserve(10); // size、capacity都不改变
	std::cout << "size=" << s.size() << ", capacity=" << s.capacity() << "\n";
	s.resize(100); // 会改变size，但不改变capacity
	std::cout << "size=" << s.size() << ", capacity=" << s.capacity() << "\n";
	s.resize(5); // 会改变size，但不改变capacity
	std::cout << "size=" << s.size() << ", capacity=" << s.capacity() << "\n";
}

void test14()
{
	std::string s(1000, 'a');
	std::cout << "初始: size=" << s.size()
			  << ", capacity=" << s.capacity() << "\n";

	s.resize(10);
	std::cout << "resize(10) 后: size=" << s.size()
			  << ", capacity=" << s.capacity() << "\n";

	s.shrink_to_fit();
	std::cout << "shrink_to_fit() 后: size=" << s.size()
			  << ", capacity=" << s.capacity() << "\n";
}

void test15()
{
	std::cout << "=== 测试 std::string::operator+= ===\n\n";

	// (1) 追加另一个 string 对象
	std::cout << "(1) 追加另一个 string 对象:\n";
	std::string s1 = "Hello";
	std::string s2 = " World";
	std::cout << "Before: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
	s1 += s2;
	std::cout << "After:  s1 = \"" << s1 << "\"\n\n";

	// (2) 追加 C 风格字符串
	std::cout << "(2) 追加 C 风格字符串:\n";
	std::string s3 = "Hello";
	const char *cstr = " World";
	std::cout << "Before: s3 = \"" << s3 << "\", cstr = \"" << cstr << "\"\n";
	s3 += cstr;
	std::cout << "After:  s3 = \"" << s3 << "\"\n\n";

	// (3) 追加单个字符
	std::cout << "(3) 追加单个字符:\n";
	std::string s4 = "ABC";
	char ch = 'D';
	std::cout << "Before: s4 = \"" << s4 << "\", ch = '" << ch << "'\n";
	s4 += ch;
	std::cout << "After:  s4 = \"" << s4 << "\"\n\n";

	// (4) 追加初始化列表 (C++11)
	std::cout << "(4) 追加初始化列表:\n";
	std::string s5 = "Hello";
	std::cout << "Before: s5 = \"" << s5 << "\"\n";
	s5 += {' ', 'W', 'o', 'r', 'l', 'd'};
	std::cout << "After:  s5 = \"" << s5 << "\"\n\n";
}

void test16()
{
	std::string s1 = "hellohellohellohellohello";
	std::string s2 = "worldworldworldworldworld";

	// 打印初始状态
	std::cout << "操作前:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n\n";

	// 成员函数 swap
	s1.swap(s2);
	std::cout << "s1.swap(s2) 后:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n\n";

	// 全局函数 swap
	std::swap(s1, s2);
	std::cout << "std::swap(s1, s2) 后:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n";
}

void test17()
{
	// 出现了短字符串优化
	std::string s1 = "hello";
	std::string s2 = "world";

	// 打印初始状态
	std::cout << "操作前:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n\n";

	// 成员函数 swap
	s1.swap(s2);
	std::cout << "s1.swap(s2) 后:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n\n";

	// 全局函数 swap
	std::swap(s1, s2);
	std::cout << "std::swap(s1, s2) 后:\n";
	std::cout << "s1 对象地址: " << &s1 << "\n";
	std::cout << "s2 对象地址: " << &s2 << "\n";
	std::cout << "s1 字符串地址: " << static_cast<const void *>(s1.c_str()) << "\n";
	std::cout << "s2 字符串地址: " << static_cast<const void *>(s2.c_str()) << "\n";
}

void test18()
{
	std::string str = "Hello, world!";

	// 查找子串
	size_t pos1 = str.find("world"); // 返回7

	// 从位置5开始查找字符'o'
	size_t pos2 = str.find('o', 5); // 返回8

	// 查找C风格字符串的前3个字符
	size_t pos3 = str.find("llo", 0, 3); // 返回2

	// 未找到的情况
	size_t pos4 = str.find("xyz"); // 返回std::string::npos

	// 判断是否找到
	if (pos4 == std::string::npos)
	{
		std::cout << "未找到匹配内容" << std::endl;
	}
}

// 函数用于提取文件扩展名（带点）
std::string getFileExtension(const std::string &filename)
{
	if (filename.empty())
	{
		return ""; // 空文件名返回空字符串
	}

	// 从后向前查找最后一个点的位置
	size_t lastDotPos = filename.rfind('.');

	// 如果没找到点，或者点是文件名的第一个字符（隐藏文件），返回空
	if (lastDotPos == std::string::npos || lastDotPos == 0)
	{
		return "";
	}

	// 如果点后面没有字符（例如"filename."），返回空
	if (lastDotPos + 1 >= filename.size())
	{
		return "";
	}

	// 检查点后面是否有非目录分隔符的字符
	// 处理类似"path/to/file/."的情况
	for (size_t i = lastDotPos + 1; i < filename.size(); ++i)
	{
		if (filename[i] != '/' && filename[i] != '\\')
		{
			return filename.substr(lastDotPos); // 返回带点的扩展名
		}
	}

	return ""; // 如果点后面只有目录分隔符，返回空
}

// 函数用于提取文件扩展名（不带点）
std::string getFileExtensionWithoutDot(const std::string &filename)
{
	std::string ext = getFileExtension(filename);
	if (!ext.empty())
	{
		return ext.substr(1); // 去掉扩展名开头的点
	}
	return "";
}

// 测试函数
void test19()
{
	// 测试用例
	std::string testFiles[] = {
		"string.cpp",
		"main.py",
		"document.txt",
		"image.jpg",
		"archive.tar.gz",
		".hidden_file",
		"no_extension",
		"file.with.multiple.dots.txt",
		"path/to/file.jpg",
		"path\\to\\file.jpg",
		"filename.",
		"",
		"中文文件名.txt"};

	for (const auto &file : testFiles)
	{
		std::cout << "文件名: " << file << std::endl;

		std::string ext = getFileExtension(file);
		std::string extWithoutDot = getFileExtensionWithoutDot(file);

		if (!ext.empty())
		{
			std::cout << "带点扩展名: " << ext << std::endl;
			std::cout << "不带点扩展名: " << extWithoutDot << std::endl;
		}
		else
		{
			std::cout << "没有扩展名" << std::endl;
		}
		std::cout << "------------------------" << std::endl;
	}
}

/**
 * @struct URLComponents
 * @brief 存储解析后的URL各部分组件
 */
struct URLComponents
{
	std::string protocol; // 协议部分（如"http"、"https"）
	std::string domain;	  // 域名部分（如"www.example.com"）
	std::string port;	  // 端口号（如"8080"）
	std::string path;	  // 路径部分（如"/path/to/resource"）
	std::string query;	  // 查询参数（如"param1=value1&param2=value2"）
	std::string fragment; // 片段标识符（如"section1"）

	/**
	 * @brief 打印URL各组件信息
	 */
	void print() const
	{
		std::cout << "协议: " << protocol << std::endl;
		std::cout << "域名: " << domain << std::endl;
		if (!port.empty())
			std::cout << "端口: " << port << std::endl;
		std::cout << "路径: " << path << std::endl;
		if (!query.empty())
			std::cout << "查询参数: " << query << std::endl;
		if (!fragment.empty())
			std::cout << "片段: " << fragment << std::endl;
		std::cout << "------------------------" << std::endl;
	}
};

/**
 * @brief 解析URL字符串为各组件
 * @param url 待解析的URL字符串
 * @return URLComponents 解析后的URL组件
 * @throws std::invalid_argument 如果URL格式无效
 */
URLComponents parseURL(const std::string &url)
{
	URLComponents components;

	// 检查URL是否为空
	if (url.empty())
	{
		throw std::invalid_argument("URL不能为空");
	}

	// 解析协议部分（格式为"protocol://"）
	size_t protocolEnd = url.find("://");
	if (protocolEnd != std::string::npos)
	{
		components.protocol = url.substr(0, protocolEnd);
		if (components.protocol.empty())
		{
			throw std::invalid_argument("非法协议");
		}
	}
	else
	{
		throw std::invalid_argument("URL缺少协议部分");
	}

	// 解析域名和端口部分
	size_t domainStart = protocolEnd + 3;
	if (domainStart >= url.size())
	{
		throw std::invalid_argument("非法域名");
	}

	// 查找路径开始位置（域名后的第一个斜杠）
	size_t pathStart = url.find('/', domainStart);
	if (pathStart == std::string::npos)
	{
		pathStart = url.size(); // 没有路径部分
	}

	// 查找域名后的端口号（格式为":port"）
	size_t portStart = url.find(':', domainStart);
	if (portStart != std::string::npos && portStart < pathStart)
	{
		components.domain = url.substr(domainStart, portStart - domainStart);
		components.port = url.substr(portStart + 1, pathStart - portStart - 1);

		// 验证端口号是否为合法数字
		for (char c : components.port)
		{
			if (!std::isdigit(c))
			{
				throw std::invalid_argument("非法端口号");
			}
		}
	}
	else
	{
		components.domain = url.substr(domainStart, pathStart - domainStart);
	}

	// 检查域名是否为空
	if (components.domain.empty())
	{
		throw std::invalid_argument("非法域名");
	}

	// 解析路径、查询参数和片段部分
	if (pathStart < url.size())
	{
		components.path = url.substr(pathStart);

		// 查找查询参数（格式为"?key=value"）
		size_t queryStart = components.path.find('?');
		if (queryStart != std::string::npos)
		{
			// 查找片段标识符（格式为"#fragment"）
			size_t fragmentStart = components.path.find('#', queryStart);
			if (fragmentStart != std::string::npos)
			{
				components.query = components.path.substr(queryStart + 1, fragmentStart - queryStart - 1);
				components.fragment = components.path.substr(fragmentStart + 1);
				components.path = components.path.substr(0, queryStart);
			}
			else
			{
				components.query = components.path.substr(queryStart + 1);
				components.path = components.path.substr(0, queryStart);
			}
		}
		else
		{
			// 检查是否有片段标识符（无查询参数的情况）
			size_t fragmentStart = components.path.find('#');
			if (fragmentStart != std::string::npos)
			{
				components.fragment = components.path.substr(fragmentStart + 1);
				components.path = components.path.substr(0, fragmentStart);
			}
		}
	}

	return components;
}

/**
 * @brief 测试URL解析功能的主函数
 */
void test20()
{
	// 测试用例集合，覆盖各种URL格式
	std::string testURLs[] = {
		"http://www.cplusplus.com/reference/string/string/find/",
		"https://leetcode.cn/problems/design-skiplist/solution/tiao-biao-probabilistic-alternative-to-b-0cd8/",
		"ftp://example.com/files/data.txt",
		"http://localhost:8080/api/users?page=1&size=20",
		"https://www.example.com/path/#section1",
		"ws://127.0.0.1:8080/socket",
		"https://中文域名.测试/路径?参数=值#片段",
		"http://user:pass@example.com:8080/path?query#fragment"};

	// 遍历测试用例并打印解析结果
	for (const auto &url : testURLs)
	{
		std::cout << "原始URL: " << url << std::endl;
		try
		{
			URLComponents components = parseURL(url);
			components.print();
		}
		catch (const std::exception &e)
		{
			std::cout << "解析错误: " << e.what() << std::endl;
			std::cout << "------------------------" << std::endl;
		}
	}
}

void test21()
{
	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found = str.find_first_of("aeiou");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aeiou", found + 1);
	}

	std::cout << str << '\n';
	// Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.
}

void test22()
{
	yzq::string str("Hello, World!");
	std::cout << str.c_str() << '\n';
	for (int i = 0; i < str.size(); ++i)
	{
		std::cout << str[i] << ' ';
	}
	std::cout << '\n';

	// 迭代器遍历
	for (yzq::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	// 范围 for
	for (auto ch : str)
	{
		std::cout << ch << ' ';
	}
	std::cout << '\n';
}

void test23()
{
	yzq::string str("Hello, World!");
	str.push_back(':');
	std::cout << str << '\n';
	str.append("Hello Hello Hello");
	std::cout << str << '\n';

	str += " World World World";
	std::cout << str << '\n';
}

void test24()
{
	yzq::string str("123");
	str.insert(0, "456");
	std::cout << str.size() << std::endl;
	std::cout << str << std::endl;

	str.erase(0, 3);
	std::cout << str << std::endl;
}

void test25()
{
	yzq::string str("123");
	str.insert(0, "456");
	std::cout << str.size() << std::endl;
	std::cout << str << std::endl;
	str.resize(5);
	std::cout << str << std::endl;
	str.resize(15, 'x');
	std::cout << str << std::endl;

	size_t pos = str.find('x');
	if (pos != yzq::string::npos)
	{
		std::cout << "pos: " << pos << std::endl;
	}
	yzq::string ret = str.substr(pos, 3);
	std::cout << ret << std::endl;
}

void test26()
{
	// 测试用例1：空字符串
	yzq::string s1("");
	assert(s1.substr(0) == "");
	try
	{
		s1.substr(1);  // 应该抛出异常
		assert(false); // 如果没抛出异常，测试失败
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Test 1 exception caught: " << e.what() << std::endl;
	}

	// 测试用例2：常规截取
	yzq::string s2("HelloWorld");
	assert(s2.substr(0, 5) == "Hello");
	assert(s2.substr(5, 5) == "World");
	assert(s2.substr(3, 3) == "loW");

	// 测试用例3：len为npos（截取到末尾）
	assert(s2.substr(5) == "World");
	assert(s2.substr(0) == "HelloWorld");

	// 测试用例4：超长len（自动截断）
	assert(s2.substr(5, 100) == "World");
	assert(s2.substr(0, 100) == "HelloWorld");

	// 测试用例5：起始位置等于字符串长度（空字符串）
	assert(s2.substr(10) == "");

	// 测试用例6：起始位置超出字符串长度（异常）
	try
	{
		s2.substr(11);
		assert(false);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Test 6 exception caught: " << e.what() << std::endl;
	}

	// 测试用例8：截取后原字符串不变
	yzq::string s4("abc");
	yzq::string sub = s4.substr(1, 2);
	assert(sub == "bc");
	assert(s4 == "abc"); // 原字符串未改变

	// 测试用例9：截取空字符串的各种情况
	yzq::string s5("");
	assert(s5.substr(0, 0) == "");
	try
	{
		s5.substr(1, 0);
		assert(false);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Test 9 exception caught: " << e.what() << std::endl;
	}

	// 测试用例10：pos为npos（如果npos+1不溢出）
	if (yzq::string::npos + 1 > 0)
	{ // 检查是否会溢出
		try
		{
			s2.substr(yzq::string::npos);
			assert(false);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "Test 10 exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "All substr tests passed!" << std::endl;
}

void test27()
{
	yzq::string s1("Hello, World!");
	yzq::string s2(s1);
	std::cout << s2 << std::endl;
	yzq::string s3;
	s3 = s1;
	std::cout << s3 << std::endl;
}

void test28()
{
	std::string s1;
	yzq::string s2;
	std::cin >> s1;
	std::cout << s1 << std::endl;
}

void test29()
{
	std::string s1("hello wordl");
	std::string s2(s1);
	printf("写时拷贝前，共享内存\n");
	printf("s1:%p\n", s1.c_str());
	printf("s2:%p\n", s2.c_str());
	s2 += '!';
	printf("写时拷贝后，内存不共享\n");
	printf("s1:%p\n", s1.c_str());
	printf("s2:%p\n", s2.c_str());
}

int main()
{
	test29();
	return 0;
}