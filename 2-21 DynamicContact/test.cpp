#define _CRT_SECURE_NO_WARNINGS 1
// 1. ���1000���˵���Ϣ
// 2. �˵������Ϣ�����֣����䣬�绰��סַ���Ա�
// 3. ��ɾ���
// 4. ����

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
	static Contact con; //ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
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
			//������Ϣ���ļ�
			SaveContact(&con);
			DestroyContact(&con);
			break;
			printf("�˳�ͨѶ¼\n");
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}