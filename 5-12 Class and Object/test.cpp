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



class A1 
{
public:
	void f1() {}
private:
	int _a; // ռ��0~3
	char _x; // char��С������1��ռ��4
	// VSĬ�϶�����8���ṹ���ܴ�СΪ����������ÿ����Ա��������һ������������������
	// ��������������4������ܵĴ�С����8
};

//����
class A2
{};

//���н��г�Ա����
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
	cout << sizeof(A1) << endl;// 8 ע���ڴ���룺VSĬ�϶���Ϊ8
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