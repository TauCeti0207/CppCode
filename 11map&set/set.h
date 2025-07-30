/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-03 21:00:10
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-07-29 22:18:53
 */
#pragma once
#include "RedBlackTree.h"
namespace yzq
{
	template <class K>
	class set
	{
		struct SetKeyOfT
		{
			const K &operator()(const K &key)
			{
				return key;
			}
		};

	public:
		// 取的是类模板里面的内嵌类型，里面可以带有某些没被实例化的参数
		// 需要用typename 声明这些是类型，等实例化了再去对应的类模板里面取值。
		// 对于set，iterator和const_iterator是同一个类型，因为set的key和value是一样的，都不支持修改
		typedef typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const
		{
			// 这里begin的iterator是const迭代器，
			// 如果不加const，那么调用的是普通版本Begin，返回的又是普通迭代器，
			// const迭代器转化成普通迭代器，编不过，因此得加const，const修饰的this指针，这样就会去调用const版本Begin
			// 而且普通对象也是可以调用const修饰过的begin
			return _t.Begin();
		}
		iterator end() const
		{
			return _t.End();
		}
		std::pair<iterator, bool> insert(const K &key)
		{
			std::pair<typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
			// auto ret = _t.Insert(key);
			return std::pair<iterator, bool>(iterator(ret.first._node), ret.second);
			// node 是__RBTreeIterator 中的对象
		}
		iterator find(const K &key)
		{
			return iterator(_t.Find(key)._node);
		}

	private:
		RBTree_for_map_set::RBTree<K, K, SetKeyOfT> _t;
	};

}