#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//namespace yzq
//{
//	//class String
//	//{
//	//public:
//	//	String(const char* str = "")
//	//		:_str(new char[strlen(str) + 1])
//	//	{
//	//		strcpy(_str, str);
//	//	}
//
//	//	String(const String& s)
//	//		:_str(s._str)
//	//	{}
//
//	//	String& operator=(const String& s)
//	//	{
//	//		if (this != &s)
//	//		{
//	//			_str = s._str;
//	//		}
//	//		return *this;
//	//	}
//
//	//	~String()
//	//	{
//	//		if (_str)
//	//		{
//	//			delete[] _str;
//	//		}
//	//		_str = nullptr;
//	//	}
//	//private:
//	//	char* _str;
//	//};
//
//	class string
//	{
//	public:
//		string(const char* str = "")
//			: _str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str); //����ʱ \0Ҳ��һ�𿽱�
//		}
//
//		//// s2(s1)
//		//string(const string& s)
//		//	: _str(new char[strlen(s._str)] + 1)
//		//{
//		//	strcpy(_str, s._str);
//		//}
//		//// s1 = s3
//		//string& operator=(const string& s)
//		//{
//		//	if (this != &s)
//		//	{
//		//		delete[] _str;//�ͷ�s1�Ŀռ�
//		//		_str = nullptr;
//		//		_str = new char[strlen(s._str) + 1];//���ٺ�s3һ����Ŀռ�
//		//		strcpy(_str, s._str);//������ȥ
//		//	}
//		//	return *this;
//		//}
//
//		 //����������ִ�д��      
//		string(const string& s)
//			:_str(nullptr)
//		{
//			string tmp(s._str);   //���ù��캯������tmp����������Ҫ��
//			swap(_str, tmp._str);   //��_str��tmp��_strָ��Ŀռ���н�����tmp._str�ͻ�ָ��_str�Ŀռ�
//			//�������������tmp�ͻ�������������ͷſռ䣬����tmp�����_strֵ���ܲ�ȷ���������ڳ�ʼ���б��н�_str�ÿա�
//		}
//
//		//��ֵ���ִ�д��
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				string tmp(s._str);    //���ù��캯��
//				swap(_str, tmp._str);   //tmp�Ǿֲ����󣬳������������ͻ���������������ͻὫtmp�����ָ��ָ��Ŀռ��ͷŵ���
//			}
//			return *this;
//		}
//
//
//		~string()
//		{
//			cout << "~string()" << endl;
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//	};
//}
//
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//
//	B(const B& bb)
//		:_b(bb._b)
//	{
//		cout << "B(const B& bb)" << endl;
//	}
//
//	B& operator=(const B& bb) //��������
//	{
//		cout << "B& operator=(const B& bb)" << endl;
//		if (this != &bb)
//		{
//			_b = bb._b;
//		}
//		return *this;
//	}
//private:
//	int _b;
//};
//
//class C
//{
//public:
//	C(int c1 = 0, int c2 = 0)
//		:_c1(c1)
//		, _c2(c2)
//	{}
//private:
//	int _c1;
//	int _c2;
//};
//
//class A
//{
//private:
//	// Ĭ�����ɹ��캯���Ի������ͳ�Ա�����ǲ�����ġ�
//	// (��Щ�Ƚ��µı�����Ҳ�п��ܻ��ʼ����0�����Ǵ���������������ᴦ������Ҫ���ɲ���ʼ��)
//
//	// �������Ͳ�������C++�﷨��Ƶ�һ��Сȱ��
//	// ����C++11�������˲����﷨������ȱʡֵ�������������ȱ��
//	int _a1 = 1; // ���ﲻ�ǳ�ʼ���������Ǹ�ȱʡֵ
//	int _a2 = 2;
//
//	// Ĭ�����ɹ��캯�����Զ����͵ĳ�Ա��ȥ��������Ĭ�Ϲ��캯����ʼ��
//	//B _b = B(1);
//	B _b = 1;
//
//	//C _c = C(1, 1);
//	C _c = { 1, 1 };
//};
//
//class D
//{
//public:
//
//	D()
//	{}
//
//private:
//	int _d = 0;    // ��Ա����
//	B	_b;
//};
//
//
//class Date
//{
//public:
//	~Date()
//	{
//		// ... �����û��ʲô��Դ��Ҫ����
//		// ������ʵ����д�����������������Զ����ɾͿ���
//	}
//private:
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//
//	B _b = 10;
//};
//void Test()
//{
//	yzq::string s1("hello");
//	yzq::string s2(s1);
//}
//int main(int argc, char const* argv[])
//{
//	//Date d1;
//	//Date d2(d1);
//	//Date d3 = d1;
//	//Date d4;
//	//d4 = d1;
//
//	//yzq::string s1("hello");
//	//yzq::string s2(s1);
//	//yzq::string s3("hello hello");
//	//s1 = s3;
//	Test();
//	return 0;
//}




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// ����ʵ��

// ��������ڵ�
typedef struct QNode
{
    struct QNode* next;
    int data;
}QNode;
// ����ѭ������
typedef struct {
    QNode* front;
    QNode* tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(obj);
    obj->front = obj->tail = NULL;
    k += 1;// ע��࿪��һ���ռ�
    // �����ڵ�
    while (k--)
    {
        QNode* newNode = (QNode*)malloc(sizeof(QNode));
        assert(newNode);
        // ����һ��ʼ��Ϊ�յ����
        if (obj->front == NULL && obj->tail == NULL)
            obj->front = obj->tail = newNode;
        else
        {
            obj->tail->next = newNode;
            obj->tail = newNode;
        }
    }
    // ��������ɺ�ע����Ҫ������ͷβ����
    obj->tail->next = obj->front;
    obj->tail = obj->front;
    return obj;
}

// �����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    // ע������
    if (myCircularQueueIsFull(obj))
        return false;
    // else
    // {
    obj->tail->data = value;
    obj->tail = obj->tail->next;
    return true;
    // }

}

// ������ ע���п�
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return false;
    // ��front��ǰ�ƶ�����
    else
    {
        // ����������������������Ǳ߽�������
        obj->front = obj->front->next;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->front->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    // ������Ҫ��tail��ǰһ�����
    else
    {
        QNode* cur = obj->front;
        while (cur->next != obj->tail)
            cur = cur->next;
        return cur->data;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    // front == tail���ǿ�
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    // tail��next == front������
    return obj->tail->next == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    // Ҫfree�����ÿһ�����
    QNode* cur = obj->front;
    while (cur->next != obj->front)
    {
        QNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    // ע���ʱ��©����obj->frontûfree
    free(obj->front);
    free(obj);
    // ע��Ҫ�ں������ú��ֶ��ÿ�obj
}
 
int main()
{
    MyCircularQueue* cq = myCircularQueueCreate(3);
    bool ret = myCircularQueueEnQueue(cq, 1);
    return 0;
}
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/