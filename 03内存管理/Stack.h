/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:19:28
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-09 16:35:00
 */
// stack.h
#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#include <assert.h>

template <typename T>
class Stack
{
private:
	T *_data;
	int _capacity;
	int _top;

public:
	Stack(int initialCapacity = 10);
	Stack(const Stack<T> &other);
	Stack<T> &operator=(const Stack<T> &other);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const T &value);
	T pop();
	T peek() const;
	int size() const;
};

#endif // STACK_H