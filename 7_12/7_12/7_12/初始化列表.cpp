#include<iostream>
using namespace std;
class Box
{
public:
	Box();
	Box(int h, int w, int len) :height(h), width(w),length(len)
		//����һ���вι��캯��,�ò�����ʼ���б�����ݳ�Ա��ʼ��
	{

	}
	int volume();

private:
	int height;
	int width;
	int length;
};
Box::Box()			//���ⶨ���޲ι��캯��Box
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
	Box box1;		//��������,��ָ��ʵ��
	cout << "the volume of box1 is" << box1.volume() << endl;
	Box box2(15, 30, 25);
	cout << "the volume of box2 is" << box2.volume() << endl;
	system("pause");
	return 0;
}