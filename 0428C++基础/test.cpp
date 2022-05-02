//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	cout << "hello world" << endl;
	// 对比C语言printf scanf 优势: 自动识别类型
	int a = 10;
	int* p = &a;
	// 自动识别类型原理：函数重载+运算符重载
	cout << a << "," << p << endl;
	char str[10];

	// >>流提取运算符
	cin >> a;
	cin >> str;

	// <<流插入运算符
	cout << a << str << endl;
	return 0;
}


//using std::cout;
//
//
//int main()
//{
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//
//	return 0;
//}

//namespace yzq
//{
//	int scanf = 0;
//	int strlen = 10;
//}




//int a = 0;
//int main(int argc, char const* argv[])
//{
//	//namespace ctl
//	//{
//	//	int scanf = 0;
//	//	int strlen = 10;
//	//}
//	int a = 1;
//	printf("%d\n", a); // 局部优先 1
//	printf("%d\n", ::a); // 默认访问全局 0
//	return 0;
//}

//#include <stdio.h>
//int main(int argc, char const* argv[])
//{
//	//命名冲突
//	//c语言库里面，有2个函数用了scanf 和strlen名称
//	int scanf = 0;
//	int strlen = 10;
//	//变量定义时能通过，但下面调用scanf时就不行，调用scanf是就近读取
//	//C语言解决不了这个冲突问题
//	scanf("%d ", &scanf);
//	return 0;
//}