/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-08-03 14:35:33
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-09-07 18:05:31
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <type_traits>

namespace closeHash
{
	enum Status // 默认从0 1 2开始
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template <class K, class V>
	struct HashData
	{
		std::pair<K, V> _kv;
		Status _status = EMPTY;
	};
	template <class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K &key)
		{
			return (size_t)key;
		}
	};
	struct StringHashFunc
	{
		size_t operator()(const std::string &key)
		{
			// BKDR 的字符串哈希算法
			size_t hash = 0;
			for (auto ch : key)
				hash = hash * 131 + ch;
			return hash;
		}
	};

	/// @brief BKDR Hash Function
	/// @detail 本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名，
	/// 是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）。
	// 利用模版特化，针对string，调用string版本的DefaultHashFunc
	template <>
	struct DefaultHashFunc<std::string>
	{
		size_t operator()(const std::string &key)
		{
			// BKDR 的字符串哈希算法
			size_t hash = 0;
			for (auto ch : key)
			{
				hash = hash * 131 + ch; // 也可以乘以31、131、1313、13131、131313..
										// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;
										// 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，
										// 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；
										// 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：
										// 当乘数8-31位都为1或0时，需要1个时钟周期
										// 当乘数16-31位都为1或0时，需要2个时钟周期
										// 当乘数24-31位都为1或0时，需要3个时钟周期
										// 否则，需要4个时钟周期
										// 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大
			}
			return hash;
		}
	};

	template <class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	private:
		std::vector<HashData<K, V>> _tables;
		// 存储的关键字个数
		size_t _n = 0;

	public:
		HashTable()
		{
			_tables.resize(10);
		}
		bool Insert(const std::pair<K, V> &kv)
		{
			if (Find(kv.first) != nullptr) // 排除冗余值
				return false;

			// 负载因子>0.7就扩容
			// _n / _tables.size() >= 0.7 这样写不行，_n是整数 但是如果用浮点数，效率又会有所下降 需要转换一下写法
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				// 扩容以后 映射关系会发生变化，比如原来10映射到0，扩容到20个空间后，10应该映射到10
				// 因此扩容之后需要重新映射 原来冲突的可能不冲突，原来不冲突的反而可能冲突了
				// 利用现代写法 复用insert然后再swap
				HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize); // 开空间
				// 遍历旧表插入newHT
				for (auto &e : _tables)
					if (e._status == EXIST)
						newHT.Insert(e._kv);
				// 这里调用的是vector库里的swap 效率比较高 现代C++的交换方式
				_tables.swap(newHT._tables);
			}
			// 这里得进行泛化，传进来的key不一定是整形，借助HashFunc仿函数hash
			HashFunc hf;
			size_t starti = hf(kv.first);
			// size_t starti = kv.first;
			starti %= _tables.size(); // 这里得取模size而不能模capacity，因为如果模capacity，结果starti可能超出size的范围，size的大小是有效访问空间 []会检查时候越界，超过size的大小。
			size_t hashi = starti;
			size_t i = 1;
			// 线性探测/二次探测
			// 空和删除都能放值，遇到空或删除过的就停下来赋值
			while (_tables[hashi]._status == EXIST)
			{
				hashi = starti + i; // 线性探测，换成i*i就变成二次探测
				i++;
				hashi %= _tables.size(); // 一直++但不能超出size的界限
			}
			_tables[hashi]._kv = kv; // 出来时就表示找到空的位置 EMPTY或者DELETE
			_tables[hashi]._status = EXIST;
			_n++; // 存储的有效关键字个数
			return true;
		}

		HashData<const K, V> *Find(const K &key)
		{
			if (_tables.size() == 0) // 空表返回空
				return nullptr;

			HashFunc hf;
			size_t starti = hf(key);
			// size_t starti = key;
			starti %= _tables.size();
			size_t hashi = starti;
			size_t i = 1;
			// 当前位置是删除和存在都要继续找，!=EMPTY就要继续查找
			while (_tables[hashi]._status != EMPTY)
			{
				// 不能返回已经delete的值
				if (_tables[hashi]._status == EXIST && _tables[hashi]._kv.first == key)
				{
					// 函数什么
					return (HashData<const K, V> *)&_tables[hashi]; // 找到后返回的是HashData<K, V>*
				}
				hashi = starti + i;
				i++;
				hashi %= _tables.size();
			}
			// 找不到返回空指针
			return nullptr;
		}

		bool Erase(const K &key)
		{
			HashData<const K, V> *ret = Find(key);
			if (ret != nullptr)
			{
				// 不需要真的去删除，只需要将状态改为DELETE
				ret->_status = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}
		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._status == EXIST)
				{
					// printf("[%zu]->%d\n", i, _tables[i]._kv.first);
					std::cout << "[" << i << "]->" << _tables[i]._kv.first << ":" << _tables[i]._kv.second << std::endl;
				}
				else if (_tables[i]._status == DELETE)
				{
					// printf("[%zu]->DELETE\n", i);
					std::cout << "[" << i << "]->DELETE" << std::endl;
				}
				else
				{
					// printf("[%zu]->EMPTY\n", i);
					std::cout << "[" << i << "]->EMPTY" << std::endl;
				}
			}
		}
	};
}

namespace HashBucket
{
	template <class K, class V>
	struct HashNode
	{
		std::pair<K, V> _kv;
		HashNode<K, V> *_next;
		HashNode(const std::pair<K, V> &kv)
			: _kv(kv), _next(nullptr)
		{
		}
	};
	/*
		// java里面的哈希桶就是这样实现的，节点太长，哈希桶下面就挂一个红黑树
		template <class K, class V>
		struct bucket
		{
			std::list<std::pair<K, V>> _lt;
			std::set<std::pair<K, V>> _rbtree;
			// 长度超过8 就放到红黑树
			size_t len = 0;
		};
	*/
	template <class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K &key)
		{
			return (size_t)key;
		}
	};

	template <>
	struct DefaultHashFunc<std::string>
	{
		size_t operator()(const std::string &key)
		{
			size_t hash = 0;
			for (auto ch : key)
				hash = hash * 131 + ch;
			return hash;
		}
	};

	template <class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	private:
		std::vector<Node *> _tables;
		size_t _n = 0;

	public:
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node *cur = _tables[i];
				while (cur)
				{
					Node *next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		HashTable()
			// 在对象构造时就直接初始化了vector 也是调用vector构造函数完成构造
			: _tables(10, nullptr), _n(0)
		{
		}

		// 拷贝构造
		// 通过逐个复制每个桶中的节点，确保新哈希表拥有自己的节点内存，不会与原表共享数据（避免浅拷贝导致的内存问题）
		HashTable(const HashTable<K, V, HashFunc> &ht)
		{
			_tables.resize(ht._tables.size());
			// 遍历原表的每个桶
			for (int i = 0; i < ht._tables.size(); i++)
			{
				Node *cur = ht._tables[i];
				while (cur)
				{
					// 循环复制当前桶中的所有节点
					Node *tmp = new Node(cur->_kv);
					tmp->_next = _tables[i];
					_tables[i] = tmp;
					_n++;
					cur = cur->_next;
				}
			}
		}

		// 现代写法赋值重载
		// 函数参数是值传递，会先通过拷贝构造函数，创建一个右操作数的临时副本（ht 是原对象的完整拷贝）。
		HashTable<K, V, HashFunc> operator=(HashTable<K, V, HashFunc> ht)
		{
			if (this != &ht)
			{
				// 交换当前对象与临时副本的资源
				std::swap(_tables, ht._tables);
				std::swap(_n, ht._n);
			}
			// 函数结束时，临时参数 ht 会被销毁，其析构函数会自动释放它所持有当前对象的旧资源，避免内存泄漏。
			return *this;
		}

		bool Insert(const std::pair<K, V> &kv)
		{
			// 防止键值对冗余
			if (Find(kv.first))
				return false;

			HashFunc hf;
			// 需要扩容，不扩容查找效率太低了，哈希桶负载因子可以达到1，平均每个桶一个数据
			if (_tables.size() == _n)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				std::vector<Node *> newTables;
				newTables.resize(newSize, nullptr);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					// 对于每个桶，用cur指针指向当前旧桶的头节点
					Node *cur = _tables[i];
					while (cur) // 使用头插更方便
					{
						// 改变了cur，需要提前保存一下cur的next
						Node *next = cur->_next;
						// 新表大小变了（newSize），节点在新表中的位置需要重新计算
						size_t hashi = hf(cur->_kv.first) % newSize;
						// 让当前节点的next指向新表中hashi位置的当前头节点（如果没有，那就指向nullptr）
						cur->_next = newTables[hashi];
						// 让新表中hashi位置的头节点更新为当前节点
						newTables[hashi] = cur;
						// 继续处理下一个节点
						cur = next;
					}
					// 旧哈希表的节点都被移走了
					// 旧桶处理完毕，置空（后续会被替换）
					_tables[i] = nullptr;
				}
				newTables.swap(_tables);
			}

			size_t hashi = hf(kv.first);
			hashi %= _tables.size();
			// 头插 _tables[hashi] newNode nullptr
			// _tables[hashi] node1 nullptr
			// 头插之后：_tables[hashi] newNode node1 nullptr
			Node *newNode = new Node(kv);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;
			++_n;

			return true;
		}

		Node *Find(const K &key)
		{
			if (_tables.size() == 0)
				return nullptr;
			HashFunc hf;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node *cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K &key)
		{
			if (_tables.size() == 0)
				return false;
			HashFunc hf;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node *prev = nullptr;
			Node *cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					// prev cur cur->next
					// 注意prev可能为空 相当于是头删 那就让tables[i]指向cur的下一个
					if (prev == nullptr)
						_tables[hashi] = cur->_next;
					else
						prev->_next = cur->_next;
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		// 获取哈希表大小的公有接口
		size_t size() const
		{
			return _n;
		}

		// 获取桶数量的公有接口
		size_t bucket_count() const
		{
			return _tables.size();
		}

		void hashTablesInfo()
		{
			size_t usedBucketCount = 0;		// 已使用的桶数量（非空桶）
			size_t maxBucketLen = 0;		// 最长桶的长度
			size_t totalNodeCount = 0;		// 总节点数量
			double averageBucketSize = 0.0; // 平均桶长度（仅计算非空桶）
			double loadFactor = 0.0;		// 负载因子（总节点数/总桶数）

			// 遍历所有桶，统计信息
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node *cur = _tables[i];
				size_t currentBucketLen = 0;

				// 统计当前桶的节点数量
				while (cur)
				{
					++currentBucketLen;
					cur = cur->_next;
				}

				// 更新总节点数
				totalNodeCount += currentBucketLen;

				// 如果当前桶非空，更新已使用桶计数
				if (currentBucketLen > 0)
				{
					++usedBucketCount;

					// 更新最长桶长度
					if (currentBucketLen > maxBucketLen)
					{
						maxBucketLen = currentBucketLen;
					}
				}
			}

			// 计算平均桶长度（仅针对非空桶）
			if (usedBucketCount > 0)
			{
				averageBucketSize = static_cast<double>(totalNodeCount) / usedBucketCount;
			}

			// 计算负载因子（总节点数 / 总桶数）
			if (_tables.size() > 0)
			{
				loadFactor = static_cast<double>(totalNodeCount) / _tables.size();
			}

			// 输出哈希表信息
			std::cout << "===== 哈希表状态信息 =====" << std::endl;
			std::cout << "总桶数量: " << _tables.size() << std::endl;
			std::cout << "已使用桶数量: " << usedBucketCount << std::endl;
			std::cout << "总节点数量: " << totalNodeCount << std::endl;
			std::cout << "负载因子: " << std::fixed << std::setprecision(2) << loadFactor << std::endl;
			std::cout << "最长桶长度: " << maxBucketLen << std::endl;
			std::cout << "非空桶平均长度: " << std::fixed << std::setprecision(2) << averageBucketSize << std::endl;
			std::cout << "==========================" << std::endl;
		}

		void Print()
		{
			std::cout << "=== 哈希桶状态 ===" << std::endl;
			for (size_t i = 0; i < _tables.size(); i++)
			{
				std::cout << "[" << i << "]: ";
				Node *cur = _tables[i];
				if (cur == nullptr)
				{
					std::cout << "nullptr" << std::endl;
				}
				else
				{
					// 遍历当前桶的链表
					while (cur)
					{
						std::cout << cur->_kv.first << ":" << cur->_kv.second;
						cur = cur->_next;
						if (cur)
							std::cout << " -> ";
					}
					std::cout << " -> nullptr" << std::endl;
				}
			}
			std::cout << "总元素数量: " << _n << std::endl;
			std::cout << "================" << std::endl;
		}
	};
}
namespace HashBucketForMapSet
{

	template <class T>
	struct HashNode
	{
		HashNode<T> *_next;
		T _data;
		HashNode(const T &data)
			: _data(data), _next(nullptr)
		{
		}
	};

	template <class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K &key)
		{
			return key;
		}
	};

	template <>
	struct DefaultHashFunc<std::string>
	{
		size_t operator()(const std::string &key)
		{
			size_t hash = 0;
			for (auto ch : key)
			{
				hash = hash * 131 + ch;
			}
			return hash;
		}
	};

	// 前置声明
	template <class K, class T, class KeyofT, class HashFunc>
	class HashTable;

	template <class K, class T, class Ptr, class Ref, class KeyofT, class HashFunc = DefaultHashFunc<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Ptr, Ref, KeyofT, HashFunc> Self;
		typedef __HTIterator<K, T, T *, T &, KeyofT, HashFunc> iterator;
		Node *_node;
		// 需要把整个哈希表传过来
		const HashTable<K, T, KeyofT, HashFunc> *_pht;
		size_t _hashi; // 当前哈希桶的索引

		__HTIterator(Node *node, const HashTable<K, T, KeyofT, HashFunc> *pht, size_t hashi)
			: _node(node), _pht(pht), _hashi(hashi)
		{
		}

		// 拷贝构造,完成普通迭代器到const迭代器转换
		__HTIterator(const iterator &it)
			: _node(it._node), _pht(it._pht), _hashi(it._hashi)
		{
		}

		Self &operator++()
		{
			if (_node->_next)
			{
				// 当前哈希桶没走完，直接去下一个节点
				_node = _node->_next;
			}
			else
			{
				// 当前桶走完了，找下一个桶
				// 在创建迭代器时， begin() 函数会遍历哈希表找到第一个非空桶，然后将该桶的索引 i 作为参数传递给迭代器构造函数
				++_hashi;
				while (_hashi < _pht->_tables.size())
				{
					// 桶不为空 找到后break出来
					if (_pht->_tables[_hashi])
					{
						_node = _pht->_tables[_hashi];
						break;
					}
					// 桶为空 继续找下一个桶
					++_hashi;
				}
				// 走到结束位置
				if (_hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		bool operator!=(const __HTIterator &s)
		{
			// 两个迭代器比较，用节点指针比较
			return _node != s._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}
	};

	// unordered_set -> HashTable<K, K>
	// unordered_map -> HashTable<K, pair<K,V>>
	template <class K, class T, class KeyofT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;
		friend struct __HTIterator<K, T, T *, T &, KeyofT, HashFunc>;
		friend struct __HTIterator<K, T, const T *, const T &, KeyofT, HashFunc>;

	private:
		/*
		// java里面的哈希桶就是这样实现的，节点太长，哈希桶下面就挂一个红黑树
		struct bucket
		{
			list<std::pair<K, V>> _lt;
			std::set<std::pair<K, V>> _rbtree;
			// 长度超过8 就放到红黑树
			size_t len = 0;
		};
		std::vector<bucket> _tables;
		*/
		std::vector<Node *> _tables;
		size_t _n = 0;

	public:
		typedef __HTIterator<K, T, T *, T &, KeyofT, HashFunc> iterator;
		typedef __HTIterator<K, T, const T *, const T &, KeyofT, HashFunc> const_iterator;

		// 获取下一个素数的函数
		// 使用素数作为哈希表大小可以减少哈希冲突，提高哈希表性能
		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			// 预定义的素数表，涵盖了从53到4294967291的28个素数
			// 这些素数经过精心选择，能够满足大多数哈希表扩容需求
			static const size_t primeList[PRIMECOUNT] =
				{
					53ul, 97ul, 193ul, 389ul, 769ul,
					1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
					49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
					1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
					50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
					1610612741ul, 3221225473ul, 4294967291ul};

			// 查找第一个大于当前prime的素数
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}

			// 如果超出了素数表范围，返回最大的素数
			return primeList[PRIMECOUNT - 1];
		}

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				// 找到第一个非空桶
				Node *cur = _tables[i];
				if (cur)
				{
					// 构造迭代器需要，节点指针、哈希表指针、当前哈希桶索引位置
					return iterator(cur, this, i);
				}
			}
			// 找不到返回空 也就是end()
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}

		const_iterator begin() const
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				// 找到第一个非空桶
				Node *cur = _tables[i];
				if (cur)
				{
					// 构造const迭代器需要，节点指针、哈希表指针、当前哈希桶索引位置
					return const_iterator(cur, this, i);
				}
			}
			// 找不到返回空 也就是end()
			return end();
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this, -1);
		}

	public:
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node *cur = _tables[i];
				while (cur)
				{
					Node *next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		HashTable()
			: _tables(0, nullptr), _n(0)
		{
			// 初始化时使用素数表中的第一个素数作为初始大小
			// 这样可以从一开始就获得更好的哈希分布
		}

		// 拷贝构造
		// 通过逐个复制每个桶中的节点，确保新哈希表拥有自己的节点内存，不会与原表共享数据（避免浅拷贝导致的内存问题）
		HashTable(const HashTable<K, T, KeyofT, HashFunc> &ht)
		{
			_tables.resize(ht._tables.size());
			// 遍历原表的每个桶
			for (int i = 0; i < ht._tables.size(); i++)
			{
				Node *cur = ht._tables[i];
				while (cur)
				{
					// 循环复制当前桶中的所有节点
					Node *tmp = new Node(cur->_data);
					tmp->_next = _tables[i];
					_tables[i] = tmp;
					_n++;
					cur = cur->_next;
				}
			}
		}

		// 现代写法赋值重载
		// 函数参数是值传递，会先通过拷贝构造函数，创建一个右操作数的临时副本（ht 是原对象的完整拷贝）。
		HashTable<K, T, KeyofT, HashFunc> operator=(HashTable<K, T, KeyofT, HashFunc> ht)
		{
			if (this != &ht)
			{
				// 交换当前对象与临时副本的资源
				std::swap(_tables, ht._tables);
				std::swap(_n, ht._n);
			}
			// 函数结束时，临时参数 ht 会被销毁，其析构函数会自动释放它所持有当前对象的旧资源，避免内存泄漏。
			return *this;
		}

		std::pair<iterator, bool> Insert(const T &data)
		{
			HashFunc hf;
			KeyofT kot;
			// 防止键值对冗余
			iterator it = Find(kot(data));
			if (it != end())
			{
				// 插入失败,返回false
				return std::make_pair(it, false);
			}

			// 需要扩容，不扩容查找效率太低了，哈希桶负载因子可以达到1
			// 使用素数作为哈希表大小可以减少哈希冲突，提高性能
			if (_tables.size() == _n)
			{
				// 使用素数表获取下一个合适的素数作为新的哈希表大小
				size_t newSize = _tables.size() == 0 ? GetNextPrime(0) : GetNextPrime(_tables.size());
				std::vector<Node *> newTables;
				newTables.resize(newSize, nullptr);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					// 对于每个桶，用cur指针指向当前旧桶的头节点
					Node *cur = _tables[i];
					while (cur) // 使用头插更方便
					{
						// 改变了cur，需要提前保存一下cur的next
						Node *next = cur->_next;
						// 新表大小变了（newSize），节点在新表中的位置需要重新计算
						// 需要先取出data里的key，再用哈希函数就计算哈希
						size_t hashi = hf(kot(cur->_data)) % newSize;
						// 让当前节点的next指向新表中hashi位置的当前头节点（如果没有，那就指向nullptr）
						cur->_next = newTables[hashi];
						// 让新表中hashi位置的头节点更新为当前节点
						newTables[hashi] = cur;

						cur = next; // update cur
					}
					// 旧桶处理完毕，置空（后续会被替换）
					_tables[i] = nullptr;
				}
				newTables.swap(_tables);
			}

			size_t hashi = hf(kot(data));
			hashi %= _tables.size();
			Node *newNode = new Node(data);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;
			++_n;

			return std::make_pair(iterator(newNode, this, hashi), true);
		}

		iterator Find(const K &key)
		{
			if (_tables.size() == 0)
				return end();
			HashFunc hf;
			KeyofT kot;
			size_t hashi = hf(key) % _tables.size();
			Node *cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return iterator(cur, this, hashi);
				cur = cur->_next;
			}
			return end();
		}

		const_iterator Find(const K &key) const
		{
			if (_tables.size() == 0)
				return end();
			HashFunc hf;
			KeyofT kot;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node *cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return const_iterator(cur, this, hashi);
				cur = cur->_next;
			}
			return end();
		}

		bool Erase(const K &key)
		{
			if (_tables.size() == 0)
				return false;
			HashFunc hf;
			KeyofT kot;
			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node *prev = nullptr;
			Node *cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// prev cur cur->next
					// 注意prev可能为空 相当于是头删 那就让tables[i]指向cur的下一个
					if (prev == nullptr)
						_tables[hashi] = cur->_next;
					else
						prev->_next = cur->_next;
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		size_t size() const
		{
			return _n;
		}

		size_t bucket_count() const
		{
			return _tables.size();
		}

		void hashTablesInfo()
		{
			size_t usedBucketCount = 0;		// 已使用的桶数量（非空桶）
			size_t maxBucketLen = 0;		// 最长桶的长度
			size_t totalNodeCount = 0;		// 总节点数量
			double averageBucketSize = 0.0; // 平均桶长度（仅计算非空桶）
			double loadFactor = 0.0;		// 负载因子（总节点数/总桶数）

			// 遍历所有桶，统计信息
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node *cur = _tables[i];
				size_t currentBucketLen = 0;

				// 统计当前桶的节点数量
				while (cur)
				{
					++currentBucketLen;
					cur = cur->_next;
				}

				// 更新总节点数
				totalNodeCount += currentBucketLen;

				// 如果当前桶非空，更新已使用桶计数
				if (currentBucketLen > 0)
				{
					++usedBucketCount;

					// 更新最长桶长度
					if (currentBucketLen > maxBucketLen)
					{
						maxBucketLen = currentBucketLen;
					}
				}
			}

			// 计算平均桶长度（仅针对非空桶）
			if (usedBucketCount > 0)
			{
				averageBucketSize = static_cast<double>(totalNodeCount) / usedBucketCount;
			}

			// 计算负载因子（总节点数 / 总桶数）
			if (_tables.size() > 0)
			{
				loadFactor = static_cast<double>(totalNodeCount) / _tables.size();
			}

			// 输出哈希表信息
			std::cout << "===== 哈希表状态信息 =====" << std::endl;
			std::cout << "总桶数量: " << _tables.size() << std::endl;
			std::cout << "已使用桶数量: " << usedBucketCount << std::endl;
			std::cout << "总节点数量: " << totalNodeCount << std::endl;
			std::cout << "负载因子: " << std::fixed << std::setprecision(2) << loadFactor << std::endl;
			std::cout << "最长桶长度: " << maxBucketLen << std::endl;
			std::cout << "非空桶平均长度: " << std::fixed << std::setprecision(2) << averageBucketSize << std::endl;
			std::cout << "==========================" << std::endl;
		}

		// 辅助函数：检测是否为std::pair类型
		template <typename U>
		struct is_pair : std::false_type
		{
		};

		template <typename First, typename Second>
		struct is_pair<std::pair<First, Second>> : std::true_type
		{
		};

		// 输出数据的辅助函数 - 针对pair类型
		template <typename U>
		typename std::enable_if<is_pair<U>::value, void>::type
		PrintData(const U &data)
		{
			std::cout << "(" << data.first << ", " << data.second << ")";
		}

		// 输出数据的辅助函数 - 针对非pair类型
		template <typename U>
		typename std::enable_if<!is_pair<U>::value, void>::type
		PrintData(const U &data)
		{
			std::cout << data;
		}

		void Print()
		{
			std::cout << "=== 哈希桶状态 ===" << std::endl;
			for (size_t i = 0; i < _tables.size(); i++)
			{
				std::cout << "[" << i << "]: ";
				Node *cur = _tables[i];
				if (cur == nullptr)
				{
					std::cout << "nullptr" << std::endl;
				}
				else
				{
					// 遍历当前桶的链表
					while (cur)
					{
						// 根据数据类型智能输出
						PrintData(cur->_data);
						cur = cur->_next;
						if (cur)
							std::cout << " -> ";
					}
					std::cout << " -> nullptr" << std::endl;
				}
			}
			std::cout << "总元素数量: " << _n << std::endl;
			std::cout << "================" << std::endl;
		}
	};
}