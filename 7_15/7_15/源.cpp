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
	//t.x = 0;//私有不可访问
	p = &t;
	Test &a = t;
	t.getx();
}