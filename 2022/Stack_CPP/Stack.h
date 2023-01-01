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

//#ifdef __cplusplus
//	#define EXTERN_C extern "C" // 识别到c++文件就用 extern "C" 替换 EXTERN_C
//#else
//	#define EXTERN_C // 否则就用空替换 EXTERN_C
//#endif // __cplusplus
//
//
//// 告诉编译器，按C的规则去修饰这些函数
//EXTERN_C void StackInit(Stack * pst);
//EXTERN_C void StackDestroy(Stack* pst);
////性质决定了只能在栈顶出入数据
//EXTERN_C void StackPush(Stack* pst, STDataType x);
//EXTERN_C void StackPop(Stack* pst);
//EXTERN_C STDataType StackTop(Stack* pst);
//EXTERN_C bool StackEmpty(Stack* pst);
//EXTERN_C int StackSize(Stack* pst);


// 利用条件编译就只在c++文件中才会展开extern "C"
#ifdef __cplusplus
extern "C"
{
#endif
	// 告诉编译器，按C的规则去修饰这些函数
	void StackInit(Stack* pst);
	void StackDestroy(Stack* pst);
	//性质决定了只能在栈顶出入数据
	void StackPush(Stack* pst, STDataType x);
	void StackPop(Stack* pst);
	STDataType StackTop(Stack* pst);
	bool StackEmpty(Stack* pst);
	int StackSize(Stack* pst);
#ifdef __cplusplus
}
#endif