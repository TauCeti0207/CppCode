#include<iostream>
using namespace std;
class Test
{
private:
	int x;
public:
	int getx()
	{
		return x;
	}
};

void main()
{
	Test t, * p;
	//t.x = 0;//˽�в��ɷ���
	p = &t;
	Test &a = t;
	t.getx();
}