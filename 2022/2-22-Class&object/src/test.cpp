// #include <iostream>
// using namespace std;

// // int main(int argc, char const *argv[])
// // {

// //     return 0;
// // }

// typedef int STDataType;

// // // c����
// // // ����
// // struct Stack
// // {
// // 	STDataType* a;
// // 	int size;
// // 	int capacity;
// // };
// // // �������� -- ���ݺͷ����Ƿ���ģ��ص��ע���ǹ���-����������
// // void StackPush(struct Stack* ps, STDataType x);

// // C++
// // ��  -�����һ���µ�����
// // ���������ֹ��ɣ�1����Ա���� (����) 2����Ա���� (������Ϊ)
// // C++�е�struct����C�������÷���ͬʱC++�а�struct��������
// // struct Stack
// // {
// // 	void Init(int initSize = 4)
// // 	{
// // 		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
// // 		size = 0;
// // 		capacity = initSize;
// // 	}

// // 	void Push(STDataType x)
// // 	{
// // 		// ...
// // 		a[size] = x;
// // 		size++;
// // 	}

// // 	// ...

// // 	STDataType* a;
// // 	int size;
// // 	int capacity;
// // };

// // int main()
// // {
// // 	//struct Stack st;
// // 	Stack st;
// // 	st.Init();
// // 	st.Push(1);
// // 	st.Push(2);
// // 	st.Push(3);

// // 	return 0;
// // }

// class Stack
// {
// public:
// 	void Init(int initSize = 4);
// 	void Push(STDataType x);

// 	// ...
// private:
// 	STDataType *a;
// 	int size;
// 	int capacity;
// };
// void Stack::Init(int initSize)
// {
// 	a = (STDataType *)malloc(sizeof(STDataType) * initSize);
// 	size = 0;
// 	capacity = initSize;
// }

// void Stack::Push(STDataType x)
// {
// 	// ...
// 	a[size] = x;
// 	size++;
// }

// void test()
// {
// 	// struct Stack st;
// 	Stack st;
// 	st.Init();
// 	st.Push(1);
// 	st.Push(2);
// 	st.Push(3);

// 	Stack st2;
// 	cout << sizeof(st) << endl;	 // 16
// 	cout << sizeof(st2) << endl; // 16 64λ������
// }

// //����
// class A2
// {
// };
// //���н��г�Ա����
// class A3
// {
// public:
// 	void f2()
// 	{
// 	}
// };
// void test2()
// {
// 	A2 a2;
// 	A3 a3;
// 	cout << sizeof(a2) << endl; // 1
// 	cout << sizeof(a3) << endl; // 1
// }

// class Date9
// {
// private:
// 	//���ǳ�Ա����,���������������
// 	int _year;
// 	int _month;
// 	int _day;

// public:
// 	//������������һ�������Ĳ���void Init(Date* this, int year,int month, int day)
// 	// 1.thisָ����������,���ǲ������Ե��ڵ��úͺ��������м�
// 	// 2.�����ǿ����ڳ�Ա������ʹ��thisָ��
// 	// 3.this���β�,һ���Ǵ���ջ�ϵ�,��ͬ�ı�������ͬ,vs��ʹ��ecx�Ĵ����洢,����
// 	void Init(int year, int month, int day)
// 	{
// 		//������ںϷ���
// 		//...
// 		//��дthis,������Ҳ���Զ�����
// 		// _year = year;
// 		// _month = month;
// 		// _day = day;
// 		//�������ᴦ���:
// 		this->_year = year;
// 		this->_month = month;
// 		this->_day = day;
// 		cout << "this:" << this << endl;
// 	}
// };

// void test3()
// {
// 	Date d1;
// 	d1.Init(2021, 2, 21); //�������ᴦ��� d1.Init(&d1, 2021, 2, 21)
// 	cout << "d1:" << &d1 << endl;
// 	Date d2;
// 	d2.Init(2021, 2, 22); //�������ᴦ��� d2.Init(&d2, 2021, 2, 22)
// 	cout << "d2:" << &d2 << endl;
// }

// // int main()
// // {
// // 	test3();
// // 	return 0;
// // }

// // 1.��������ܱ���ͨ����
// // 2.����������������������
// // class A
// // {
// // public:
// // 	void PrintA()
// // 	{
// // 		cout << _a << endl;
// // 	}

// // 	void Show()
// // 	{
// // 		cout << "Show()" << endl;
// // 	}
// // private:
// // 	int _a;
// // };

// // int main()
// // {
// // 	A* p = nullptr;
// // 	// p->PrintA(); // ��ָ��
// // 	p->Show();     // ��������
// // }

// // 1.���캯�� --> �����ʼ�� ����Init()
// //������ʱ���ܻ����ǳ�ʼ������,��ȥʹ����,C++Ϊ�˽�����ȱ��,�����˹��캯��
// //
// class Date2
// {
// private:
// 	int _year;
// 	int _month;
// 	int _day;

// public:
// 	//���캯�� ����ʵ������ʱ���Զ�����,��֤����ĳ�ʼ��
// 	//һ�����,�����ʼ����ΪĬ��ֵ��ʼ���͸���ֵ��ʼ��
// 	//����ȫȱʡ����,��2�ߺ϶�Ϊһ
// 	Date2(int year = 2020, int month = 1, int day = 1)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}
// 	// Date2(int year, int month, int day)
// 	// {
// 	// 	_year = year;
// 	// 	_month = month;
// 	// 	_day = day;
// 	// }
// 	// //Date2����
// 	// Date2()
// 	// {
// 	// 	_year = 2000;
// 	// 	_month = 1;
// 	// 	_day = 1;
// 	// }
// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}
// };

// void test4()
// {
// 	Date2 d1(2022, 2, 21);
// 	d1.Print(); // 2022-2-21

// 	Date2 d2(2022);
// 	d2.Print(); // 2022-1-1

// 	Date2 d3;
// 	d3.Print(); // 2000-1-1
// }
// // int main(int argc, char const *argv[])
// // {
// // 	test4();
// // 	return 0;
// // }

// class A
// {
// public:
// 	A(int a = 0)
// 	{
// 		cout << "A(int a = 0)���캯��" << endl;
// 		_a = a;
// 	}

// 	void Print()
// 	{
// 		cout << _a << endl;
// 	}

// private:
// 	int _a;
// };

// class Date4
// {
// public:
// 	// ���ǲ�д��������������һ�����캯��������д�˱������Ͳ��������ˡ�����˵���캯����Ĭ�ϳ�Ա����

// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 		_aa.Print();
// 	}

// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	A _aa;
// };

// // int main()
// // {
// // 	Date4 d2;
// // 	d2.Print();

// // 	return 0;
// // }
// class Stack2
// {
// private:
// 	int *_a;
// 	int _size;
// 	int _capacity;

// public:
// 	Stack2(int capacity = 4);
// 	~Stack2();
// 	void Push(int x)
// 	{
// 	}
// };

// Stack2::Stack2(int capacity)
// {
// 	_a = (int *)malloc(sizeof(int) * capacity);
// 	_size = 0;
// 	_capacity = capacity;
// }

// Stack2::~Stack2()
// {
// 	cout << "Stack2::~Stack2() ��������" << endl;
// 	free(_a);
// 	_a = nullptr;
// 	_size = _capacity = 0;
// }
// // int main(int argc, char const *argv[])
// // {
// // 	Stack2 st1;
// // 	st1.Push(1);
// // 	st1.Push(2);
// // 	st1.Push(3);

// // 	Stack2 st2;
// // 	st2.Push(1);
// // 	st2.Push(2);
// // 	st2.Push(3);
// // 	return 0;
// // }//���е�����,Ҳ���Ƕ�����������ڽ���֮����Զ���������������
// // //����ʱֻ�ܿ�����ǰ������ı���,��˿��Խ���thisָ��۲�

// class Date5
// {
// public:
// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	Stack2 _st;
// };

// // int main(int argc, char const *argv[])
// // {
// // 	Date5 d;//Stack2::~Stack2() ��������
// // 	return 0;
// // }
// // class Date6
// // {
// // public:
// // 	Date6(int year = 2000, int month = 0, int day = 0)
// // 	{
// // 		_year = year;
// // 		_month = month;
// // 		_day = day;
// // 	}

// // 	//d1.Equal(d2)  d1������this d2������d
// // 	bool Equal(Date6 d) //������һ��thisָ��,���ֻ��Ҫһ���������ɱȽ�
// // 	//���д��ȫ�ֺ���,�Ǿ���Ҫ2��������,���ֲ��ܷ���˽�г�Ա����
// // 	{
// // 		return _year == d._day && _month == d._month && _day == d._day;
// // 	}

// // private:
// // 	int _year;
// // 	int _month;
// // 	int _day;
// // };

// // int main(int argc, char const *argv[])
// // {
// // 	Date6 d1(2022, 2, 22);
// // 	Date6 d2(2022, 2, 21);
// // 	cout << d1.Equal(d2) << endl;//0
// // 	return 0;
// // }

// class Date6
// {
// public:
// 	Date6(int year = 2000, int month = 0, int day = 0)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}

// 	bool operator==(Date6 d) //������һ��thisָ��,���ֻ��Ҫһ���������ɱȽ�
// 	//���д��ȫ�ֺ���,�Ǿ���Ҫ2��������,���ֲ��ܷ���˽�г�Ա����
// 	{
// 		return _year == d._day && _month == d._month && _day == d._day;
// 	}
// 	bool operator<(Date6 d)
// 	{
// 		if (_year < d._year)
// 		{
// 			return true;
// 		}
// 		else if (_year == d._year)
// 		{
// 			if (_month < d._month)
// 			{
// 				return true;
// 			}
// 			else if (_month == d._month)
// 			{
// 				if (_day < d._day)
// 				{
// 					return true;
// 				}
// 			}
// 		}
// 		return false;
// 	}
// 	// d1 - 100
//
// 	// d1 + 100

// 	// d1 - d2
// 	int operator-(Date6 d)
// 	{
// 	}

// private:
// 	int _year;
// 	int _month;
// 	int _day;
// };

// class Array
// {
// private:
// 	int _a[10];

// public:
// 	Array()
// 	{
// 		for (size_t i = 0; i < 10; i++)
// 		{
// 			_a[i] = i * 10;
// 		}
// 	}
// 	int &operator[](size_t pos)
// 	{
// 		return _a[pos]; //���ص��Ǳ���(����)
// 	}
// };

// // int main(int argc, char const *argv[])
// // {
// // 	Date6 d1(2022, 2, 22);
// // 	Date6 d2(2022, 2, 21);
// // 	cout << d1.operator==(d2) << endl; // 0
// // 	//��������� d1.operator==(d2) ת���� d1.operator==(&d1, d2)
// // 	int tmp = d1 == d2;
// // 	//��������� d1==d2 ת���� d1.operator==(&d1, d2)
// // 	cout << tmp << endl;	   // 0
// // 	cout << (d1 < d2) << endl; // 0

// // 	Array ay;
// // 	cout << ay[0] << endl;//ת���� ay.operator[](&ay, 0);
// // 	cout << ay[1] << endl;
// // 	cout << ay[2] << endl;
// // 	cout << ay[3] << endl;

// // 	//�޸� -- ��ֵ���˷��ض���ı���
// // 	ay[0] = 100;
// // 	ay[1] = 200;
// // 	ay[2] = 300;
// // 	ay[3] = 400;

// // 	cout << ay[0] << endl;//ת���� ay.operator[](&ay, 0);
// // 	cout << ay[1] << endl;
// // 	cout << ay[2] << endl;
// // 	cout << ay[3] << endl;
// // 	return 0;
// // }

// // class Date7
// // {
// // public:
// // 	// ���ǲ�д��������������һ�����캯��������д�˱������Ͳ��������ˡ�����˵���캯����Ĭ�ϳ�Ա����
// // 	Date7(int year = 2000, int month = 1, int day = 1)
// // 	{
// // 		_year = year;
// // 		_month = month;
// // 		_day = day;
// // 	}
// // 	void Print()
// // 	{
// // 		cout << _year << "-" << _month << "-" << _day << endl;
// // 	}
// // 	//Date7 d4(d1);  �������캯��
// // 	// Date7(Date7& d)//d4 ����this d1����d
// // 	// {
// // 	// 	_year = d._year;
// // 	// 	_month = d._month;
// // 	// 	_day = d._day;
// // 	// }

// // private:
// // 	int _year;
// // 	int _month;
// // 	int _day;

// // 	A4 _aa;
// // };
// // void f1(Date7 d)
// // {

// // }

// // void f2(Date7& d)
// // {

// // }
// class A4
// {
// public:
// 	A4(int a = 1)
// 	{
// 		cout << "A(int a = 1)���캯��" << endl;
// 		_a = a;
// 	}
// 	A4(const A4 &a)
// 	{
// 		cout << "A4(const A4& a) ��������" << endl;
// 		_a = a._a;
// 	}
// 	~A4()
// 	{
// 		cout << "~A4() ��������" << endl;
// 	}

// private:
// 	int _a;
// };
// class Date7
// {
// public:
// 	// ���ǲ�д��������������һ�����캯��������д�˱������Ͳ��������ˡ�����˵���캯����Ĭ�ϳ�Ա����
// 	Date7(int year = 2000, int month = 1, int day = 1)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}
// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}
// 	// Date7 d4(d1);  �������캯��
// 	//  Date7(Date7& d)//d4 ����this d1����d
// 	//  {
// 	//  	_year = d._year;
// 	//  	_month = d._month;
// 	//  	_day = d._day;
// 	//  }

// 	// d1 = d2 �����þ�������ȥ���ÿ�������
// 	//  Date7 operator=(const Date7& d) // void operator=(Date7* this, const Date7& d)
// 	//  {
// 	//  	_year = d._year;
// 	//  	_month = d._month;
// 	//  	_day = d._day;
// 	//  	return *this;
// 	//  }

// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	A4 _aa;
// };
// // int main(int argc, char const *argv[])
// // {
// // 	//  Date7 d1(2022,2,21);
// // 	// Date7 d2;
// // 	// //Date7 d3();  ��������д����������˺�����������û��ȥ�������

// // 	// //����븴��d1��ֵ
// // 	// Date7 d4(d1);//��������

// // 	// d1.Print();//2022-2-21
// // 	// d2.Print();//2000-1-1
// // 	// d4.Print();//2022-2-21
// // 	// Date7 d1(2022,2,21);
// // 	// f1(d1);
// // 	// f2(d1);

// // 	// Date7 d4(d1);//��������
// // 	// d1.Print();
// // 	// d4.Print();

// // 	Date7 d1(2022, 2, 21);
// // 	Date7 d2;

// // 	//����Ҳ�ǿ�����Ϊ������һ�����ǣ����������Ǵ���һ������ʱ����ͬ������ʼ���Ŀ���
// // 	//����ĸ��ƿ���ʱ�����������Ѿ����ڣ�������ʼ�����ˣ����������һ�����󣬸��ƿ�������һ������
// // 	d2 = d1;
// // 	d1.Print(); // 2000-1-1
// // 	d2.Print(); // 2000-1-1
// // 	system("pause");
// // 	return 0;
// // }

#include "Date.h"
void Test1()
{
	Date d(2021, 0, 29);
	d.Print();
	Date d2(2021, 0, 29);
	d2.Print();
}
void Test2()
{
	Date d1(2022,2,22);
	d1.Print();
	d1 += 3;
	d1.Print();
	Date d2 = d1 + 1;
	d2.Print();//2-26
	Date d3 = d2++;//2-26 d2�Ѿ����2-27��
	d2.Print();
	d3.Print();
	Date d4 = ++d2;
	d4.Print();//2-28
	d4 -= 2;
	d4.Print();
	d4 -= 26;
	d4.Print();
	Date d5(2021,5,27);
	d5 -= -100;
	d5.Print();
}
void Test3()
{
	Date d1(2022,2,22);
	Date d2(2023,1,1);
	cout << d1-d2 << endl;
}
int main(int argc, char const *argv[])
{
	Test3();
	system("pause");
	return 0;
}
