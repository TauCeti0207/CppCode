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
		// string�ĵ�������ʵ����ָ��
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

		// �ṩһ��const�汾�ĵ�������ע����Ҫ����const char*
		// �����ҪҲ��const������
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//�ṩ�޲εıȽ����࣬�����ṩһ��ȫȱʡ
		//stringΪ��ʱ����һ��" "
		/*string()
			:_size(0)
			,_capacity(0)
		{
			_str = new char[1];
			_str[0] = '\0';
		}*/
		

		// ""��Ĭ�ϳ����ַ��������������\0
		// "\0" ����дҲ��ok�� ֻ������������2��\0��
		// '\0' ����ַ���ASCII����0�����Ͳ�ƥ��
		string(const char* str = "")
			// ��ʼ���б�ĳ�ʼ��˳��ͳ�Ա��������˳��һ��
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1]; // +1��Ϊ\0���Ŀռ�
			strcpy(_str, str);
		}

		
		// s2(s1) s1����s��s2����thisָ��
		// ע������ε���strlen��O(N)�ĸ��Ӷ�
		// ��ͳд�����
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

		// ��ͳд���Ŀ����������������ʵʵȥ�ɻ�ÿ��ռ�Ϳ��ռ䣬�ÿ������ݾͿ�������
		// �ִ�д����һ�ְ�����Ϊ�����ű���ȥ�ɻ�
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			// ����ȥ���ô�������s��_strȥ�����µ�tmp
			// ����tmp�Ǹ���ʱ���󣬳�������ʱ������
			// ��swap��ȥ��ָ�������ֵ��deleteʱ���ܻ����
			// �������ĳ�Ա������ó�ʼ��һ��
			string tmp(s._str);
			/*
			swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);
			*/
			// �����Լ�д��swap����
			swap(tmp);
		}

		/*
		// s1 = s3 Ҳ����s1.operator=(&s1, s3)
		string& operator=(const string& s)
		{
			if (this != &s) // �����Լ���ֵ���Լ�
			{
				//��һ���ռ�ʧ���ˣ�s1ȴ�Ѿ����ͷ���
				//delete[] _str;//�ͷ�s1�Ŀռ�
				//_str = nullptr;
				//_str = new char[strlen(s._str) + 1];// ���ٺ�s3һ����Ŀռ�
				//strcpy(_str, s._str);
				

				// �ȿ��ռ�ȽϺ���
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this; // Ϊ��֧��������ֵ�������������
		}
		*/

		// ��ֵ�����ִ�д��1 s3 = s1
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

		// �ִ�д��2 ���Ӱ��� s3 = s1
		// s1������ֱ�Ӿ��ǿ������� ���������������� ��ֱ�ӽ���
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

		// ��������Ϊ��֧���޸ģ�Ҳ�ܼ��ٿ���
		char& operator[](size_t pos)
		{
			//assert(pos < strlen(_str));
			assert(pos < _size);
			return _str[pos];
		}

		// �ṩ��const������õģ����ص���const���ã������޸���
		const char& operator[](size_t pos) const
		{
			assert(pos < strlen(_str));
			return _str[pos];
		}

		// �����ڲ����ı��Ա��������������const����
		// ��ͨ������Ե��ã�const����Ҳ���Ե���
		// ��ʵ���� size_t size(const string* this)
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		// ����capacity����
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // ��һ���ռ��\0
				strcpy(tmp, _str);
				delete[] _str; // ����ɿռ�
				_str = tmp; // ָ���¿ռ�
				_capacity = n;
			}
		}

		// resize��Ҫ�������ռ�+��ʼ����ɾ���������ݱ���ǰn��
		// ����3�����
		void resize(size_t n, char ch = '\0')
		{
			// 1.nС��size��ֱ���޸�size�����\0
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				// 2.n����capacity�����ݺ���ĩβ���ch��ע������\0
				if (n > _capacity)
				{
					reserve(n);
				}
				// 3.nС��capacity��n����size��ֱ�Ӱ�����ֵ����
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
				//reserve(_capacity * 2); // �����
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			// ע�⴦��\0
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

		// appendҪ����2���ռ�Ҳ���ܲ���������
		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			// ֱ�ӿ���������
			strcpy(_str + _size, str);
			_size = len;

			// Ҳ���Ը���insert
			//insert(_size, str);
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);// =size��ʱ�����β��
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			/* ����Ҳ�еģ����ǱȽϴ�
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
				// һ����Ų��len��λ��
				// _str[_size]����\0��λ��
				_str[end + len - 1] = _str[end - 1];
				--end;
			}
			// str������ȥ
			// ��strncpyҲ�У�ע�ⲻ����stcpy��stcpy����\0�ͻ�ֹͣ��
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
			// len�����Լ����������\0����
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
			// �Ҳ���
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			// KMP��ʵ���в���ʵ�ã�BM�õĲűȽ϶�
			const char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				// ָ��������صĲ�����Ҫ���±�
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
		size_t _size;// ��Ч�ַ�����
		size_t _capacity;// ʵ�ʴ洢��Ч�ַ��ռ�
		// \0������Ч�ַ�
		const static size_t npos;
	};

	// ��̬��Ա�����������������ⶨ��
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		//out << s.c_str() << endl; // ���ֲ��У��޷�����\0�Ĵ��� ����\0����ֹ��
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
		//in >> ch; // cin�ǻ�ȡ���˿ո���߻��з��ģ���˻���ѭ��
		ch = in.get(); // һ��һ��ȥ��������ȡ�ַ�
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
		*/

		// ����д��Ƶ��+=����Ƶ�����ݽ���Ч��
		// ����buff�Ż�һ��

		s.clear();
		char ch;
		ch = in.get(); // һ��һ��ȥ��������ȡ�ַ�
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
		// ��������δ������buff
		s += buff;
		return in;
	}

	istream& getline(istream& in, string& s)
	{
		//��ʵ��operator>>���ƣ�ֻ�������ո񲻽�������
		s.clear();
		char ch;
		ch = in.get(); // һ��һ��ȥ��������ȡ�ַ�
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
		// ��������δ������buff
		s += buff;
		return in;
	}

	// ֱ�ӵ���c��������ַ����ȽϺ������ȣ�����c_strд��ȫ�ֺ���
	bool operator<(const string& s1, const string& s2)
	{
		// strcmp ����ֵС��0��ʾ�ľ���s1 < s2
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
