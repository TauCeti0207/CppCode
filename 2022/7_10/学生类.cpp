
#include<iostream>
using namespace std;
class student
{
public:
	void setname(string name)
	{
		m_name = name;
	}
	void setID(int id)
	{
		m_id = id;

	}
	void showstudent()
	{
		cout<<m_name<<m_id<<endl;
	}
private:
	string m_name;
	int m_id;
};
int main()
{
	student stu;
	stu.setname("Tom");
	stu.setID(245);
	stu.showstudent();
	system("pause");
	return 0;
}