#pragma once
// ÉùÃ÷
template<typename T>
void Swap(T& left, T& right);

template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10);
	void PushBack(const T& x);
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

// ¶¨Òå
template<typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template<class T>
Vector<T>::Vector(size_t capacity)
	: _pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
{}

template<class T>
void Vector<T>::PushBack(const T& x)
{
	// ...
}