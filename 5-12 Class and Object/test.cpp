#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Student
//{
////public:
//	void SetStudentInfo(const char* name, const char* gender, int age)//Ĭ����Ϊ�� inline
//	{
//		strcpy(_name, name); // ��������Ա����Ҳ���õ�name���Ǿͻ������ͻ��
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
//	int _age; // ��Ա����������ֻ����������û�и������ٿռ䡣
//};
//
//int main()
//{
//	Student s1;
//	s1.SetStudentInfo("����", "��", 18);
//	s1.PrintStudentInfo();
//
//	return 0;
//}

//// C -- ���ݺͷ����Ƿ����
//// ̫�����ˣ����á�
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
//	printf("%d\n", StackTop(&st)); // �淶����
//	printf("%d\n", st._a[st._top]); // ���淶�Ĳ�����ĳЩ������������ôд��
//	// top��ջ��Ԫ�ػ���ջ��Ԫ����һ�������߲�һ���������˾��п��ܲ�������
//
//	return 0;
//}


 //��װ�����ϸ�������
 //���ݺͷ�����װ��һ�𣬷ŵ������档

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
//	//cout << st._a[st._top] << endl; // �޷�����˽�г�Ա����
//	//C++ǿ�ƹ涨���û�ʹ�ù淶��
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
//	st2.Init(); // ��st���õ���ͬһ������
//	cout << sizeof(st) << endl;// 12 
//	cout << sizeof(st2) << endl;// 12 32λ������ �ṹ���ܴ�СΪ����������������
//	return 0;
//}



//class A1
//{
//public:
//	void f1() {}
//private:
//	int _a; // ռ��0~3
//	char _x; // char��С������1��ռ��4
//	// VSĬ�϶�����8���ṹ���ܴ�СΪ����������ÿ����Ա��������һ������������������
//	// ��������������4������ܵĴ�С����8
//};
//
////����
//class A2
//{};
//
////���н��г�Ա����
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
//	cout << sizeof(A1) << endl;// 8 ע���ڴ���룺VSĬ�϶���Ϊ8
//	cout << sizeof(a1) << endl;// 8
//	cout << sizeof(A2) << endl;// 1
//	cout << sizeof(A3) << endl;// 1
//	cout << sizeof(a2) << endl;// 1
//	cout << sizeof(a3) << endl;// 1
//
//	// ��ͬ�����ַ��ͬ
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
//		// this = nullptr; thisָ�뱾�����޸ģ���Ϊ����const���ε�
//		// thisָ�������Ա��޸�
//		cout << this << endl;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
//	d1.Print(); // ʵ������ d1.Print(&d1);
//
//	// ͨ�������ָ����ú���
//	Date* p1 = &d1;
//	p1->Print(); // ʵ������ p1->Print(p1);
//}
// 
// 
// 1.��������ܱ���ͨ����
// 2.����������������������
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
////���Ա���ͨ��
//int main()
//{
//	A* p = nullptr;
//	//p->PrintA(); // ��ָ������ñ�����PrintҪ���ʶ�����ĳ�Ա��������pָ����ǿգ��Ҳ�����س�Ա������
//	p->Show();     // �������У�û���漰����Ա�������ͺ���ͨ�ĵ��ú���һ����ȥcall�����ĵ�ַ��
//	// ����Ҳֻ�ǰ�p��ֵ���δ�����thisָ�롣
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		// һ�㲻��Ҫ��thisд����
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
//	//�Զ�����
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
//	// 1.�޲ι��캯��
//	Date()
//	{
//		_year = 2022;
//		_month = 1;
//		_day = 1;
//	}
//
//	// 2.���ι��캯��
//	//ȫȱʡ����
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

// 1.���캯�� --> ��ɶ����ʼ�� ����Init()
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
//	// û�ж��幹�캯��������Ҳ���Դ����ɹ�����Ϊ�˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
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
////����ĳ��������ֶ������˹��캯�������ֲ���Ĭ�Ϲ��캯��������������ȥ�����Զ������͵�Ĭ�Ϲ��캯�������Ҳ�������˱���ͨ����
//
//class Date
//{
//public:
//	// ���ǲ�д�����������Զ�����һ�����캯��������д�˱������Ͳ��������ˡ�
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
//	Date d1; // ���������Ͳ���������˶������ֵ�� ֻ���Զ�������_aa �ĳ�Ա���� _a�����ˡ�
//	// �����Զ������͵Ĺ��캯����ɳ�ʼ��
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
//	// ȫ���Զ������ͣ�Ĭ�����ɹ��캯���͹����ˣ�����Ҫ�Լ���д���캯����
//	void push(int x) {
//	}
//
//	int pop() {
//	}
//
//private:
//	// ���軹�и��������ͣ����ֲ����Լ�ȥд���캯������������C++11�����ԡ�
//	// ����ֻ�Ǹ���һ��ȱʡֵ�����ǳ�ʼ�����Ǹ��������Լ����ɵ�Ĭ�Ϲ��캯���õģ�
//	int _size = 0; // ����ֻ���������ǻ�û���ٿռ�ġ�
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
////���е����Ҳ���Ƕ�����������ڽ���֮����Զ���������������
////����ʱֻ�ܿ�����ǰ������ı��������isָ��۲�

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
//	// ���������ɵ�Ĭ�Ϲ��캯����������
//	// ���������ɵ�Ĭ������������������
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
	// ֻ�����ʵ��
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

	// Date d2(d1) d2��ֵ��thisָ�룬d1��ֵ��d
	// Date(Date d) // �Ƿ������봫���ã���ֵ����������ݹ�
	// ���ÿ������캯����Ҫ�ȴ��Σ���������һ���������죬�����������Ҳ
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
//	static int n = 0; // ��̬����ֻ���ʼ��һ�Ρ�
//	n++;
//	// ...
//	return n;
//}
// ��̬�ľֲ���������Ȼ������ֻ��Count���棬������������ȫ�ֵġ�
// n�ĵ�ַ��ʼ��֮���ַ�Ͳ����ˡ�

//int main()
//{
//	cout << Count() << endl;
//	cout << Count() << endl;
//	cout << Count() << endl;
//	// ���Ϊ1 2 3 ��̬����ֻ���ʼ��һ�Ρ�
//	return 0;
//}


//int main()
//{
//	Date d1(2022, 5, 20);
//	Date d2(d1);// ������һ��һ���Ķ���
//	return 0;
//}
int main(int argc, char const* argv[])
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array) //���������û���ָ��, �� auto e : array ֻ�ǰ�array�е�ֵ������e
		e *= 2;
	//�Զ�����������ȡ��array�е�Ԫ�أ���ֵ��e��ֱ������
	for (auto e : array)
		cout << e << " ";
	cout << endl;//4 8 12 16 20
	return 0;
}