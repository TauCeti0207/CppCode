#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

namespace yzq
{
	//class String
	//{
	//public:
	//	String(const char* str = "")
	//		:_str(new char[strlen(str) + 1])
	//	{
	//		strcpy(_str, str);
	//	}

	//	String(const String& s)
	//		:_str(s._str)
	//	{}

	//	String& operator=(const String& s)
	//	{
	//		if (this != &s)
	//		{
	//			_str = s._str;
	//		}
	//		return *this;
	//	}

	//	~String()
	//	{
	//		if (_str)
	//		{
	//			delete[] _str;
	//		}
	//		_str = nullptr;
	//	}
	//private:
	//	char* _str;
	//};

	class string
	{
	public:
		string(const char* str = "")
			: _str(new char[strlen(str) + 1])
		{
			strcpy(_str, str); //拷贝时 \0也会一起拷贝
		}

		//// s2(s1)
		//string(const string& s)
		//	: _str(new char[strlen(s._str)] + 1)
		//{
		//	strcpy(_str, s._str);
		//}
		//// s1 = s3
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		delete[] _str;//释放s1的空间
		//		_str = nullptr;
		//		_str = new char[strlen(s._str) + 1];//开辟和s3一样大的空间
		//		strcpy(_str, s._str);//拷贝过去
		//	}
		//	return *this;
		//}

		 //拷贝构造的现代写法      
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);   //调用构造函数，则tmp就是我们需要的
			swap(_str, tmp._str);   //将_str与tmp的_str指向的空间进行交换，tmp._str就会指向_str的空间
			//出了这个作用域，tmp就会调用析构函数释放空间，但是tmp里面的_str值可能不确定，所以在初始化列表中将_str置空。
		}

		//赋值的现代写法
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);    //调用构造函数
				swap(_str, tmp._str);   //tmp是局部对象，出了这个作用域就会调用析构函数，就会将tmp里面的指针指向的空间释放掉。
			}
			return *this;
		}


		~string()
		{
			cout << "~string()" << endl;
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}

class B
{
public:
	B(int b = 0)
		:_b(b)
	{}

	B(const B& bb)
		:_b(bb._b)
	{
		cout << "B(const B& bb)" << endl;
	}

	B& operator=(const B& bb) //拷贝构造
	{
		cout << "B& operator=(const B& bb)" << endl;
		if (this != &bb)
		{
			_b = bb._b;
		}
		return *this;
	}
private:
	int _b;
};

class C
{
public:
	C(int c1 = 0, int c2 = 0)
		:_c1(c1)
		, _c2(c2)
	{}
private:
	int _c1;
	int _c2;
};

class A
{
private:
	// 默认生成构造函数对基本类型成员变量是不处理的。
	// (有些比较新的编译器也有可能会初始化成0，但是大多数编译器都不会处理，我们要当成不初始化)

	// 基本类型不处理，是C++语法设计的一个小缺陷
	// 所以C++11，给出了补充语法：声明缺省值，来补足这里的缺陷
	int _a1 = 1; // 这里不是初始化，这里是给缺省值
	int _a2 = 2;

	// 默认生成构造函数对自动类型的成员回去调用它的默认构造函数初始化
	//B _b = B(1);
	B _b = 1;

	//C _c = C(1, 1);
	C _c = { 1, 1 };
};

class D
{
public:

	D()
	{}

private:
	int _d = 0;    // 成员声明
	B	_b;
};


class Date
{
public:
	~Date()
	{
		// ... 这个类没有什么资源需要清理，
		// 所以其实它不写析构函数，编译器自动生成就可以
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;

	B _b = 10;
};
void Test()
{
	yzq::string s1("hello");
	yzq::string s2(s1);
}
int main(int argc, char const* argv[])
{
	//Date d1;
	//Date d2(d1);
	//Date d3 = d1;
	//Date d4;
	//d4 = d1;

	//yzq::string s1("hello");
	//yzq::string s2(s1);
	//yzq::string s3("hello hello");
	//s1 = s3;
	Test();
	return 0;
}
