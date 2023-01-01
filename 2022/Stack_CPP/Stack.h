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

//#ifdef __cplusplus
//	#define EXTERN_C extern "C" // ʶ��c++�ļ����� extern "C" �滻 EXTERN_C
//#else
//	#define EXTERN_C // ������ÿ��滻 EXTERN_C
//#endif // __cplusplus
//
//
//// ���߱���������C�Ĺ���ȥ������Щ����
//EXTERN_C void StackInit(Stack * pst);
//EXTERN_C void StackDestroy(Stack* pst);
////���ʾ�����ֻ����ջ����������
//EXTERN_C void StackPush(Stack* pst, STDataType x);
//EXTERN_C void StackPop(Stack* pst);
//EXTERN_C STDataType StackTop(Stack* pst);
//EXTERN_C bool StackEmpty(Stack* pst);
//EXTERN_C int StackSize(Stack* pst);


// �������������ֻ��c++�ļ��вŻ�չ��extern "C"
#ifdef __cplusplus
extern "C"
{
#endif
	// ���߱���������C�Ĺ���ȥ������Щ����
	void StackInit(Stack* pst);
	void StackDestroy(Stack* pst);
	//���ʾ�����ֻ����ջ����������
	void StackPush(Stack* pst, STDataType x);
	void StackPop(Stack* pst);
	STDataType StackTop(Stack* pst);
	bool StackEmpty(Stack* pst);
	int StackSize(Stack* pst);
#ifdef __cplusplus
}
#endif