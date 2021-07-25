#include<iostream>
using namespace std;
#include<string>

class Teacher
{
public:
	Teacher(string, int, char, string, int, string);
	void display();
private:
	string name;
	int age;
	char sex;
	string addres;
	int phone;
	string title;
};
Teacher::Teacher(string nam, int a, char s, string ad, int p,string t)
{
	name = nam;
	age = a;
	sex = s;
	addres = ad;
	phone = p;
	title = t;
}
void Teacher::display()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "address: " << addres << endl;
	cout << "phone: " << phone << endl;
	cout << "title: " << title << endl;
}
class Cadre
{
public:
	Cadre(string, int, char, string, int, string);
	void display();
	void show_1()
	{
		cout << "post:" << post << endl;
	}
protected:
	string name;
	int age;
	char sex;
	string addres;
	int phone;
	string post;
};
Cadre::Cadre(string nam, int a, char s, string ad, int p, string po)
{
	name = nam;
	age = a;
	sex = s;
	addres = ad;
	phone = p;
	post = po;
}
void Cadre::display()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "address: " << addres << endl;
	cout << "phone: " << phone << endl;
	cout << "post: " << post << endl;
}
class Teacher_Cadre :public Teacher, public Cadre
{
public:
	Teacher_Cadre
	(string nam, int a, char s, string ad, int p, string t, string po,float w) :
		Teacher(nam, a, s, ad, p, t), Cadre(nam, a, s, ad, p, po), wage(w) 
	{
	}
	void show();
private:
	float wage;
};
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "post:" <<Cadre::post << endl;
	cout << "wage:" << wage << endl;
}
int main()
{
	Teacher_Cadre tc
	("zhang", 28, 'm', "shanghai", 13725986670, "professional", "headteacher", 12000.99);
	tc.show();
	system("pause");
	return 0;
}