/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-26 19:36:22
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-03 20:44:18
 */
#pragma once
namespace yzq
{
	// 当适配list时，list传过来的参数是iterator 也就是Node*的封装
	// 也就是_it 也是一个结点指针
	template <class Iterator, class Ref, class Ptr>
	class ReverseIterator
	{
	private:
		Iterator _it;

	public:
		typedef ReverseIterator<Iterator, Ref, Ptr> Self;
		// STL标准迭代器类型别名

		ReverseIterator(Iterator it)
			: _it(it)
		{
		}

		Ref operator*()
		{
			// return *_it;

			// 模仿标准库的写法，解引用返回的是前一个元素
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			// return _it.operator->();
			return &(operator*());
		}

		Self operator--()
		{
			_it++;
			return *this;
		}

		// 后置自减
		Self operator--(int)
		{
			Self tmp = *this;
			_it++;
			return tmp;
		}

		Self operator++()
		{
			_it--;
			return *this;
		}

		// 后置自增
		Self operator++(int)
		{
			Self tmp = *this;
			_it--;
			return tmp;
		}

		bool operator!=(const Self &s) const
		{
			return _it != s._it;
		}

		bool operator==(const Self &s) const
		{
			return _it == s._it;
		}
	};
}