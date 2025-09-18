/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-07 15:01:06
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-09-07 00:29:14
 */
#pragma once
#include "HashTable.h"
#include <stdexcept>

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
		// 迭代器类型定义 typename 是为了告诉编译器，iterator 是一个类型，而不是一个值
		// 在模板编程中，当访问依赖于模板参数的嵌套类型时，需要使用 typename 关键字，告诉编译器 HashBucketForMapSet::HashTable<K, K, SetKeyOfT>::iterator 是一个类型名，而不是静态成员变量
		typedef typename HashBucketForMapSet::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename HashBucketForMapSet::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;

		// iterator begin()
		// {
		// 	return _ht.begin();
		// }
		// iterator end()
		// {
		// 	return _ht.end();
		// }

		// 只提供const迭代器接口
		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		// 插入接口
		std::pair<iterator, bool> insert(const K &key)
		{
			// 这样写是不好的,如果编译器检查严格可能就编译不过去 因为类型毕竟不同
			// return _ht.Insert(key);
			// 注意这里返回的iterator实际上const_iterator
			std::pair<typename HashBucketForMapSet::HashTable<K, K, SetKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			// 调用pair构造函数
			return std::pair<iterator, bool>(ret.first, ret.second);
		}

		// 查找接口
		iterator find(const K &key)
		{
			return _ht.Find(key);
		}

		// 删除接口
		bool erase(const K &key)
		{
			return _ht.Erase(key);
		}

		// 容量相关接口
		size_t size() const
		{
			return _ht.size();
		}

		bool empty() const
		{
			return size() == 0;
		}

		// 清空接口
		void clear()
		{
			// 通过重新构造来清空
			_ht = HashBucketForMapSet::HashTable<K, K, SetKeyOfT>();
		}

		// 计数接口（对于set，只能是0或1）
		size_t count(const K &key) const
		{
			return _ht.Find(key) != end() ? 1 : 0;
		}

		// 哈希表统计信息
		size_t bucket_count() const
		{
			return _ht.bucket_count();
		}

		// 负载因子
		float load_factor() const
		{
			return static_cast<float>(size()) / bucket_count();
		}

		// 打印接口
		void Print()
		{
			_ht.Print();
		}
	};
}
