#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <memory.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <Windows.h>

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
#define DEFAULT_SZ 3 //Ĭ�ϴ洢��������Ϣ
typedef struct Peoinfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
} Peoinfo;

//ͨѶ¼�Ľṹ��
typedef struct Contact
{
	// Peoinfo data[MAX];
	Peoinfo *data;
	int sz;		  //ͨѶ¼����Ч��Ϣ�ĸ���
	int capacity; //��¼��ǰͨѶ¼���������
} Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact *pc);
//����ͨѶ¼
void DestroyContact(Contact *pc);
//�����ϵ����Ϣ
void AddContact(Contact *pc);
//չʾͨѶ¼
void ShowContact(const Contact *pc);
//ɾ��ͨѶ¼
void DeleteContact(Contact *pc);
//������ϵ��
void SearchContact(Contact *pc);
//�޸���ϵ��
void ModifyContact(Contact *pc);
//������ϵ��
void SortContact(Contact *pc);
//����
void ClsContact();

//������Ϣ���ļ�
void SaveContact(Contact *pc);
//�������
void check_capacity(Contact *pc);
//�����ļ��е���Ϣ
void LoadContact(Contact *pc);