#include <iostream>
using namespace std;
#include <vector>
#include <assert.h>

// //函数模板
// template <class T> // Type
// // void Swap(T &x1, T &x2)
// // {
// //     T tmp = x1;
// //     x1 = x2;
// //     x2 = tmp;
// // }
// T Add(const T &x1, const T &x2)
// {
//     return x1 + x2;
// }
// // int main(int argc, char const *argv[])
// // {
// //     int a = 10, b = 20;
// //     double c = 1.2, d = 3.4;
// //     Swap(a, b);
// //     Swap(c, d);
// //     system("pause");
// //     return 0;
// // }
// int main(int argc, char const *argv[])
// {
//     int a = 10, b = 20;
//     double c = 1.2, d = 3.4;
//     Add(a, b);
//     Add(c, d);

//     //cout << Add(a, c) << endl; //err
//     //不让编译器推演泪腺，显示指定类型
//     //显示实例化
//     cout << Add<int>(a, c) << endl;
//     cout << Add<double>(a, c) << endl;
//     system("pause");
//     return 0;
// }

// //专门处理int的加法函数
// int Add(int left, int right)
// {
//     return left + right;
// }

// // 通用加法函数
// template <class T>
// T Add(T left, T right)
// {
//     return left + right;
// }

// int main()
// {
//     Add(1, 2);      // 与非模板函数匹配，编译器不需要特化
//     Add<int>(1, 2); // 调用编译器特化的Add版本
//     return 0;
// }

// int Add(int left, int right)
// {
// 	return left + right;
// }

// // 通用加法函数
// template<class T1, class T2>
// T1 Add(T1 left, T2 right)
// {
// 	return left + right;
// }

// // 模板调用，有现成匹配函数，绝对不去实例化模板
// // 有更匹配的，优先匹配类型最合适的
// int main()
// {
// 	Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化
// 	Add(1, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//     return 0;
// }

// typedef double VDataType;

//类模板
// namespace yzq
// {
//     template <class T>
//     class vector
//     {
//     public:
//         vector()
//             : _a(nullptr), _size(0), _capacity(0)
//         {
//         }
//         ~vector()
//         {
//             delete[] _a;
//             _a = nullptr;
//             _size = _capacity = 0;
//         }
//         void push_back(const T &x)
//         {
//             if (_size == _capacity)
//             {
//                 int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                 T *tmp = new T[newcapacity];
//                 if (_a)
//                 {
//                     memcpy(tmp, _a, sizeof(T) * _size);
//                     delete[] _a;
//                 }
//                 _a = tmp;
//                 _capacity = newcapacity;
//             }
//             _a[_size] = x;
//             ++_size;
//         }
//         T &operator[](size_t pos); //传引用返回可以修改值也能减少拷贝

//         size_t size();

//     private:
//         T *_a;
//         int _size;
//         int _capacity;
//     };
//     template <class T>
//     T &vector<T>::operator[](size_t pos)
//     {
//         assert(pos < _size); //越界检查
//         return _a[pos];
//     }

//     template <class T>
//     size_t vector<T>::size()
//     {
//         return _size;
//     }
// }
// int main()
// {
//     yzq::vector<int> v1; // int
//     v1.push_back(1);
//     v1.push_back(2);
//     v1.push_back(3);
//     v1.push_back(4);
//     for (size_t i = 0; i < v1.size(); i++)
//     {
//         v1[i] *= 2;
//     }

//     for (size_t i = 0; i < v1.size(); i++)
//     {
//         cout << v1[i] << " ";
//     }
//     cout << endl;

//     //等价 v1.operator[](3);
//     cout << v1[3] << endl;
//     std::vector<double> v2; // double
//     v2.push_back(1.1);
//     v2.push_back(2.2);
//     v2.push_back(2.2);
//     v2.push_back(2.2);
//     return 0;
// }

// int main()
// {
//     //先算有多少天,考虑闰年
//     int day = 0;
//     for (int i = 1901; i <= 2000; i++)
//     {
//         if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//         {
//             day += 366;
//         }
//         else
//         {
//             day += 365;
//         }
//     }
//     cout << day / 7 << endl;
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
// #include <iostream>
// #include <memory.h>
// using namespace std;
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
    int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return 0;
}
