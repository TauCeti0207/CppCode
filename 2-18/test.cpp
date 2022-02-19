// #include <iostream>
// using namespace std;
// //C++兼容C的语法
// int main(int argc, char const *argv[])
// {
//     cout << "hello world" << endl;
//     return 0;
// }

// namespace 定义一个域
//本质是解决C语言命名冲突问题
// #include <stdio.h>
// #include <windows.h>
// #include "List.h"
// //C++利用命名空间的机制

// // int main(int argc, char const *argv[])
// // {
// //     //命名冲突
// //     //c语言库里面,有2个函数用了scanf 和strlen名称
// //     // int scanf = 0;
// //     // int strlen = 10;
// //     //变量定义时能通过,但下面调用scanf时就不行,调用scanf是就近读取
// //     //C语言解决不了这个冲突问题
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
//     //默认访问的是局部或全局
//     printf("%x\n",scanf); //2d312e90 结果就是scanf函数的地址
//     //搜索scanf时是就近原则,不会到namespace里面去搜索,就近找不到就去全局搜索,头文件里找

//     //指定访问yzq空间中的
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

// 	// 嵌套定义命名空间
// 	namespace N3
// 	{
// 		int c;
// 		int d;
// 		int Sub(int left, int right)
// 		{
// 			return left - right;
// 		}

// 		// 还可以再套
// 	}
// }

// C++库为了防止命名冲突,把自己库里面定义的东西都定义在一个std的命名空间中
//使用标准库中的东西 3种方式

// 1.指定命名空间 不使用 using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      std::cout << "hello world" << std::endl;
//      system("pause");
//      return 0;
//  }

// using namespace std;
// C++兼容C的语法
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// 2.把std整个展开,相当于库里面的东西都到全局域了
//看起来方便了,但如果是我们自己定义的东西跟库冲突了就没法解决
//规范的工程项目中是不推荐这种方式的  日常练习比较方便
//  using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// //3.对部分常用的库里的东西展开
// //折中方案,项目中也经常用
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
//     //对比C语言printf scanf 优势: 自动识别类型
//     // int a = 10;
//     // int *p = &a;
//     //自动识别类型 原理与函数重载+运算符重载
//     // cout << a << "," << p << endl;
//     // char str[10];
//     // cin>>a;
//     // cin>>str;
//     // cout<<a<<str<<endl;

//     struct Person p = {"小李", 10};
//     printf("name:%s\n age:%d\n", p.name,p.age); //格式化输出时用printf更舒服反而
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
//     cout << Add(1, 2) << endl;     // 3 字面量  给的整形默认算常量
//     cout << Add('1', '2') << endl; // c 49 + 50 --> 99 也就是'c'
//     cout << Add(1.1, 2.2) << endl; // 3.3
//     f(1, 2, 3);
//     //f(1, 2);
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     struct Stack st1;
//     //假设知道栈里面存100个数据
//     StackInit(&st1, 100);

//     struct Stack st2;
//     //假设知道栈里面存10个数据
//     StackInit(&st1, 10);

//     struct Stack st3;
//     //假设不知道栈里可能要存多少数据
//     StackInit(&st3);
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a = 10;
//     // b是a的引用(别名)
//     int &b = a;
//     b = 20;
//     //还可以继续取别名
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
