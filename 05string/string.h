#include <iostream>
#include <assert.h>
#include <string.h>

namespace yzq
{
	/**
	 * @class string
	 * @brief 模拟实现STL风格的字符串类，支持常见字符串操作
	 *
	 * 该类实现了动态字符串，包含构造、拷贝、赋值、析构、迭代器、
	 * 容量管理、字符操作、字符串连接、插入删除、查找比较等功能。
	 */
	class string
	{
	public:
		// ----------------------------- 类型定义 -----------------------------
		/**
		 * @brief 迭代器类型（指向字符的指针）
		 * 支持通过迭代器遍历字符串字符
		 */
		typedef char *iterator;
		/**
		 * @brief 常量迭代器类型（指向常量字符的指针）
		 * 支持通过常量迭代器遍历常量字符串字符
		 */
		typedef const char *const_iterator;
		// ----------------------------- 迭代器接口 -----------------------------
		/**
		 * @brief 返回指向字符串首字符的迭代器
		 * @return 迭代器指向第一个字符（_str）
		 */
		iterator begin()
		{
			return _str;
		}
		/**
		 * @brief 返回指向字符串末尾下一位置的迭代器（哨兵）
		 * @return 迭代器指向有效字符末尾的下一位置（_str + _size）
		 */
		iterator end()
		{
			return _str + _size;
		}
		/**
		 * @brief 返回指向常量字符串首字符的常量迭代器
		 * @return 常量迭代器指向第一个字符（_str）
		 */
		const_iterator begin() const
		{
			return _str;
		}
		/**
		 * @brief 返回指向常量字符串末尾下一位置的常量迭代器（哨兵）
		 * @return 常量迭代器指向有效字符末尾的下一位置（_str + _size）
		 */
		const_iterator end() const
		{
			return _str + _size;
		}

		// ----------------------------- 构造函数 -----------------------------
#if 0
		// 提供无参的比较冗余，不如提供一个全缺省
		string()
			:_size(0)
			,_capacity(0)
		{
			_str = new char[1];
			_str[0] = '\0';
		}
#endif
		/**
		 * @brief 构造函数（默认/带初始字符串）
		 * @param str 初始化字符串（C风格字符串，默认空字符串""）
		 * @note 初始化时分配足够空间存储str（包括终止符'\0'）
		 * ""是默认常量字符串，后面是有\0的
		 * "\0" 这样写也是ok的 只不过这样是有2个\0了
		 * '\0' 这个字符的ASCII码是0
		 */
		string(const char *str = "")
			// 初始化列表的初始化顺序和成员变量声明顺序一致
			: _size(strlen(str)), _capacity(_size)
		{
			_str = new char[_capacity + 1]; // +1是为\0开的空间
			strcpy(_str, str);
		}

		void swap(string &s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

// 传统写法的拷贝构造和赋值重载
#if 0
		// s2(s1) s1传给s，s2传给this指针
		string(const string &s)
			: _size(s._size), _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		// s1 = s3 也就是s1.operator=(&s1, s3)
		string &operator=(const string &s)
		{
			if (this != &s) // 避免自己赋值给自己
			{
				// 先开空间比较合适
				char *tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this; // 为了支持连续赋值，返回左操作数
		}
#endif

// 现代拷贝构造和赋值重载
#if 1
		/**
		 * @brief 拷贝构造函数（现代写法：通过交换实现深拷贝）
		 * @param s 待拷贝的string对象
		 * @note 初始化临时对象后交换资源，确保异常安全
		 * 		 传统写法: 拷贝构造深拷贝，老老实实去干活，该开空间就开空间，该拷贝数据就拷贝数据
		 * 		 现代写法: 一种剥削行为，安排别人去干活
		 */
		string(const string &s)
			: _str(nullptr), _size(0), _capacity(0)
		{
			// swap过去的指针是随机值，delete时可能会崩溃 因此自身的成员变量最好初始化一下
			string tmp(s._str);
			swap(tmp); // 利用自己写的swap函数
		}

		/*
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(tmp);
			}
			return *this;
		}
		*/

		/**
		 * @brief 赋值运算符重载（现代写法：值传递优化）
		 * @param s 待赋值的string对象（值传递，自动触发拷贝构造）
		 * @return 当前对象的引用（支持链式赋值）
		 * @note 通过交换临时对象资源实现高效赋值，自动处理自赋值
		 *       现代写法2 更加剥削 s3 = s1
		 * 		 s1传过来直接就是拷贝构造 拷贝构造完成深拷贝后 再直接交换
		 */
		string &operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}
#endif

		// 赋值重载现代写法1 s3 = s1

		// ----------------------------- 析构函数 -----------------------------
		/**
		 * @brief 析构函数
		 * @note 释放动态分配的内存，重置成员为安全状态
		 */
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}
		// ----------------------------- 元素访问 -----------------------------
		/**
		 * @brief 下标访问运算符（非const版本）
		 * @param pos 字符位置（0-based，范围[0, _size)）
		 * @return 对应位置字符的引用
		 * @throw assert 若pos >= _size（调试期检查）
		 */
		char &operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		/**
		 * @brief 下标访问运算符（const版本）
		 * @param pos 字符位置（0-based，范围[0, _size)）
		 * @return 对应位置字符的常量引用（不可修改）
		 * @throw assert 若pos >= _size（调试期检查）
		 * @note 提供给const对象调用的，返回的是const引用，不能修改了
		 */
		const char &operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		// ----------------------------- 容量查询 -----------------------------
		/**
		 * @brief 获取有效字符长度（不包含终止符'\0'）
		 * @return 字符串中有效字符的个数（_size）
		 * @note 函数内部不改变成员变量尽量都加上const修饰
		 * 		 普通对象可以调用，const对象也可以调用
		 * 		 其实就是size_t size(const string* this)
		 */
		//
		size_t size() const
		{
			return _size;
		}
		/**
		 * @brief 返回C风格字符串（以'\0'结尾的底层数组）
		 * @return 指向底层字符数组的常量指针
		 */
		const char *c_str() const
		{
			return _str;
		}
		/**
		 * @brief 获取底层数组容量（可存储的最大字符数，不包含终止符'\0'）
		 * @return 已分配的存储容量（_capacity）
		 */
		size_t capacity() const
		{
			return _capacity;
		}

		// ----------------------------- 容量管理 -----------------------------
		/**
		 * @brief 预留至少n个字符的存储容量（不改变有效长度）
		 * @param n 所需最小容量
		 * @note 若n > 当前容量则扩容，否则无操作；扩容后容量不小于n
		 *       扩容会导致迭代器、引用、指针失效
		 */
		void reserve(size_t n)
		{
			// 检查是否需要增加容量 reserve只扩容不缩容
			if (n > _capacity)
			{
				if (n > _capacity)
				{								 // 仅在需要时扩容
					char *tmp = new char[n + 1]; // +1用于存储'\0'
					strcpy(tmp, _str);			 // 拷贝原字符串（包括'\0'）
					delete[] _str;				 // 释放旧内存
					_str = tmp;
					_capacity = n; // 更新容量
				}
			}
		}

		/**
		 * @brief 调整字符串长度为n，超出部分用ch填充或截断
		 * @param n 目标长度
		 * @param ch 填充字符（默认'\0'）
		 * @note 分三种情况处理：
		 *       1. n < size：截断到前n个字符，添加'\0'
		 *       2. size <= n <= capacity：用ch填充到n，添加'\0'
		 *       3. n > capacity：先扩容到n，再填充ch
		 */
		void resize(size_t n, char ch = '\0')
		{
			// 1.n小于size，直接修改size并添加\0
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				// 2.n大于capacity，扩容后在末尾添加ch，注意最后放\0
				if (n > _capacity)
				{
					reserve(n);
				}
				// 3.n小于capacity且n大于size，直接挨个赋值就行
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		// ----------------------------- 字符操作 -----------------------------
		/**
		 * @brief 在字符串末尾添加单个字符
		 * @param ch 待添加的字符
		 * @note 若当前容量不足，自动扩容（通常扩容为2倍或初始4）
		 */
		void push_back(char ch)
		{
			// 满了扩容
			if (_size == _capacity)
			{
				// reserve(_capacity * 2); // 会崩溃
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			// 注意处理\0
			++_size;
			_str[_size] = '\0';
		}
		// ----------------------------- 字符串连接 -----------------------------
		/**
		 * @brief 在字符串末尾追加C风格字符串
		 * @param str 待追加的C风格字符串
		 * @note 自动计算长度并检查容量，确保有足够空间后拷贝数据
		 */
		void append(const char *str)
		{
			// 计算需要追加的字符串长度
			size_t len = strlen(str);
			// 检查当前容量是否足够，如果不足，则进行扩展
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			// 直接拷贝到后面
			strcpy(_str + _size, str);
			_size += len;
		}

#if 0
		void push_back(char ch)
		{
			insert(_size, ch);
		}
#endif
		string &operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string &operator+=(const char *str)
		{
			append(str);
			return *this;
		}
		// ----------------------------- 插入操作 -----------------------------
		/**
		 * @brief 在指定位置插入单个字符
		 * @param pos 插入位置（0-based，允许pos == size，即尾插）
		 * @param ch 待插入的字符
		 * @return 当前对象的引用（支持链式调用）
		 * @throw assert 若pos > size（调试期检查）
		 * @note 插入会导致后续字符后移，容量不足时自动扩容
		 */
		string &insert(size_t pos, char ch)
		{
			assert(pos <= _size); // =size的时候就是尾插
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
#if 0
			// 这样也行的，就是不够优雅
			size_t end = _size;
			while ((int)end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
#endif
			// 注意考虑pos为0的情况 end类型是 size_t 因此不能比较 end == pos的情况
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}

		/**
		 * 在字符串中的指定位置插入另一个字符串
		 *
		 * @param pos 插入位置的索引，必须小于等于当前字符串的长度
		 * @param str 要插入的字符串，以C风格字符串形式传入
		 * @return 返回字符串引用，支持链式调用
		 *
		 * 此函数首先检查插入位置是否有效，然后检查是否有足够的容量
		 * 如果容量不足，则增加容量接下来，它将现有字符串中的字符
		 * 向后移动以腾出空间，然后将新字符串插入到指定位置
		 */
		string &insert(size_t pos, const char *str)
		{
			// 确保插入位置是有效的
			assert(pos <= _size);

			// 开辟空间
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// "123\0" 在3的前面插入“456” “123\0   ”
			// end 指向\0 后面的位置
			size_t end = _size + 1;
			while (end > pos)
			{
				// 相当于是挪动 len 长度数据
				_str[end - 1 + len] = _str[end - 1];
				--end;
			}

			// 将str拷贝进去
			// 用strncpy也行，注意不能用strcpy，strcpy遇到\0就会停止的
			// strncpy(_str + pos, str, len);
			size_t tmp = len;
			while (tmp--)
			{
				_str[pos] = *str;
				++pos, ++str;
			}

			_size += len;
			return *this;
		}

		// ----------------------------- 删除操作 -----------------------------
		/**
		 * @brief 删除从pos开始的len个字符（默认删除到末尾）
		 * @param pos 起始删除位置（0-based，范围[0, size)）
		 * @param len 删除长度（默认npos，表示删除到末尾）
		 * @return 当前对象的引用（支持链式调用）
		 * @throw assert 若pos >= size（调试期检查）
		 * @note npos定义为size_t(-1)，表示最大无符号整数值
		 */
		string &erase(size_t pos, size_t len = npos)
		{
			// 确保擦除位置pos在字符串长度范围内
			assert(pos < _size);

			// 如果len为npos或超出剩余字符串长度，将pos位置的字符设为'\0'，并更新_size
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				// 如果len指定的长度小于剩余字符串长度，将pos+len位置及其之后的字符向前移动len个位置
				// begin=_size表示要把\0也挪过去
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					++begin;
				}
				// 更新字符串大小，减去擦除的长度
				_size -= len;
			}

			// 支持链式调用，返回字符串本身
			return *this;
		}

		// ----------------------------- 查找操作 -----------------------------
		/**
		 * @brief 查找单个字符首次出现的位置
		 * @param ch 待查找的字符
		 * @param pos 起始查找位置（0-based，默认0）
		 * @return 字符首次出现的位置，若未找到返回npos
		 */
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			// 找不到
			return npos;
		}

		/**
		 * @brief 查找C风格字符串首次出现的位置
		 * @param str 待查找的C风格字符串
		 * @param pos 起始查找位置（0-based，默认0）
		 * @return 子串首次出现的位置，若未找到返回npos
		 * @note 使用C库函数strstr进行查找，返回指针偏移量
		 */
		size_t find(const char *str, size_t pos = 0)
		{
			const char *p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				// 指针相减返回的才是需要的下标
				return p - _str;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			// 边界检查：如果起始位置超过字符串长度，抛出异常
			if (pos > _size)
			{
				throw std::out_of_range("string::substr: pos exceeds string size");
			}
			string s;
			size_t end = pos + len;
			// 超过了，有多少就取多少
			if (len == npos || len + pos >= _size)
			{
				len = _size - pos;
				end = _size;
			}
			s.reserve(len);
			for (size_t i = pos; i < end; ++i)
			{
				s += _str[i];
			}
			return s;
		}
		/**
		 * @brief 清空字符串（有效长度置0，保留'\0'）
		 * @note 不释放内存，仅重置有效长度和终止符
		 */
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char *_str;		  ///< 底层字符数组（以'\0'结尾）
		size_t _size;	  ///< 有效字符个数（不包含'\0'）
		size_t _capacity; ///< 底层数组容量（不包含'\0'，>= _size）
	public:
		static const size_t npos; ///< 表示不存在的位置（定义为size_t(-1)）
	};

	// 静态成员变量类内声明，类外定义
	const size_t string::npos = -1;

	// ----------------------------- 全局运算符重载 -----------------------------
	/**
	 * @brief 流插入运算符（支持输出string对象）
	 * @param out 输出流对象
	 * @param s 待输出的string对象
	 * @return 输出流对象引用（支持链式调用）
	 * @note 遍历字符串字符逐个输出，避免直接输出c_str()导致提前终止
	 */
	// 注意，流插入流提取不是必须要写成友元的，除非是要访问私有成员变量
	std::ostream &operator<<(std::ostream &out, const string &s)
	{
		// out << s.c_str() << endl; // 这种不行，无法体现\0的存在
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	/**
	 * @brief 流提取运算符（支持输入string对象，遇空格/换行终止）
	 * @param in 输入流对象
	 * @param s 待输入的string对象
	 * @return 输入流对象引用（支持链式调用）
	 * @note 使用缓冲区优化输入，减少频繁扩容带来的性能开销
	 */
	std::istream &operator>>(std::istream &in, string &s)
	{
		/*
		char ch;
		//in >> ch; // cin是获取不了空格或者换行符的，因此会死循环
		ch = in.get(); // 一个一个去缓冲区获取字符
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
		*/

		// 频繁+=，会频繁扩容降低效率 利用buff优化一下

		s.clear();
		char ch;
		ch = in.get(); // 一个一个去缓冲区获取字符
		char buff[128] = {'\0'};
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				s += buff;
				memset(buff, '\0', 128);
				i = 0;
			}
			ch = in.get();
		}
		// 继续加上未填满的buff
		s += buff;
		return in;
	}
	/**
	 * @brief 读取整行输入（遇换行终止，保留换行符前的内容）
	 * @param in 输入流对象
	 * @param s 待输入的string对象
	 * @return 输入流对象引用（支持链式调用）
	 * @note 行为类似std::getline，处理换行符但不包含在结果中
	 */
	std::istream &getline(std::istream &in, string &s)
	{
		// 其实和operator>>类似，只是遇到空格不结束罢了
		s.clear();
		char ch;
		ch = in.get(); // 一个一个去缓冲区获取字符
		char buff[128] = {'\0'};
		size_t i = 0;
		while (ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				s += buff;
				memset(buff, '\0', 128);
				i = 0;
			}
			ch = in.get();
		}
		// 继续加上未填满的buff
		s += buff;
		return in;
	}
	// ----------------------------- 关系运算符重载 -----------------------------
	/**
	 * @brief 小于比较运算符（基于C库strcmp函数）
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true若s1按字典序小于s2，否则false
	 */
	// 直接调用c库里面的字符串比较函数来比，利用c_str写成全局函数
	bool operator<(const string &s1, const string &s2)
	{
		// strcmp 返回值小于0表示的就是s1 < s2
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	/**
	 * @brief 等于比较运算符（基于C库strcmp函数）
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true 若s1与s2的字符序列完全相同（长度和内容均一致），否则false
	 * @note 通过strcmp比较底层C风格字符串，返回值为0时表示相等
	 */
	bool operator==(const string &s1, const string &s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	/**
	 * @brief 小于等于比较运算符
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true 若s1按字典序小于s2，或s1与s2相等，否则false
	 * @note 等价于逻辑表达式 `(s1 < s2) || (s1 == s2)`，基于strcmp的组合判断
	 */
	bool operator<=(const string &s1, const string &s2)
	{
		return s1 < s2 || s1 == s2;
	}

	/**
	 * @brief 大于比较运算符
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true 若s1按字典序严格大于s2，否则false
	 * @note 等价于逻辑非表达式 `!(s1 <= s2)`，即当s1不小于等于s2时返回true
	 */
	bool operator>(const string &s1, const string &s2)
	{
		return !(s1 <= s2);
	}

	/**
	 * @brief 大于等于比较运算符
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true 若s1按字典序大于或等于s2，否则false
	 * @note 等价于逻辑非表达式 `!(s1 < s2)`，即当s1不小于s2时返回true
	 */
	bool operator>=(const string &s1, const string &s2)
	{
		return !(s1 < s2);
	}

	/**
	 * @brief 不等于比较运算符
	 * @param s1 左操作数string对象
	 * @param s2 右操作数string对象
	 * @return true 若s1与s2的字符序列不同（长度或内容至少有一项不同），否则false
	 * @note 等价于逻辑非表达式 `!(s1 == s2)`，即当s1和s2不相等时返回true
	 */
	bool operator!=(const string &s1, const string &s2)
	{
		return !(s1 == s2);
	}
}
