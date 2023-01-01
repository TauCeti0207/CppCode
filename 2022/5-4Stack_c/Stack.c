#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	//初始时给一定空间大小方便增容
	pst->a = (STDataType*)malloc(sizeof(STDataType)*4);
	pst->top = 0;
	pst->capacity = 4;
}
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
//性质决定了只能在栈顶出入数据
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//结束整个程序,return是结束当前函数
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void StackPop(Stack* pst)
{
	assert(pst);
	//非空才能删除
	assert(!StackEmpty(pst));
	pst->top--;//无需取抹除原来空间的元素,只要访问不到就行
}
//取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	//非空才能取值
	assert(!StackEmpty(pst));
	return pst->a[pst->top-1];
}
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;//top恰好就是size大小
}