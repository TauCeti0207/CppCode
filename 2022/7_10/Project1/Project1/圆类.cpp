
#include<iostream>
using namespace std;
const double PI = 3.14;
class circle
{
public:
	int m_r;
	double cacluateZC()
	{
		return 2 * PI * m_r;
	}
};
int main()
{
	circle c1;
	c1.m_r = 10;
	cout << c1.cacluateZC() << endl;
	system("pause");
	return 0;
}