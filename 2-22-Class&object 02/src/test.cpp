// #include <iostream>
// using namespace std;

// class Date
// {
// public:
//     friend ostream &operator<<(ostream &out, const Date &d);
//     friend istream &operator>>(istream &in, Date &d);
//     Date(int year = 0, int month = 1, int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     bool operator==(const Date &d) const
//     //==> bool operator==(const Date* this, const Date &d)
//     //ȷ��thisָ������ݲ����޸ģ������ź���д��const
//     //��������в�С���޸��˳�Ա����������ʱ���ܼ�����
//     {
//         if (_year == d._year && _month == d._month && _day == d._day)
//         {
//             return true;
//         }
//         return false;
//     }
//     void Print() const
//     {
//         cout << _year << "-" << _month << "-" << _day << endl;
//     }
//     //��Ա�����У������������Ժ��ڳ�Ա����Ա����/��Ա������ǰ�����this->
//     void Fun1()
//     {
//         Print(); // this->Print();
//     }

//     Date *operator&()
//     {
//         return this;
//     }

//     const Date *operator&() const
//     {
//         return this;
//     }

//     // //d1 << cout; �������ò��У��ǳ���ֱ��
//     // //��һ������������������ڶ����������Ҳ�����
//     // void operator<<(ostream& out)//void operator<<(Date* this, ostream& out)
//     // {
//     //     //cout��������out����cout����
//     //     //�������Ϳ���ֱ����cout���
//     //     out << _year << "-" << _month << "-" << _day << endl;
//     // }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// ostream &operator<<(ostream &out, const Date &d)
// {
//     out << d._year << "-" << d._month << "-" << d._day << endl;
//     return out;
// }
// istream &operator>>(istream &in, Date &d)
// {
//     in >> d._year >> d._month >> d._day;
//     return in;
// }
// // int main(int argc, char const *argv[])
// // {
// //     Date d1(2022, 2, 22);
// //     Date d2(2022, 2, 22);
// //     // cout << (d1 == d2) << endl;
// //     // d1.Fun1();
// //     // cout << &d1 << endl;
// //     // &d2;
// //     cin >> d1 >> d2;
// //     cout << d1 << endl
// //          << d2 << endl;
// //     system("pause");
// //     return 0;
// // }

// // int main(int argc, char const *argv[])
// // {
// //     int x = 5, y = 7;
// //     cout << (true ? (++x, ++y) : (--x, --y)) << endl;
// //     system("pause");
// //     return 0;
// // }
// // #include <stdio.h>
// // int main()
// // {
// //     unsigned char a = 200;
// //     unsigned char b = 100;
// //     unsigned char c = 0;
// //     c = a + b;
// //     printf("%d %d", a + b, c); //300 44
// //     system("pause");
// // }
// // 1
// // 1 1
// // 1 2 1
// // 1 3 3 1
// // 1 4 6 4 1
// // #include<stdio.h>
// // //ת��Ϊ��ά�������⣬��һ�ж��Խ��߶���1
// // int main()
// // {
// // 	int arr[10][10] = { 0 };
// // 	int i = 0;
// // 	int j = 0;
// // 	for (i = 0; i < 10; i++)
// // 	{
// //         for(int k = 0; k < 10-i; k++)
// //             {
// //                 printf(" ");
// //             }
// // 		for (j = 0; j <= i; j++)
// // 		{
// // 			if (j == 0)//��һ��
// // 				arr[i][j] = 1;
// // 			if (i == j)//�Խ���
// // 				arr[i][j] = 1;
// // 			if (i >= 2 && j >= 1)
// // 				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
// // 			printf("%2d ", arr[i][j]);
// // 		}
// // 		printf("\n");
// // 	}
// //     system("pause");
// // 	return 0;
// // }

// // #include <stdio.h>
// // int main()
// // {
// //     int arr[10] = {0};
// //     printf("arr = %p\n", arr);
// //     printf("&arr = %p\n", &arr);

// //     printf("&(arr[0]) = %p\n", &(arr[0]));
// //     printf(" &(arr[0])+1) = %p\n", &(arr[0]) + 1);

// //     printf("arr+1 = %p\n", arr + 1);
// //     printf("&arr+1= %p\n", &arr + 1);
// //     system("pause");
// //     return 0;
// // }
// // // arr = 0000001bac7ffd00
// // // &arr = 0000001bac7ffd00
// // // &(arr[0]) = 0000001bac7ffd00
// // //  &(arr[0])+1) = 0000001bac7ffd04
// // // arr+1 = 0000001bac7ffd04
// // // &arr+1= 0000001bac7ffd28

// #include <stdio.h>
// // int main()
// // {
// //     int arr[10] = {0};
// //     printf("arr = %p\n", arr);
// //     printf("arr+1 = %p\n", arr + 1);

// //     printf("&(arr[0]) = %p\n", &(arr[0]));
// //     printf(" &(arr[0])+1) = %p\n", &(arr[0]) + 1);

// //     printf("arr+1 = %p\n", arr + 1);
// //     printf("&arr+1= %p\n", &arr + 1);
// //     system("pause");
// //     return 0;
// // }
// // arr = 000000e0f57ffd20
// // arr+1 = 000000e0f57ffd24
// // &(arr[0]) = 000000e0f57ffd20
// //  &(arr[0])+1) = 000000e0f57ffd24
// // arr+1 = 000000e0f57ffd24
// // &arr+1= 000000e0f57ffd48

// // int main()
// // {
// //     char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
// //     char **cp[] = {c + 3, c + 2, c + 1, c}; // c��char*��char*��ַ��char**���
// //     char ***cpp = cp;                       // cp��char**��char**�ĵ�ַ��char***���
// //     printf("%s\n", **++cpp);                //++֮��cppָ��c+2����һ�ν����õõ���c+2��c+2���c�е�����Ԫ�ص�ַ���ٴν����õõ�����c�е�����Ԫ�ش�Ķ�����Ҳ����POINT\0�ĵ�ַ

// //     printf("%s\n", *--*++cpp + 3); //����++cpp����ʱcppָ��c+1����һ�ν����õõ���cp�е�����Ԫ�ص����ݣ�Ҳ����c+1����ִ��*--����--ʹ��c+1���c��ָ�����c�е�һ��Ԫ�أ����ٽ����ã��õ�c�е�һ��Ԫ�����ݣ�Ҳ����ENTER\0����Ԫ�ص�ַ�������+3���õ��ľ���ER

// //     printf("%s\n", *cpp[-2] + 3); //**(cpp-2)+3
// //                                   // cpp-2ָ��ľ���c+3����һ�ν����õõ���c+3���ٴν����õõ��ľ���FIRST\0�ĵ�ַ�����+3��ָ��ľ���ST�����մ�ӡ�ľ���ST

// //     printf("%s\n", cpp[-1][-1] + 1); //*(*(cpp-1)-1)+1
// //                                      // cpp-1ָ��ľ���c+2�������õõ�c+2����-1�ͱ��c+1���ٴν����õõ��ľ���NEW\0��ַ��+1ָ��ľ���EW\0
// //     // z
// //     system("pause");
// //     return 0;
// // }

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// // char* my_strcat(char* dest, const char* src)
// // {
// // 	char* ret = dest;
// // 	assert(dest && src);//�ж��Ƿ�Ϊ��ָ��
// // 	//1.���ҵ�Ŀ��ռ��\0
// // 	while (*dest)
// // 	{
// // 		dest++;
// // 	}

// // 	//2.׷�����ݵ�Ŀ��ռ�
// // 	while (*dest++ = *src++)
// // 	{
// // 		;
// // 	}
// // 	return ret;
// // }
// // int main()
// // {
// // 	char arr1[30] = "hello";
// // 	char arr2[] = " world";
// // 	printf("%s\n", my_strcat(arr1, arr2));
// // 	return 0;
// // }

// // char* my_strncpy(char* dest, const char* src, size_t count)
// // {
// // 	assert(dest && src);
// // 	int i = 0;
// // 	for ( i = 0; src[i] && (i < count); i++)//src�����\0���ܿ���ȥ
// // 	{
// // 		dest[i] = src[i];
// // 	}

// // 	//���src�����ݸ���С��count
// // 	if (i < count)
// // 	{
// // 		dest[i] = 0;
// // 	}
// // 	return dest;
// // }
// // int main()
// // {
// // 	char arr1[] = "xxxxxxxxxx";
// // 	char arr2[] = "hel";
// // 	my_strncpy(arr1, arr2, 5);
// // 	printf("%s\n", arr1);//hel
// //     system("pause");
// // 	return 0;
// // }

// // //����ʹ��forѭ��
// // int main()
// // {
// // 	const char* p = "@.";//�������˳������
// // 	char arr[] = "yzq2076188013@qq.com";
// // 	char buff[50] = { 0 };
// // 	strcpy(buff, arr);
// // 	char* str = NULL;
// // 	for (str = strtok(buff, p); str != NULL; str = strtok(NULL, p))
// // 	{
// // 		printf("%s\n",str);
// // 	}
// //     system("pause");
// // 	return 0;
// // }
// // int main(int argc, char const *argv[])
// // {
// //     // printf("%s\n",__FILE__);//D:\code\2022code\Cpp_Code\2-22-Class&object 02\src\test.cpp
// //     // printf("%s\n",__TIME__);
// //     //��¼��־
// //     FILE *pf = fopen("log.txt", "w");
// //     if (pf == nullptr)
// //     {
// //         printf("fopen fail\n");
// //         return 1;
// //     }
// //     for (int i = 0; i < 10; i++)
// //     {
// //         fprintf(pf, "%s %s %s %d %d\n", __DATE__, __TIME__, __LINE__, __FILE__, i);
// //     }
// //     fclose(pf);
// //     pf = nullptr;
// //     system("pause");
// //     return 0;
// // }

// // int main()
// // {
// // 	int i = 0;
// // 	int j = 0;
// // 	int count = 0;
// // 	for (i = 100; i <= 20000; ++i)
// // 	{
// // 		for (j = 2; j < i; ++j)
// // 		{
// // 			if (i%j == 0)
// // 				break;
// // 		}
// // 		if (j == i)
// // 		{
// // 			printf("%d������\n", i);
// // 			count++;
// // 		}
// // 	}
// // 	printf("%d\n", count);
// // 	system("pause");
// // 	return 0;
// // }
// // int main(int argc, char const *argv[])
// // {
// //     int sum = 0, tmp = 0;
// //     for (int i = 1; i <= 100; i++)
// //     {
// //         /* code */
// //         tmp += i;
// //         sum += tmp;
// //     }
// //     printf("%d", sum);
// //     system("pause");
// //     return 0;
// // }
// // #define MAX 1000
// // #define reg register �0�2 �0�2 �0�2 �0�2 �0�2 //Ϊ register����ؼ��֣�����һ����̵�����
// // #define do_forever \
// //     for (;;)       \
// //     �0�2 �0�2 //�ø�����ķ������滻һ��ʵ��
// // #define CASE \
// //     break;   \
// //     case �0�2 �0�2 �0�2 �0�2 //��дcase����ʱ���Զ��� breakд�ϡ�
// // // �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
// // #define DEBUG_PRINT printf("file:%s\tline:%d\tdate:%s\ttime:%s\n", __FILE__, __LINE__, __DATE__, __TIME__)
// // #define PRINT(n) printf("the value of " #n " is %d\n", n)
// // #define CAT(c, num) c##num
// // #define MAX(x, y) ((x) > (y)) ? (x) : (y)
// // #define MALLOC(num,type) (type*)malloc(num*sizeof(type))
// // int main(int argc, char const *argv[])
// // {
// //     // int a = 10;
// //     // int b = 20;
// //     // PRINT(a);//the value of a is 10
// //     // PRINT(b);//the value of b is 20
// //     // int Class104 = 10000;
// //     // printf("%d\n",CAT(Class,104));//Class104  10000

// //     // getchar();
// //     // // fgetc();//��ȡһ���ַ�ͬʱ�ͻ������Ǹ��ַ�
// //     // int a = 2;
// //     // int b = ++a; // b=3,a=3  ������
// //     // int c = a + 1;//b=3,a=2  �޸�����

// //     // int a = 3;
// //     // int b = 5;
// //     // int m = MAX(a++,b++);
// //     // //ʵ������ֱ�Ӱ�a++��b++�滻��ȥ��
// //     // //int m = ((a++)>(b++))?(a++):(b++)
// //     // printf("%d\n",m);//6
// //     // printf("%d %d\n",a,b);//4 7
// //     int* p2 = MALLOC(10,int);//�����Ĳ����ɲ��ܴ����ͣ���ſ���
// //     system("pause");
// //     return 0;
// // }
// // #define MAX(x,y) ((x)>(y))?(x):(y)
// // int main(int argc, char const *argv[])
// // {
// // #undef MAX
// //     int a = 3;
// //     int b = 5;
// //     //int m = MAX(a,b);//err ��������
// //     printf("%d\n",m);
// //     system("pause");
// //     return 0;
// // }

// // #include <stdio.h>
// // #define M 0
// // int main()
// // {
// // //     int i = 0;
// // //     int arr[10] = {0};
// // //     for (i = 0; i < 10; i++)
// // //     {
// // //         arr[i] = i;

// // // #if 1
// // //         printf("%d\n", arr[i]); //Ϊ�˹۲������Ƿ�ֵ�ɹ���
// // // #endif
// // //     }
// // #if defined(M)
// //     printf("hehe\n");
// // #endif

// // #ifdef M
// //     printf("haha\n");
// // #endif

// // #if !defined(M)
// //     printf("hehe\n");
// // #endif

// // #ifndef M
// //     printf("haha\n");
// // #endif

// //     system("pause");
// //     return 0;
// // }
// // 1.
// // #if �������ʽ
// // //...
// // #endif
// //     //�������ʽ��Ԥ��������ֵ��
// //     �磺
// // #define __DEBUG__ 1
// // #if __DEBUG__
// // //..
// // #endif
// //     2.�����֧����������
// // #if �������ʽ
// // //...
// // #elif �������ʽ
// // //...
// // #else
// // //...
// // #endif
// //     3.�ж��Ƿ񱻶���
// // #if defined(symbol)
// // #ifdef symbol
// // #if !defined(symbol)
// // #ifndef symbol
// //     4.Ƕ��ָ��
// // #if defined(OS_UNIX)
// // #ifdef OPTION1
// //     unix_version_option1();
// // #endif
// // #ifdef OPTION2
// // unix_version_option2();
// // #endif
// // #elif defined(OS_MSDOS)
// // #ifdef OPTION2
// //     msdos_version_option2();
// // #endif
// // #endif

// // #include <stdio.h>
// // #include <assert.h>
// // #include <ctype.h>
// // enum State
// // {
// //     INVALID, //�Ƿ�
// //     VALID    //�Ϸ�
// // };
// // enum State status = INVALID;
// // int MyAtoi(const char *str)
// // {
// //     assert(str);
// //     //���ַ���
// //     if (*str == '\0')
// //         return 0; //��ʱ��statusȫ�ֱ�����INVALID
// //     //�����հ��ַ�
// //     while (isspace(*str))
// //     {
// //         str++;
// //     }
// //     //������
// //     int flag = 1;
// //     if (*str == '+')
// //     {
// //         flag = 1;
// //         str++;
// //     }
// //     else if (*str == '-')
// //     {
// //         flag = -1;
// //         str++;
// //     }
// //     //ֻ���������ַ�
// //     long long n = 0;
// //     while (isdigit(*str))
// //     {
// //         n = n * 10 + flag * (*str - '0');
// //         //����Խ���ֵ
// //         if (n > INT_MAX || n < INT_MIN)
// //         {
// //             return 0; //û��ת����
// //         }
// //         str++;
// //     }
// //     if (*str == '\0')
// //     {
// //         status = VALID; //��������ķ���
// //         return (int)n;
// //     }

// //     //����������ǷǷ�����
// //     return n;
// // }
// // // 1.��ָ��
// // // 2.���ַ������հ��ַ�
// // // 3.+-
// // // 4.�������ַ�
// // // 5.��������
// // int main(int argc, char const *argv[])
// // {
// //     int ret = MyAtoi("  -123");
// //     if (status == VALID)
// //         printf("%d\n", ret);
// //     else
// //         printf("�Ƿ�����\n");
// //     system("pause");
// //     return 0;
// // }

// // 10
// // 00000000000000000000000000001010  -10
// // 01010101010101010101010101010101  ��λ����ܱ������е�����λ��ż��λ��0
// // 0x55555555
// // 01010101010101010101010101010101  ��λ����ܱ������е�ż��λ������λ��0��
// // 0xAAAAAAAA
// //�ֱ�<< >> ���ɣ���������Ӽ���
// // #define SWAPODDEVEN(x) ((x) = (((x & 0x55555555) << 1) + ((x & 0xAAAAAAAA) >> 1)))
// // int main(int argc, char const *argv[])
// // {
// //     int x = 10;
// //     SWAPODDEVEN(x);
// //     printf("%d\n", x);
// //     system("pause");
// //     return 0;
// // // }
// // #include <stddef.h>
// // #include <stdio.h>
// // struct S
// // {
// //     char c;
// //     int a;
// //     double d;
// // };

// //����ṹ����ĳ����������׵�ַ��ƫ��
// // #define OFFSETOF(sName, mName) (int)&(((sName*)0)->mName)
// // int main(int argc, char const *argv[])
// // {
// //     // struct S s = {0};
// //     // printf("%d\n",OFFSETOF(struct S, c));//0
// //     // printf("%d\n",offsetof(struct S, c));//0
// //     // printf("%d\n",OFFSETOF(struct S, a));//4
// //     // printf("%d\n",offsetof(struct S, a));//4
// //     // printf("%d\n",OFFSETOF(struct S, d));//8
// //     // printf("%d\n",offsetof(struct S, d));//8
// //     // int a = -3;
// //     // unsigned int b = 2;
// //     // long c = a + b;
// //     // printf("%ld\n",c);
// //     char a =0,ch;
// //     while ((ch=getchar())!='\n')
// //     {
// //         if(a%2 != 0 && (ch >='a') && ch <='z')
// //         {
// //             ch = ch - 'a' + 'A';
// //         }
// //         a++;
// //         putchar(ch);
// //     }
// //     printf("\n");

// //     system("pause");
// //     return 0;
// // }

// // 10000000000000000000000000000011
// // 11111111111111111111111111111100
// // 11111111111111111111111111111101

// // 00000000000000000000000000000010
// // 11111111111111111111111111111111

// // int Add(int num1, int num2)
// // {
// //     while (num2)
// //     {
// //         int tmp = (num1 & num2) << 1;
// //         //if tmp != 0  need carry bit
// //         num1 ^= num2;
// //         num2 = tmp;
// //     }
// //     return num1;
// // }
// // //assume str point to the space  is enough

// // void ReplaceSpace(char *str, int length)
// // {
// //     int spaceCount = 0;
// //     char *cur = str; // don't change str
// //     // Determine the number of Spaces
// //     while (cur)
// //     {
// //         if (*cur == ' ')
// //         {
// //             spaceCount++;
// //         }
// //         cur++;
// //     }
// //     //%20 3character space == 1character
// //     // only add 2*spaceCount
// //     int newLen = length + spaceCount * 2;
// //     // control the end
// //     int end1 = length - 1;
// //     int end2 = newLen - 1;
// //     while (end1 != end2)
// //     {
// //         if(str[end1] != ' ')
// //         {
// //             str[end2--] = str[end1--];
// //         }
// //         else
// //         {
// //             str[end2--] = '0';
// //             str[end2--] = '2';
// //             str[end2--] = '%';
// //             end1--;
// //         }
// //     }
// // }
// // int main(int argc, char const *argv[])
// // {
// //     int n = 0;
// //     int a = 0;
// //     int b = 1;
// //     int c = a + b;
// //     scanf("%d", &n);
// //     while (1)
// //     {
// //         if (n == b)
// //         {
// //             printf("%d\n", 0);
// //             break;
// //         }
// //         else if (n < b) // Between a and b
// //         {
// //             if (abs(a - n) < abs(b - n))
// //             {
// //                 printf("%d\n", abs(a - n));
// //                 break;
// //             }
// //             else
// //             {
// //                 printf("%d\n", abs(b - n));
// //                 ;
// //                 break;
// //             }
// //         }
// //         // n��b��ʱ����һ��쳲�������
// //         a = b;
// //         b = c;
// //         c = a + b;
// //     }
// //     return 0;
// // }
#include <iostream>
using namespace std;
// int ComDiv(int x,int y)
// {
//   int tmp = x>y?y:x;
//   while(tmp > 0)
//   {
//     if(x % tmp == 0 && y % tmp == 0)
//     {
//       break;
//     }
//     tmp--;
//   }
//   return tmp;
// }
// int main()
// {
//   // ���ڴ��������Ĵ���
//   int count = 0;
//   for(int i = 1; i <= 2020; i++)
//   {
//     for(int j = 1; j <= 2020; j++)
//     {
//       if(ComDiv(i,j)==1)
//       {
//         count++;
//       }
//     }
//   }
//   cout << count << endl;
//   system("pause");
//   return 0;
// }

class Person
{
public:
    void PrintPersonInfo();
private:
    char _name[20];
    char _gender[3];
    int _age;
};

void test()
{
    Person man;   //���ʵ����
    man.PrintPersonInfo();
}