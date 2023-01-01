#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace yzq
{
	class string
	{
	public:
		// string的迭代器其实就是指针
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// 提供一个const版本的迭代器，注意需要返回const char*
		// 因此需要也跟const迭代器
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//提供无参的比较冗余，不如提供一个全缺省
		//string为空时，是一个" "
		/*string()
			:_size(0)
			,_capacity(0)
		{
			_str = new char[1];
			_str[0] = '\0';
		}*/
		

		// ""是默认常量字符串，后面存在有\0
		// "\0" 这样写也是ok的 只不过这样是有2个\0了
		// '\0' 这个字符的ASCII码是0，类型不匹配
		string(const char* str = "")
			// 初始化列表的初始化顺序和成员变量声明顺序一致
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1]; // +1是为\0开的空间
			strcpy(_str, str);
		}

		
		// s2(s1) s1传给s，s2传给this指针
		// 注意避免多次调用strlen，O(N)的复杂度
		// 传统写法深拷贝
		/*string(const string& s)
			:_size(strlen(s._str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}*/
		

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// 传统写法的拷贝构造深拷贝，老老实实去干活，该开空间就开空间，该拷贝数据就拷贝数据
		// 现代写法：一种剥削行为，安排别人去干活
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			// 就是去利用传过来的s的_str去构造新的tmp
			// 但是tmp是个临时对象，出作用域时会销毁
			// 而swap过去的指针是随机值，delete时可能会崩溃
			// 因此自身的成员变量最好初始化一下
			string tmp(s._str);
			/*
			swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);
			*/
			// 利用自己写的swap函数
			swap(tmp);
		}

		/*
		// s1 = s3 也就是s1.operator=(&s1, s3)
		string& operator=(const string& s)
		{
			if (this != &s) // 避免自己赋值给自己
			{
				//万一开空间失败了，s1却已经被释放了
				//delete[] _str;//释放s1的空间
				//_str = nullptr;
				//_str = new char[strlen(s._str) + 1];// 开辟和s3一样大的空间
				//strcpy(_str, s._str);
				

				// 先开空间比较合适
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this; // 为了支持连续赋值，返回左操作数
		}
		*/

		// 赋值重载现代写法1 s3 = s1
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

		// 现代写法2 更加剥削 s3 = s1
		// s1传过来直接就是拷贝构造 拷贝构造完成深拷贝后 再直接交换
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		const char* c_str() const
		{
			return _str;
		}

		// 返回引用为了支持修改，也能减少拷贝
		char& operator[](size_t pos)
		{
			//assert(pos < strlen(_str));
			assert(pos < _size);
			return _str[pos];
		}

		// 提供给const对象调用的，返回的是const引用，不能修改了
		const char& operator[](size_t pos) const
		{
			assert(pos < strlen(_str));
			return _str[pos];
		}

		// 函数内部不改变成员变量尽量都加上const修饰
		// 普通对象可以调用，const对象也可以调用
		// 其实就是 size_t size(const string* this)
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		// 仅对capacity处理
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // 留一个空间给\0
				strcpy(tmp, _str);
				delete[] _str; // 清理旧空间
				_str = tmp; // 指向新空间
				_capacity = n;
			}
		}

		// resize主要用于扩空间+初始化、删除部分数据保留前n个
		// 考虑3种情况
		void resize(size_t n, char ch = '\0')
		{
			// 1.n小于size，直接修改size并添加\0
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
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

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//reserve(_capacity * 2); // 会崩溃
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			// 注意处理\0
			++_size;
			_str[_size] = '\0';
		}

		void push_back2(char ch)
		{
			insert(_size, ch);
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		// append要考虑2倍空间也可能不够的问题
		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			// 直接拷贝到后面
			strcpy(_str + _size, str);
			_size = len;

			// 也可以复用insert
			//insert(_size, str);
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);// =size的时候就是尾插
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			/* 这样也行的，就是比较挫
			size_t end = _size;
			while ((int)end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			*/
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

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				// 一次性挪动len个位置
				// _str[_size]就是\0的位置
				_str[end + len - 1] = _str[end - 1];
				--end;
			}
			// str拷贝进去
			// 用strncpy也行，注意不能用stcpy，stcpy遇到\0就会停止的
			//strncpy(_str + pos, str, len);
			size_t tmp = len;
			while (tmp--)
			{
				_str[pos] = *str;
				++pos, ++str;
			}
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			// len过长自己清楚，加上\0就行
			if (len == npos || len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					++begin;
				}
				_size -= len;
			}
			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (; pos < _size; ++pos)
			{
				if (_str[pos] == ch)
				{
					return pos;
				}
			}
			// 找不到
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			// KMP在实际中并不实用，BM用的才比较多
			const char* p = strstr(_str + pos, str);
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

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;// 有效字符个数
		size_t _capacity;// 实际存储有效字符空间
		// \0不算有效字符
		const static size_t npos;
	};

	// 静态成员变量类内声明，类外定义
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		//out << s.c_str() << endl; // 这种不行，无法体现\0的存在 遇到\0就终止了
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
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

		// 上述写法频繁+=，会频繁扩容降低效率
		// 利用buff优化一下

		s.clear();
		char ch;
		ch = in.get(); // 一个一个去缓冲区获取字符
		char buff[128] = { '\0' };
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

	istream& getline(istream& in, string& s)
	{
		//其实和operator>>类似，只是遇到空格不结束罢了
		s.clear();
		char ch;
		ch = in.get(); // 一个一个去缓冲区获取字符
		char buff[128] = { '\0' };
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

	// 直接调用c库里面的字符串比较函数来比，利用c_str写成全局函数
	bool operator<(const string& s1, const string& s2)
	{
		// strcmp 返回值小于0表示的就是s1 < s2
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
}
