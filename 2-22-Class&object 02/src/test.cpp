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
//     //确保this指向的内容不被修改，在括号后面写上const
//     //如果函数中不小心修改了成员变量，编译时就能检查出来
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
//     //成员函数中，编译器处理以后在成员（成员变量/成员函数）前面加上this->
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

//     // //d1 << cout; 这样调用才行，非常反直觉
//     // //第一个参数是左操作数，第二个参数是右操作数
//     // void operator<<(ostream& out)//void operator<<(Date* this, ostream& out)
//     // {
//     //     //cout传进来，out就是cout别名
//     //     //内置类型可以直接用cout输出
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
// // //转换为二维数组问题，第一列都对角线都是1
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
// // 			if (j == 0)//第一列
// // 				arr[i][j] = 1;
// // 			if (i == j)//对角线
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
// //     char **cp[] = {c + 3, c + 2, c + 1, c}; // c是char*，char*地址用char**存放
// //     char ***cpp = cp;                       // cp是char**，char**的地址用char***存放
// //     printf("%s\n", **++cpp);                //++之后cpp指向c+2，第一次解引用得到的c+2，c+2存的c中第三个元素地址，再次解引用得到就是c中第三个元素存的东西，也就是POINT\0的地址

// //     printf("%s\n", *--*++cpp + 3); //先算++cpp，此时cpp指向c+1，第一次解引用得到的cp中第三个元素的内容，也就是c+1，再执行*--，先--使得c+1变成c，指向的是c中第一个元素，，再解引用，得到c中第一个元素内容，也就是ENTER\0的首元素地址，最后再+3，得到的就是ER

// //     printf("%s\n", *cpp[-2] + 3); //**(cpp-2)+3
// //                                   // cpp-2指向的就是c+3，第一次解引用得到的c+3，再次解引用得到的就是FIRST\0的地址，最后+3，指向的就是ST，最终打印的就是ST

// //     printf("%s\n", cpp[-1][-1] + 1); //*(*(cpp-1)-1)+1
// //                                      // cpp-1指向的就是c+2，解引用得到c+2，再-1就变成c+1，再次解引用得到的就是NEW\0地址，+1指向的就是EW\0
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
// // 	assert(dest && src);//判断是否为空指针
// // 	//1.先找到目标空间的\0
// // 	while (*dest)
// // 	{
// // 		dest++;
// // 	}

// // 	//2.追加内容到目标空间
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
// // 	for ( i = 0; src[i] && (i < count); i++)//src里面的\0不能拷进去
// // 	{
// // 		dest[i] = src[i];
// // 	}

// // 	//如果src的数据个数小于count
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

// // //巧妙使用for循环
// // int main()
// // {
// // 	const char* p = "@.";//这个无需顺序区分
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
// //     //记录日志
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
// // 			printf("%d是素数\n", i);
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
// // #define reg register           //为 register这个关键字，创建一个简短的名字
// // #define do_forever \
// //     for (;;)       \
// //         //用更形象的符号来替换一种实现
// // #define CASE \
// //     break;   \
// //     case         //在写case语句的时候自动把 break写上。
// // // 如果定义的 stuff过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。
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
// //     // // fgetc();//读取一个字符同时就会拿走那个字符
// //     // int a = 2;
// //     // int b = ++a; // b=3,a=3  副作用
// //     // int c = a + 1;//b=3,a=2  无副作用

// //     // int a = 3;
// //     // int b = 5;
// //     // int m = MAX(a++,b++);
// //     // //实际上是直接把a++，b++替换进去的
// //     // //int m = ((a++)>(b++))?(a++):(b++)
// //     // printf("%d\n",m);//6
// //     // printf("%d %d\n",a,b);//4 7
// //     int* p2 = MALLOC(10,int);//函数的参数可不能传类型，宏才可以
// //     system("pause");
// //     return 0;
// // }
// // #define MAX(x,y) ((x)>(y))?(x):(y)
// // int main(int argc, char const *argv[])
// // {
// // #undef MAX
// //     int a = 3;
// //     int b = 5;
// //     //int m = MAX(a,b);//err 不能用了
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
// // //         printf("%d\n", arr[i]); //为了观察数组是否赋值成功。
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
// // #if 常量表达式
// // //...
// // #endif
// //     //常量表达式由预处理器求值。
// //     如：
// // #define __DEBUG__ 1
// // #if __DEBUG__
// // //..
// // #endif
// //     2.多个分支的条件编译
// // #if 常量表达式
// // //...
// // #elif 常量表达式
// // //...
// // #else
// // //...
// // #endif
// //     3.判断是否被定义
// // #if defined(symbol)
// // #ifdef symbol
// // #if !defined(symbol)
// // #ifndef symbol
// //     4.嵌套指令
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
// //     INVALID, //非法
// //     VALID    //合法
// // };
// // enum State status = INVALID;
// // int MyAtoi(const char *str)
// // {
// //     assert(str);
// //     //空字符串
// //     if (*str == '\0')
// //         return 0; //此时的status全局变量是INVALID
// //     //跳过空白字符
// //     while (isspace(*str))
// //     {
// //         str++;
// //     }
// //     //正负号
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
// //     //只遍历数字字符
// //     long long n = 0;
// //     while (isdigit(*str))
// //     {
// //         n = n * 10 + flag * (*str - '0');
// //         //处理越界的值
// //         if (n > INT_MAX || n < INT_MIN)
// //         {
// //             return 0; //没法转换了
// //         }
// //         str++;
// //     }
// //     if (*str == '\0')
// //     {
// //         status = VALID; //正常情况的返回
// //         return (int)n;
// //     }

// //     //其他情况都是非法返回
// //     return n;
// // }
// // // 1.空指针
// // // 2.空字符串，空白字符
// // // 3.+-
// // // 4.非数字字符
// // // 5.超大数字
// // int main(int argc, char const *argv[])
// // {
// //     int ret = MyAtoi("  -123");
// //     if (status == VALID)
// //         printf("%d\n", ret);
// //     else
// //         printf("非法返回\n");
// //     system("pause");
// //     return 0;
// // }

// // 10
// // 00000000000000000000000000001010  -10
// // 01010101010101010101010101010101  按位与就能保留所有的奇数位，偶数位置0
// // 0x55555555
// // 01010101010101010101010101010101  按位与就能保留所有的偶数位，奇数位置0，
// // 0xAAAAAAAA
// //分别<< >> 即可，二者再相加即可
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

// //计算结构体中某变量相对于首地址的偏移
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
// //         // n比b大时换下一个斐波那契数
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
//   // 请在此输入您的代码
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
    Person man;   //类的实例化
    man.PrintPersonInfo();
}