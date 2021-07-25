#include<iostream>
using namespace std;
#include<string.h>

class Person
{
public:
	//姓名设置可读可写
	void setname(string name)
	{
		m_name = name;

	}
	string getname()
	{
		return m_name;
	}
	
	int getage()
	{
		return m_age;
	}
	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "你不是人!!" << endl;
			return;
		}
		m_age = age;
	}
	void setlover(string lover)
	{
		m_lover = lover;
	}
	string getlover()
	{
		return m_lover;
	}
private:

	string m_name;
	int m_age; //只读  年龄
	string m_lover; //只写  情人
};
int main()
{
	Person p;
	p.setname("Tom");
	cout << "name:" << p.getname() << endl;

	p.setage(50);
	cout << "age:" << p.getage() << endl;

	p.setlover("azure");
	cout << "lover:" << p.getlover()<< endl;
	system("pause");
	return 0;
}