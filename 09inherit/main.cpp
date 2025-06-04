/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-04 12:57:53
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

class Person
{
public:
	void Print()
	{
		std::cout << "name:" << _name << std::endl;
		std::cout << "age:" << _age << std::endl;
	}
	// protected/private成员对于基类 -- 一样的，类外面不能访问，类里面可以访问
	// protected/private成员对于派生类 -- private成员不能用 protected成员类里面可以用

	// protected:
private:
	std::string _name = "peter"; // 姓名
	int _age = 18;				 // 年龄
								 // ...
};

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
public:
	void func()
	{
		Print();
		//_age = 0; // 不可见
	}

protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};

void test1()
{
	Student s;
	std::cout << sizeof(s) << std::endl;

	Teacher t;
	// s._age = 0;
	// s.Print();
	// t.Print();
}

int main(int argc, char const *argv[])
{
	test1();
	return 0;
}
