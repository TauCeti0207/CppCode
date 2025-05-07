/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:19:37
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-07 00:42:33
 */
// stack.cpp
#include "Stack.h"

template <typename T>
Stack<T>::Stack(int initialCapacity)
	: capacity(initialCapacity), top(-1)
{
	data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return top == -1;
}

template <typename T>
bool Stack<T>::isFull() const
{
	return top == capacity - 1;
}

template <typename T>
void Stack<T>::push(const T &value)
{
	if (isFull())
	{
		int newCapacity = capacity * 2;
		T *newData = new T[newCapacity];
		for (int i = 0; i <= top; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
	data[++top] = value;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack is empty, cannot pop.");
	}
	return data[top--];
}

template <typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack is empty, cannot peek.");
	}
	return data[top];
}

template <typename T>
int Stack<T>::size() const
{
	return top + 1;
}

// 显式实例化，用于模板类的分离编译
template class Stack<int>;