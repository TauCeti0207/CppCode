#include<iostream>//Ԥ��������,�������������
using namespace std;		
//ʹ�������ռ�std,c++��׼������ͺ������������ռ�std��������
class vehicle	//��������
{
private:		//����˽�г�Ա
	int wh;
	float we;
public:			//���๫�ó�Ա
	vehicle(int wheels, float weight)//���ù��캯����ʼ��
	{ 
		wh = wheels; we = weight;
	}
	int get_wheels()	//���๫�г�Ա����,��ȡ����������
	{
		return wh;
	}
	float get_weight()	//���๫�г�Ա����,��ȡ��������
	{
		return we;
	}
	void show()			//���๫�г�Ա����,�������
	{ 
		cout << "������" << endl;
	}
	void print()		//���๫�г�Ա����,��������ĳ������ͳ���
	{
		cout << "������Ϊ��" << wh << "��" << endl;
		cout << "����Ϊ��" << we << "��" << endl;
	}
};
class car :public vehicle	//�Թ��м̳з�ʽ����������car
{
	int wh, pa;				//������˽�����ݳ�Ա
	float we;
public:						//�����๫�����ݳ�Ա
	car(int wheels, float weight, int passengers) :vehicle(wheels, weight)
		//���������๹�캯��
	{
		pa = passengers;
	}//�ں�������ֻ�����������������ݳ�Ա��ʼ��
	int get_passengers() //���������๫�г�Ա����
	{
		return pa;
	}
	void print()		//�����๲�г�Ա����,�������,���С��:��С��������
	{
		cout << "С����" << endl;
		vehicle::print();
		cout << "������Ϊ��" << pa << "��" << endl;
	}
};
class truck :public vehicle		//�Թ��м̳з�ʽ˵��������truck
{					
	int wh, pa;			//������˽�����ݳ�Ա
	float we, pay;		//������˽�����ݳ�Ա
public:					
	truck(int wheels, float weight, int passenger_load, float
		pay_load) :vehicle(wheels, weight)
		//���������๹�캯��
	{
		pa = passenger_load;
		pay = pay_load;
	}//�ں�������ֻ�����������������ݳ�Ա��ʼ��
	int get_passenger_load()		//���������๫�г�Ա����,��ȡ������
	{
		return pa;
	}
	float get_pay_load()			//���������๫�г�Ա����,��ȡ������
	{
		return pay;
	}void print()			//���������๫�г�Ա����,�������
							//�������,����������,��������
	{
		cout << "������" << endl;
		vehicle::print();
		cout << "������Ϊ��" << pa << "��" << endl;
		cout << "����Ϊ��" << pay << "��" << endl;
	}
};
void main()		//������
{
	vehicle ve1(8, 5);	//����vehicle����vel,����������
	ve1.show();			//ִ��vehicle����vel����ʾ����.����Ӷ�������,����
	ve1.print();		//ִ��vehicle����vel���������.����Ӷ�������,
						//�����������ĳ������ͳ���
	car car1(4, 1, 5);	//����car����car1,����������
	car1.print();		//ִ��car����car1���������.����Ӷ�������,
						//���С��:��С��������
	{
	truck tr1(6, 8, 2, 10);	//����truck����trl,����������
	tr1.print();		//�����������,�������,����������,��������
}