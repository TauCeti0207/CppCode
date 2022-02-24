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