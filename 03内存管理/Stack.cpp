/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:19:37
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-09 16:37:17
 */
// stack.cpp
#include "Stack.h"

template <typename T>
Stack<T>::Stack(int initialCapacity)
	: _capacity(initialCapacity), _top(-1)
{
	_data = new T[_capacity];
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
	: _capacity(other._capacity), _top(other._top)
{
	_data = new T[_capacity];
	for (int i = 0; i <= _top; ++i)
	{
		_data[i] = other._data[i];
	}
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
	if (this != &other)
	{
		delete[] _data;
		_capacity = other._capacity;
		_top = other._top;
		_data = new T[_capacity];
		assert(_data);
		for (int i = 0; i <= _top; ++i)
		{
			_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	std::cout << "Stack Destroy" << std::endl;
	delete[] _data;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return _top == -1;
}

template <typename T>
bool Stack<T>::isFull() const
{
	return _top == _capacity - 1;
}

template <typename T>
void Stack<T>::push(const T &value)
{
	if (isFull())
	{
		int newCapacity = _capacity * 2;
		T *newData = new T[newCapacity];
		if (!newData)
		{
			throw std::bad_alloc();
		}
		for (int i = 0; i <= _top; ++i)
		{
			newData[i] = _data[i];
		}
		delete[] _data;
		_data = newData;
		_capacity = newCapacity;
	}
	_data[++_top] = value;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack is empty, cannot pop.");
	}
	return _data[_top--];
}

template <typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack is empty, cannot peek.");
	}
	return _data[_top];
}

template <typename T>
int Stack<T>::size() const
{
	return _top + 1;
}

// 显式实例化，用于模板类的分离编译
template class Stack<int>;