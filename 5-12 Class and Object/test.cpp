#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Student
//{
////public:
//	void SetStudentInfo(const char* name, const char* gender, int age)//默认认为是 inline
//	{
//		strcpy(_name, name); // 如果这里成员变量也是用的name，那就会产生冲突。
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//private:
//	char _name[20];
//	char _gender[3];
//	int _age; // 成员变量在这里只是声明，还没有给他开辟空间。
//};
//
//int main()
//{
//	Student s1;
//	s1.SetStudentInfo("张三", "男", 18);
//	s1.PrintStudentInfo();
//
//	return 0;
//}

//// C -- 数据和方法是分离的
//// 太自由了，不好。
//struct Stack
//{
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//void StackInit(struct Stack* ps)
//{
//	ps->_a = NULL;
//	ps->_top = 0;
//	ps->_capacity = 0;
//}
//
//void StackPush(struct Stack* ps, int x)
//{}
//
//int StackTop(struct Stack* ps)
//{}
//
//int main()
//{
//	struct Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//
//	printf("%d\n", StackTop(&st)); // 规范操作
//	printf("%d\n", st._a[st._top]); // 不规范的操作，某些书上甚至就这么写。
//	// top是栈顶元素还是栈顶元素下一个调用者不一定清楚，因此就有可能产生误用
//
//	return 0;
//}


 //封装：更严格管理设计
 //数据和方法封装到一起，放到类里面。

//class Stack
//{
//private:
//	void Checkcapaicty()
//	{}
//public:
//	void Init()
//	{}
//
//	void Push(int x)
//	{}
//
//	int Top()
//	{}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//
//	cout << st.Top() << endl;
//	//cout << st._a[st._top] << endl; // 无法访问私有成员变量
//	//C++强制规定了用户使用规范。
//	return 0;
//}

//typedef int STDataType;
//
//class Stack
//{
//public:
//	void Init(int initSize = 4);
//	void Push(STDataType x);
//
//	// ...
//private:
//	STDataType* _a;
//	int _size;
//	int _capacity;
//};
//void Stack::Init(int initSize)
//{
//	_a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//	_size = 0;
//	_capacity = initSize;
//}
//
//void Stack::Push(STDataType x)
//{
//	// ...
//	_a[_size] = x;
//	_size++;
//}
//int main()
//{
//	//struct Stack st;
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	Stack st2;
//	st2.Init(); // 和st调用的是同一个函数
//	cout << sizeof(st) << endl;// 12 
//	cout << sizeof(st2) << endl;// 12 32位环境下 结构体总大小为最大对齐数的整数倍
//	return 0;
//}



class A1 
{
public:
	void f1() {}
private:
	int _a; // 占了0~3
	char _x; // char最小对齐是1，占用4
	// VS默认对齐是8，结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
	// 现在最大对齐数是4，因此总的大小就是8
};

//空类
class A2
{};

//类中仅有成员函数
class A3
{
public:
	void f2() {}
};
void test2()
{
	A1 a1;
	A2 a2;
	A3 a3;
	cout << sizeof(A1) << endl;// 8 注意内存对齐：VS默认对齐为8
	cout << sizeof(a1) << endl;// 8
	cout << sizeof(A2) << endl;// 1
	cout << sizeof(A3) << endl;// 1
	cout << sizeof(a2) << endl;// 1
	cout << sizeof(a3) << endl;// 1

	cout << &a1 << endl;
	cout << &a2 << endl;
	cout << &a3 << endl;
}
int main()
{
	test2();
	return 0;
}