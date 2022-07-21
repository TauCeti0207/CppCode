#include "string.h"

void test_string1()
{
	yzq::string s1("hello world");
	cout << s1.c_str() << endl;
	s1[0] = 'a';
	// ���ʾ���s1.operator[](0) = 'x'
	cout << s1.c_str() << endl;
}

void test_string2()
{
	yzq::string s1("hello world");
	yzq::string s2(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	yzq::string s3("123456");
	s1 = s3;
	cout << s3.c_str() << endl;
}

void test_string3()
{
	yzq::string s1("hello world");
	s1.push_back('1');
	s1.push_back('1');
	cout << s1.c_str() << endl;
	s1 += '2';
	s1 += '2';
	s1 += '2';
	cout << s1.c_str() << endl;

	s1.append("hellohellohellohellohellohello");

	yzq::string s2;
	s2.reserve(20); //����Ƶ������
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	s2 += '2';
	cout << s2.c_str() << endl;
}

void test_string4()
{
	yzq::string s1("hello world");
	s1.reserve(15);
	//s1.resize(20, 'x');
	//s1.resize(14, 'x');
	s1.resize(5);
}

void test_string5()
{
	yzq::string s1("hello world");
	// ����
	// 1.�±�
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	// 2.������
	yzq::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 3.��Χfor �ײ���Ǳ��滻�ɵ�����
	// ��ʵ�Ͱ�*it��ֵ��ch
	for (auto& ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : s1)
	{
		// �ı��ֻ��ch��s1��û�иı�
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void func(const yzq::string& s)
{
	// const��Ա����ֻ�ܵ���const��Ա����
	for (size_t i = 0; i < s.size(); ++i)
	{
		//s[i] += 1; // const�������const�汾�ģ����ص���const���ã���֧���޸���
		cout << s[i] << " "; // ֧�ֿɶ�
	}
	cout << endl;

	// ��ΧforҲ��ʧЧ const�����޷����÷�const�ĳ�Ա����
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;

	yzq::string::const_iterator it = s.begin();
	while (it != s.end())
	{
		//*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_string6()
{
	yzq::string s1("hello world");
	func(s1);
}

void test_string7()
{
	yzq::string s1("hello world");
	s1.insert(6, 'w');
	cout << s1.c_str() << endl;
	s1.insert(12, 'w');
	cout << s1.c_str() << endl;
	s1.insert(0, 'w');
	cout << s1.c_str() << endl;

	s1.push_back2('a');
	cout << s1.c_str() << endl;
	s1 += 's'; // +=���õ���push_back
	cout << s1.c_str() << endl;
	cout << "-------------------------" << endl;
	yzq::string s2("hello world");
	cout << s2.c_str() << endl;
	s2.insert(1, "xxx");
	cout << s2.c_str() << endl;
	s2.insert(0, "xxx");
	cout << s2.c_str() << endl;
	s2.insert(3, "11111");
	cout << s2.c_str() << endl;
	s2.insert(0, " ");
	cout << s2.c_str() << endl;
}

void test_string8()
{
	yzq::string s1("hello world");
	s1.erase(5, 10);
	cout << s1.c_str() << endl;
	s1.erase(2);
	cout << s1.c_str() << endl;
}

void test_string9()
{
	// �������string \0��Ȼ���ɼ������ǻ�ռ��λ��
	std::string s1("hello world");
	cout << s1 << endl;
	cout << s1.c_str() << endl;
	s1 += '\0';
	s1 += '\0';
	s1 += '\0';
	s1 += 'x';
	s1 += '\0';
	s1 += '\0';
	s1 += 'x';
	cout << s1 << endl;
	// �����cstrʶ��\0����ֹ��
	cout << s1.c_str() << endl;
}

void test_string10()
{
	yzq::string s1("hello world");
	cout << s1 << endl;
	cout << s1.c_str() << endl;
	s1 += '\0';
	s1 += '\0';
	s1 += '\0';
	s1 += 'x';
	s1 += '\0';
	s1 += '\0';
	s1 += 'x';
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	yzq::string s2, s3, s4;
	cin >> s2 >> s3 >> s4;
	cout << s2 << "-" << s3 << "-" << s4 << endl;
}

void test_string11()
{
	yzq::string s1("hello world");
	cin >> s1;
	cout << s1 << endl;

	std::string s2("hello world");
	cin >> s2;
	cout << s2 << endl;
}

void test_string12()
{
	yzq::string s3("hello world");
	yzq::getline(cin, s3);
	cout << s3 << endl;
}

void test_string13()
{
	yzq::string s1("hello world");
	yzq::string s2(s1);
	cout << s2 << endl;

	yzq::string s3;
	s3 = s1;
	cout << s3 << endl;
}

void test_string14()
{
	int i;
	cin >> i;
	std::string s = to_string(i);
	int val = stoi(s);
}

int main()
{
	try
	{
		test_string14();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}