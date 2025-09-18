/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-07 15:01:06
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-09-07 17:55:19
 */

#include "HashTable.h"
#include <stdexcept>

namespace yzq
{
	template <class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K &operator()(const std::pair<const K, V> &kv) const
			{
				return kv.first;
			}
		};

	private:
		HashBucketForMapSet::HashTable<K, std::pair<const K, V>, MapKeyOfT> _ht;

	public:
		// 迭代器类型定义 typename 是为了告诉编译器这是一个类型，而不是一个变量
		typedef typename HashBucketForMapSet::HashTable<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename HashBucketForMapSet::HashTable<K, std::pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		// 迭代器接口
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		// const迭代器接口
		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		// 插入接口
		std::pair<iterator, bool> insert(const std::pair<K, V> &kv)
		{
			return _ht.Insert(kv);
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

		// 下标操作符
		V &operator[](const K &key)
		{
			// 创建一个键值对，其中值使用默认构造函数初始化
			// 如果键已存在，Insert 不会插入新元素，返回现有元素的迭代器
			// 如果键不存在，Insert 会插入新的键值对
			std::pair<iterator, bool> ret = _ht.Insert(std::make_pair(key, V()));
			// 返回对值的引用，允许读写操作
			return ret.first->second;
		}

		// 容量相关接口
		size_t size() const
		{
			return _ht.size();
		}

		bool empty() const
		{
			return _ht.size() == 0;
		}

		// 清空接口
		void clear()
		{
			// 重新构造一个空的哈希表
			_ht = HashBucketForMapSet::HashTable<K, std::pair<const K, V>, MapKeyOfT>();
		}

		// count接口 - 返回指定键的元素个数（0或1）
		size_t count(const K &key) const
		{
			return _ht.Find(key) != _ht.end() ? 1 : 0;
		}

		// at接口 - 安全的元素访问，不存在时抛出异常
		V &at(const K &key)
		{
			iterator it = _ht.Find(key);
			if (it != end())
			{
				return it->second;
			}
			else
			{
				throw std::out_of_range("unordered_map::at: key not found");
			}
		}

		const V &at(const K &key) const
		{
			iterator it = _ht.Find(key);
			if (it != end())
			{
				return it->second;
			}
			else
			{
				throw std::out_of_range("unordered_map::at: key not found");
			}
		}

		// 获取桶数量
		size_t bucket_count() const
		{
			return _ht.bucket_count();
		}

		// 获取负载因子
		float load_factor() const
		{
			return bucket_count() > 0 ? static_cast<float>(size()) / bucket_count() : 0.0f;
		}

		// 兼容旧接口
		std::pair<iterator, bool> Insert(const std::pair<K, V> &kv)
		{
			return insert(kv);
		}

		void Print()
		{
			_ht.Print();
		}
	};
}
