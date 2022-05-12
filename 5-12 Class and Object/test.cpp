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

class Stack
{
private:
	void Checkcapaicty()
	{}
public:
	void Init()
	{}

	void Push(int x)
	{}

	int Top()
	{}

private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);

	cout << st.Top() << endl;
	//cout << st._a[st._top] << endl; // 无法访问私有成员变量
	//C++强制规定了用户使用规范。
	return 0;
}