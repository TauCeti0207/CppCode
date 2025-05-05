/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-06 00:00:18
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-06 00:04:32
 */
#include "singleList.h"

// 在单链表尾部插入新节点
void PushBack(PListNode &phead, int x)
{
	// 分配新节点的内存，使用 C++ 的 new 操作符，更符合 C++ 风格
	ListNode *newnode = new ListNode;
	if (newnode == nullptr)
	{
		std::cerr << "内存分配失败" << std::endl;
		return;
	}
	// 初始化新节点的值和指针
	newnode->val = x;
	newnode->next = nullptr;

	// 若链表为空，新节点成为头节点
	if (phead == nullptr)
	{
		phead = newnode;
	}
	else
	{
		// 找到链表的尾节点
		ListNode *tail = phead;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		// 将新节点插入到尾节点之后
		tail->next = newnode;
	}
}

// 打印单链表
void PrintList(PListNode phead)
{
	ListNode *cur = phead;
	while (cur != nullptr)
	{
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}
