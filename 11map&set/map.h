/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-03 21:00:10
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-07-29 22:23:56
 */
#pragma once
#include "RedBlackTree.h"
namespace yzq
{
	template <class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K &operator()(const std::pair<K, V> &kv)
			{
				return kv.first;
			}
		};

	public:
		// 取的是类模板里面的内嵌类型，里面可能带有某些没被实例化的参数
		// 需要用typename 声明iterator是类型，等实例化了再去对应的类模板里面取值。
		typedef typename RBTree_for_map_set::RBTree<K, std::pair<K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree_for_map_set::RBTree<K, std::pair<K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		std::pair<iterator, bool> insert(const std::pair<K, V> &kv)
		{
			return _t.Insert(kv);
		}
		iterator find(const K &key)
		{
			return _t.Find(key);
		}
		V &operator[](const K &key)
		{
			// 如果key存在，相当于是一次查找，如果key不存在，相当于是一次插入
			std::pair<iterator, bool> ret = insert(std::make_pair(key, V()));
			// ret.first就是iterator，再通过迭代器去访问val
			return ret.first->second;
		}

	private:
		RBTree_for_map_set::RBTree<K, std::pair<K, V>, MapKeyOfT> _t;
	};

}