#include<iostream>
using namespace std;
class Teacher
{
public:
	int ag, num;
	string na, adr, ti;
	char s;
	void display();
	Teacher(string, int, int, string, char, string);
};
Teacher::Teacher(string name, int age, int number, string title, char sex, string adress)
{
	name = na;
	age = ag;
	number = num;
	title = ti;
	sex = s;
	adress = adr;
}
void Teacher::display()
{
	cout << "������" << na << endl;
	cout << "���䣺" << ag << endl;
	cout << "�绰��" << num << endl;
	cout << "�Ա�" << s << endl;
	cout << "��ַ��" << adr << endl;
	cout << "ְ�ƣ�" << ti << endl;
};
class Cadre
{
public:
	int ag, num;
	string na, adr, po;
	char s;
	Cadre(string name, int age, string adress, int number, char sex, string post) 
	{ na = name; ag = age; adr = adress; num = number; po = post; s = sex; }
	void display();
};
void Cadre::display()
{
	cout << "������" << na << endl;
	cout << "���䣺" << ag << endl;
	cout << "�绰��" << num << endl;
	cout << "�Ա�" << s << endl;
	cout << "��ַ��" << adr << endl;
	cout << "ְ��" << po << endl;
}
class Teacher_Cadre :public Teacher, public Cadre
{
private:
	float wa;
public:
	Teacher_Cadre(string name, int age, int number, char sex, string adress, string title, string post, float wages) :Teacher(name, age, number, title, sex, adress), Cadre(name, age, adress, number, sex, post), wa(wages)
	{
	}
	void show();
};
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "ְ��" << po << endl;
	cout << "���ʣ�" << wa << "Ԫ" << endl;
}
int main()
{
	Teacher_Cadre TC("Liming", 29, 10086, 'M', "Dalian", "director", "Teacher", 6999);
	TC.show();
}