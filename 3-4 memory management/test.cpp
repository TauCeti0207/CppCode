#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//void f2()
//{
//	int b = 0;
//	cout << &b << endl;
//}
//void f1()
//{
//	int a = 0;
//	cout << &a << endl;
//	f2();
//}
////int main()
////{
////	f1();
////	return 0;
////}
//
//int main()
//{
//	int* p1 = (int*)malloc(4);
//	int* p2 = (int*)malloc(4);
//	cout << "p1:" << p1 << endl;
//	cout << "p2:" << p2 << endl;
//	return 0;
//}

//int globalVar = 1;//ȫ�ֱ���->��̬��
//static int staticGlobalVar = 1;//��̬��
//void Test()
//{
//	static int staticVar = 1;//��̬��
//	int localVar = 1;//ջ��
//	int num1[10] = { 1,2,3,4 };//ջ��
//	char char2[] = "hello";//char2��ջ��*char2Ҳ��ջ�ϣ���ջ�Ͽ��˸����飬��hello���ݶ�������ȥ��,hello�ǳ�����������
//	const char* pChar3 = "hello";//pChar3��ջ����*pChar3�ڳ�����
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1��ջ����ָ�򿪱ٵĿռ��ڶ���
//	int* ptr2 = (int*)calloc(4, sizeof(int));//
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//
//	free(ptr1);
//	free(ptr3);
//}

//int main()
//{
//	//�������
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];//new�ǲ�����
//	free(p1);
//	delete 
//	//��������
//	int* p3 = (int*)malloc(sizeof(int));
//
//	return 0;
//}

struct ListNode
{
	//struct ListNode* _next;//c��д��
	ListNode* _next;//C++д��
	ListNode* _prev;
	int _val;
	
	ListNode(int val = 0)//���캯��
		:_next(nullptr)
		,_prev(nullptr)
		,_val(val)
	{
		cout << "ListNode(int val = 0)//���캯��" << endl;
	}
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}

};

//int main()
//{
//	//c mallocֻ�ǿ��ռ� free �������ͷſռ�
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	free(n1);
//
//
//	//C++ new ����Զ������� ���ռ�+���캯����ɳ�ʼ��
//	//delete ����Զ������ͣ������� ���ͷſռ�
//	ListNode* n2 = new ListNode;
//	delete n2;
//
//	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode)*4);
//	free(arr3);
//
//	ListNode* arr4 = new ListNode[4];//����4������͵���4�ι��캯��
//	delete[] arr4;//deleteʱҲ����4��
//	//delete arr4;// ����д�Ͳ�ƥ�䣬�����
//	return 0;
//}

int main()
{
	//void* p1 = malloc(1024 * 1024 * 1024);//1GB

	void* p1 = malloc(0xffffffff);//4GB

	cout << p1 << endl;
	return 0;
}