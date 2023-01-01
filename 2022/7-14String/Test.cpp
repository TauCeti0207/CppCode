#include <iostream>
#include <string>
using namespace std;

void StringTest1()
{
	string s1;
	string s2("hello world");
	s2 += "!!!";
	string s3(s2);
	string s4 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	string s5("https://cplusplus.com/reference/string/string/string/", 4);
	cout << s5 << endl;
	string s6(10, 'c');
	cout << s6 << endl;
	string s7(s2, 6, 5);
	cout << s7 << endl;
}

void StringTest2()
{
	string s1("hello");
	string s2 = s1;
	cout << s2 << endl;
	s2 = "hello world";
	cout << s2 << endl;
	s2 = 'a';
	cout << s2 << endl;
}

void StringTest3()
{
	string s1("hello world");
	cout << s1.size() << endl; // size()������\0
	for (size_t i = 0; i < s1.size(); ++i)
	{
		//��ʵ���� s1.operator[](i)
		cout << s1[i] << " ";
		//s1[i] = 'x'; // Ҳ�����޸�
	}
	cout << endl;

	const char* str = "world";
	cout << str[1] << endl; // ������ָ��ƫ�ƣ�*(str+1),strָ���ַ������׵�ַ
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;
}

void StringTest4()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void StringTest5()
{
	string s1("123456");
	for (char& e : s1)
	{
		e += 1;
		cout << e << " "; // 2 3 4 5 6 7
	}
	cout << endl;
}
void StringTest6()
{
	string s1("123456");
	for (auto e : s1)
	{
		cout << e << " ";// 1 2 3 4 5 6
	}
	cout << endl;
}

void StringTest7()
{
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";//d l r o w   o l l e h
		++rit;
	}
	cout << endl;
}

void StringTest8()
{
	string s1("hello");
	const string s2 = "hello";
	s1[0] = 'x';
	//s2[0] = 'x'; // err ���õ���const�汾��operator[]�޷��޸�
	//s1[6]; // ͨ�����Ա���
	s1.at(6);
}
//int main()
//{
//	try
//	{
//		StringTest8();
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


void StringTest9(const string& rs)
{
	string::const_reverse_iterator rit = rs.rbegin();
	while (rit != rs.rend())
	{
		//(*rit) += 1;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}



//int main()
//{
//	string s1 = "hello world";
//	StringTest9(s1);
//	return 0;
//}

void StringTest10()
{
	// ��֤�������һ��
	string s;
	// ��ǰֱ����Ҫ����1000�����ݵĻ�������ǰ�������㹻������
	//s.reserve(1000);
	s.resize(1000);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	cout << "capacity changed: " << sz << '\n';
	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void StringTest11()
{
	string s;
	s.push_back('x');
	s.append("hello");
	string s2("world");
	s.append(s2);
	cout << s << endl;
	s += 'a';
	s += "hello world";
	s += s2;
	cout << s << endl;
}

void StringTest12()
{
	string s("hello world");
	s.insert(0, 1, 'x'); // ��һ��λ�ò���x
	cout << s << endl;
	s.insert(s.begin(), 'y');
	cout << s << endl;
	s.insert(s.begin() + 3, 'y');
	cout << s << endl;
	s.insert(0, "hello");
	cout << s << endl;
}

void StringTest13()
{
	string s1 = "";
	s1.insert(0, "x");
	s1.insert(0, "xyy");
	cout << s1 << endl; // xyyx��
	s1.erase(0, 1);
	cout << s1 << endl; // yyx
	s1.erase(0, 2);
	cout << s1 << endl; // x

	s1.insert(0, "x");
	s1.insert(0, "xyy");
	cout << s1 << endl; // xyyxx
	s1.erase(s1.begin());
	cout << s1 << endl; // yyxx
	s1.erase(s1.begin() + 3);
	cout << s1 << endl; // yyx
	s1.erase(0);        //��ʾɾ�꣬Ĭ�ϲ�����npos
	// s1.erase(0, 100); ����Ҳ��ɾ���ˣ��Ͼ�ֻ��3���ַ�
	// s1.erase(); // ȫ��ɾ�� ȱʡ����Ϊ0
	cout << s1 << endl;
}

void StringTest14()
{
	string s1 = "hello";
	string s2 = "world";
	cout << s1 + s2 << endl;

	// Ч�ʸߣ�ֱ�ӽ���ָ��
	s1.swap(s2); // �������������
	cout << s1 + s2 << endl;

	// Ч�ʵͣ��������
	swap(s1, s2); // ȫ�ֵģ����ÿ������
	cout << s1 + s2 << endl;
	cout << (s1 + s2).c_str() << endl;
}

void StringTest15()
{
	string file("string.cpp");
	size_t pos = file.find('.');
	if (pos != string::npos)
	{
		string suffix1 = file.substr(pos, file.size() - pos);
		string suffix2 = file.substr(pos);
		cout << "��׺��" << suffix1 << endl;
		cout << "��׺��" << suffix2 << endl;
	}
	else
	{
		cout << "û�ҵ���׺" << endl;
	}
}

void StringTest16()
{
	string file("string.cpp.tar.zip");
	size_t pos = file.rfind('.');
	if (pos != string::npos)
	{
		string suffix = file.substr(pos);
		cout << "��׺��" << suffix << endl;
	}
	else
	{
		cout << "û�ҵ���׺" << endl;
	}
}

void StringTest17()
{
	// ȡ��url�е�����
	string url1("http://www.cplusplus.com/reference/string/string/find/");
	string url2("https://leetcode.cn/problems/design-skiplist/solution/tiao-biao-probabilistic-alternative-to-b-0cd8/");

	string& url = url2;

	// Э�� ���� ��Դ
	string protocol;
	size_t pos1 = url.find("://");
	if (pos1 != string::npos)
	{
		protocol = url.substr(0, pos1);
		cout << "protocol:" << protocol << endl;
	}
	else
	{
		cout << "�Ƿ�url" << endl;
	}

	string domain;
	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != string::npos)
	{
		domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		cout << "domain:" << domain << endl;
	}
	else
	{
		cout << "�Ƿ�domain" << endl;
	}

	string uri = url.substr(pos2 + 1);
	cout << "uri:" << uri << endl;
}
int main()
{
	StringTest17();
	return 0;
}