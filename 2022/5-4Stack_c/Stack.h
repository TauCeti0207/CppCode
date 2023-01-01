#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//����,��������
};
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
//���ʾ�����ֻ����ջ����������
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);