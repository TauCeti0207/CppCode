#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量,方便增容
};
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
//性质决定了只能在栈顶出入数据
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);