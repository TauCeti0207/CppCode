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



//class A1
//{
//public:
//	void f1() {}
//private:
//	int _a; // 占了0~3
//	char _x; // char最小对齐是1，占用4
//	// VS默认对齐是8，结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
//	// 现在最大对齐数是4，因此总的大小就是8
//};
//
////空类
//class A2
//{};
//
////类中仅有成员函数
//class A3
//{
//public:
//	void f2() {}
//};
//void test2()
//{
//	A1 a1;
//	A2 a2;
//	A3 a3;
//	cout << sizeof(A1) << endl;// 8 注意内存对齐：VS默认对齐为8
//	cout << sizeof(a1) << endl;// 8
//	cout << sizeof(A2) << endl;// 1
//	cout << sizeof(A3) << endl;// 1
//	cout << sizeof(a2) << endl;// 1
//	cout << sizeof(a3) << endl;// 1
//
//	// 不同对象地址不同
//	cout << &a1 << endl;// 010FFC20
//	cout << &a2 << endl;// 010FFC17
//	cout << &a3 << endl;// 010FFC0B
//}
//
//struct A {
//
//	long a1; // 0~7
//
//	short a2;//8 9
//
//	int a3;//12 ~15
//
//	int* a4;// 16~23
//
//};
//int main()
//{
//	//test2();
//	cout << sizeof(A) << endl; // 24
//	return 0;
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cour << _year << "-" << _month
//	}
//};

//class Date
//{
//public:
//	//void Print(Date* const this)
//	//{
//	//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	//}
//
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//	/*void Init(Date* const this, int year, int month, int day)
//	{
//	this->_year = year;
//	this->_month = month;
//	this->_day = day;
//	}*/
//
//	void Init(int year, int month, int day)
//	{
//		// this = nullptr; this指针本身不能修改，因为他是const修饰的
//		// this指向对象可以被修改
//		cout << this << endl;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};

//int main()
//{
//	Date d1;
//	Date d2;
//	Date d3;
//
//	d1.Init(2022, 5, 15);
//	d2.Init(2022, 5, 20);
//	d3.Init(2022, 5, 25);
//	d1.Print(); // 实际上是 d1.Print(&d1);
//
//	// 通过对象的指针调用函数
//	Date* p1 = &d1;
//	p1->Print(); // 实际上是 p1->Print(p1);
//}
// 
// 
// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void Show()
//	{
//		cout << this << endl;
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
////可以编译通过
//int main()
//{
//	A* p = nullptr;
//	//p->PrintA(); // 空指针解引用崩溃，Print要访问对象里的成员变量，而p指向的是空，找不到相关成员变量。
//	p->Show();     // 正常运行，没有涉及到成员变量，就和普通的调用函数一样，去call函数的地址。
//	// 这里也只是把p的值传参传给了this指针。
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		// 一般不需要把this写出来
//	}
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main()
//{
//	Date d1;
//	//d1.Init(2022, 05, 01);
//	d1.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	//自动调用
//	Date()
//	{
//		_year = 2022;
//		_month = 1;
//		_day = 1;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{
//		_year = 2022;
//		_month = 1;
//		_day = 1;
//	}
//
//	// 2.带参构造函数
//	//全缺省参数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(2022, 05, 16);
//	d2.Print();
//	return 0;
//}

// 1.构造函数 --> 完成对象初始化 顶替Init()
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year = 2022, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//};
//
//int main()
//{
//	Date d1(2022, 2, 21);
//	d1.Print();// 2022-2-21
//
//	Date d2(2022);
//	d2.Print();// 2022-1-1
//
//	Date d3;
//	d3.Print();// 2022-1-1
//	return 0;
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// 没有定义构造函数，对象也可以创建成功，因为此处调用的是编译器生成的默认构造函数
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << _a << endl;
//		_a = 0;
//		cout << _a << endl;
//	}
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
////如果改成这样，手动创建了构造函数，但又不是默认构造函数，编译器本该去调用自定义类型的默认构造函数，但找不到，因此编译通不过
//
//class Date
//{
//public:
//	// 我们不写，编译器会自动生成一个构造函数，我们写了编译器就不会生成了。
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//
//};
//int main()
//{
//	Date d1; // 对内置类型不做处理，因此都是随机值。 只对自定义类型_aa 的成员变量 _a处理了。
//	// 调用自定义类型的构造函数完成初始化
//	d1.Print();
//
//	return 0;
//}

#include <assert.h>

//class Stack
//{
//public:
//	//Stack()
//	//{
//	//	_a = nullptr;
//	//	_top = _capacity = 0;
//	//}
//
//	Stack(int capacity = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		assert(_a);
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	//Stack(int capacity)
//	//{
//	//	_a = (int*)malloc(sizeof(int) * capacity);
//	//	assert(_a);
//
//	//	_top = 0;
//	//	_capacity = capacity;
//	//}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class MyQueue {
//public:
//	// 全是自定义类型，默认生成构造函数就够用了，不需要自己再写构造函数。
//	void push(int x) {
//	}
//
//	int pop() {
//	}
//
//private:
//	// 假设还有个内置类型，但又不想自己去写构造函数，可以利用C++11的特性。
//	// 这里只是给了一个缺省值，不是初始化，是给编译器自己生成的默认构造函数用的，
//	int _size = 0; // 这里只是声明，是还没开辟空间的。
//	Stack _st1;
//	Stack _st2;
//};
//
//int main()
//{
//	MyQueue q;
//	Stack st;
//
//	return 0;
//}

//class Stack
//{
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//
//public:
//	Stack(int capacity = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//		cout << "~Stack()" << endl;
//	}
//	void Push(int x)
//	{
//		//...
//	}
//};
//
//
//
//int main(int argc, char const* argv[])
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	return 0;
//}
////运行到这里，也就是对象的生命周期结束之后才自动调用析构函数的
////调试时只能看到当前作用域的变量，因此is指针观察

//class Stack
//{
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//
//public:
//	Stack(int capacity = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//		cout << "Stack(int capacity = 10)" << endl;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//		cout << "~Stack():" << this << endl;
//	}
//	void Push(int x)
//	{
//		//...
//	}
//};
//
//
//
//
//class MyQueue {
//public:
//	// 编译器生成的默认构造函数可以用了
//	// 编译器生成的默认析构函数可以用了
//	void push(int x) {
//	}
//
//	int pop() {
//	}
//
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
//int main()
//{
//	Stack st1(1);
//	Stack st2(2);
//
//	MyQueue q;
//
//	return 0;
//}

class Stack
{
public:
	Stack(int capacity = 10)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		assert(_a);

		_top = 0;
		_capacity = capacity;
	}

	// st2(st1)
	// 只能深拷贝实现
	/*Stack(const Stack& st)
	{
	_a = st._a;
	_top = st._top;
	_capacity = st._capacity;
	}*/

	~Stack()
	{
		cout << "~Stack():" << this << endl;

		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// Date d2(d1) d2赋值给this指针，d1赋值给d
	// Date(Date d) // 非法，必须传引用，传值会引发无穷递归
	// 调用拷贝构造函数，要先传参，传参又是一个拷贝构造，子子孙孙无穷尽也
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

void Func(Date& d)
{
	//...
}

//int main()
//{
//	Date d1(2022, 5, 20);
//	Func(d1);
//	return 0;
//}

//int Count()
//{
//	static int n = 0; // 静态变量只会初始化一次。
//	n++;
//	// ...
//	return n;
//}
// 静态的局部变量，虽然作用域只在Count里面，但生命周期是全局的。
// n的地址初始化之后地址就不变了。

//int main()
//{
//	cout << Count() << endl;
//	cout << Count() << endl;
//	cout << Count() << endl;
//	// 结果为1 2 3 静态变量只会初始化一次。
//	return 0;
//}


//int main()
//{
//	Date d1(2022, 5, 20);
//	Date d2(d1);// 拷贝出一个一样的对象
//	return 0;
//}
int main(int argc, char const* argv[])
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array) //必须用引用或者指针, 而 auto e : array 只是把array中的值拷贝给e
		e *= 2;
	//自动遍历，依次取出array中的元素，赋值给e，直到结束
	for (auto e : array)
		cout << e << " ";
	cout << endl;//4 8 12 16 20
	return 0;
}