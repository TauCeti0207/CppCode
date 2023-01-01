#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact *pc)
{
	assert(pc);
	pc->sz = 0;
	// data是一片连续的空间
	// memset(pc->data, 0, sizeof(pc->data));
	Peoinfo *tmp = (Peoinfo *)malloc(DEFAULT_SZ * sizeof(Peoinfo));
	if (NULL != tmp)
	{
		pc->data = tmp;
	}
	else
	{
		printf("InitContact()::%s\n", strerror(errno));
		return;
	}
	pc->capacity = DEFAULT_SZ;

	LoadContact(pc);
}

void DestroyContact(Contact *pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void check_capacity(Contact *pc)
{
	assert(pc);
	if (pc->sz == pc->capacity)
	{
		//扩容
		Peoinfo *tmp = (Peoinfo *)realloc(pc->data, (pc->capacity + 2) * sizeof(Peoinfo));
		if (NULL != tmp)
		{
			pc->data = tmp;
			pc->capacity += 2;
			printf("扩容成功\n");
		}
		else
		{
			printf("Check_Capacity()::%s\n", strerror(errno));
		}
	}
}
void AddContact(Contact *pc)
{
	assert(pc);

	//检测是否扩容
	check_capacity(pc);

	//输入联系人
	printf("请输入名字:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加联系人成功\n");
	Sleep(1000);
	system("cls");
}

void ShowContact(const Contact *pc)
{
	assert(pc);
	int i = 0;
	//负号表示左对齐
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			   pc->data[i].name, pc->data[i].age,
			   pc->data[i].sex, pc->data[i].tele,
			   pc->data[i].addr);
	}
	printf("显示成功\n");
}

int FindByName(const Contact *pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1; //找不到
}

void DeleteContact(Contact *pc)
{
	char name[NAME_MAX] = {0};
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法删除\n");
		return;
	}
	printf("请输入要删除人的名字:>\n");
	scanf("%s", name);
	//查找指定联系人
	int pos = FindByName(pc, name); //下标
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		//删除
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		// sz-1 如果sz是999 访问到最大的就是998,998+1没有越界
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除指定联系人成功\n");
	}
}

void SearchContact(Contact *pc)
{
	char name[NAME_MAX] = {0};
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法查找\n");
		return;
	}
	printf("请输入要查找人的名字:>\n");
	scanf("%s", name);
	//查找指定联系人
	int pos = FindByName(pc, name); //下标
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		//负号表示左对齐
		printf("%-20s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			   pc->data[pos].name, pc->data[pos].age,
			   pc->data[pos].sex, pc->data[pos].tele,
			   pc->data[pos].addr);
	}
}

void ModifyContact(Contact *pc)
{
	char name[NAME_MAX] = {0};
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法修改\n");
		return;
	}
	printf("请输入要修改人的名字:>\n");
	scanf("%s", name);
	//查找指定联系人
	int pos = FindByName(pc, name); //下标
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		//修改联系人信息
		printf("请输入名字:>\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>\n");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>\n");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址:>\n");
		scanf("%s", pc->data[pos].addr);

		printf("修改联系人成功\n");
	}
}
int cmp_con_by_age(const void *e1, const void *e2)
{
	return (((Peoinfo *)e1)->age - ((Peoinfo *)e2)->age);
}

void SortContact(Contact *pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法排序\n");
		return;
	}
	qsort(pc->data, pc->sz, sizeof(Peoinfo), cmp_con_by_age);
	printf("排序完成:\n");
	ShowContact(pc);
}

void ClsContact()
{
	Sleep(1000);
	system("cls");
}

void SaveContact(Contact *pc)
{
	//打开文件
	FILE *pf = fopen("contact.txt", "wb");
	if (pf == nullptr)
	{
		printf("SaveContact::%s\n", strerror(errno));
		exit(-1);
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		//一次写1组,data指向一块连续空间,每次写入的地址要增加
		fwrite(pc->data + i, sizeof(Peoinfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = nullptr;
}

void LoadContact(Contact *pc)
{
	//从文件加载数据
	FILE *pf = fopen("contact.txt", "rb");
	if (pf == nullptr)
	{
		printf("InitContact:: open for reading :: %s\n", strerror(errno));
	}
	//读取文件
	Peoinfo buf = {0};
	while (fread(&buf, sizeof(Peoinfo), 1, pf))
	{
		//放进去前要检测容量是否足够
		check_capacity(pc);
		pc->data[pc->sz] = buf;
		pc->sz++;
	}
}