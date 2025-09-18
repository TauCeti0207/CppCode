#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <cmath>
#include <climits>
#include <type_traits>
#include <bitset>
#include <chrono>

namespace HashBucketForMapSet
{
	// 哈希函数结构体
	struct BKDRHash
	{
		template <typename T>
		size_t operator()(const T &key) const
		{
			if constexpr (std::is_same_v<T, std::string>)
			{
				size_t hash = 0;
				for (char c : key)
				{
					hash = hash * 131 + c;
				}
				return hash;
			}
			else
			{
				return std::hash<T>{}(key);
			}
		}
	};

	struct APHash
	{
		template <typename T>
		size_t operator()(const T &key) const
		{
			if constexpr (std::is_same_v<T, std::string>)
			{
				size_t hash = 0xAAAAAAAA;
				for (size_t i = 0; i < key.length(); i++)
				{
					if ((i & 1) == 0)
					{
						hash ^= ((hash << 7) ^ key[i] * (hash >> 3));
					}
					else
					{
						hash ^= (~((hash << 11) + (key[i] ^ (hash >> 5))));
					}
				}
				return hash;
			}
			else
			{
				return std::hash<T>{}(key) * 16777619UL;
			}
		}
	};

	struct DJBHash
	{
		template <typename T>
		size_t operator()(const T &key) const
		{
			if constexpr (std::is_same_v<T, std::string>)
			{
				size_t hash = 5381;
				for (char c : key)
				{
					hash = ((hash << 5) + hash) + c;
				}
				return hash;
			}
			else
			{
				return std::hash<T>{}(key) * 33;
			}
		}
	};

	/**
	 * @brief 布隆过滤器实现
	 *
	 * 布隆过滤器是一种空间效率很高的概率型数据结构，用于测试一个元素是否在一个集合中。
	 * 特点：
	 * - 如果布隆过滤器说某个元素不存在，那么该元素一定不存在（无假阴性）
	 * - 如果布隆过滤器说某个元素存在，那么该元素可能存在（可能有假阳性）
	 * - 不支持删除操作
	 * - 空间效率高，时间复杂度为O(k)，其中k是哈希函数个数
	 */
	template <size_t BitSize = 1024 * 1024,
			  class K = std::string,
			  class Hash1 = BKDRHash,
			  class Hash2 = APHash,
			  class Hash3 = DJBHash> // 默认1MB位图
	class BloomFilter
	{
	private:
		std::bitset<BitSize> _bitset; // 位图存储
		size_t _hash_count;			  // 哈希函数个数
		size_t _element_count;		  // 已插入元素个数
		Hash1 _hasher1;				  // 第一个哈希函数对象
		Hash2 _hasher2;				  // 第二个哈希函数对象
		Hash3 _hasher3;				  // 第三个哈希函数对象

	public:
		/**
		 * @brief 构造函数
		 * @param hash_count 哈希函数个数，默认为3
		 */
		explicit BloomFilter(size_t hash_count = 3)
			: _hash_count(hash_count), _element_count(0), _hasher1(), _hasher2(), _hasher3()
		{
			if (_hash_count == 0)
			{
				_hash_count = 1;
			}
			std::cout << "布隆过滤器初始化完成：" << std::endl;
			std::cout << "  位图大小: " << BitSize << " 位" << std::endl;
			std::cout << "  哈希函数个数: " << _hash_count << std::endl;
			std::cout << "  预期误判率: " << getExpectedFalsePositiveRate() << std::endl;
		}

		/**
		 * @brief 获取键的哈希值数组
		 * @param key 要计算哈希值的键
		 * @return 哈希值数组
		 */
		std::vector<size_t> getHashValues(const K &key) const
		{
			std::vector<size_t> hash_values;

			// 直接使用具体的哈希函数，不进行重复哈希
			if (_hash_count >= 1)
			{
				hash_values.push_back(_hasher1(key) % BitSize);
			}
			if (_hash_count >= 2)
			{
				hash_values.push_back(_hasher2(key) % BitSize);
			}
			if (_hash_count >= 3)
			{
				hash_values.push_back(_hasher3(key) % BitSize);
			}

			// 如果需要更多哈希函数，可以通过组合现有哈希函数实现
			for (size_t i = 3; i < _hash_count; ++i)
			{
				size_t base_hash = hash_values[i % 3];
				size_t combined_hash = (base_hash + i * 17) % BitSize;
				hash_values.push_back(combined_hash);
			}

			return hash_values;
		}

		/**
		 * @brief 向布隆过滤器中插入元素
		 * @param key 要插入的键
		 */
		void insert(const K &key)
		{
			std::vector<size_t> hash_values = getHashValues(key);

			for (size_t hash_val : hash_values)
			{
				_bitset.set(hash_val);
			}

			_element_count++;
		}

		/**
		 * @brief 设置元素（通过多个哈希函数映射到不同位置）
		 * @param key 要设置的键
		 * @param value 要设置的值，默认为true
		 */
		void set(const K &key, bool value = true)
		{
			auto hash_values = getHashValues(key);
			for (size_t hash : hash_values)
			{
				_bitset.set(hash, value);
			}
			if (value)
			{
				_element_count++;
			}
		}

		/**
		 * @brief 测试元素是否在位图中
		 * @param key 要测试的键
		 * @return true表示可能存在，false表示一定不存在
		 */
		bool test(const K &key) const
		{
			auto hash_values = getHashValues(key);

			for (size_t hash : hash_values)
			{
				if (!_bitset.test(hash))
				{
					return false;
				}
			}

			return true;
		}

		/**
		 * @brief 清空布隆过滤器（注意：这会重置整个位图，可能影响其他数据）
		 * @param force_reset 是否强制重置位图，默认为false（仅重置计数器）
		 */
		void clear(bool force_reset = false)
		{
			if (force_reset)
			{
				_bitset.reset(); // 清空整个位图
			}
			_element_count = 0; // 重置元素计数器
		}

		/**
		 * @brief 安全清空：仅重置计数器，不影响位图数据
		 */
		void soft_clear()
		{
			_element_count = 0;
		}

		/**
		 * @brief 完全清空：重置位图和计数器（危险操作）
		 */
		void hard_clear()
		{
			_bitset.reset();
			_element_count = 0;
		}

		/**
		 * @brief 获取已插入元素个数
		 */
		size_t size() const
		{
			return _element_count;
		}

		/**
		 * @brief 获取位图中被设置的位数
		 */
		size_t getBitCount() const
		{
			return _bitset.count();
		}

		/**
		 * @brief 获取位图大小
		 */
		size_t getBitSize() const
		{
			return BitSize;
		}

		/**
		 * @brief 获取哈希函数个数
		 */
		size_t getHashCount() const
		{
			return _hash_count;
		}

		/**
		 * @brief 查看指定键的所有哈希值
		 * @param key 要查看哈希值的键
		 * @return 包含所有哈希值的向量
		 */
		std::vector<size_t> viewHashValues(const K &key) const
		{
			return getHashValues(key);
		}

		/**
		 * @brief 打印指定键的所有哈希值（调试用）
		 * @param key 要打印哈希值的键
		 */
		void printHashValues(const K &key) const
		{
			std::vector<size_t> hash_values = getHashValues(key);
			std::cout << "键 '" << key << "' 的哈希值:\n";
			for (size_t i = 0; i < hash_values.size(); ++i)
			{
				std::cout << "  哈希函数 " << (i + 1) << ": " << hash_values[i]
						  << " (位置: " << hash_values[i] << ", 位图状态: "
						  << (_bitset[hash_values[i]] ? "已设置" : "未设置") << ")\n";
			}
			std::cout << std::endl;
		}

		/**
		 * @brief 计算当前的误判率
		 * @return 当前误判率的估计值
		 */
		double getCurrentFalsePositiveRate() const
		{
			if (_element_count == 0)
				return 0.0;

			// 误判率公式: (1 - e^(-k*n/m))^k
			// 其中 k = 哈希函数个数, n = 元素个数, m = 位图大小
			double k = static_cast<double>(_hash_count);
			double n = static_cast<double>(_element_count);
			double m = static_cast<double>(BitSize);

			double exponent = -k * n / m;
			double base = 1.0 - std::exp(exponent);
			return std::pow(base, k);
		}

		/**
		 * @brief 获取理论最优误判率（基于当前参数）
		 */
		double getExpectedFalsePositiveRate() const
		{
			// 对于给定的m和k，最优的n使得误判率最小
			// 最优误判率约为 (1/2)^k
			return std::pow(0.5, static_cast<double>(_hash_count));
		}

		/**
		 * @brief 打印布隆过滤器统计信息
		 */
		void printStatistics() const
		{
			std::cout << "=== 布隆过滤器统计信息 ===" << std::endl;
			std::cout << "位图大小: " << BitSize << " 位" << std::endl;
			std::cout << "哈希函数个数: " << _hash_count << std::endl;
			std::cout << "已插入元素个数: " << _element_count << std::endl;
			std::cout << "已设置位数: " << getBitCount() << std::endl;
			std::cout << "位图使用率: " << (getBitCount() * 100.0 / BitSize) << "%" << std::endl;
			std::cout << "当前误判率: " << getCurrentFalsePositiveRate() << std::endl;
			std::cout << "理论最优误判率: " << getExpectedFalsePositiveRate() << std::endl;
			std::cout << "内存使用: " << (BitSize / 8) << " 字节 (" << (BitSize / 8.0 / 1024 / 1024) << " MB)" << std::endl;
		}
	};

	/**
	 * @brief 计数布隆过滤器实现
	 *
	 * 计数布隆过滤器使用计数器数组替代传统布隆过滤器的位图，支持删除操作。
	 * 特点：
	 * - 支持插入、删除、查询操作
	 * - 使用计数器而非位图，每个位置存储计数值
	 * - 插入时计数器+1，删除时计数器-1
	 * - 查询时检查所有对应位置计数器是否都>0
	 * - 内存占用比传统布隆过滤器大（每个位置需要存储计数值）
	 */
	template <size_t ArraySize = 1024 * 128, // 默认128K个计数器
			  class K = std::string,
			  class Hash1 = BKDRHash,
			  class Hash2 = APHash,
			  class Hash3 = DJBHash,
			  typename CounterType = uint16_t> // 计数器类型，默认16位无符号整数
	class CountingBloomFilter
	{
	private:
		std::vector<CounterType> _counters; // 计数器数组
		size_t _hash_count;					// 哈希函数个数
		size_t _element_count;				// 当前元素个数
		Hash1 _hasher1;						// 第一个哈希函数对象
		Hash2 _hasher2;						// 第二个哈希函数对象
		Hash3 _hasher3;						// 第三个哈希函数对象

		// constexpr : 表示这是一个编译时常量，值在编译时就确定了
		// numeric_limits<CounterType>::max() 返回指定数值类型能表示的最大值
		static constexpr CounterType MAX_COUNTER = std::numeric_limits<CounterType>::max();

	public:
		/**
		 * @brief 构造函数
		 * @param hash_count 哈希函数个数，默认为3
		 */
		explicit CountingBloomFilter(size_t hash_count = 3)
			: _counters(ArraySize, 0), _hash_count(hash_count), _element_count(0),
			  _hasher1(), _hasher2(), _hasher3()
		{
			if (_hash_count == 0)
			{
				_hash_count = 1;
			}
			std::cout << "计数布隆过滤器初始化完成：" << std::endl;
			std::cout << "  计数器数组大小: " << ArraySize << " 个" << std::endl;
			std::cout << "  哈希函数个数: " << _hash_count << std::endl;
			std::cout << "  计数器类型大小: " << sizeof(CounterType) << " 字节" << std::endl;
			std::cout << "  最大计数值: " << static_cast<size_t>(MAX_COUNTER) << std::endl;
			std::cout << "  内存使用: " << (ArraySize * sizeof(CounterType) / 1024.0 / 1024.0) << " MB" << std::endl;
		}

		/**
		 * @brief 获取键的哈希值数组
		 * @param key 要计算哈希值的键
		 * @return 哈希值数组
		 */
		std::vector<size_t> getHashValues(const K &key) const
		{
			std::vector<size_t> hash_values;

			// 直接使用具体的哈希函数
			if (_hash_count >= 1)
			{
				hash_values.push_back(_hasher1(key) % ArraySize);
			}
			if (_hash_count >= 2)
			{
				hash_values.push_back(_hasher2(key) % ArraySize);
			}
			if (_hash_count >= 3)
			{
				hash_values.push_back(_hasher3(key) % ArraySize);
			}

			// 如果需要更多哈希函数，通过组合现有哈希函数实现
			for (size_t i = 3; i < _hash_count; ++i)
			{
				size_t base_hash = hash_values[i % 3];
				size_t combined_hash = (base_hash + i * 17) % ArraySize;
				hash_values.push_back(combined_hash);
			}

			return hash_values;
		}

		/**
		 * @brief 向计数布隆过滤器中插入元素
		 * @param key 要插入的键
		 * @return true表示插入成功，false表示计数器溢出
		 */
		bool insert(const K &key)
		{
			std::vector<size_t> hash_values = getHashValues(key);

			// 检查是否会导致计数器溢出
			for (size_t hash_val : hash_values)
			{
				if (_counters[hash_val] >= MAX_COUNTER)
				{
					std::cout << "警告：计数器溢出，无法插入元素！位置: " << hash_val << std::endl;
					return false;
				}
			}

			// 所有计数器都可以安全递增，执行插入
			for (size_t hash_val : hash_values)
			{
				_counters[hash_val]++;
			}

			_element_count++;
			return true;
		}

		/**
		 * @brief 从计数布隆过滤器中删除元素
		 * @param key 要删除的键
		 * @return true表示删除成功，false表示元素不存在或计数器已为0
		 */
		bool remove(const K &key)
		{
			std::vector<size_t> hash_values = getHashValues(key);

			// 首先检查元素是否存在
			if (!test(key))
			{
				return false; // 元素不存在，无法删除
			}

			// 检查是否所有计数器都大于0
			for (size_t hash_val : hash_values)
			{
				if (_counters[hash_val] == 0)
				{
					std::cout << "警告：尝试删除不存在的元素或计数器异常！位置: " << hash_val << std::endl;
					return false;
				}
			}

			// 所有计数器都可以安全递减，执行删除
			for (size_t hash_val : hash_values)
			{
				_counters[hash_val]--;
			}

			if (_element_count > 0)
			{
				_element_count--;
			}
			return true;
		}

		/**
		 * @brief 测试元素是否在计数布隆过滤器中
		 * @param key 要测试的键
		 * @return true表示可能存在，false表示一定不存在
		 */
		bool test(const K &key) const
		{
			std::vector<size_t> hash_values = getHashValues(key);

			for (size_t hash_val : hash_values)
			{
				if (_counters[hash_val] == 0)
				{
					return false;
				}
			}

			return true;
		}

		/**
		 * @brief 清空计数布隆过滤器
		 */
		void clear()
		{
			std::fill(_counters.begin(), _counters.end(), 0);
			_element_count = 0;
		}

		/**
		 * @brief 获取已插入元素个数（估计值）
		 */
		size_t size() const
		{
			return _element_count;
		}

		/**
		 * @brief 获取非零计数器的个数
		 */
		size_t getNonZeroCounters() const
		{
			size_t count = 0;
			for (const auto &counter : _counters)
			{
				if (counter > 0)
				{
					count++;
				}
			}
			return count;
		}

		/**
		 * @brief 获取计数器数组大小
		 */
		size_t getArraySize() const
		{
			return ArraySize;
		}

		/**
		 * @brief 获取哈希函数个数
		 */
		size_t getHashCount() const
		{
			return _hash_count;
		}

		/**
		 * @brief 获取指定键的计数器值
		 * @param key 要查询的键
		 * @return 所有对应位置的计数器值
		 */
		std::vector<CounterType> getCounterValues(const K &key) const
		{
			std::vector<size_t> hash_values = getHashValues(key);
			std::vector<CounterType> counter_values;

			for (size_t hash_val : hash_values)
			{
				counter_values.push_back(_counters[hash_val]);
			}

			return counter_values;
		}

		/**
		 * @brief 打印指定键的哈希值和计数器状态
		 * @param key 要打印信息的键
		 */
		void printKeyInfo(const K &key) const
		{
			std::vector<size_t> hash_values = getHashValues(key);
			std::cout << "键 '" << key << "' 的信息:\n";
			for (size_t i = 0; i < hash_values.size(); ++i)
			{
				std::cout << "  哈希函数 " << (i + 1) << ": 位置=" << hash_values[i]
						  << ", 计数值=" << static_cast<size_t>(_counters[hash_values[i]]) << "\n";
			}
			std::cout << "  存在性: " << (test(key) ? "可能存在" : "一定不存在") << "\n";
			std::cout << std::endl;
		}

		/**
		 * @brief 计算当前的误判率（估算）
		 */
		double getCurrentFalsePositiveRate() const
		{
			if (_element_count == 0)
				return 0.0;

			// 计算非零计数器的比例
			double non_zero_ratio = static_cast<double>(getNonZeroCounters()) / ArraySize;

			// 误判率近似为 non_zero_ratio^k
			return std::pow(non_zero_ratio, static_cast<double>(_hash_count));
		}

		/**
		 * @brief 打印统计信息
		 */
		void printStatistics() const
		{
			std::cout << "=== 计数布隆过滤器统计信息 ===" << std::endl;
			std::cout << "计数器数组大小: " << ArraySize << " 个" << std::endl;
			std::cout << "哈希函数个数: " << _hash_count << std::endl;
			std::cout << "已插入元素个数: " << _element_count << std::endl;
			std::cout << "非零计数器个数: " << getNonZeroCounters() << std::endl;
			std::cout << "计数器使用率: " << (getNonZeroCounters() * 100.0 / ArraySize) << "%" << std::endl;
			std::cout << "当前误判率估算: " << getCurrentFalsePositiveRate() << std::endl;
			std::cout << "内存使用: " << (ArraySize * sizeof(CounterType)) << " 字节 ("
					  << (ArraySize * sizeof(CounterType) / 1024.0 / 1024.0) << " MB)" << std::endl;

			// 计数器分布统计
			std::map<CounterType, size_t> counter_distribution;
			for (const auto &counter : _counters)
			{
				counter_distribution[counter]++;
			}

			std::cout << "计数器值分布:" << std::endl;
			for (const auto &pair : counter_distribution)
			{
				if (pair.second > 0)
				{
					std::cout << "  计数值 " << static_cast<size_t>(pair.first)
							  << ": " << pair.second << " 个 ("
							  << (pair.second * 100.0 / ArraySize) << "%)" << std::endl;
				}
			}
		}
	};

	// 类型别名，方便使用
	using StringBloomFilter = BloomFilter<1024 * 1024, std::string>; // 字符串布隆过滤器
	using IntBloomFilter = BloomFilter<1024 * 1024, int>;			 // 整数布隆过滤器
	using SmallBloomFilter = BloomFilter<1024>;						 // 1KB，适合小规模测试
	using MediumBloomFilter = BloomFilter<1024 * 1024>;				 // 1MB，适合中等规模应用
	using LargeBloomFilter = BloomFilter<8 * 1024 * 1024>;			 // 8MB，适合大规模应用

	// 计数布隆过滤器类型别名
	using StringCountingBloomFilter = CountingBloomFilter<1024 * 128, std::string>; // 字符串计数布隆过滤器
	using IntCountingBloomFilter = CountingBloomFilter<1024 * 128, int>;			// 整数计数布隆过滤器
	using SmallCountingBloomFilter = CountingBloomFilter<1024>;						// 小型计数布隆过滤器
	using LargeCountingBloomFilter = CountingBloomFilter<1024 * 512>;				// 大型计数布隆过滤器

	/**
	 * @brief 测试布隆过滤器功能
	 */
	void test_bloom_filter()
	{
		std::cout << "==================== 布隆过滤器测试 ====================" << std::endl;

		// 测试1: 基础功能测试
		std::cout << "\n【测试1: 基础功能测试】" << std::endl;
		SmallBloomFilter bf(3); // 使用3个哈希函数

		// 插入一些元素
		std::vector<std::string> insert_data = {
			"apple", "banana", "cherry", "date", "elderberry",
			"fig", "grape", "honeydew", "kiwi", "lemon"};

		std::cout << "插入元素: ";
		for (const auto &item : insert_data)
		{
			bf.insert(item);
			std::cout << item << " ";
		}
		std::cout << std::endl;

		// 测试存在的元素
		std::cout << "\n检查已插入的元素:" << std::endl;
		for (const auto &item : insert_data)
		{
			bool exists = bf.test(item);
			std::cout << "  " << item << ": " << (exists ? "可能存在 ✓" : "不存在 ✗") << std::endl;
		}

		// 测试不存在的元素
		std::cout << "\n检查未插入的元素:" << std::endl;
		std::vector<std::string> test_data = {
			"orange", "pear", "mango", "peach", "plum"};

		for (const auto &item : test_data)
		{
			bool exists = bf.test(item);
			std::cout << "  " << item << ": " << (exists ? "可能存在（误判）" : "不存在 ✓") << std::endl;
		}

		// 测试2: 误判率测试
		std::cout << "\n【测试2: 误判率测试】" << std::endl;
		MediumBloomFilter large_bf(5); // 使用5个哈希函数

		// 插入大量数据
		std::cout << "插入1000个元素..." << std::endl;
		for (int i = 0; i < 1000; ++i)
		{
			large_bf.insert("element_" + std::to_string(i));
		}

		// 测试误判率
		int false_positives = 0;
		int test_count = 1000;

		std::cout << "测试" << test_count << "个不存在的元素..." << std::endl;
		for (int i = 1000; i < 1000 + test_count; ++i)
		{
			if (large_bf.test("element_" + std::to_string(i)))
			{
				false_positives++;
			}
		}

		double actual_fpr = static_cast<double>(false_positives) / test_count;
		std::cout << "实际误判个数: " << false_positives << "/" << test_count << std::endl;
		std::cout << "实际误判率: " << actual_fpr << std::endl;
		std::cout << "理论误判率: " << large_bf.getCurrentFalsePositiveRate() << std::endl;

		// 测试3: 整数类型布隆过滤器测试
		std::cout << "\n【测试3: 整数类型布隆过滤器测试】" << std::endl;
		IntBloomFilter int_bf(4);

		// 插入整数
		std::vector<int> int_data = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
		std::cout << "插入整数: ";
		for (int num : int_data)
		{
			int_bf.insert(num);
			std::cout << num << " ";
		}
		std::cout << std::endl;

		// 测试存在的整数
		std::cout << "\n检查已插入的整数:" << std::endl;
		for (int num : int_data)
		{
			bool exists = int_bf.test(num);
			std::cout << "  " << num << ": " << (exists ? "可能存在 ✓" : "不存在 ✗") << std::endl;
		}

		// 测试不存在的整数
		std::cout << "\n检查未插入的整数:" << std::endl;
		std::vector<int> test_int_data = {4, 6, 7, 9, 10};
		for (int num : test_int_data)
		{
			bool exists = int_bf.test(num);
			std::cout << "  " << num << ": " << (exists ? "可能存在（误判）" : "不存在 ✓") << std::endl;
		}

		// 测试4: 性能和统计信息
		std::cout << "\n【测试3: 统计信息】" << std::endl;
		large_bf.printStatistics();

		// 测试4: 清空功能
		std::cout << "\n【测试4: 清空功能测试】" << std::endl;
		std::cout << "清空前元素个数: " << large_bf.size() << std::endl;
		std::cout << "清空前设置位数: " << large_bf.getBitCount() << std::endl;

		large_bf.clear();

		std::cout << "清空后元素个数: " << large_bf.size() << std::endl;
		std::cout << "清空后设置位数: " << large_bf.getBitCount() << std::endl;
		std::cout << "清空后检查'element_0': " << (large_bf.test("element_0") ? "存在" : "不存在") << std::endl;

		// 测试5: 不同哈希函数个数的比较
		std::cout << "\n【测试5: 不同哈希函数个数比较】" << std::endl;
		std::vector<size_t> hash_counts = {1, 3, 5, 7};

		for (size_t k : hash_counts)
		{
			SmallBloomFilter test_bf(k);

			// 插入相同的数据
			for (const auto &item : insert_data)
			{
				test_bf.insert(item);
			}

			std::cout << "哈希函数个数 " << k << ": ";
			std::cout << "设置位数=" << test_bf.getBitCount() << ", ";
			std::cout << "使用率=" << (test_bf.getBitCount() * 100.0 / test_bf.getBitSize()) << "%, ";
			std::cout << "理论误判率=" << test_bf.getExpectedFalsePositiveRate() << std::endl;
		}

		std::cout << "\n==================== 测试完成 ====================" << std::endl;
	}

	// 测试哈希值查看功能
	void test_hash_values()
	{
		std::cout << "\n==================== 测试哈希值查看功能 ====================\n";

		// 测试字符串布隆过滤器
		StringBloomFilter bf(3);

		// 测试几个不同的字符串
		std::vector<std::string> test_keys = {"hello", "world", "bloom", "filter", "hash"};

		for (const auto &key : test_keys)
		{
			bf.printHashValues(key);
			bf.insert(key);
			std::cout << "插入后:\n";
			bf.printHashValues(key);
			std::cout << "-------------------\n";
		}

		// 测试整数布隆过滤器
		std::cout << "\n【整数布隆过滤器哈希值测试】\n";
		IntBloomFilter int_bf(4);
		std::vector<int> test_nums = {1, 42, 100, 999, -5};

		for (int num : test_nums)
		{
			int_bf.printHashValues(num);
		}

		std::cout << "\n==================== 哈希值测试完成 ====================\n";
	}

	// 测试计数布隆过滤器的删除功能
	void test_counting_bloom_filter()
	{
		std::cout << "\n==================== 计数布隆过滤器测试 ====================\n";

		// 测试1: 基础插入和删除功能
		std::cout << "\n【测试1: 基础插入和删除功能】\n";
		SmallCountingBloomFilter cbf(3);

		std::vector<std::string> test_data = {"apple", "banana", "cherry", "date", "elderberry"};

		// 插入元素
		std::cout << "插入元素:\n";
		for (const auto &item : test_data)
		{
			bool success = cbf.insert(item);
			std::cout << "  插入 '" << item << "': " << (success ? "成功" : "失败") << "\n";
			cbf.printKeyInfo(item);
		}

		std::cout << "插入后统计信息:\n";
		cbf.printStatistics();

		// 测试查询
		std::cout << "\n查询测试:\n";
		for (const auto &item : test_data)
		{
			bool exists = cbf.test(item);
			std::cout << "  查询 '" << item << "': " << (exists ? "存在" : "不存在") << "\n";
		}

		// 删除部分元素
		std::cout << "\n删除元素:\n";
		std::vector<std::string> to_remove = {"apple", "cherry", "elderberry"};
		for (const auto &item : to_remove)
		{
			bool success = cbf.remove(item);
			std::cout << "  删除 '" << item << "': " << (success ? "成功" : "失败") << "\n";
			cbf.printKeyInfo(item);
		}

		std::cout << "删除后统计信息:\n";
		cbf.printStatistics();

		// 再次查询
		std::cout << "\n删除后查询测试:\n";
		for (const auto &item : test_data)
		{
			bool exists = cbf.test(item);
			std::cout << "  查询 '" << item << "': " << (exists ? "存在" : "不存在") << "\n";
		}

		// 测试2: 重复插入和删除
		std::cout << "\n【测试2: 重复插入和删除测试】\n";
		SmallCountingBloomFilter cbf2(3);

		std::string test_key = "test_key";

		// 多次插入同一个元素
		std::cout << "多次插入同一元素 '" << test_key << "':\n";
		for (int i = 0; i < 5; ++i)
		{
			cbf2.insert(test_key);
			std::cout << "  第" << (i + 1) << "次插入后:\n";
			cbf2.printKeyInfo(test_key);
		}

		// 多次删除同一个元素
		std::cout << "多次删除同一元素 '" << test_key << "':\n";
		for (int i = 0; i < 7; ++i)
		{ // 尝试删除7次（超过插入次数）
			bool success = cbf2.remove(test_key);
			std::cout << "  第" << (i + 1) << "次删除: " << (success ? "成功" : "失败") << "\n";
			cbf2.printKeyInfo(test_key);
		}

		// 测试3: 哈希冲突情况下的删除
		std::cout << "\n【测试3: 哈希冲突测试】\n";
		SmallCountingBloomFilter cbf3(2); // 使用较少的哈希函数增加冲突概率

		std::vector<std::string> conflict_test = {"key1", "key2", "key3", "key4", "key5"};

		// 插入所有元素
		std::cout << "插入可能冲突的元素:\n";
		for (const auto &key : conflict_test)
		{
			cbf3.insert(key);
			cbf3.printKeyInfo(key);
		}

		std::cout << "所有元素插入后的统计信息:\n";
		cbf3.printStatistics();

		// 删除中间的元素
		std::cout << "\n删除中间元素 'key3':\n";
		cbf3.remove("key3");
		cbf3.printKeyInfo("key3");

		// 检查其他元素是否仍然存在
		std::cout << "\n检查其他元素状态:\n";
		for (const auto &key : conflict_test)
		{
			if (key != "key3")
			{
				bool exists = cbf3.test(key);
				std::cout << "  '" << key << "': " << (exists ? "仍存在" : "被误删") << "\n";
			}
		}

		// 测试4: 性能对比测试
		std::cout << "\n【测试4: 性能对比测试】\n";

		const size_t test_size = 1000;

		// 传统布隆过滤器测试
		std::cout << "传统布隆过滤器测试:\n";
		SmallBloomFilter normal_bf(3);

		auto start_time = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < test_size; ++i)
		{
			normal_bf.insert("element_" + std::to_string(i));
		}
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

		std::cout << "  插入" << test_size << "个元素耗时: " << duration.count() << " μs\n";
		std::cout << "  内存使用: " << (normal_bf.getBitSize() / 8) << " 字节\n";

		// 计数布隆过滤器测试
		std::cout << "\n计数布隆过滤器测试:\n";
		SmallCountingBloomFilter counting_bf(3);

		start_time = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < test_size; ++i)
		{
			counting_bf.insert("element_" + std::to_string(i));
		}
		end_time = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

		std::cout << "  插入" << test_size << "个元素耗时: " << duration.count() << " μs\n";
		std::cout << "  内存使用: " << (counting_bf.getArraySize() * sizeof(uint16_t)) << " 字节\n";

		// 删除测试（只有计数布隆过滤器支持）
		start_time = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < test_size / 2; ++i)
		{
			counting_bf.remove("element_" + std::to_string(i));
		}
		end_time = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

		std::cout << "  删除" << (test_size / 2) << "个元素耗时: " << duration.count() << " μs\n";

		// 验证删除效果
		size_t remaining_count = 0;
		for (size_t i = 0; i < test_size; ++i)
		{
			if (counting_bf.test("element_" + std::to_string(i)))
			{
				remaining_count++;
			}
		}
		std::cout << "  删除后剩余元素: " << remaining_count << " 个（预期约" << (test_size / 2) << "个）\n";

		std::cout << "\n最终统计信息:\n";
		counting_bf.printStatistics();

		std::cout << "\n==================== 计数布隆过滤器测试完成 ====================\n";
	}

	// 测试大量数据下布隆过滤器的误判率和效率
	void test_bloom_filter_performance()
	{
		std::cout << "\n==================== 大量数据性能测试 ====================\n";

		// 测试不同规模的数据集
		std::vector<size_t> test_sizes = {10000, 50000, 100000, 500000};
		std::vector<size_t> hash_counts = {3, 5, 7};

		for (size_t hash_count : hash_counts)
		{
			std::cout << "\n【哈希函数个数: " << hash_count << "】\n";

			for (size_t test_size : test_sizes)
			{
				std::cout << "\n--- 测试数据量: " << test_size << " ---\n";

				// 使用大容量布隆过滤器
				LargeBloomFilter bf(hash_count);

				// 记录插入时间
				auto start_time = std::chrono::high_resolution_clock::now();

				// 插入数据
				std::vector<std::string> inserted_data;
				for (size_t i = 0; i < test_size; ++i)
				{
					std::string key = "element_" + std::to_string(i);
					bf.insert(key);
					inserted_data.push_back(key);
				}

				auto insert_end = std::chrono::high_resolution_clock::now();
				auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(insert_end - start_time);

				// 测试查询时间（已插入的数据）
				auto query_start = std::chrono::high_resolution_clock::now();
				size_t true_positives = 0;
				for (const auto &key : inserted_data)
				{
					if (bf.test(key))
					{
						true_positives++;
					}
				}
				auto query_end = std::chrono::high_resolution_clock::now();
				auto query_duration = std::chrono::duration_cast<std::chrono::milliseconds>(query_end - query_start);

				// 测试误判率（完全不同的字符串）
				auto false_test_start = std::chrono::high_resolution_clock::now();
				size_t false_positives_different = 0;
				size_t test_negative_count = std::min(test_size, static_cast<size_t>(10000)); // 最多测试10000个

				for (size_t i = test_size; i < test_size + test_negative_count; ++i)
				{
					std::string key = "not_exist_" + std::to_string(i);
					if (bf.test(key))
					{
						false_positives_different++;
					}
				}
				auto false_test_end = std::chrono::high_resolution_clock::now();
				auto false_test_duration = std::chrono::duration_cast<std::chrono::milliseconds>(false_test_end - false_test_start);

				// 测试相似字符串的误判率
				auto similar_test_start = std::chrono::high_resolution_clock::now();
				size_t false_positives_similar = 0;
				std::vector<std::string> similar_data;

				// 生成相似的字符串数据集
				std::string base_url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
				for (size_t i = 0; i < test_negative_count; ++i)
				{
					// 方法1：在URL后添加不同的参数
					std::string similar_key = base_url + "?param=" + std::to_string(999999 + i);
					similar_data.push_back(similar_key);

					if (bf.test(similar_key))
					{
						false_positives_similar++;
					}
				}
				auto similar_test_end = std::chrono::high_resolution_clock::now();
				auto similar_test_duration = std::chrono::duration_cast<std::chrono::milliseconds>(similar_test_end - similar_test_start);

				// 额外测试：基于已插入数据的变体
				auto variant_test_start = std::chrono::high_resolution_clock::now();
				size_t false_positives_variant = 0;

				for (size_t i = 0; i < std::min(test_negative_count, test_size); ++i)
				{
					// 对已插入的数据进行小幅修改
					std::string original = "element_" + std::to_string(i);
					std::string variant1 = "Element_" + std::to_string(i);			 // 首字母大写
					std::string variant2 = "element_" + std::to_string(i) + "_copy"; // 添加后缀
					std::string variant3 = "elem_" + std::to_string(i);				 // 缩短前缀

					if (bf.test(variant1))
						false_positives_variant++;
					if (bf.test(variant2))
						false_positives_variant++;
					if (bf.test(variant3))
						false_positives_variant++;
				}
				auto variant_test_end = std::chrono::high_resolution_clock::now();
				auto variant_test_duration = std::chrono::duration_cast<std::chrono::milliseconds>(variant_test_end - variant_test_start);

				size_t variant_test_count = std::min(test_negative_count, test_size) * 3;

				// 计算各种误判率
				double false_positive_rate_different = static_cast<double>(false_positives_different) / test_negative_count;
				double false_positive_rate_similar = static_cast<double>(false_positives_similar) / test_negative_count;
				double false_positive_rate_variant = static_cast<double>(false_positives_variant) / variant_test_count;
				double expected_false_positive_rate = bf.getExpectedFalsePositiveRate();

				// 输出结果
				std::cout << "插入性能:\n";
				std::cout << "  插入时间: " << insert_duration.count() << " ms\n";
				std::cout << "  平均插入时间: " << (insert_duration.count() * 1000.0 / test_size) << " μs/元素\n";

				std::cout << "查询性能:\n";
				std::cout << "  查询时间: " << query_duration.count() << " ms\n";
				std::cout << "  平均查询时间: " << (query_duration.count() * 1000.0 / test_size) << " μs/元素\n";
				std::cout << "  真阳性率: " << (true_positives * 100.0 / test_size) << "%\n";

				std::cout << "误判测试:\n";
				std::cout << "  【完全不同字符串测试】\n";
				std::cout << "    测试时间: " << false_test_duration.count() << " ms\n";
				std::cout << "    测试样本数: " << test_negative_count << "\n";
				std::cout << "    误判数量: " << false_positives_different << "\n";
				std::cout << "    误判率: " << (false_positive_rate_different * 100) << "%\n";

				std::cout << "  【相似字符串测试】\n";
				std::cout << "    测试时间: " << similar_test_duration.count() << " ms\n";
				std::cout << "    测试样本数: " << test_negative_count << "\n";
				std::cout << "    误判数量: " << false_positives_similar << "\n";
				std::cout << "    误判率: " << (false_positive_rate_similar * 100) << "%\n";

				std::cout << "  【变体字符串测试】\n";
				std::cout << "    测试时间: " << variant_test_duration.count() << " ms\n";
				std::cout << "    测试样本数: " << variant_test_count << "\n";
				std::cout << "    误判数量: " << false_positives_variant << "\n";
				std::cout << "    误判率: " << (false_positive_rate_variant * 100) << "%\n";

				std::cout << "  【理论vs实际对比】\n";
				std::cout << "    理论误判率: " << (expected_false_positive_rate * 100) << "%\n";
				std::cout << "    不同字符串偏差: " << std::abs(false_positive_rate_different - expected_false_positive_rate) * 100 << "%\n";
				std::cout << "    相似字符串偏差: " << std::abs(false_positive_rate_similar - expected_false_positive_rate) * 100 << "%\n";
				std::cout << "    变体字符串偏差: " << std::abs(false_positive_rate_variant - expected_false_positive_rate) * 100 << "%\n";

				// 内存使用情况
				bf.printStatistics();

				auto total_test_time = insert_duration + query_duration + false_test_duration + similar_test_duration + variant_test_duration;
				std::cout << "总测试时间: " << total_test_time.count() << " ms\n";
				std::cout << "----------------------------------------\n";
			}
		}

		// 比较不同位图大小的性能
		std::cout << "\n【不同位图大小性能比较】\n";
		size_t fixed_test_size = 100000;
		size_t fixed_hash_count = 5;

		std::cout << "测试数据量: " << fixed_test_size << ", 哈希函数个数: " << fixed_hash_count << "\n\n";

		// 小容量布隆过滤器 (1KB)
		{
			std::cout << "--- 小容量布隆过滤器 (1KB) ---\n";
			SmallBloomFilter small_bf(fixed_hash_count);

			auto start = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < fixed_test_size; ++i)
			{
				small_bf.insert("element_" + std::to_string(i));
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			std::cout << "插入时间: " << duration.count() << " ms\n";
			small_bf.printStatistics();
		}

		// 中等容量布隆过滤器 (1MB)
		{
			std::cout << "\n--- 中等容量布隆过滤器 (1MB) ---\n";
			MediumBloomFilter medium_bf(fixed_hash_count);

			auto start = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < fixed_test_size; ++i)
			{
				medium_bf.insert("element_" + std::to_string(i));
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			std::cout << "插入时间: " << duration.count() << " ms\n";
			medium_bf.printStatistics();
		}

		// 大容量布隆过滤器 (8MB)
		{
			std::cout << "\n--- 大容量布隆过滤器 (8MB) ---\n";
			LargeBloomFilter large_bf(fixed_hash_count);

			auto start = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < fixed_test_size; ++i)
			{
				large_bf.insert("element_" + std::to_string(i));
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

			std::cout << "插入时间: " << duration.count() << " ms\n";
			large_bf.printStatistics();
		}

		std::cout << "\n==================== 性能测试完成 ====================\n";
	}
}