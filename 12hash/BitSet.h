#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

namespace yzq
{
	/**
	 * @brief 位图类模板，用于高效存储和操作大量布尔值
	 * @tparam N 位图的最大位数
	 */
	template <size_t N>
	class bitset
	{
	public:
		/**
		 * @brief 构造函数，初始化位图
		 * 计算所需字节数：N位需要 (N/8 + 1) 个字节来存储
		 * 例如：16位需要3个字节，18位也需要3个字节
		 */
		bitset()
		{
			_bits.resize(N / 8 + 1, 0); // +1确保有足够的位存储空间
		}

		/**
		 * @brief 将指定位置的位设置为1
		 * @param x 要设置的位的索引（从0开始）
		 */
		void set(size_t x)
		{
			if (x >= N)
				return;			  // 边界检查
			size_t i = x / 8;	  // 计算在哪个字节
			size_t j = x % 8;	  // 计算在字节中的哪一位
			_bits[i] |= (1 << j); // 使用或运算设置对应位为1
		}

		/**
		 * @brief 将所有位设置为1
		 */
		void set()
		{
			for (size_t i = 0; i < _bits.size(); ++i)
			{
				_bits[i] = 0xFF; // 设置所有8位为1
			}
		}

		/**
		 * @brief 将指定位置的位设置为0
		 * @param x 要重置的位的索引
		 */
		void reset(size_t x)
		{
			if (x >= N)
				return;				 // 边界检查
			size_t i = x / 8;		 // 计算在哪个字节
			size_t j = x % 8;		 // 计算在字节中的哪一位
			_bits[i] &= (~(1 << j)); // 使用与运算和取反设置对应位为0
		}

		/**
		 * @brief 将所有位设置为0
		 */
		void reset()
		{
			for (size_t i = 0; i < _bits.size(); ++i)
			{
				_bits[i] = 0; // 清零所有位
			}
		}

		/**
		 * @brief 翻转指定位置的位（0变1，1变0）
		 * @param x 要翻转的位的索引
		 */
		void flip(size_t x)
		{
			if (x >= N)
				return;			  // 边界检查
			size_t i = x / 8;	  // 计算在哪个字节
			size_t j = x % 8;	  // 计算在字节中的哪一位
			_bits[i] ^= (1 << j); // 使用异或运算翻转对应位
		}

		/**
		 * @brief 翻转所有位
		 */
		void flip()
		{
			for (size_t i = 0; i < _bits.size(); ++i)
			{
				_bits[i] = ~_bits[i]; // 翻转所有位
			}
		}

		/**
		 * @brief 测试指定位置的位是否为1
		 * @param x 要测试的位的索引
		 * @return true表示该位为1，false表示该位为0
		 */
		bool test(size_t x) const
		{
			if (x >= N)
				return false; // 边界检查
			size_t i = x / 8; // 计算在哪个字节
			size_t j = x % 8; // 计算在字节中的哪一位
			// 使用与运算检查对应位是否为1
			// 例如：0000 1100 & 0000 0100 = 0000 0100 (非零，返回true)
			//      1111 1011 & 0000 0100 = 0000 0000 (零，返回false)
			return _bits[i] & (1 << j);
		}

		/**
		 * @brief 计算位图中设置为1的位的数量
		 * @return 值为1的位的总数
		 */
		size_t count() const
		{
			size_t cnt = 0;
			for (size_t i = 0; i < N; ++i)
			{
				if (test(i))
					++cnt;
			}
			return cnt;
		}

		/**
		 * @brief 获取位图的大小（总位数）
		 * @return 位图的大小
		 */
		size_t size() const
		{
			return N;
		}

		/**
		 * @brief 检查是否所有位都为1
		 * @return 如果所有位都为1则返回true
		 */
		bool all() const
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (!test(i))
					return false;
			}
			return true;
		}

		/**
		 * @brief 检查是否至少有一位为1
		 * @return 如果至少有一位为1则返回true
		 */
		bool any() const
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (test(i))
					return true;
			}
			return false;
		}

		/**
		 * @brief 检查是否所有位都为0
		 * @return 如果所有位都为0则返回true
		 */
		bool none() const
		{
			return !any();
		}

		/**
		 * @brief 将位图转换为字符串表示
		 * @return 位图的字符串表示，最高位在左边
		 */
		std::string to_string() const
		{
			std::string result;
			result.reserve(N);
			for (int i = N - 1; i >= 0; --i) // 从最高位开始
			{
				result += test(i) ? '1' : '0';
			}
			return result;
		}

		/**
		 * @brief 重载[]操作符，提供位的访问接口
		 * @param pos 位的索引
		 * @return 该位的值
		 */
		bool operator[](size_t pos) const
		{
			return test(pos);
		}

	private:
		std::vector<char> _bits; // 使用char数组存储位，每个char存储8位
	};

	/**
	 * @brief 完整测试bitset的所有功能
	 */
	void test_bitset_complete()
	{
		std::cout << "==================== BitSet 完整功能测试 ====================" << std::endl;

		// 测试1: 基础功能测试
		std::cout << "\n【测试1: 基础功能测试】" << std::endl;
		bitset<32> bs1;

		// 初始状态检查
		std::cout << "初始状态:" << std::endl;
		std::cout << "  大小: " << bs1.size() << std::endl;
		std::cout << "  计数: " << bs1.count() << std::endl;
		std::cout << "  是否全为0: " << (bs1.none() ? "是" : "否") << std::endl;
		std::cout << "  二进制表示: " << bs1.to_string() << std::endl;

		// 设置单个位
		bs1.set(0);
		bs1.set(5);
		bs1.set(15);
		bs1.set(31);
		std::cout << "\n设置位0,5,15,31后:" << std::endl;
		std::cout << "  计数: " << bs1.count() << std::endl;
		std::cout << "  是否有1: " << (bs1.any() ? "是" : "否") << std::endl;
		std::cout << "  二进制表示: " << bs1.to_string() << std::endl;

		// 测试单个位访问
		std::cout << "\n单个位访问测试:" << std::endl;
		std::cout << "  bs1[0] = " << bs1[0] << std::endl;
		std::cout << "  bs1[5] = " << bs1[5] << std::endl;
		std::cout << "  bs1[10] = " << bs1[10] << std::endl;
		std::cout << "  bs1.test(15) = " << bs1.test(15) << std::endl;
		std::cout << "  bs1.test(31) = " << bs1.test(31) << std::endl;

		// 测试2: 重置功能
		std::cout << "\n【测试2: 重置功能测试】" << std::endl;
		bs1.reset(5);
		bs1.reset(15);
		std::cout << "重置位5和15后:" << std::endl;
		std::cout << "  计数: " << bs1.count() << std::endl;
		std::cout << "  二进制表示: " << bs1.to_string() << std::endl;

		// 测试3: 翻转功能
		std::cout << "\n【测试3: 翻转功能测试】" << std::endl;
		bs1.flip(1);  // 翻转未设置的位
		bs1.flip(0);  // 翻转已设置的位
		bs1.flip(10); // 翻转未设置的位
		std::cout << "翻转位0,1,10后:" << std::endl;
		std::cout << "  计数: " << bs1.count() << std::endl;
		std::cout << "  二进制表示: " << bs1.to_string() << std::endl;

		// 测试4: 全局操作
		std::cout << "\n【测试4: 全局操作测试】" << std::endl;
		bitset<16> bs2;

		// 设置所有位
		bs2.set();
		std::cout << "设置所有位为1后:" << std::endl;
		std::cout << "  计数: " << bs2.count() << std::endl;
		std::cout << "  是否全为1: " << (bs2.all() ? "是" : "否") << std::endl;
		std::cout << "  二进制表示: " << bs2.to_string() << std::endl;

		// 重置所有位
		bs2.reset();
		std::cout << "\n重置所有位为0后:" << std::endl;
		std::cout << "  计数: " << bs2.count() << std::endl;
		std::cout << "  是否全为0: " << (bs2.none() ? "是" : "否") << std::endl;
		std::cout << "  二进制表示: " << bs2.to_string() << std::endl;

		// 翻转所有位
		bs2.flip();
		std::cout << "\n翻转所有位后:" << std::endl;
		std::cout << "  计数: " << bs2.count() << std::endl;
		std::cout << "  是否全为1: " << (bs2.all() ? "是" : "否") << std::endl;
		std::cout << "  二进制表示: " << bs2.to_string() << std::endl;

		// 测试5: 边界测试
		std::cout << "\n【测试5: 边界测试】" << std::endl;
		bitset<8> bs3;

		// 有效边界测试
		bs3.set(0); // 最小索引
		bs3.set(7); // 最大索引
		std::cout << "设置边界位0和7:" << std::endl;
		std::cout << "  二进制表示: " << bs3.to_string() << std::endl;
		std::cout << "  计数: " << bs3.count() << std::endl;

		// 无效边界测试（应该被安全忽略）
		std::cout << "\n无效边界测试:" << std::endl;
		size_t old_count = bs3.count();
		bs3.set(100);	// 超出范围
		bs3.reset(200); // 超出范围
		bs3.flip(300);	// 超出范围
		std::cout << "  尝试操作超出范围的位后，计数变化: " << old_count << " -> " << bs3.count() << std::endl;
		std::cout << "  test(100) = " << bs3.test(100) << " (应该返回false)" << std::endl;
		std::cout << "  二进制表示: " << bs3.to_string() << std::endl;

		// 测试6: 状态检查函数
		std::cout << "\n【测试6: 状态检查函数测试】" << std::endl;
		bitset<4> bs4;

		// 空状态
		std::cout << "空状态 (0000):" << std::endl;
		std::cout << "  all(): " << bs4.all() << " any(): " << bs4.any() << " none(): " << bs4.none() << std::endl;

		// 部分设置
		bs4.set(1);
		bs4.set(3);
		std::cout << "\n部分设置 (1010):" << std::endl;
		std::cout << "  二进制: " << bs4.to_string() << std::endl;
		std::cout << "  all(): " << bs4.all() << " any(): " << bs4.any() << " none(): " << bs4.none() << std::endl;

		// 全部设置
		bs4.set();
		std::cout << "\n全部设置 (1111):" << std::endl;
		std::cout << "  二进制: " << bs4.to_string() << std::endl;
		std::cout << "  all(): " << bs4.all() << " any(): " << bs4.any() << " none(): " << bs4.none() << std::endl;

		// 测试7: 大容量测试
		std::cout << "\n【测试7: 大容量测试】" << std::endl;
		bitset<1000> bs5;

		// 设置一些分散的位
		bs5.set(0);
		bs5.set(100);
		bs5.set(500);
		bs5.set(999);
		std::cout << "在1000位的bitset中设置位0,100,500,999:" << std::endl;
		std::cout << "  计数: " << bs5.count() << std::endl;
		std::cout << "  test(0): " << bs5.test(0) << std::endl;
		std::cout << "  test(100): " << bs5.test(100) << std::endl;
		std::cout << "  test(500): " << bs5.test(500) << std::endl;
		std::cout << "  test(999): " << bs5.test(999) << std::endl;
		std::cout << "  test(50): " << bs5.test(50) << " (未设置的位)" << std::endl;

		// 测试8: 字符串转换测试
		std::cout << "\n【测试8: 字符串转换测试】" << std::endl;
		bitset<12> bs6;
		bs6.set(0);
		bs6.set(2);
		bs6.set(4);
		bs6.set(6);
		bs6.set(8);
		bs6.set(10);
		std::cout << "设置偶数位(0,2,4,6,8,10):" << std::endl;
		std::cout << "  二进制表示: " << bs6.to_string() << std::endl;
		std::cout << "  从左到右应该是: 010101010101" << std::endl;

		// 测试9: 操作符重载测试
		std::cout << "\n【测试9: 操作符重载测试】" << std::endl;
		bitset<8> bs7;
		bs7.set(1);
		bs7.set(3);
		bs7.set(5);
		bs7.set(7);
		std::cout << "使用[]操作符访问各位:" << std::endl;
		for (size_t i = 0; i < 8; ++i)
		{
			std::cout << "  bs7[" << i << "] = " << bs7[i] << std::endl;
		}

		// 测试10: 性能和一致性测试
		std::cout << "\n【测试10: 一致性测试】" << std::endl;
		bitset<64> bs8;

		// 设置一些位
		for (size_t i = 0; i < 64; i += 3)
		{
			bs8.set(i);
		}

		std::cout << "每隔3位设置一个位:" << std::endl;
		std::cout << "  计数: " << bs8.count() << std::endl;
		std::cout << "  预期计数: " << (64 + 2) / 3 << std::endl; // 0,3,6,9...63

		// 验证test()和[]操作符的一致性
		bool consistent = true;
		for (size_t i = 0; i < 64; ++i)
		{
			if (bs8.test(i) != bs8[i])
			{
				consistent = false;
				break;
			}
		}
		std::cout << "  test()和[]操作符一致性: " << (consistent ? "通过" : "失败") << std::endl;

		// 验证状态函数的逻辑一致性
		bool logic_consistent = true;
		if (bs8.none() && bs8.any())
			logic_consistent = false;
		if (bs8.all() && bs8.none())
			logic_consistent = false;
		if (!bs8.any() && bs8.count() > 0)
			logic_consistent = false;
		if (bs8.all() && bs8.count() != bs8.size())
			logic_consistent = false;
		std::cout << "  状态函数逻辑一致性: " << (logic_consistent ? "通过" : "失败") << std::endl;

		std::cout << "\n==================== 测试完成 ====================" << std::endl;
	}

	/**
	 * @brief 简单的基础测试（保持向后兼容）
	 */
	void test_bitset1()
	{
		std::cout << "=== 基础功能快速测试 ===" << std::endl;
		bitset<1000> bs;
		bs.set(18);
		bs.set(19);
		std::cout << "设置位18,19后: " << bs.test(18) << ", " << bs.test(19) << ", " << bs.test(20) << std::endl;

		bs.reset(18);
		bs.reset(19);
		std::cout << "重置位18,19后: " << bs.test(18) << ", " << bs.test(19) << ", " << bs.test(20) << std::endl;
		std::cout << "计数: " << bs.count() << ", 大小: " << bs.size() << std::endl;
	}

	// 模板类two_bitset：使用两个bitset跟踪元素出现的次数状态
	// 模板参数N：指定bitset的大小，即能处理的最大元素值（元素x需满足x < N）
	template <size_t N>
	class two_bitset
	{
	public:
		// 成员函数set：更新元素x的出现次数状态
		// 逻辑：通过两个bitset的组合状态表示元素出现的次数
		// - 00（_bs1和_bs2均为0）：元素未出现过，第一次出现时设置为01（_bs2置1）
		// - 01（_bs1为0，_bs2为1）：元素已出现1次，再次出现时设置为10（_bs1置1，_bs2置0）
		// - 10及以上：元素出现2次及更多，状态不再变化
		void set(size_t x)
		{
			// 获取当前元素x在两个bitset中的状态
			int in1 = _bs1.test(x); // _bs1的x位状态（0或1）
			int in2 = _bs2.test(x); // _bs2的x位状态（0或1）

			// 状态00：首次出现，更新为01（_bs2置1）
			if (in1 == 0 && in2 == 0)
				_bs2.set(x); // 01：表示出现1次
			// 状态01：再次出现（第2次），更新为10（_bs1置1，_bs2置0）
			else if (in1 == 0 && in2 == 1)
			{
				_bs1.set(x);   // _bs1置1
				_bs2.reset(x); // _bs2置0，状态变为10：表示出现2次及以上
			}
			// 状态10及以上：出现次数≥2，不做处理
		}

		// 成员函数is_once：判断元素x是否只出现过一次
		// 条件：_bs1为0且_bs2为1（即状态01）
		bool is_once(size_t x)
		{
			return _bs1.test(x) == 0 && _bs2.test(x) == 1;
		}

	private:
		bitset<N> _bs1; // 辅助bitset，与_bs2配合表示状态：10表示出现≥2次
		bitset<N> _bs2; // 辅助bitset，与_bs1配合表示状态：01表示出现1次，00表示未出现
	};

	// 测试函数：验证two_bitset类的功能
	void test_two_bitset()
	{
		// 测试数组：包含多个重复元素
		int a[] = {4, 3, 2, 4, 5, 2, 2, 4, 7, 8, 9, 2, 1, 3, 7};

		std::cout << "测试数组: ";
		for (auto e : a)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		// 实例化two_bitset，大小为10（可处理0~9的元素）
		two_bitset<10> tbs;

		// 遍历数组，更新每个元素的出现状态
		for (auto e : a)
		{
			tbs.set(e);
		}

		// 遍历0~9，输出只出现过一次的元素
		std::cout << "只出现过一次的元素: ";
		for (size_t i = 0; i < 10; ++i)
		{
			if (tbs.is_once(i))
			{
				std::cout << i << " "; // 预期输出：1 5 8 9（这些元素在数组中仅出现1次）
			}
		}
		std::cout << std::endl;
	}
}