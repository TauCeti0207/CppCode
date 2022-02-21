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
#define DEFAULT_SZ 3 //默认存储的人数信息
typedef struct Peoinfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
} Peoinfo;

//通讯录的结构体
typedef struct Contact
{
	// Peoinfo data[MAX];
	Peoinfo *data;
	int sz;		  //通讯录中有效信息的个数
	int capacity; //记录当前通讯录的最大容量
} Contact;

//初始化通讯录
void InitContact(Contact *pc);
//销毁通讯录
void DestroyContact(Contact *pc);
//添加联系人信息
void AddContact(Contact *pc);
//展示通讯录
void ShowContact(const Contact *pc);
//删除通讯录
void DeleteContact(Contact *pc);
//查找联系人
void SearchContact(Contact *pc);
//修改联系人
void ModifyContact(Contact *pc);
//排序联系人
void SortContact(Contact *pc);
//清屏
void ClsContact();

//保存信息到文件
void SaveContact(Contact *pc);
//容量检测
void check_capacity(Contact *pc);
//加载文件中的信息
void LoadContact(Contact *pc);