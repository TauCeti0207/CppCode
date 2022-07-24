#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <assert.h>
using namespace std;

namespace yzq
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//vector(const vector& v)
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
			//this->swap(tmp); 等价
		}

		//vector& operator=(vector v)
		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
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
				T* tmp = new T[n];
				if (_start) // 有数据才拷贝
				{
					//memcpy(tmp, _start, size() * sizeof(T)); 存在浅拷贝问题 要一个一个拷贝
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i]; // 如果涉及深拷贝，会去调用自己的赋值重载完成深拷贝
					}
						delete[] _start;
				}
				_start = tmp;
			}

			//_finish = _start + size(); // size()的计算出现了错误，_start已经改变了
			//_endofstorage = _start + capacity();
			_finish = _start + sz;
			_endofstorage = _start + n;
		}

		//void resize(size_t n, T val = T()) T()是生成匿名对象，调用默认构造函数
		// 注意：C++的内置类型也是有默认构造函数的 int的就是0 double的就是0.0
		void resize(size_t n, const T& val = T())
		{
			// 3种情况
			// 大于capacity
			if (n > capacity())
			{
				reserve(n);
			}
			// 大于size小于capacity
			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else // 小于size
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*
			if (_finish == _endofstorage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}

			*_finish = x;
			++_finish;
			*/
			// 复用insert
			insert(end(), x);
		}

		void pop_back()
		{
			/*
			if (_finish > _start)
			{
				--_finish;
			}
			*/
			//复用erase
			erase(end() - 1);
			// 不能--end() end返回的临时对象具有常性
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			// 考虑扩容
			// 扩容后pos失效了，利用相对距离更新pos
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
				pos = _start + n;
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
			assert(pos >= _start && pos < _finish);
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
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}