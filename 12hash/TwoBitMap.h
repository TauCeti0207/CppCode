#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <climits>
#include <bitset>
#include "BitSet.h"

namespace HashBucketForMapSet
{
	/**
	 * @brief 双位图类，用于解决大数据去重问题
	 *
	 * 问题描述：一个文件有100亿个int，只有1G内存，找到次数不超过2次的所有整数
	 *
	 * 解决方案：使用2个位图表示每个数字的出现次数
	 * 状态编码：
	 * - 00: 出现0次（初始状态）
	 * - 01: 出现1次
	 * - 10: 出现2次
	 * - 11: 出现2次及以上（超过2次）
	 *
	 * 内存分析：
	 * - int范围：-2^31 到 2^31-1，约43亿个数字
	 * - 需要2个bit位表示状态，总共需要：43亿 * 2 / 8 = 约1GB内存
	 * - 正好符合1G内存限制
	 */
	template <size_t N>
	class TwoBitMap
	{
	private:
		std::bitset<N> _bit1; // 第一个位图
		std::bitset<N> _bit2; // 第二个位图

		/**
		 * @brief 将int值映射到位图索引
		 * @param value 输入的int值（可能为负数）
		 * @return 映射后的无符号索引
		 */
		size_t mapToIndex(int value) const
		{
			// 将int值映射到[0, N-1]范围内
			// 对于测试，使用简单的模运算
			if (N >= 4294967296ULL) {
				// 完整范围：将int范围[-2^31, 2^31-1]映射到[0, 2^32-1]
				return static_cast<size_t>(static_cast<unsigned int>(value));
			} else {
				// 测试范围：使用哈希函数映射到较小范围
				unsigned int uval = static_cast<unsigned int>(value);
				return static_cast<size_t>(uval % N);
			}
		}

	public:
		/**
		 * @brief 构造函数，初始化双位图
		 */
		TwoBitMap()
		{
			// 位图默认初始化为全0，表示所有数字出现0次
		}

		/**
		 * @brief 更新数字的出现次数
		 * @param value 要更新的数字
		 *
		 * 状态转换逻辑：
		 * 00 -> 01 (0次 -> 1次)
		 * 01 -> 10 (1次 -> 2次)
		 * 10 -> 11 (2次 -> 2次以上)
		 * 11 -> 11 (保持2次以上)
		 */
		void insert(int value)
		{
			size_t index = mapToIndex(value);

			// 获取当前状态
			bool bit1 = _bit1.test(index);
			bool bit2 = _bit2.test(index);

			// 状态转换 检查当前是否为00
			if (!bit1 && !bit2) // 00 -> 01
			{
				_bit2.set(index); // 设置bit2为1
			}
			else if (!bit1 && bit2) // 01 -> 10
			{
				_bit1.set(index);	// 设置bit1为1
				_bit2.reset(index); // 重置bit2为0
			}
			else if (bit1 && !bit2) // 10 -> 11
			{
				_bit2.set(index); // 设置bit2为1
			}
			// 11 -> 11 (无需操作)
		}

		/**
		 * @brief 获取数字的出现次数状态
		 * @param value 要查询的数字
		 * @return 出现次数：0, 1, 2, 或 3(表示2次以上)
		 */
		int getCount(int value) const
		{
			size_t index = mapToIndex(value);

			bool bit1 = _bit1.test(index);
			bool bit2 = _bit2.test(index);

			if (!bit1 && !bit2)
				return 0; // 00: 0次
			else if (!bit1 && bit2)
				return 1; // 01: 1次
			else if (bit1 && !bit2)
				return 2; // 10: 2次
			else
				return 3; // 11: 2次以上
		}

		/**
		 * @brief 检查数字是否出现次数不超过2次
		 * @param value 要检查的数字
		 * @return true表示出现次数≤2次，false表示出现次数>2次
		 */
		bool isCountLessOrEqualTwo(int value) const
		{
			return getCount(value) <= 2;
		}

		/**
		 * @brief 检查数字是否出现次数恰好为1次或2次
		 * @param value 要检查的数字
		 * @return true表示出现1次或2次，false表示出现0次或超过2次
		 */
		bool isCountOneOrTwo(int value) const
		{
			int count = getCount(value);
			return count == 1 || count == 2;
		}

		/**
		 * @brief 获取位图的内存使用情况
		 * @return 内存使用量（字节）
		 */
		size_t getMemoryUsage() const
		{
			return (N * 2) / 8; // 2个bit位，除以8转换为字节
		}

		/**
		 * @brief 打印统计信息
		 */
		void printStatistics() const
		{
			std::cout << "=== TwoBitMap 统计信息 ===" << std::endl;
			std::cout << "支持的数字范围: " << INT_MIN << " 到 " << INT_MAX << std::endl;
			std::cout << "位图大小: " << N << " 位" << std::endl;
			std::cout << "内存使用: " << getMemoryUsage() << " 字节 ("
					  << getMemoryUsage() / (1024.0 * 1024.0) << " MB)" << std::endl;
		}
	};

	// 为32位int范围定义的双位图类型（实际应用中使用完整范围）
	// 2^32 = 4,294,967,296 个可能的值
	// 注意：完整范围需要约1GB内存，这里使用较小范围用于测试
	using IntTwoBitMap = TwoBitMap<1000000>;  // 测试用，支持100万个数字
	// using IntTwoBitMap = TwoBitMap<4294967296ULL>;  // 生产环境使用完整范围

	/**
	 * @brief 处理大文件中的整数，找出出现次数不超过2次的数字
	 * @param filename 输入文件名
	 * @param outputFilename 输出文件名
	 * @return 处理的数字总数
	 */
	size_t processLargeFile(const std::string &filename, const std::string &outputFilename)
	{
		std::cout << "开始处理大文件: " << filename << std::endl;

		IntTwoBitMap twoBitMap;
		twoBitMap.printStatistics();

		// 第一遍扫描：统计每个数字的出现次数
		std::ifstream inputFile(filename, std::ios::binary);
		if (!inputFile.is_open())
		{
			std::cerr << "无法打开输入文件: " << filename << std::endl;
			return 0;
		}

		int value;
		size_t totalCount = 0;
		size_t processedCount = 0;

		std::cout << "第一遍扫描：统计出现次数..." << std::endl;
		while (inputFile.read(reinterpret_cast<char *>(&value), sizeof(int)))
		{
			twoBitMap.insert(value);
			totalCount++;

			// 每处理1000万个数字输出一次进度
			if (++processedCount % 10000000 == 0)
			{
				std::cout << "已处理: " << processedCount << " 个数字" << std::endl;
			}
		}
		inputFile.close();

		std::cout << "第一遍扫描完成，总共处理了 " << totalCount << " 个数字" << std::endl;

		// 第二遍扫描：输出出现次数不超过2次的数字
		inputFile.open(filename, std::ios::binary);
		if (!inputFile.is_open())
		{
			std::cerr << "无法重新打开输入文件: " << filename << std::endl;
			return totalCount;
		}

		std::ofstream outputFile(outputFilename);
		if (!outputFile.is_open())
		{
			std::cerr << "无法创建输出文件: " << outputFilename << std::endl;
			inputFile.close();
			return totalCount;
		}

		processedCount = 0;
		size_t outputCount = 0;

		std::cout << "第二遍扫描：输出符合条件的数字..." << std::endl;
		while (inputFile.read(reinterpret_cast<char *>(&value), sizeof(int)))
		{
			if (twoBitMap.isCountLessOrEqualTwo(value))
			{
				outputFile << value << std::endl;
				outputCount++;
			}

			// 每处理1000万个数字输出一次进度
			if (++processedCount % 10000000 == 0)
			{
				std::cout << "已处理: " << processedCount << " 个数字，输出: " << outputCount << " 个" << std::endl;
			}
		}

		inputFile.close();
		outputFile.close();

		std::cout << "处理完成！" << std::endl;
		std::cout << "输入数字总数: " << totalCount << std::endl;
		std::cout << "符合条件的数字数量: " << outputCount << std::endl;
		std::cout << "结果已保存到: " << outputFilename << std::endl;

		return totalCount;
	}

	/**
	 * @brief 测试双位图算法的正确性
	 */
	void test_two_bit_map()
	{
		std::cout << "==================== TwoBitMap 算法测试 ====================" << std::endl;

		// 测试1: 基础功能测试
		std::cout << "\n【测试1: 基础功能测试】" << std::endl;
		TwoBitMap<1000> tbm;

		// 测试状态转换
		std::cout << "初始状态 - 数字42出现次数: " << tbm.getCount(42) << std::endl;

		tbm.insert(42);
		std::cout << "插入1次后 - 数字42出现次数: " << tbm.getCount(42) << std::endl;

		tbm.insert(42);
		std::cout << "插入2次后 - 数字42出现次数: " << tbm.getCount(42) << std::endl;

		tbm.insert(42);
		std::cout << "插入3次后 - 数字42出现次数: " << tbm.getCount(42) << " (应该是3，表示超过2次)" << std::endl;

		tbm.insert(42);
		std::cout << "插入4次后 - 数字42出现次数: " << tbm.getCount(42) << " (应该保持3)" << std::endl;

		// 测试2: 边界值测试
		std::cout << "\n【测试2: 边界值测试】" << std::endl;
		TwoBitMap<10000> bigTbm; // 使用较小范围进行测试

		// 测试极值
		int testValues[] = {INT_MIN, INT_MIN + 1, -1, 0, 1, INT_MAX - 1, INT_MAX};

		for (int val : testValues)
		{
			bigTbm.insert(val);
			bigTbm.insert(val); // 插入2次
			std::cout << "数字 " << val << " 出现次数: " << bigTbm.getCount(val) << std::endl;
		}

		// 测试3: 查询函数测试
		std::cout << "\n【测试3: 查询函数测试】" << std::endl;
		TwoBitMap<100> smallTbm;

		// 设置不同的出现次数
		smallTbm.insert(10); // 1次
		smallTbm.insert(20); // 2次
		smallTbm.insert(20);
		smallTbm.insert(30); // 3次
		smallTbm.insert(30);
		smallTbm.insert(30);

		std::cout << "数字5 (0次) - isCountLessOrEqualTwo: " << smallTbm.isCountLessOrEqualTwo(5) << std::endl;
		std::cout << "数字10 (1次) - isCountLessOrEqualTwo: " << smallTbm.isCountLessOrEqualTwo(10) << std::endl;
		std::cout << "数字20 (2次) - isCountLessOrEqualTwo: " << smallTbm.isCountLessOrEqualTwo(20) << std::endl;
		std::cout << "数字30 (3次) - isCountLessOrEqualTwo: " << smallTbm.isCountLessOrEqualTwo(30) << std::endl;

		std::cout << "数字5 (0次) - isCountOneOrTwo: " << smallTbm.isCountOneOrTwo(5) << std::endl;
		std::cout << "数字10 (1次) - isCountOneOrTwo: " << smallTbm.isCountOneOrTwo(10) << std::endl;
		std::cout << "数字20 (2次) - isCountOneOrTwo: " << smallTbm.isCountOneOrTwo(20) << std::endl;
		std::cout << "数字30 (3次) - isCountOneOrTwo: " << smallTbm.isCountOneOrTwo(30) << std::endl;

		// 测试4: 内存使用测试
		std::cout << "\n【测试4: 内存使用测试】" << std::endl;
		bigTbm.printStatistics();

		// 测试5: 小规模完整流程测试
		std::cout << "\n【测试5: 小规模完整流程测试】" << std::endl;

		// 创建测试数据
		std::vector<int> testData = {1, 2, 3, 1, 2, 4, 5, 1, 6, 7, 8, 2, 9, 10};
		std::cout << "测试数据: ";
		for (int val : testData)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;

		// 统计出现次数
		TwoBitMap<100> testTbm;
		for (int val : testData)
		{
			testTbm.insert(val);
		}

		// 输出结果
		std::cout << "各数字出现次数:" << std::endl;
		for (int i = 1; i <= 10; ++i)
		{
			int count = testTbm.getCount(i);
			if (count > 0)
			{
				std::cout << "  数字" << i << ": " << count << "次";
				if (testTbm.isCountLessOrEqualTwo(i))
				{
					std::cout << " ✓ (符合条件)";
				}
				else
				{
					std::cout << " ✗ (超过2次)";
				}
				std::cout << std::endl;
			}
		}

		std::cout << "\n符合条件的数字(出现次数≤2): ";
		for (int i = 1; i <= 10; ++i)
		{
			if (testTbm.getCount(i) > 0 && testTbm.isCountLessOrEqualTwo(i))
			{
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;

		std::cout << "\n==================== 测试完成 ====================" << std::endl;
	}

	/**
	 * @brief 生成测试文件（用于算法验证）
	 * @param filename 输出文件名
	 * @param count 生成的数字数量
	 */
	void generateTestFile(const std::string &filename, size_t count)
	{
		std::cout << "生成测试文件: " << filename << " (包含 " << count << " 个数字)" << std::endl;

		std::ofstream file(filename, std::ios::binary);
		if (!file.is_open())
		{
			std::cerr << "无法创建测试文件: " << filename << std::endl;
			return;
		}

		// 生成一些重复的数字来测试算法
		for (size_t i = 0; i < count; ++i)
		{
			int value = static_cast<int>(i % 1000); // 0-999循环
			file.write(reinterpret_cast<const char *>(&value), sizeof(int));
		}

		file.close();
		std::cout << "测试文件生成完成" << std::endl;
	}
}