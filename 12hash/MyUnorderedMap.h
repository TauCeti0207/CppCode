/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-07 15:01:06
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-08-07 16:35:22
 */
#pragma once
#include "HashTable.h"

namespace yzq
{
	template <class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K &operator()(const std::pair<K, V> &kv) const
			{
				return kv.first;
			}
		};

	private:
		HashBucketForMapSet::HashTable<K, std::pair<K, V>, MapKeyOfT> _ht;

	public:
		bool Insert(const std::pair<K, V> &kv)
		{
			return _ht.Insert(kv);
		}
	};
}
