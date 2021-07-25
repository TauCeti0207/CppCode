#include<iostream>
using namespace std;
class Box
{
public:
	Box();
	Box(int h, int w, int len) :height(h), width(w),length(len)
		//定义一个有参构造函数,用参数初始化列表对数据成员初始化
	{

	}
	int volume();

private:
	int height;
	int width;
	int length;
};
Box::Box()			//类外定义无参构造函数Box
{
	height = 10;
	width = 10;
	length = 10;
}
int Box::volume()
{
	return (height * width * length);
}
int main()
{
	Box box1;		//建立对象,不指定实参
	cout << "the volume of box1 is" << box1.volume() << endl;
	Box box2(15, 30, 25);
	cout << "the volume of box2 is" << box2.volume() << endl;
	system("pause");
	return 0;
}