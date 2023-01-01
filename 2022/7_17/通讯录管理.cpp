#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
struct Person	//联系人结构体
{
	string m_Name ; //姓名
	int m_Sex ; //性别：1男 2女
	int m_Age ; //年龄
	string m_Phone ; //电话
	string m_Addr ; //住址
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录保存的联系人数组
	struct Person personArray[MAX];

	//记录通讯录当前人数
	int m_Size;
};
//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断电话本是否满了
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入"<< endl;
			}
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (1)
		{
			if (age < 0 || age>150)
			{
				cin >> age;
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入";
			}

		}

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中人数
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs);//利用地址传递,可以修饰实参
			break;
		case 2:  //显示联系人
			break;
		case 3:  //删除联系人
			break;
		case 4:  //查找联系人
			break;
		case 5:  //修改联系人
			break;
		case 6:  //清空联系人
			break;
		case 0:  //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}