#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// ǰ������
struct BinaryTreeNode;

//���������ŵ���ָ���������ָ��
typedef struct BinaryTreeNode* QDataType;

// ������нڵ�
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QueueNode;

// �������
typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

// pq��ʾpointer queue
void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);
//ȡ��ͷ����
QDataType QueueFront(Queue *pq);
//ȡ��β����
QDataType QueueBack(Queue *pq);
bool QueueEmpty(Queue *pq);
size_t QueueSize(Queue *pq);