#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "�вι��캯��" << endl;
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "�������캯��!" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;

	}
public:
	int age;
};
void test01()
{
	Person p;
}
void test02()
{
	Person p1;
	Person p2(10);
	Person p3(p2);
	cout << p2.age << endl;
	cout << p3.age << endl;
}
void test03()
{
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);
	cout << p2.age << endl;
	cout << p3.age << endl; 
}
void test04()
{

}
int main()
{
	//test01();
	test02();

	test03();
	//Person p;
	system("pause");
	return 0;
}