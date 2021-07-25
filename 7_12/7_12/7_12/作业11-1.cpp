#include<iostream>
using namespace std;
#include<string>
class Student
{
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
private:
	int num;
	string  name;
	char sex;
};
class Student1 : public Student//公有继承
{
public:
	void get_value_1()//输入派生类数据
	{
		
		cin >> age >> addr;
	}
	void display_1()
	{
		cout << "age: " << age << endl;//引用派生类的私有成员
		cout << "address: " << addr << endl;//引用派生类的私有成员
	}
private:
	int age;
	string  addr;
};
int main()
{
	Student1 stud;
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display_1();
	system("pause");
	return 0;
}