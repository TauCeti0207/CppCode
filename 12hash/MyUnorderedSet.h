/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-07 15:01:06
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-08-07 21:44:43
 */
/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-07 15:01:06
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-08-07 15:25:24
 */
#pragma once
#include "HashTable.h"

namespace yzq
{
	template <class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K &operator()(const K &key) const
			{
				return key;
			}
		};

	private:
		HashBucketForMapSet::HashTable<K, K, SetKeyOfT> _ht;

	public:
		typedef typename HashBucketForMapSet::HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
		bool
		Insert(const K &key)
		{
			return _ht.Insert(key);
		}
	};
}
