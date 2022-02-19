#include "f.h"

// int &Add(int a, int b)
// {
//     static int c = a + b;
//     return c;
// }
// int main()
// {
//     //��ʱ������c�ı���
//     int& ret = Add(1,2); //�������ͨ�� �����˾���
//     //���н����ȷ��
//     //ret�п�����3 Ҳ�п��������ֵ Add��ջ֡���ý������Ѿ���������
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     //Խ�粻һ�������
//     int a[10] = {1, 2, 3};
//     //Խ�������������,��������鲻����
//     cout<< a[10] << endl;
//     cout<< a[11] << endl;
//     cout<< a[12] << endl;
//     cout<< a[13] << endl;

//     //Խ��д���ܻᱨ�� ���������������Ƿ��ϸ�
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
//     // ��ֵ��Ϊ��������
//     size_t begin1 = clock();
//     for (size_t i = 0; i < 10000; ++i)
//         TestFunc1(aa);
//     size_t end1 = clock();

//     // ��������Ϊ��������
//     size_t begin2 = clock();
//     for (size_t i = 0; i < 10000; ++i)
//         TestFunc2(aa);
//     size_t end2 = clock();

//     // �ֱ���������������н������ʱ��
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
// // ֵ����
// A TestFunc1()
// {
//     return a;
// }
// // ���÷���
// A &TestFunc2()
// {
//     return a;
// }

// void TestReturnByRefOrValue()
// {
//     // ��ֵ��Ϊ�����ķ���ֵ����
//     size_t begin1 = clock();
//     for (size_t i = 0; i < 100000; ++i)
//         TestFunc1();
//     size_t end1 = clock();

//     // ��������Ϊ�����ķ���ֵ����
//     size_t begin2 = clock();
//     for (size_t i = 0; i < 100000; ++i)
//         TestFunc2();
//     size_t end2 = clock();

//     // �������������������֮���ʱ��
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
//��ֹ���� ADD(1,2) * 4  --->   (1) + (2) * 4�����

// int main(int argc, char const *argv[])
// {
//     // int a = 10;
//     // //�﷨��,�����a���ռ�ȡ�˸�����,û���¿��ռ�
//     // int& ra = a;
//     // ra = 20;

//     // //�﷨��,���ﶨ��һ��paָ�����,����4���ֽڿռ�,�洢a�ĵ�ַ
//     // int* pa = &a;//int* ��ʾ������ʱ����4���ֽڵĿռ�
//     // *pa = 20;
//     int a = 10;
//     int *pa = &a;
//     *pa = 20;

//     int b = 30;
//     int *&rpa = pa;
//     rpa = &b;
//     return 0;
// }

// // C++ �Ƽ�Ƶ�����õ�С���� �����inline,û��ջ֡����

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
//     // auto b = a; //����������auto ���Ը���a�������Զ��Ƶ�b������

//     int x = 10;
//     auto a = &x;//int*
//     auto *b = &x;//int*
//     int& y = x;//y��������int
//     auto c = y;//�Ƴ�����cҲ��int
//     auto& d = x;//d��������int ������ǿ��ָ����d��x������

//     //��ӡ��������
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

    //��Χfor C++11���﷨����,����
    for (auto &e : array) //���������û���ָ��, auto e : array ֻ�ǰ�array�е�ֵ������e
        e *= 2;
    //�Զ�����,����ȡ��array�е�Ԫ��,��ֵ��e,ֱ������
    for (auto e : array)
        cout << e << " ";
    cout << endl;
    return 0;
}
