//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	cout << "hello world" << endl;
	// �Ա�C����printf scanf ����: �Զ�ʶ������
	int a = 10;
	int* p = &a;
	// �Զ�ʶ������ԭ����������+���������
	cout << a << "," << p << endl;
	char str[10];

	// >>����ȡ�����
	cin >> a;
	cin >> str;

	// <<�����������
	cout << a << str << endl;
	return 0;
}


//using std::cout;
//
//
//int main()
//{
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//
//	return 0;
//}

//namespace yzq
//{
//	int scanf = 0;
//	int strlen = 10;
//}




//int a = 0;
//int main(int argc, char const* argv[])
//{
//	//namespace ctl
//	//{
//	//	int scanf = 0;
//	//	int strlen = 10;
//	//}
//	int a = 1;
//	printf("%d\n", a); // �ֲ����� 1
//	printf("%d\n", ::a); // Ĭ�Ϸ���ȫ�� 0
//	return 0;
//}

//#include <stdio.h>
//int main(int argc, char const* argv[])
//{
//	//������ͻ
//	//c���Կ����棬��2����������scanf ��strlen����
//	int scanf = 0;
//	int strlen = 10;
//	//��������ʱ��ͨ�������������scanfʱ�Ͳ��У�����scanf�Ǿͽ���ȡ
//	//C���Խ�����������ͻ����
//	scanf("%d ", &scanf);
//	return 0;
//}