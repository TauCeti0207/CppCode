#include "f.h"

// int &Add(int a, int b)
// {
//     static int c = a + b;
//     return c;
// }
// int main()
// {
//     //临时变量是c的别名
//     int& ret = Add(1,2); //编译可以通过 但报了警告
//     //运行结果不确定
//     //ret有可能是3 也有可能是随机值 Add的栈帧调用结束就已经被销毁了
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     //越界不一定报错的
//     int a[10] = {1, 2, 3};
//     //越界读基本不报错,编译器检查不出来
//     cout<< a[10] << endl;
//     cout<< a[11] << endl;
//     cout<< a[12] << endl;
//     cout<< a[13] << endl;

//     //越界写可能会报错 看具体编译器检查是否严格
//     a[10] = 0;
//     return 0;
// }
// #include <time.h>
// struct A
// {
//     int a[100000];
// };

// void TestFunc1(A a) {}

// void TestFunc2(A &a) {}

// void TestRefAndValue()
// {
//     A aa;
//     // 以值作为函数参数
//     size_t begin1 = clock();
//     for (size_t i = 0; i < 10000; ++i)
//         TestFunc1(aa);
//     size_t end1 = clock();

//     // 以引用作为函数参数
//     size_t begin2 = clock();
//     for (size_t i = 0; i < 10000; ++i)
//         TestFunc2(aa);
//     size_t end2 = clock();

//     // 分别计算两个函数运行结束后的时间
//     cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//     cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
// }
// int main(int argc, char const *argv[])
// {
//     TestRefAndValue();
//     // TestFunc1(A)-time:83
//     // TestFunc2(A&)-time:0
//     return 0;
// }

// #include <time.h>
// struct A
// {
//     int a[100000];
// };

// A a;
// // 值返回
// A TestFunc1()
// {
//     return a;
// }
// // 引用返回
// A &TestFunc2()
// {
//     return a;
// }

// void TestReturnByRefOrValue()
// {
//     // 以值作为函数的返回值类型
//     size_t begin1 = clock();
//     for (size_t i = 0; i < 100000; ++i)
//         TestFunc1();
//     size_t end1 = clock();

//     // 以引用作为函数的返回值类型
//     size_t begin2 = clock();
//     for (size_t i = 0; i < 100000; ++i)
//         TestFunc2();
//     size_t end2 = clock();

//     // 计算两个函数运算完成之后的时间
//     cout << "TestFunc1 time:" << end1 - begin1 << endl;
//     cout << "TestFunc2 time:" << end2 - begin2 << endl;
// }

// int main()
// {
//     TestReturnByRefOrValue();
//     // TestFunc1 time:907
//     // TestFunc2 time:0
//     return 0;
// }

//#define ADD(x, y) ((x) + (y))
//防止出现 ADD(1,2) * 4  --->   (1) + (2) * 4的情况

// int main(int argc, char const *argv[])
// {
//     // int a = 10;
//     // //语法上,这里给a这块空间取了个别名,没有新开空间
//     // int& ra = a;
//     // ra = 20;

//     // //语法上,这里定义一个pa指针变量,开辟4个字节空间,存储a的地址
//     // int* pa = &a;//int* 表示解引用时访问4个字节的空间
//     // *pa = 20;
//     int a = 10;
//     int *pa = &a;
//     *pa = 20;

//     int b = 30;
//     int *&rpa = pa;
//     rpa = &b;
//     return 0;
// }

// // C++ 推荐频繁调用的小函数 定义成inline,没有栈帧开销

// inline int Add(int x, int y)
// {
//     return x + y;
// }
// int main(int argc, char const *argv[])
// {
//     int c = Add(1, 2);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     // int a = 10;
//     // // int b = a;
//     // auto b = a; //类型声明成auto 可以根据a的类型自动推导b的类型

//     int x = 10;
//     auto a = &x;//int*
//     auto *b = &x;//int*
//     int& y = x;//y的类型是int
//     auto c = y;//推出来的c也是int
//     auto& d = x;//d的类型是int 但这里强制指定了d是x的引用

//     //打印变量类型
//     cout << typeid(x).name() << endl;//int
//     cout << typeid(y).name() << endl;//int
//     cout << typeid(a).name() << endl;//int*
//     cout << typeid(b).name() << endl;//int*
//     cout << typeid(c).name() << endl;//int
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        array[i] *= 2;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        cout << array[i] << " ";
    cout << endl;

    //范围for C++11新语法遍历,更简单
    for (auto &e : array) //必须用引用或者指针, auto e : array 只是把array中的值拷贝给e
        e *= 2;
    //自动遍历,依次取出array中的元素,赋值给e,直到结束
    for (auto e : array)
        cout << e << " ";
    cout << endl;
    return 0;
}
