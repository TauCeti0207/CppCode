#include<iostream>
using namespace std;


class Cube
{
public:
	void setL(int l)//���ó�
	{
		m_L = l;
	}
	int getL()
	{
		return m_L;
	}

	void setW(int w)//���ó�
	{
		m_W = w;
	}
	int getW()
	{
		return m_W;
	}

	void setH(int h)//���ó�
	{
		m_H = h;
	}
	int getH()
	{
		return m_H;
	}

	int calculateS()
	{
		return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
	}

	int calculateV()
	{
		return m_L * m_W * m_H;
	}

	bool issamebyclass(Cube& c)
	{
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}
private:
	int m_L;
	int m_W;
	int m_H;


};

bool issame(Cube c1, Cube c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	return false;
}
int main()
{
	Cube c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);
	cout << "c1�����Ϊ:" << c1.calculateS() << endl;
	cout << "c1�����Ϊ:" << c1.calculateV() << endl;
	
	Cube c2;
	c2.setH(10);
	c2.setL(10);
	c2.setW(11);

	bool ret = issame(c1, c2);
		if (ret) {
			cout << "ȫ�ֺ����ж�c1 c2���" << endl;
		
		}
		else
		{
			cout << "ȫ�ֺ����ж�c1 c2�����" << endl;
		
}

		ret = c1.issamebyclass(c2);
		if (ret) {
			cout << "��Ա�����ж�c1 c2���" << endl;

		}
		else
		{
			cout << "��Ա�����ж�c1 c2�����" << endl;

		}
	system("pause");
	return 0;

}