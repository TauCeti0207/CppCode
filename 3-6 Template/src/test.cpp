// #include <iostream>
// using namespace std;

// //函数模板
// template <class T, class T2> // Type
// void Swap(T &x1, T &x2)
// {
//     T tmp = x1;
//     x1 = x2;
//     x2 = tmp;
// }
// T Add(T x1, T x2)
// {
//     return x1 + x2;
// }
// int main(int argc, char const *argv[])
// {
//     int a = 10, b = 20;
//     double c = 1.2, d = 3.4;
//     Swap(a, b);
//     Swap(c, d);
//     system("pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int count = 0;
//     for (int i = 1; i <= 2020; i++) //先遍历1-2020
//     {
//         int tmp = i;
//         while (tmp)
//         {
//             if (tmp % 10 == 2)
//             {
//                 count++;
//             }
//             tmp /= 10;
//         }
//     }
//     cout << count << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// //当1用完的时候就是最大的数字
// int main(int argc, char const *argv[])
// {
//     int card = 2021; // 1号卡片剩余数量
//     //从1开始
//     int i = 1;
//     while (1)
//     {
//         int count = 0;
//         int tmp = i;
//         while (tmp) // tmp有几个1
//         {
//             if (tmp % 10 == 1)
//             {
//                 count++;
//             }
//             tmp /= 10;
//         }
//         card -= count; //每一次都要减去count
//         if (card < 0)//card = 0时表示刚好用完
//         {
//             i--; //当进入if里面说明此时的i是不能顺利拼出来的，只有上一个i才拼出来的。
//             cout << i << endl;
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// //模拟
// int main(int argc, char const *argv[])
// {
//     int i = 1;
//     int arr[10] = {2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021};
//     while (1)
//     {
//         int tmp = i; //临时保存i，并一位一位拆下来
//         while (tmp)
//         {
//             if (arr[tmp % 10] == 0) //有一种卡片不够用了
//             {
//                 cout << i - 1 << endl; //恰好=0时表明当前的i是不满足条件的，前一个i恰好能拼成功
//                 return 0;
//             }
//             arr[tmp % 10]--;
//             tmp /= 10;
//         }
//         i++;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int card = 2021; // 记录剩余的卡片数量，当剩余卡片数量小于0时，退出循环
//     int i = 1;
//     while (1)
//     {
//         int count = 0; // 记录当前数字含有1的个数
//         int m = i;
//         while (m)
//         {
//             int temp = m % 10;
//             // 用temp变量接收当前数字的最后一位，判断如果是1，count值加一
//             // 可以通过分析得出，一定是卡片1先用完，所有判断每个数字里含有1的个数
//             // 用卡片总数2021减去每个数字里含有1的个数
//             // 临界值判断：当最后一个合法的数字拼完时，1号卡片剩余个数应该等于0或大于0
//             // 并且进入下一个循环，i的值会再加一，这次i不能满足条件，退出循环
//             // 而我们要的是满足条件的ii，也就是退出循环的i的上一个值，将i-1
//             // 得到我们要的值，也就是2021张卡片能拼到的最大的数字
//             if (temp == 1)
//             {
//                 count++;
//             }
//             m = m / 10;
//             // 将当前数字除以10，相当于去除掉最后一位，比如对11除以10，得到的数字就是1，直到m的值为0时，退出
//         }
//         card -= count;
//         if (card < 0)
//         { // 当剩余卡片数量小于0时，退出循环
//             i--;
//             cout << i << endl;
//             return 0;
//         }
//         i++; //当前数字满足条件之后，取下一个数字，将变量i的值加1
//     }
//     return 0;
// }
#include <iostream>
#include <memory.h>
using namespace std;
// //二维数组模拟矩阵
// int main(int argc, char const *argv[])
// {
//     int m, n;
//     cin >> m >> n; // m行n列
//     int arr[201][201];
//     memset(arr, -1, sizeof(arr)); // memset这样用才好
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     int total = 0; //总数
//     int i = 0, j = 0;
//     while (total < m * n)
//     {
//         //向下打印
//         while (i <= m - 1 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             i++;
//             total++;
//         }
//         //向右打印
//         i--; // i多加了一次，超出矩阵范围需要减掉
//         j++; // j去下一列
//         while (j <= n - 1 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             j++;
//             total++;
//         }
//         //向上打印
//         j--; //同理，需要减去多加一次的j
//         i--; //指向上一行
//         while (i >= 0 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             i--;
//             total++;
//         }
//         //向左打印
//         i++;
//         j--;
//         while (j >= 0 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             j--;
//             total++;
//         }
//         j++;
//         i++; //继续重新遍历一遍
//     }
//     cout << endl;
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int md[11] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return 0;
}
