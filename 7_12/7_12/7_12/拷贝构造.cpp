#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
	 cout << "�޲ι��캯��!" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "�вι��캯��!" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "�������캯��!" << endl;
	}
	//�����������ͷ��ڴ�֮ǰ����
	~Person() {
		cout << "��������!" << endl;
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