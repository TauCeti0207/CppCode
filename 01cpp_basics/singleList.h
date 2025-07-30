/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-06 00:01:59
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-06 00:02:09
 */

#include <iostream>

// 定义单链表节点结构
typedef struct ListNode
{
	int val;
	struct ListNode *next;
} ListNode, *PListNode;

void PushBack(PListNode &phead, int x);

void PrintList(PListNode phead);
