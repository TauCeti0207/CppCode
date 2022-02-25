#include <iostream>
using namespace std;

class Date
{
public:
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    bool operator==(const Date &d) const
    //==> bool operator==(const Date* this, const Date &d)
    //ȷ��thisָ������ݲ����޸ģ������ź���д��const
    //��������в�С���޸��˳�Ա����������ʱ���ܼ�����
    {
        if (_year == d._year && _month == d._month && _day == d._day)
        {
            return true;
        }
        return false;
    }
    void Print() const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    //��Ա�����У������������Ժ��ڳ�Ա����Ա����/��Ա������ǰ�����this->
    void Fun1()
    {
        Print(); // this->Print();
    }

    Date *operator&()
    {
        return this;
    }

    const Date *operator&() const
    {
        return this;
    }

    // //d1 << cout; �������ò��У��ǳ���ֱ��
    // //��һ������������������ڶ����������Ҳ�����
    // void operator<<(ostream& out)//void operator<<(Date* this, ostream& out)
    // {
    //     //cout��������out����cout����
    //     //�������Ϳ���ֱ����cout���
    //     out << _year << "-" << _month << "-" << _day << endl;
    // }

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &out, const Date &d)
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
    return out;
}
istream &operator>>(istream &in, Date &d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
// int main(int argc, char const *argv[])
// {
//     Date d1(2022, 2, 22);
//     Date d2(2022, 2, 22);
//     // cout << (d1 == d2) << endl;
//     // d1.Fun1();
//     // cout << &d1 << endl;
//     // &d2;
//     cin >> d1 >> d2;
//     cout << d1 << endl
//          << d2 << endl;
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int x = 5, y = 7;
//     cout << (true ? (++x, ++y) : (--x, --y)) << endl;
//     system("pause");
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     unsigned char a = 200;
//     unsigned char b = 100;
//     unsigned char c = 0;
//     c = a + b;
//     printf("%d %d", a + b, c); //300 44
//     system("pause");
// }
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// #include<stdio.h>
// //ת��Ϊ��ά�������⣬��һ�ж��Խ��߶���1
// int main()
// {
// 	int arr[10][10] = { 0 };
// 	int i = 0;
// 	int j = 0;
// 	for (i = 0; i < 10; i++)
// 	{
//         for(int k = 0; k < 10-i; k++)
//             {
//                 printf(" ");
//             }
// 		for (j = 0; j <= i; j++)
// 		{
// 			if (j == 0)//��һ��
// 				arr[i][j] = 1;
// 			if (i == j)//�Խ���
// 				arr[i][j] = 1;
// 			if (i >= 2 && j >= 1)
// 				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
// 			printf("%2d ", arr[i][j]);
// 		}
// 		printf("\n");
// 	}
//     system("pause");
// 	return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int arr[10] = {0};
//     printf("arr = %p\n", arr);
//     printf("&arr = %p\n", &arr);

//     printf("&(arr[0]) = %p\n", &(arr[0]));
//     printf(" &(arr[0])+1) = %p\n", &(arr[0]) + 1);

//     printf("arr+1 = %p\n", arr + 1);
//     printf("&arr+1= %p\n", &arr + 1);
//     system("pause");
//     return 0;
// }
// // arr = 0000001bac7ffd00
// // &arr = 0000001bac7ffd00
// // &(arr[0]) = 0000001bac7ffd00
// //  &(arr[0])+1) = 0000001bac7ffd04
// // arr+1 = 0000001bac7ffd04
// // &arr+1= 0000001bac7ffd28

#include <stdio.h>
// int main()
// {
//     int arr[10] = {0};
//     printf("arr = %p\n", arr);
//     printf("arr+1 = %p\n", arr + 1);

//     printf("&(arr[0]) = %p\n", &(arr[0]));
//     printf(" &(arr[0])+1) = %p\n", &(arr[0]) + 1);

//     printf("arr+1 = %p\n", arr + 1);
//     printf("&arr+1= %p\n", &arr + 1);
//     system("pause");
//     return 0;
// }
// arr = 000000e0f57ffd20
// arr+1 = 000000e0f57ffd24
// &(arr[0]) = 000000e0f57ffd20
//  &(arr[0])+1) = 000000e0f57ffd24
// arr+1 = 000000e0f57ffd24
// &arr+1= 000000e0f57ffd48

// int main()
// {
//     char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
//     char **cp[] = {c + 3, c + 2, c + 1, c}; // c��char*��char*��ַ��char**���
//     char ***cpp = cp;                       // cp��char**��char**�ĵ�ַ��char***���
//     printf("%s\n", **++cpp);                //++֮��cppָ��c+2����һ�ν����õõ���c+2��c+2���c�е�����Ԫ�ص�ַ���ٴν����õõ�����c�е�����Ԫ�ش�Ķ�����Ҳ����POINT\0�ĵ�ַ

//     printf("%s\n", *--*++cpp + 3); //����++cpp����ʱcppָ��c+1����һ�ν����õõ���cp�е�����Ԫ�ص����ݣ�Ҳ����c+1����ִ��*--����--ʹ��c+1���c��ָ�����c�е�һ��Ԫ�أ����ٽ����ã��õ�c�е�һ��Ԫ�����ݣ�Ҳ����ENTER\0����Ԫ�ص�ַ�������+3���õ��ľ���ER

//     printf("%s\n", *cpp[-2] + 3); //**(cpp-2)+3
//                                   // cpp-2ָ��ľ���c+3����һ�ν����õõ���c+3���ٴν����õõ��ľ���FIRST\0�ĵ�ַ�����+3��ָ��ľ���ST�����մ�ӡ�ľ���ST

//     printf("%s\n", cpp[-1][-1] + 1); //*(*(cpp-1)-1)+1
//                                      // cpp-1ָ��ľ���c+2�������õõ�c+2����-1�ͱ��c+1���ٴν����õõ��ľ���NEW\0��ַ��+1ָ��ľ���EW\0
//     // z
//     system("pause");
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <assert.h>
// char* my_strcat(char* dest, const char* src)
// {
// 	char* ret = dest;
// 	assert(dest && src);//�ж��Ƿ�Ϊ��ָ��
// 	//1.���ҵ�Ŀ��ռ��\0
// 	while (*dest)
// 	{
// 		dest++;
// 	}

// 	//2.׷�����ݵ�Ŀ��ռ�
// 	while (*dest++ = *src++)
// 	{
// 		;
// 	}
// 	return ret;
// }
// int main()
// {
// 	char arr1[30] = "hello";
// 	char arr2[] = " world";
// 	printf("%s\n", my_strcat(arr1, arr2));
// 	return 0;
// }

// char* my_strncpy(char* dest, const char* src, size_t count)
// {
// 	assert(dest && src);
// 	int i = 0;
// 	for ( i = 0; src[i] && (i < count); i++)//src�����\0���ܿ���ȥ
// 	{
// 		dest[i] = src[i];
// 	}

// 	//���src�����ݸ���С��count
// 	if (i < count)
// 	{
// 		dest[i] = 0;
// 	}
// 	return dest;
// }
// int main()
// {
// 	char arr1[] = "xxxxxxxxxx";
// 	char arr2[] = "hel";
// 	my_strncpy(arr1, arr2, 5);
// 	printf("%s\n", arr1);//hel
//     system("pause");
// 	return 0;
// }

// //����ʹ��forѭ��
// int main()
// {
// 	const char* p = "@.";//�������˳������
// 	char arr[] = "yzq2076188013@qq.com";
// 	char buff[50] = { 0 };
// 	strcpy(buff, arr);
// 	char* str = NULL;
// 	for (str = strtok(buff, p); str != NULL; str = strtok(NULL, p))
// 	{
// 		printf("%s\n",str);
// 	}
//     system("pause");
// 	return 0;
// }
// int main(int argc, char const *argv[])
// {
//     // printf("%s\n",__FILE__);//D:\code\2022code\Cpp_Code\2-22-Class&object 02\src\test.cpp
//     // printf("%s\n",__TIME__);
//     //��¼��־
//     FILE *pf = fopen("log.txt", "w");
//     if (pf == nullptr)
//     {
//         printf("fopen fail\n");
//         return 1;
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         fprintf(pf, "%s %s %s %d %d\n", __DATE__, __TIME__, __LINE__, __FILE__, i);
//     }
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }

// int main()
// {
// 	int i = 0;
// 	int j = 0;
// 	int count = 0;
// 	for (i = 100; i <= 20000; ++i)
// 	{
// 		for (j = 2; j < i; ++j)
// 		{
// 			if (i%j == 0)
// 				break;
// 		}
// 		if (j == i)
// 		{
// 			printf("%d������\n", i);
// 			count++;
// 		}
// 	}
// 	printf("%d\n", count);
// 	system("pause");
// 	return 0;
// }
// int main(int argc, char const *argv[])
// {
//     int sum = 0, tmp = 0;
//     for (int i = 1; i <= 100; i++)
//     {
//         /* code */
//         tmp += i;
//         sum += tmp;
//     }
//     printf("%d", sum);
//     system("pause");
//     return 0;
// }
// #define MAX 1000
// #define reg register �0�2 �0�2 �0�2 �0�2 �0�2 //Ϊ register����ؼ��֣�����һ����̵�����
// #define do_forever \
//     for (;;)       \
//     �0�2 �0�2 //�ø�����ķ������滻һ��ʵ��
// #define CASE \
//     break;   \
//     case �0�2 �0�2 �0�2 �0�2 //��дcase����ʱ���Զ��� breakд�ϡ�
// // �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
// #define DEBUG_PRINT printf("file:%s\tline:%d\tdate:%s\ttime:%s\n", __FILE__, __LINE__, __DATE__, __TIME__)
#define PRINT(n) printf("the value of "#n" is %d\n",n)
#define CAT(c,num) c##num
int main(int argc, char const *argv[])
{
    // int a = 10;
    // int b = 20;
    // PRINT(a);//the value of a is 10
    // PRINT(b);//the value of b is 20
    int Class104 = 10000;
    printf("%d\n",CAT(Class,104));//Class104  10000
    system("pause");
    return 0;
}
