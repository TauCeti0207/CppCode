// #include <iostream>
// using namespace std;
// //C++����C���﷨
// int main(int argc, char const *argv[])
// {
//     cout << "hello world" << endl;
//     return 0;
// }

// namespace ����һ����
//�����ǽ��C����������ͻ����
// #include <stdio.h>
// #include <windows.h>
// #include "List.h"
// //C++���������ռ�Ļ���

// // int main(int argc, char const *argv[])
// // {
// //     //������ͻ
// //     //c���Կ�����,��2����������scanf ��strlen����
// //     // int scanf = 0;
// //     // int strlen = 10;
// //     //��������ʱ��ͨ��,���������scanfʱ�Ͳ���,����scanf�Ǿͽ���ȡ
// //     //C���Խ�����������ͻ����
// //     //scanf("%d ",&scanf);
// //     printf("%p\n",scanf);
// //     system("pause");
// //     return 0;
// // }

// namespace yzq
// {
//     int scanf = 0;
//     int strlen = 10;
// }
// int main(int argc, char const *argv[])
// {
//     //Ĭ�Ϸ��ʵ��Ǿֲ���ȫ��
//     printf("%x\n",scanf); //2d312e90 �������scanf�����ĵ�ַ
//     //����scanfʱ�Ǿͽ�ԭ��,���ᵽnamespace����ȥ����,�ͽ��Ҳ�����ȥȫ������,ͷ�ļ�����

//     //ָ������yzq�ռ��е�
//     printf("%x\n",yzq::scanf); //0
//     printf("%d\n",bit::scanf); //30

//     bit::ListNode* pHead = NULL;
//     system("pause");
//     return 0;
// }

// namespace bit
// {
// 	int scanf = 10;
// 	int strlen = 20;

// 	int Add(int left, int right)
// 	{
// 		return left + right;
// 	}

// 	// Ƕ�׶��������ռ�
// 	namespace N3
// 	{
// 		int c;
// 		int d;
// 		int Sub(int left, int right)
// 		{
// 			return left - right;
// 		}

// 		// ����������
// 	}
// }

// C++��Ϊ�˷�ֹ������ͻ,���Լ������涨��Ķ�����������һ��std�������ռ���
//ʹ�ñ�׼���еĶ��� 3�ַ�ʽ

// 1.ָ�������ռ� ��ʹ�� using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      std::cout << "hello world" << std::endl;
//      system("pause");
//      return 0;
//  }

// using namespace std;
// C++����C���﷨
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// 2.��std����չ��,�൱�ڿ�����Ķ�������ȫ������
//������������,������������Լ�����Ķ��������ͻ�˾�û�����
//�淶�Ĺ�����Ŀ���ǲ��Ƽ����ַ�ʽ��  �ճ���ϰ�ȽϷ���
//  using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// //3.�Բ��ֳ��õĿ���Ķ���չ��
// //���з���,��Ŀ��Ҳ������
// using std::cout;
// using std::cin;
// using std::endl;

#include <iostream>
#include <windows.h>
#include "List.h"
using namespace std;
// struct Person
// {
//     char name[10];
//     int age;
// };
// int main(int argc, char const *argv[])
// {
//     cout << "hello world" << endl;
//     //�Ա�C����printf scanf ����: �Զ�ʶ������
//     // int a = 10;
//     // int *p = &a;
//     //�Զ�ʶ������ ԭ���뺯������+���������
//     // cout << a << "," << p << endl;
//     // char str[10];
//     // cin>>a;
//     // cin>>str;
//     // cout<<a<<str<<endl;

//     struct Person p = {"С��", 10};
//     printf("name:%s\n age:%d\n", p.name,p.age); //��ʽ�����ʱ��printf���������
//     cout<<"name:"<<p.name<<endl<<"age:"<<p.age<<endl;
//     system("pause");
//     return 0;
// }

void TestFun(int a = 10, int b = 20, int c = 30)
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl
         << endl;
}
// int main(int argc, char const *argv[])
// {
//     TestFun(1, 2, 3);
//     TestFun();
//     TestFun(1);
//     TestFun(1, 2);
//     system("pause");
//     return 0;
// }
#include <stdlib.h>
struct Stack
{
    int *a;
    int size;
    int capacity;
};
void StackInit(struct Stack *ps, int InitCapacity = 4)
{
    ps->a = (int *)malloc(sizeof(int) * 100);
    ps->size = 0;
    ps->capacity = InitCapacity;
}
int Add(int left = 10, int right = 20)
{
    return left + right;
}

char Add(char left, char right)
{
    return left + right;
}

double Add(double left, double right)
{
    return left + right;
}

void f(int a, int b, int c = 1)
{
    ;
}
void f(int a, int b)
{
    ;
}
void swap(int *a, int *b)
{
    // ...
}

void swap(double *a, double *b)
{
    // ...
}

// int main()
// {
//     cout << Add() << endl;         // 30
//     cout << Add(1, 2) << endl;     // 3 ������  ��������Ĭ���㳣��
//     cout << Add('1', '2') << endl; // c 49 + 50 --> 99 Ҳ����'c'
//     cout << Add(1.1, 2.2) << endl; // 3.3
//     f(1, 2, 3);
//     //f(1, 2);
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     struct Stack st1;
//     //����֪��ջ�����100������
//     StackInit(&st1, 100);

//     struct Stack st2;
//     //����֪��ջ�����10������
//     StackInit(&st1, 10);

//     struct Stack st3;
//     //���費֪��ջ�����Ҫ���������
//     StackInit(&st3);
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a = 10;
//     // b��a������(����)
//     int &b = a;
//     b = 20;
//     //�����Լ���ȡ����
//     int &c = b;
//     c = 30;
//     return 0;
// }
void Swap(int &r1, int &r2)
{
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    Swap(a, b);
    return 0;
}
