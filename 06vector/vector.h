#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <assert.h>
#include "reverse_iterator.h"

namespace yzq
{
	template <class T>
	class vector
	{
	public:
		typedef T *iterator;
		typedef const T *const_iterator;

		typedef ReverseIterator<iterator, T &, T *> reverse_iterator;
		typedef ReverseIterator<const_iterator, const T &, const T *> const_reverse_iterator;

		// 注意这个不能删，删了编译通不过，我们下面写有构造函数但不是默认构造，编译器就不会再生成默认构造，
		// 如果把这个无参的构造删除，找不到默认构造，编译过不了
		vector()
			: _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T &val = T())
			: _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T &val = T())
			: _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		void swap(vector<T> &v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T> &v)
			: _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		// v2 = v1
		vector<T> &operator=(vector<T> tmp)
		{
			// 现代写法
			swap(tmp);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			// return reverse_iterator(end() - 1);
			// 模仿stl库的实现
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			// return reverse_iterator(begin() - 1);
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			// 注意，不能--end()，end返回的是临时对象，具有常性，不能修改
			// return const_reverse_iterator(--end());
			// return const_reverse_iterator(end() - 1);
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			// return const_reverse_iterator(begin() - 1);
			return const_reverse_iterator(begin());
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			// 不考虑缩容的问题
			if (n > capacity())
			{
				T *tmp = new T[n];
				if (_start) // 有数据才拷贝
				{
					// memcpy(tmp, _start, size() * sizeof(T)); // 存在浅拷贝问题 要一个一个拷贝
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i]; // 如果涉及深拷贝，会去调用自己的赋值重载完成深拷贝
					}
					// printf("%p\n", tmp);
					// printf("%p\n", _start);
					delete[] _start;
				}
				_start = tmp;
			}

			//_finish = _start + size(); // size()的计算出现了错误，_start已经改变了
			_finish = _start + sz;
			_endofstorage = _start + n;
		}

		// T val = T() T()是生成匿名对象，调用默认构造函数，然后再拷贝构造给 val
		// const T &val = T() 这样写就是延长匿名对象寿命周期，不再使用 val 时才销毁
		// C++的内置类型也是有默认构造函数的 int的就是0 double的就是0.0
		void resize(size_t n, const T &val = T())
		{
			// 3种情况
			// 大于capacity 相当于扩容+插入新值
			if (n > capacity())
			{
				reserve(n);
			}
			// 大于size小于capacity 相当于插入新值
			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else // 小于等于size 相当于删除
			{
				_finish = _start + n;
			}
		}

		// 传引用减少开销，不改变就加const
		void push_back(const T &x)
		{
#if 0
			if (_finish == _endofstorage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}

			*_finish = x;
			++_finish;
#endif
			insert(end(), x); // 复用insert
		}

		void pop_back()
		{
			/*
			if (_finish > _start)
			{
				--_finish;
			}
			*/
			// 复用erase
			erase(end() - 1);
			// 不能--end() end返回的临时对象具有常性
		}

		T &operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T &operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		iterator insert(iterator pos, const T &x)
		{
			// 考虑越界，pos=_finish 就是尾插
			assert(pos >= _start);
			assert(pos <= _finish);
			// 考虑空间不够，扩容
			// 扩容后pos失效了，利用相对距离更新pos
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
				// 扩容后，就有新的_start，记住扩容前 pos 相对_start 的偏移量即可得到新的 pos 位置
				pos = _start + len;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		// 要考虑到实现者有可能对erase实现缩容，而缩容开辟新空间会改变pos位置
		// 因此需要返回迭代器
		iterator erase(iterator pos)
		{
			// 边界检查 pos 不能 == _finish，_finish是最后一个元素的下一个位置
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}