#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
using namespace sf;
//��������
//1.�SFML����


//2.������
//3.���ɷ���
//3.1����˹�����ʾ,����
int blocks[7][4] =
{
	1, 3, 5, 7,//1����
	2, 4, 5, 7,//Z1����
	3, 5, 4, 6,//Z2����
	3, 5, 4, 7,//T����
	2, 3, 5, 7,//L����
	3, 5, 7, 6,//J����
	2, 3, 4, 5,//������

};

const int ROW_COUNT = 20;
const int COL_COUNT = 10;

//��Ϸ�����ʾ
//table[i][j]==0��ʾ��i�е�j��Ϊ�հ�,�����з���
//table[i][j]==1��ʾ�з���,�����ǵ�1�ַ���,ʹ�õ�1����ɫ
int table[ROW_COUNT][COL_COUNT] = { 0 };

int blockIndex;//��ʾ��ǰ��������
struct Point {
	int x;
	int y;
} curBlock[4], bakBlock[4];//BakBlock����


const float SPEED_NORMAL = 0.5;
const float SPEED_QUICK = 0.05;
//�½��ٶ�
float delay = SPEED_NORMAL;
//��Ϸ�����ʾ


void moveLeftRight(int offset)
{
	for (int i = 0; i < 4; i++)
	{

		bakBlock[i] = curBlock[i];//������
		curBlock[i].x += offset;
	}

	bool check();//����check����

	if (!check())
	{
		for (int i = 0; i < 4; i++)
		{
			curBlock[i] = bakBlock[i];
		}
	}
}

void doRotate()
{
	if (blockIndex == 7)
	{
		return;
	}//�����η��鲻��ת
	//�ȱ���
	for (int i = 0; i < 4; i++)
	{
		bakBlock[i] = curBlock[i];
	}

	Point p = curBlock[1];//��ת����

	for (int i = 0; i < 4; i++)
	{
		Point tmp = curBlock[i];
		curBlock[i].x = p.x - tmp.y + p.y;
		curBlock[i].y = tmp.x - p.x + p.y;
	}
	bool check();
	if (!check())
	{
		for (int i = 0; i < 4; i++)
		{
			curBlock[i] = bakBlock[i];
		}
	}
}
void keyEvent(RenderWindow* window)

{

	bool rotate = false;//��ʾ�Ƿ���ת
	int dx = 0;//����ƫ����
	Event e;//�¼�����

	//pollEevent ���¼�������ȡ��һ���¼�
	//���û���¼���,�ͷ���false

	while (window->pollEvent(e))
	{
		if (e.type == Event::Closed)
		{
			window->close();
		}

		if (e.type == Event::KeyPressed)
		{
			switch (e.key.code)
			{
			case Keyboard::Up:
				rotate = true;	
				break;
			case Keyboard::Left:
				dx = -1;
				break;
			case Keyboard::Right:
				dx = 1;
				break;
			default:
				break;
			}
		}


		//�������¼���
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			delay = SPEED_QUICK;
		}

		if (dx != 0)
		{
			moveLeftRight(dx);

		}

		if (rotate)
		{
			doRotate(); 
		}
	}


}

void newBolck()
{
	//��ȡһ�����ֵ(1-7)
	blockIndex = 1 + rand() % 7;
	int n = blockIndex - 1;//������Ŵ�0��ʼ
	for (int i = 0; i < 4; i++)
	{
		curBlock[i].x = blocks[n][i] % 2;//x����
		curBlock[i].y = blocks[n][i] / 2;
	}

}

void drawBlocks(Sprite* spriteBlock, RenderWindow* window)
{
	//1.�Ѿ����䵽�ײ���
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			if (table[i][j] != 0)
			{
				//��С����
				//��ʹ�þ���sprite��ʾ��������ͼƬ
				spriteBlock->setTextureRect(IntRect(table[i][j] * 15, 0, 15, 15));
				spriteBlock->setPosition(j * 15, i * 15);
				//����ƫ����
				spriteBlock->move(28, 31);
				window->draw(*spriteBlock);
			}


		}
	}

	//2.���ڽ����ֵ�(��ǰ����)
	for (int i = 0; i < 4; i++)
	{
		spriteBlock->setTextureRect(IntRect(blockIndex * 15, 0, 15, 15));
		spriteBlock->setPosition(curBlock[i].x * 15, curBlock[i].y * 15);
		spriteBlock->move(28, 31);
		window->draw(*spriteBlock);
	}
}

//��鵱ǰ����Ϸ���
bool check()
{
	for (int i = 0; i < 4; i++)
	{
		if (curBlock[i].x < 0
			|| curBlock[i].x >= COL_COUNT
			|| curBlock[i].y >= ROW_COUNT
			|| table[curBlock[i].y][curBlock[i].x])//�Ѿ��з���
			{
			return false;
			}
			
	}

	return true;
}
void drop()
{
	for (int i = 0; i < 4; i++)
	{
		bakBlock[i] = curBlock[i];
		curBlock[i].y += 1;
	}

	if (check() == false)
	{
		//����ײ�����й̻�,���ǻ�ԭ!!!
		for (int i = 0; i < 4; i++)
		{
			table[bakBlock[i].y][bakBlock[i].x] = blockIndex;
		}

		//�����µķ���
		newBolck();


	}
}


void clearLine()
{

	//����д��������
	int k = ROW_COUNT - 1;

	for (int i = ROW_COUNT; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < COL_COUNT; j++)
		{
			if (table[i][j])
			{
				count++;
			}
			table[k][j] = table[i][j];
		}

		if (count < COL_COUNT)
		{
			k--;
		}
	
	}
}

int main()
{
	srand(time(0));//����һ���������
	//github
	//������Ϸ����
	RenderWindow window(
		VideoMode(320, 416),
		"Rock-2021"	);
	//�����Ϸ����
	Texture t1;//��ͼƬ���ص��ڴ�
	t1.loadFromFile("imagine/bg.jpg");
	Sprite spriteBg(t1);//����ͼƬ��������
	
	Texture t2;
	t2.loadFromFile("imagine/bg3.png");
	Sprite spriteBlock(t2);
	//��Ⱦ�������
	//window.draw(spriteBg);
	 
	//window.display();//ˢ�²���ʾ����

	//�����·���
	newBolck();

	//��ʱ��clock
	Clock clock;

	float timer = 0;//��ʱ��


	//������Ϸѭ��
	while (window.isOpen())
	{
		//��ȡ��clock������������֮��,�����ڵ�ʱ��
		float time =clock.getElapsedTime().asSeconds();
		clock.restart();//ÿ��ȡһ��ʱ��,������ʱ��
		timer += time;
		//�ȴ��û����°���,������
		keyEvent(&window);
		if (timer > delay)
		{
			//��ʼ����
			drop();//�½�һλλ��

			timer = 0;//����֮��ʱ������
		}

		//clearLine();//���һ�� !!!������,����̫��,�����Ű�
		delay = SPEED_NORMAL;
		//������Ϸ
		window.draw(spriteBg);
		//���Ʒ���
		drawBlocks(&spriteBlock, &window);

		window.display();//ˢ�²���ʾ����
	}
	system("pause");
	return 0;
}