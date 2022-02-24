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
    //确保this指向的内容不被修改，在括号后面写上const
    //如果函数中不小心修改了成员变量，编译时就能检查出来
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
    //成员函数中，编译器处理以后在成员（成员变量/成员函数）前面加上this->
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

    // //d1 << cout; 这样调用才行，非常反直觉
    // //第一个参数是左操作数，第二个参数是右操作数
    // void operator<<(ostream& out)//void operator<<(Date* this, ostream& out)
    // {
    //     //cout传进来，out就是cout别名
    //     //内置类型可以直接用cout输出
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
// //转换为二维数组问题，第一列都对角线都是1
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
// 			if (j == 0)//第一列
// 				arr[i][j] = 1;
// 			if (i == j)//对角线
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
int main()
{
    int arr[10] = {0};
    printf("arr = %p\n", arr);
    printf("arr+1 = %p\n", arr + 1);

    printf("&(arr[0]) = %p\n", &(arr[0]));
    printf(" &(arr[0])+1) = %p\n", &(arr[0]) + 1);

    printf("arr+1 = %p\n", arr + 1);
    printf("&arr+1= %p\n", &arr + 1);
    system("pause");
    return 0;
}
// arr = 000000e0f57ffd20
// arr+1 = 000000e0f57ffd24
// &(arr[0]) = 000000e0f57ffd20
//  &(arr[0])+1) = 000000e0f57ffd24
// arr+1 = 000000e0f57ffd24
// &arr+1= 000000e0f57ffd48