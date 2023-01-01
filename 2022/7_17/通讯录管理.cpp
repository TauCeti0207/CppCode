#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
struct Person	//��ϵ�˽ṹ��
{
	string m_Name ; //����
	int m_Sex ; //�Ա�1�� 2Ů
	int m_Age ; //����
	string m_Phone ; //�绰
	string m_Addr ; //סַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�������ϵ������
	struct Person personArray[MAX];

	//��¼ͨѶ¼��ǰ����
	int m_Size;
};
//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�жϵ绰���Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
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
				cout << "������������������"<< endl;
			}
		}

		//����
		cout << "���������䣺" << endl;
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
				cout << "������������������";
			}

		}

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//����
	}
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼������
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //�����ϵ��
			addPerson(&abs);//���õ�ַ����,��������ʵ��
			break;
		case 2:  //��ʾ��ϵ��
			break;
		case 3:  //ɾ����ϵ��
			break;
		case 4:  //������ϵ��
			break;
		case 5:  //�޸���ϵ��
			break;
		case 6:  //�����ϵ��
			break;
		case 0:  //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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