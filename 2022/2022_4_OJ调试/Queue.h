#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 前置声明
struct BinaryTreeNode;

//队列里面存放的是指向二叉树的指针
typedef struct BinaryTreeNode* QDataType;

// 定义队列节点
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QueueNode;

// 定义队列
typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

// pq表示pointer queue
void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);
//取队头数据
QDataType QueueFront(Queue *pq);
//取队尾数据
QDataType QueueBack(Queue *pq);
bool QueueEmpty(Queue *pq);
size_t QueueSize(Queue *pq);