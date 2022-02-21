#define _CRT_SECURE_NO_WARNINGS 1
// 1. 存放1000个人的信息
// 2. 人的相关信息，名字，年龄，电话，住址，性别
// 3. 增删查改
// 4. 排序

#include "contact.h"
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
	CLS
};
void menu()
{
	printf("***************************************\n");
	printf("********     1.add      2.del     *****\n");
	printf("********     3.search   4.modify  *****\n");
	printf("********     5.sort     6.show    *****\n");
	printf("********     7.cls      0.exit    *****\n");
	printf("***************************************\n");
}

int main()
{
	int input = 0;
	static Contact con; //通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLS:
			ClsContact();
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			DestroyContact(&con);
			break;
			printf("退出通讯录\n");
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}