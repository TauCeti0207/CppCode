/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-26 19:36:22
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-26 19:36:47
 */
#pragma once
namespace yzq
{
	// 当适配list时，list传过来的参数是iterator 也就是Node*的封装
	// 也就是_it 也是一个结点指针
	template <class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		Iterator _it;
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		Reverse_iterator(Iterator it)
			: _it(it)
		{
		}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self operator--()
		{
			_it++;
			return *this;
		}

		Self operator++()
		{
			_it--;
			return *this;
		}

		bool operator!=(const Self &s)
		{
			return _it != s._it;
		}
	};
}