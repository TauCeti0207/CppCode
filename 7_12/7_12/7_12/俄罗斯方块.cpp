#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<time.h>
using namespace sf;
//开发步骤
//1.搭建SFML环境


//2.处理按键
//3.生成方块
//3.1俄罗斯方块表示,数组
int blocks[7][4] =
{
	1, 3, 5, 7,//1字形
	2, 4, 5, 7,//Z1字形
	3, 5, 4, 6,//Z2字形
	3, 5, 4, 7,//T字形
	2, 3, 5, 7,//L字形
	3, 5, 7, 6,//J字形
	2, 3, 4, 5,//田字形

};

const int ROW_COUNT = 20;
const int COL_COUNT = 10;

//游戏区域表示
//table[i][j]==0表示第i行第j列为空白,否则有方块
//table[i][j]==1表示有方块,而且是第1种方块,使用第1种颜色
int table[ROW_COUNT][COL_COUNT] = { 0 };

int blockIndex;//表示当前方块种类
struct Point {
	int x;
	int y;
} curBlock[4], bakBlock[4];//BakBlock备份


const float SPEED_NORMAL = 0.5;
const float SPEED_QUICK = 0.05;
//下降速度
float delay = SPEED_NORMAL;
//游戏方块表示


void moveLeftRight(int offset)
{
	for (int i = 0; i < 4; i++)
	{

		bakBlock[i] = curBlock[i];//做备份
		curBlock[i].x += offset;
	}

	bool check();//生命check函数

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
	}//田字形方块不用转
	//先备份
	for (int i = 0; i < 4; i++)
	{
		bakBlock[i] = curBlock[i];
	}

	Point p = curBlock[1];//旋转中心

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

	bool rotate = false;//表示是否旋转
	int dx = 0;//定义偏移量
	Event e;//事件变量

	//pollEevent 从事件队列种取出一个事件
	//如果没有事件了,就返回false

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


		//处理向下加速
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
	//获取一个随机值(1-7)
	blockIndex = 1 + rand() % 7;
	int n = blockIndex - 1;//数组序号从0开始
	for (int i = 0; i < 4; i++)
	{
		curBlock[i].x = blocks[n][i] % 2;//x坐标
		curBlock[i].y = blocks[n][i] / 2;
	}

}

void drawBlocks(Sprite* spriteBlock, RenderWindow* window)
{
	//1.已经降落到底部的
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			if (table[i][j] != 0)
			{
				//画小方块
				//先使用精灵sprite表示完整方块图片
				spriteBlock->setTextureRect(IntRect(table[i][j] * 15, 0, 15, 15));
				spriteBlock->setPosition(j * 15, i * 15);
				//设置偏移量
				spriteBlock->move(28, 31);
				window->draw(*spriteBlock);
			}


		}
	}

	//2.正在降落种的(当前方块)
	for (int i = 0; i < 4; i++)
	{
		spriteBlock->setTextureRect(IntRect(blockIndex * 15, 0, 15, 15));
		spriteBlock->setPosition(curBlock[i].x * 15, curBlock[i].y * 15);
		spriteBlock->move(28, 31);
		window->draw(*spriteBlock);
	}
}

//检查当前方块合法性
bool check()
{
	for (int i = 0; i < 4; i++)
	{
		if (curBlock[i].x < 0
			|| curBlock[i].x >= COL_COUNT
			|| curBlock[i].y >= ROW_COUNT
			|| table[curBlock[i].y][curBlock[i].x])//已经有方块
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
		//到达底部后进行固化,不是还原!!!
		for (int i = 0; i < 4; i++)
		{
			table[bakBlock[i].y][bakBlock[i].x] = blockIndex;
		}

		//产生新的方块
		newBolck();


	}
}


void clearLine()
{

	//重新写方块行数
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
	srand(time(0));//生成一个随机种子
	//github
	//创建游戏窗口
	RenderWindow window(
		VideoMode(320, 416),
		"Rock-2021"	);
	//添加游戏背景
	Texture t1;//把图片加载到内存
	t1.loadFromFile("imagine/bg.jpg");
	Sprite spriteBg(t1);//根据图片创建精灵
	
	Texture t2;
	t2.loadFromFile("imagine/bg3.png");
	Sprite spriteBlock(t2);
	//渲染这个精灵
	//window.draw(spriteBg);
	 
	//window.display();//刷新并显示窗口

	//生成新方块
	newBolck();

	//计时器clock
	Clock clock;

	float timer = 0;//总时间


	//进入游戏循环
	while (window.isOpen())
	{
		//获取从clock被重启或启动之后,到现在的时间
		float time =clock.getElapsedTime().asSeconds();
		clock.restart();//每获取一次时间,重启计时器
		timer += time;
		//等待用户按下按键,并处理
		keyEvent(&window);
		if (timer > delay)
		{
			//开始降落
			drop();//下降一位位置

			timer = 0;//降落之后时间清零
		}

		//clearLine();//清除一行 !!!有问题,但不太会,先留着吧
		delay = SPEED_NORMAL;
		//绘制游戏
		window.draw(spriteBg);
		//绘制方块
		drawBlocks(&spriteBlock, &window);

		window.display();//刷新并显示窗口
	}
	system("pause");
	return 0;
}