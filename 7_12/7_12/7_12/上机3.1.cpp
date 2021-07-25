#include<iostream>//预处理命令,代表输入输出流
using namespace std;		
//使用命名空间std,c++标准库中类和函数是在命名空间std中声明的
class vehicle	//声明基类
{
private:		//基类私有成员
	int wh;
	float we;
public:			//基类公用成员
	vehicle(int wheels, float weight)//利用构造函数初始化
	{ 
		wh = wheels; we = weight;
	}
	int get_wheels()	//基类公有成员函数,获取汽车车轮数
	{
		return wh;
	}
	float get_weight()	//基类公有成员函数,获取汽车车重
	{
		return we;
	}
	void show()			//基类公有成员函数,输出汽车
	{ 
		cout << "汽车：" << endl;
	}
	void print()		//基类公有成员函数,输出汽车的车轮数和车重
	{
		cout << "车轮数为：" << wh << "个" << endl;
		cout << "车重为：" << we << "吨" << endl;
	}
};
class car :public vehicle	//以公有继承方式声明派生类car
{
	int wh, pa;				//派生类私有数据成员
	float we;
public:						//派生类公有数据成员
	car(int wheels, float weight, int passengers) :vehicle(wheels, weight)
		//定义派生类构造函数
	{
		pa = passengers;
	}//在函数体中只对派生类新增的数据成员初始化
	int get_passengers() //定义派生类公有成员函数
	{
		return pa;
	}
	void print()		//派生类共有成员函数,输出函数,输出小车:和小车载人数
	{
		cout << "小车：" << endl;
		vehicle::print();
		cout << "载人数为：" << pa << "个" << endl;
	}
};
class truck :public vehicle		//以公有继承方式说明派生类truck
{					
	int wh, pa;			//派生类私有数据成员
	float we, pay;		//派生类私有数据成员
public:					
	truck(int wheels, float weight, int passenger_load, float
		pay_load) :vehicle(wheels, weight)
		//定义派生类构造函数
	{
		pa = passenger_load;
		pay = pay_load;
	}//在函数体中只对派生类新增的数据成员初始化
	int get_passenger_load()		//定义派生类公有成员函数,获取载人数
	{
		return pa;
	}
	float get_pay_load()			//定义派生类公有成员函数,获取载重量
	{
		return pay;
	}void print()			//定义派生类公有成员函数,输出函数
							//输出卡车,卡车载人数,卡车载重
	{
		cout << "卡车：" << endl;
		vehicle::print();
		cout << "载人数为：" << pa << "个" << endl;
		cout << "载重为：" << pay << "吨" << endl;
	}
};
void main()		//主函数
{
	vehicle ve1(8, 5);	//定义vehicle对象vel,并传入数据
	ve1.show();			//执行vehicle对象vel的显示函数.输出子对象数据,汽车
	ve1.print();		//执行vehicle对象vel的输出函数.输出子对象数据,
						//输出输出汽车的车轮数和车重
	car car1(4, 1, 5);	//定义car对象car1,并传入数据
	car1.print();		//执行car对象car1的输出函数.输出子对象数据,
						//输出小车:和小车载人数
	{
	truck tr1(6, 8, 2, 10);	//定义truck对象trl,并传入数据
	tr1.print();		//调用输出函数,输出卡车,卡车载人数,卡车载重
}