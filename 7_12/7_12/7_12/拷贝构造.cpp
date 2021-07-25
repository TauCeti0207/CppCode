#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
	 cout << "无参构造函数!" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数!" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
	int m_Age;
};

void test01()
{
	Person p1(20);
	Person p2(p1);
}

void dowork(Person p)
{

}

void test02()
{
	Person p;
	dowork(p);
}


Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}


void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}