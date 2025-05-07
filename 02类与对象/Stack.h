/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:19:28
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-07 12:22:54
 */
// stack.h
#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack
{
private:
	T *data;
	int capacity;
	int top;

public:
	Stack(int initialCapacity = 10);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const T &value);
	T pop();
	T peek() const;
	int size() const;
};

#endif // STACK_H