#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
// void f2()
//{
//	int b = 0;
//	cout << &b << endl;
// }
// void f1()
//{
//	int a = 0;
//	cout << &a << endl;
//	f2();
// }
////int main()
////{
////	f1();
////	return 0;
////}
//
// int main()
//{
//	int* p1 = (int*)malloc(4);
//	int* p2 = (int*)malloc(4);
//	cout << "p1:" << p1 << endl;
//	cout << "p2:" << p2 << endl;
//	return 0;
//}

// int globalVar = 1;//ȫ�ֱ���->��̬��
// static int staticGlobalVar = 1;//��̬��
// void Test()
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
// }

// int main()
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
// }

// struct ListNode
// {
// 	// struct ListNode* _next;//c��д��
// 	ListNode *_next; // C++д��
// 	ListNode *_prev;
// 	int _val;

// 	ListNode(int val = 0) //���캯��
// 		: _next(nullptr), _prev(nullptr), _val(val)
// 	{
// 		cout << "ListNode(int val = 0)//���캯��" << endl;
// 	}
// 	~ListNode()
// 	{
// 		cout << "~ListNode()" << endl;
// 	}
// };

// int main()
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
// }

// int main()
// {
// 	//void* p1 = malloc(1024 * 1024 * 1024);//1GB

// 	void* p1 = malloc(0xffffffff);//4GB

// 	cout << p1 << endl;
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	ListNode *p1 = (ListNode *)malloc(sizeof(ListNode));
// 	free(p1);

// 	//�÷���malloc freeһ��
// 	ListNode *p2 = (ListNode *)operator new(sizeof(ListNode));
// 	operator delete(p2);

// 	void *p3 = malloc(0xffffffff);
// 	if (p3 == NULL)
// 	{
// 		cout << "malloc fail" << endl;
// 	}

// 	try
// 	{
// 		void *p4 = operator new(0xffffffff);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	system("pause");
// 	return 0;
// }

// int globalVar = 1;				//ȫ�ֱ���->��̬��
// static int staticGlobalVar = 1; //��̬��
// void Test()
// {
// 	static int staticVar = 1;						   //��̬��
// 	int localVar = 1;								   //ջ��
// 	int num1[10] = {1, 2, 3, 4};					   //ջ��
// 	char char2[] = "hello";							   // char2��ջ��*char2Ҳ��ջ�ϣ���ջ�Ͽ��˸����飬��hello���ݶ�������ȥ��,hello�ǳ�����������
// 	const char *pChar3 = "hello";					   // pChar3��ջ����*pChar3�ڳ�����
// 	int *ptr1 = (int *)malloc(sizeof(int) * 4);		   // ptr1��ջ����ָ�򿪱ٵĿռ��ڶ���
// 	int *ptr2 = (int *)calloc(4, sizeof(int));		   //
// 	int *ptr3 = (int *)realloc(ptr2, sizeof(int) * 4); //
// 	free(ptr1);
// 	free(ptr3);
// }

// class Stack
// {
// public:
// 	Stack()
// 		: num(new int[10]), top(0), capacity(10)
// 	{
// 	}
// 	~Stack()
// 	{
// 		delete[] num;
// 		top = capacity = 0;
// 	}

// private:
// 	int *num;
// 	int top;
// 	int capacity;
// };

// int main()
// {
// 	Stack stack;
// 	return 0;
// }

// struct ListNode
// {
// 	ListNode *_next; // C++д��
// 	ListNode *_prev;
// 	int _val;

// 	//��������ר����operator new
// 	void *operator new(size_t n)
// 	{
// 		void *p = nullptr;
// 		p = allocator<ListNode>().allocate(1); // STL�еĿռ�����������ʵ����һ���򵥵��ڴ��
// 		cout << "memory pool allocate" << endl;
// 		return p;
// 	}
// 	void operator delete(void *p)
// 	{
// 		allocator<ListNode>().deallocate((ListNode *)p, 1);
// 		cout << "memory pool deallocate" << endl;
// 	}
// 	ListNode(int val = 0) //���캯��
// 		: _next(nullptr), _prev(nullptr), _val(val)
// 	{
// 		cout << "ListNode(int val = 0)//���캯��" << endl;
// 	}
// 	~ListNode()
// 	{
// 		cout << "~ListNode()" << endl;
// 	}
// };
// int main(int argc, char const *argv[])
// {
// 	ListNode *p = new ListNode(1);
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	A* p = (A*)malloc(sizeof(A));
// 	return 0;
// }

// class A
// {
// public:
// 	A(int a = 0)
// 		: _a(a)
// 	{
// 		cout << "A():" << this << endl;
// 	}

// 	~A()
// 	{
// 		cout << "~A():" << this << endl;
// 	}

// private:
// 	int _a;
// };

// int main()
// {
// 	// A* p = (A*)malloc(sizeof(A));

// 	// �ȼ���ֱ����A* p = new A
// 	A *p = (A *)operator new(sizeof(A));
// 	new (p) A; // new(p)A(3);  // ��λnew��placement-new����ʾ���ù��캯����ʼ��������ռ�

// 	// ���� delete p
// 	p->~A(); // ��������������ʾ����
// 	operator delete(p);

// 	return 0;
// }

// void MemoryLeaks()
// {
// 	// 1.�ڴ������������ͷ�
// 	int *p1 = (int *)malloc(sizeof(int));
// 	int *p2 = new int;

// 	// 2.�쳣��ȫ����
// 	int *p3 = new int[10];

// 	Func(); //����Func�������쳣���� delete[] p3 δִ�� p3û�ͷ�
// 	delete[] p3;
// }

#include <stdio.h>
#include <assert.h>

// // ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
// long long Fac(size_t N)
// {
// 	if (0 == N)
// 		return 1;

// 	for (size_t i = 0; i < N; ++i)
// 	{
// 		printf("%d", i);
// 	}
// 	printf("\n");

// 	return Fac(N - 1) * N;
// }

// // ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�
// long long Fib(size_t N)
// {
// 	if (N < 3)
// 		return 1;

// 	return Fib(N - 1) + Fib(N - 2);
// }
int BinarySearch(int *a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}
	system("pause");
	return 0;
}