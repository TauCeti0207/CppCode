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
	//cout << st._a[st._top] << endl; // �޷�����˽�г�Ա����
	//C++ǿ�ƹ涨���û�ʹ�ù淶��
	return 0;
}