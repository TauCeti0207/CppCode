#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include "AVLTree.h"
#include "RedBlueTree.h"
#include "set.h"
#include "map.h"
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);

	// ����+ȥ��
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1; // ��ͨ��������const���������ǲ������޸ĵ�
		cout << *it << " ";
		++it;
	}
	cout << endl; // 1 2 3 4 5

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 3 4 5
}

void test_set2()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	set<int>::iterator pos = s.find(2);  // O(logN)
	if (pos != s.end())
	{
		cout << "set.find�ҵ���" << endl;
	}
	else
	{
		cout << "set.find�Ҳ���" << endl;
	}
	// set.find�ҵ���

	pos = find(s.begin(), s.end(), 20); // O(N) �㷨��Ĳ����Ǳ�������
	if (pos != s.end())
	{
		cout << "ȫ��find�ҵ���" << endl;
	}
	else
	{
		cout << "ȫ��find�Ҳ���" << endl;
	}
	// ȫ��find�Ҳ���
}

void test_set3()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	cout << s.erase(3) << endl; // 1 �ɹ�ɾ��
	cout << s.erase(30) << endl; // 0

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 4 5

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
		s.erase(pos); // ���ֱ��ɾ�������ڵ�Ԫ�� �ᱨ�� 

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 2 4 5

	int x;
	while (cin >> x)
	{
		set<int>::iterator pos = s.find(x);
		if (pos != s.end())
		{
			s.erase(pos);
			cout << "ɾ��" << x << "�ɹ�" << endl;
		}
		else
		{
			cout << x << "����set��" << endl;
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	/*if (s.count(5))
	{
		cout << "5��" << endl;
	}

	if (s.find(5) != s.end())
	{
		cout << "5��" << endl;
	}*/
}

void test_set4()
{
	std::set<int> myset;

	// set some initial values:
	for (int i = 1; i < 5; ++i) myset.insert(i * 3);    // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.count(i) != 0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.find(i) != myset.end())
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}

	/*0 is not an element of myset.
	1 is not an element of myset.
	2 is not an element of myset.
	3 is an element of myset.
	4 is not an element of myset.
	5 is not an element of myset.
	6 is an element of myset.
	7 is not an element of myset.
	8 is not an element of myset.
	9 is an element of myset.

	0 is not an element of myset.
	1 is not an element of myset.
	2 is not an element of myset.
	3 is an element of myset.
	4 is not an element of myset.
	5 is not an element of myset.
	6 is an element of myset.
	7 is not an element of myset.
	8 is not an element of myset.
	9 is an element of myset.*/
}

void test_set5()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	// ����>= val��λ�õ�����  3����3λ��  6 ����7λ��
	//set<int>::iterator lowIt = s.lower_bound(3); // ����
	//lowIt = s.lower_bound(6); // ������
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// Ҫ��ɾ��>=x������ֵ
	int x;
	cin >> x;
	set<int>::iterator lowIt = s.lower_bound(x);
	s.erase(lowIt, s.end());

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set6()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(9);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ����>xλ�õĵ�����  -�� ���Ƿ��� 7λ�õĵ�����
	//set<int>::iterator upIt = s.upper_bound(5);  // ����
	//upIt = s.upper_bound(6); // ������

	// ɾ��x <=  <= y������ ɾ�� [x,y]
	int x, y;
	cin >> x >> y;
	auto leftIt = s.lower_bound(x);  // [
	auto rightIt = s.upper_bound(y); // )
	s.erase(leftIt, rightIt);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set7()
{
	multiset<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// ���� 
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 10; /err
		cout << *it << " ";
		++it;
	}
	cout << endl; // 1 1 1 2 2 3 3 3 3 3 4 5

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 1 1 1 2 2 3 3 3 3 3 4 5

	cout << s.count(1) << endl; // 3 ����1�ĸ���
	cout << s.erase(1) << endl; // 3
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; // 2 2 3 3 3 3 3 4 5

	// ���x�Ļ���find���������һ��x
	// ֻ�������һ��3��ʼ ���ܱ������е�3 �����
	auto pos = s.find(3);
	while (pos != s.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl; // 3 3 3 3 3 4 5
}

void test_map1()
{
	map<string, string> dict;

	// ���� pair �Ĺ��캯����������
	dict.insert(pair<string, string>("sort", "����")); // ��������
	pair<string, string> kv("insert", "����");
	dict.insert(kv);

	// make_pair ����ģ��
	auto ret1 = dict.insert(make_pair("left", "���"));
	auto ret2 = dict.insert(make_pair("left", "ʣ��"));

	dict["operator"] = "����"; // ����+�޸�
	dict["left"] = "��ߡ�ʣ��"; // �޸�
	dict["erase"];  // ����
	cout << dict["left"] << endl; // ����


	// C++11 ��֧��
	//dict.insert({ "right", "�ұ�" });

	// ����
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " "; // it->operator*()
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl; // ʡ����һ�� ->
		++it;
	}
	cout << endl;

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(str);
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//		//it->first++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}

	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	//pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));
	//	auto ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//		// ret����һ��first��secon
	//		// first ��ָ��map�ĵ�������ָ�룩
	//		// secon �� bool ����
	//	}
	//}

	map<string, int> countMap;
	for (auto& str : arr)
	{
		countMap[str]++; // �ȼ���countMap.operator[](str)++
		// ��һ�β����� k����map�У�Ĭ�Ϲ����value��0��Ȼ������++���1��
		// �ڶ����ٲ�����ͬstr��value����++
	}

	for (const auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	//ƻ��:6
	//����:3
	//�㽶:2
}

//mapped_type& operator[] (const key_type& k)
//{
//	pair<map<key_type, mapped_type>::iterator, bool> ret = insert(make_pair(k, mapped_type()));
//
//	//return (*(ret.first)).second; // �ȼ�
//	return ret.first->second;
//}

void test_map3()
{
	multimap<string, string> dict;
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));
	dict.insert(make_pair("left", "���")); // ����ȫһ����valueҲ�ǿ��Ե�
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("string", "��"));
	dict.insert(make_pair("string", "ϸ��"));
	dict.insert(make_pair("string", "һϵ���¼�"));

	/*string str;
	while (cin >> str)
	{

		auto pos = dict.find(str);
		if (pos != dict.end())
		{
			cout << "�ҵ��� " << pos->first << ":" << pos->second << endl;
		}
		else
			cout << "�Ҳ��� " << endl;

	}*/

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	//left:���
	//left : ʣ��
	//left : ���
	//string : �ַ���
	//string : ��
	//string : ϸ��
	//string : һϵ���¼�
}

void test_wakatime_box()
{
	for (size_t i = 0; i < 100; ++i) {
		cout << i+1 << " "; // output 1~100
	}
	cout << endl;
}

int main()
{
	//test_set7();
	//test_map3();
	//yzq::TestAVLTree3();
	//bit_homework::TestAVLTree();
	//TestRBTree2();
	//yzq::test_map1();
	//yzq::test_map2();
	//yzq::test_map3();
	test_wakatime_box();
	return 0;
}