#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact *pc)
{
	assert(pc);
	pc->sz = 0;
	// data��һƬ�����Ŀռ�
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
		//����
		Peoinfo *tmp = (Peoinfo *)realloc(pc->data, (pc->capacity + 2) * sizeof(Peoinfo));
		if (NULL != tmp)
		{
			pc->data = tmp;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
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

	//����Ƿ�����
	check_capacity(pc);

	//������ϵ��
	printf("����������:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>\n");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("������ϵ�˳ɹ�\n");
	Sleep(1000);
	system("cls");
}

void ShowContact(const Contact *pc)
{
	assert(pc);
	int i = 0;
	//���ű�ʾ�����
	printf("%-20s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			   pc->data[i].name, pc->data[i].age,
			   pc->data[i].sex, pc->data[i].tele,
			   pc->data[i].addr);
	}
	printf("��ʾ�ɹ�\n");
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
	return -1; //�Ҳ���
}

void DeleteContact(Contact *pc)
{
	char name[NAME_MAX] = {0};
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>\n");
	scanf("%s", name);
	//����ָ����ϵ��
	int pos = FindByName(pc, name); //�±�
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		//ɾ��
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		// sz-1 ���sz��999 ���ʵ����ľ���998,998+1û��Խ��
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ��ָ����ϵ�˳ɹ�\n");
	}
}

void SearchContact(Contact *pc)
{
	char name[NAME_MAX] = {0};
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�����\n");
		return;
	}
	printf("������Ҫ�����˵�����:>\n");
	scanf("%s", name);
	//����ָ����ϵ��
	int pos = FindByName(pc, name); //�±�
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		//���ű�ʾ�����
		printf("%-20s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ��,�޷��޸�\n");
		return;
	}
	printf("������Ҫ�޸��˵�����:>\n");
	scanf("%s", name);
	//����ָ����ϵ��
	int pos = FindByName(pc, name); //�±�
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		//�޸���ϵ����Ϣ
		printf("����������:>\n");
		scanf("%s", pc->data[pos].name);
		printf("����������:>\n");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:>\n");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>\n");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ:>\n");
		scanf("%s", pc->data[pos].addr);

		printf("�޸���ϵ�˳ɹ�\n");
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
		printf("ͨѶ¼Ϊ��,�޷�����\n");
		return;
	}
	qsort(pc->data, pc->sz, sizeof(Peoinfo), cmp_con_by_age);
	printf("�������:\n");
	ShowContact(pc);
}

void ClsContact()
{
	Sleep(1000);
	system("cls");
}

void SaveContact(Contact *pc)
{
	//���ļ�
	FILE *pf = fopen("contact.txt", "wb");
	if (pf == nullptr)
	{
		printf("SaveContact::%s\n", strerror(errno));
		exit(-1);
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		//һ��д1��,dataָ��һ�������ռ�,ÿ��д��ĵ�ַҪ����
		fwrite(pc->data + i, sizeof(Peoinfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = nullptr;
}

void LoadContact(Contact *pc)
{
	//���ļ���������
	FILE *pf = fopen("contact.txt", "rb");
	if (pf == nullptr)
	{
		printf("InitContact:: open for reading :: %s\n", strerror(errno));
	}
	//��ȡ�ļ�
	Peoinfo buf = {0};
	while (fread(&buf, sizeof(Peoinfo), 1, pf))
	{
		//�Ž�ȥǰҪ��������Ƿ��㹻
		check_capacity(pc);
		pc->data[pc->sz] = buf;
		pc->sz++;
	}
}