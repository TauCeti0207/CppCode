#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//
//struct ListNode
//{
//    ListNode* _next;
//    ListNode* _prev;
//    int _val;
//
//    ListNode(int val = 0)//���캯��
//        :_next(nullptr)
//        , _prev(nullptr)
//        , _val(val)
//    {
//        cout << "ListNode(int val = 0)//���캯��" << endl;
//    }
//    ~ListNode()
//    {
//        cout << "~ListNode()" << endl;
//    }
//};
//
//class List
//{
//public:
//    List()
//    {
//        _head = new ListNode;
//        _head->_next = _head;
//        _head->_prev = _head;
//    }
//
//    ListNode* Find(int x)
//    {
//        ;
//    }
//private:
//    ListNode* _head;
//};
//
//class Stack
//{
//private:
//    int* _a;
//    int _capacity;
//    int _top;
//public:
//    Stack(int capacity = 10)
//    {
//        _a = new int[capacity];
//        _capacity = capacity;
//        _top = 0;
//    }
//    ~Stack()
//    {
//        delete[] _a;
//        _capacity = _top = 0;
//    }
//};
//int main()
//{
//    //Stack st;
//    Stack* st1 = (Stack*)malloc(sizeof(Stack));
//    Stack* st2 = new Stack;
//
//    free(st1);
//    delete st2;
//
//    return 0;
//}
//
//
///*
//operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�ʧ�ܣ�
//����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬�������쳣��
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc) 
//{
//    // try to allocate size bytes
//    void* p;
//    while ((p = malloc(size)) == 0)
//        if (_callnewh(size) == 0)
//        {
//            // report no memory
//            // ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//            static const std::bad_alloc nomem;
//            _RAISE(nomem);
//        }
//    return (p);
//}
///*
//operator delete: �ú���������ͨ��free���ͷſռ��
//*/
//void operator delete(void* pUserData) 
//{
//    _CrtMemBlockHeader* pHead;
//    RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//    if (pUserData == NULL)
//        return;
//    _mlock(_HEAP_LOCK); /* block other threads */
//    __TRY
//        /* get a pointer to memory block header */
//        pHead = pHdr(pUserData);
//    /* verify block type */
//    _ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//    _free_dbg(pUserData, pHead->nBlockUse);
//    __FINALLY
//        _munlock(_HEAP_LOCK); /* release other threads */
//    __END_TRY_FINALLY
//		return;
//}
///*
//free��ʵ��
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)


struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	ListNode(int data = 0)
		:_next(nullptr)
		, _prev(nullptr)
		, _data(data)
	{
		cout << "ListNode()" << endl;
	}

	// ר����operator new
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;  // operator new + ���캯��
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(int val)
	{
		ListNode* newnode = new ListNode;
		ListNode* tail = _head->_prev;

		// head	tail	newnode
		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;
	}

	void Clear()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}

		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

private:
	ListNode* _head;
};

int main()
{
	List l;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		l.PushBack(i);
	}

	cout << endl << endl;
	l.Clear();
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		l.PushBack(i);
	}

	return 0;
}