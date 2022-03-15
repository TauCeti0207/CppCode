

// // // // // //这个数拆开每一个数位上面的数字都是素数
// // // // // //这个数自己本身也是个素数
// // // // // // #include <iostream>
// // // // // // #include <math.h>
// // // // // // using namespace std;
// // // // // // bool IsPurePrime(int i) //判断每一位是否有 0 1 4 6 8 9
// // // // // // {
// // // // // //     while (i)
// // // // // //     {
// // // // // //         int temp = i % 10;
// // // // // //         if (temp == 0 || temp == 1 || temp == 4 || temp == 6 || temp == 8 || temp == 9)
// // // // // //         {
// // // // // //             return false;
// // // // // //         }
// // // // // //         i /= 10;
// // // // // //     }
// // // // // //     return true;
// // // // // // }
// // // // // // bool IsPrime(int i)
// // // // // // {
// // // // // //     for (int j = 2; j < sqrt(i); j++)
// // // // // //     {
// // // // // //         if (i % j == 0)
// // // // // //         {
// // // // // //             return false;
// // // // // //         }
// // // // // //     }
// // // // // //     return true;
// // // // // // }
// // // // // // int main()
// // // // // // {
// // // // // //     int count = 0;
// // // // // //     //先遍历1 ~ 20210605
// // // // // //     for (int i = 1; i <= 20210605; i += 2) //偶数不可能是素数
// // // // // //     {
// // // // // //         if (IsPurePrime(i))
// // // // // //         {
// // // // // //             if (IsPrime(i))
// // // // // //             {
// // // // // //                 count++;
// // // // // //             }
// // // // // //         }
// // // // // //     }
// // // // // //     cout << count << endl;
// // // // // //     system("pause");
// // // // // //     return 0;
// // // // // // }

// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // #include <math.h>
// // // // // // int main(int argc, char const *argv[])
// // // // // // {
// // // // // //     int N;
// // // // // //     cin >> N;
// // // // // //     int left, right;
// // // // // //     int i;
// // // // // //     for (i = 1;; i++)
// // // // // //     {
// // // // // //         if (N == 1)
// // // // // //         {
// // // // // //             cout << i << endl;
// // // // // //             return 0;
// // // // // //         }
// // // // // //         int left = (pow(3, i - 1) - 1) / 2;
// // // // // //         int right = (pow(3, i) - 1) / 2;
// // // // // //         if (left <= N && N <= right)
// // // // // //             break;
// // // // // //     }
// // // // // //     cout << i << endl;
// // // // // //     system("pause");
// // // // // //     return 0;
// // // // // // }

// // // // // // 1.先算第一分钟有多少个水管，灌溉了多少块地
// // // // // // 2.再算剩下k-1分钟蔓延多少次
// // // // // // 3.统计总共有多少块地被浇过水
// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // static int arr[110][110] = {0};
// // // // // // void water(int x, int y) //蔓延浇水
// // // // // // {
// // // // // //     arr[x][y] = 1;
// // // // // //     if (arr[x - 1][y] == 0)
// // // // // //         arr[x - 1][y] = 1;
// // // // // //     if (arr[x][y + 1] == 0)
// // // // // //         arr[x][y + 1] = 1;
// // // // // //     if (arr[x + 1][y] == 0)
// // // // // //         arr[x + 1][y] = 1;
// // // // // //     if (arr[x][y - 1] == 0)
// // // // // //         arr[x][y - 1] = 1;
// // // // // // }
// // // // // // int main()
// // // // // // {
// // // // // //     int n, m, t;
// // // // // //     cin >> n >> m; // n行m列的田地
// // // // // //     cin >> t;      // t个水管
// // // // // //     while (t--)    // t个水管，第一分钟完成的浇水量
// // // // // //     {
// // // // // //         int x, y;
// // // // // //         cin >> x >> y;
// // // // // //         water(x, y);
// // // // // //     }
// // // // // //     //输入浇水时间k
// // // // // //     int k;
// // // // // //     cin >> k;
// // // // // //     int curK = k - 1; //剩余时间
// // // // // //     while (curK--)
// // // // // //     {
// // // // // //         for (int i = 0; i <= n; i++)
// // // // // //         {
// // // // // //             for (int j = 0; j <= m; j++)
// // // // // //             {
// // // // // //                 if (arr[i][j] == 1)
// // // // // //                     water(i, j);
// // // // // //             }
// // // // // //         }
// // // // // //     }
// // // // // //     //统计浇水情况
// // // // // //     int ret = 0;
// // // // // //     for (int i = 0; i <= n; i++)
// // // // // //     {
// // // // // //         for (int j = 0; j <= m; j++)
// // // // // //         {
// // // // // //             if (arr[i][j] == 1)
// // // // // //                 ret++;
// // // // // //         }
// // // // // //     }
// // // // // //     cout << ret << endl;
// // // // // //     return 0;
// // // // // // }

// // // // // // // 源代码：
// // // // // // #include <bits/stdc++.h>
// // // // // // using namespace std;
// // // // // // int tu[101][101];
// // // // // // void dfs(int x, int y)
// // // // // // {
// // // // // //     tu[x][y] = 1;
// // // // // //     if (!tu[x - 1][y])
// // // // // //     {
// // // // // //         tu[x - 1][y] = 1;
// // // // // //     }
// // // // // //     if (!tu[x + 1][y])
// // // // // //     {
// // // // // //         tu[x + 1][y] = 1;
// // // // // //     }
// // // // // //     if (!tu[x][y - 1])
// // // // // //     {
// // // // // //         tu[x][y - 1] = 1;
// // // // // //     }
// // // // // //     if (!tu[x][y + 1])
// // // // // //     {
// // // // // //         tu[x][y + 1] = 1;
// // // // // //     }
// // // // // // }

// // // // // // int main()
// // // // // // {
// // // // // //     int k, t, n, m, r, c, i, j, ans = 0;
// // // // // //     memset(tu, 0, sizeof(tu));
// // // // // //     cin >> n >> m >> t;
// // // // // //     while (t--)
// // // // // //     {
// // // // // //         cin >> r >> c;
// // // // // //         dfs(r, c);
// // // // // //     }
// // // // // //     cin >> k;
// // // // // //     if (k > 1)
// // // // // //         k -= 1;
// // // // // //     while (k--)
// // // // // //     {
// // // // // //         for (i = 1; i <= n; i++)
// // // // // //         {
// // // // // //             for (j = 1; j <= m; j++)
// // // // // //             {
// // // // // //                 if (tu[i][j])
// // // // // //                 {
// // // // // //                     dfs(i, j);
// // // // // //                 }
// // // // // //             }
// // // // // //         }
// // // // // //     }
// // // // // //     for (i = 1; i <= n; i++)
// // // // // //     {
// // // // // //         for (j = 1; j <= m; j++)
// // // // // //         {
// // // // // //             if (tu[i][j])
// // // // // //                 ans++;
// // // // // //         }
// // // // // //     }
// // // // // //     cout << ans;
// // // // // //     return 0;
// // // // // // }
// // // // // //不知道有啥问题，运行结果是18，大佬们有空看看嘛

// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // bool getprime(int n)
// // // // // // {
// // // // // //     int i, j;
// // // // // //     bool m;
// // // // // //     for (i = 1; i <= n; i++)
// // // // // //     {
// // // // // //             m = true;
// // // // // //             for (j = 2; j < i; j++)
// // // // // //         {
// // // // // //                     if (i % j == 0)
// // // // // //             {
// // // // // //                             m = false;
// // // // // //                             break;
// // // // // //                         
// // // // // //             }
// // // // // //                 
// // // // // //         }
// // // // // //             return m;
// // // // // //     }
// // // // // // }
// // // // // // int num[20210610];
// // // // // // int main()
// // // // // // {
// // // // // //         int n = 0, cont = 0;
// // // // // //         for (int i = 1; i <= 20210605 /*20210605*/; i++)
// // // // // //     {
// // // // // //                 if (getprime(i))
// // // // // //         {
// // // // // //                         num[n++] = i;
// // // // // //                     
// // // // // //         }
// // // // // //             
// // // // // //     }
// // // // // //         for (int i = 0; i < n; i++)
// // // // // //     {
// // // // // //                 num[i] %= 100;
// // // // // //                 num[i] /= 10;
// // // // // //                 if (num[i] == 2 || num[i] == 3 || num[i] == 5 || num[i] == 7)
// // // // // //         {
// // // // // //                         cont++;
// // // // // //                     
// // // // // //         }
// // // // // //             
// // // // // //     }
// // // // // //         cont += 4;
// // // // // //         cout << cont << endl;
// // // // // //         return 0;
// // // // // // }

// // // // // // // 1.构造循环链表
// // // // // // // 2.寻找报数起点
// // // // // // // 3.按顺序依次出列
// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // struct Node
// // // // // // {
// // // // // //     int data;
// // // // // //     Node *pNext;
// // // // // // };

// // // // // // int main()
// // // // // // {
// // // // // //     int n, k, m; // n个人从k位置开始报数，数到m就出列
// // // // // //     cin >> n >> k >> m;
// // // // // //     Node *p, *q, *head;
// // // // // //     //构造循环列表
// // // // // //     Node *first = new Node;
// // // // // //     p = first;
// // // // // //     first->data = 1;
// // // // // //     for (int i = 2; i <= n; i++)
// // // // // //     {
// // // // // //         q = new Node;
// // // // // //         q->data = i;
// // // // // //         p->pNext = q;
// // // // // //         p = q; // p = p->pNext;
// // // // // //     }
// // // // // //     p->pNext = first; //循环链表，尾指向头

// // // // // //     //寻找报数的起点
// // // // // //     p = first; // first也算第一个了，只需再往后k-1次遍历就行
// // // // // //     for (size_t i = 1; i <= k - 1; i++)
// // // // // //     {
// // // // // //         p = p->pNext;
// // // // // //     }
// // // // // //     // 依次报数，报到m的那个人出列，要算上第一个人开始
// // // // // //     // 也就是报m-1次，但要保存m-2的位置，只需循环m-2次
// // // // // //     while (p != p->pNext) //只剩下一个结点就停止
// // // // // //     {
// // // // // //         for (size_t i = 1; i <= m - 2; i++)
// // // // // //         {
// // // // // //             p = p->pNext;
// // // // // //         }
// // // // // //         q = p->pNext; // q就是要出列的那个人,此时p是第m-1的数
// // // // // //         cout << q->data << endl;
// // // // // //         p->pNext = q->pNext; // p要指向q后面的数
// // // // // //         delete q;
// // // // // //         p = p->pNext;
// // // // // //     }
// // // // // //     cout << p->data << endl; //输出最后一个元素
// // // // // //     return 0;
// // // // // // }

// // // // // #include <iostream>
// // // // // using namespace std;
// // // // // struct Node
// // // // // {
// // // // //     int data;
// // // // //     Node *next;
// // // // //     Node *before;
// // // // // };
// // // // // Node *head = new Node;
// // // // // void Insert(int x)
// // // // // {
// // // // //     Node *temp = new Node;
// // // // //     temp->data = x;
// // // // //     temp->next = head->next;
// // // // //     head->next = temp;
// // // // //     temp->before = head;
// // // // //     if (temp->next != nullptr)
// // // // //     {
// // // // //         temp->next->before = temp; //第二次创建节点时，要让之前的节点的before指向后来创建的节点
// // // // //     }
// // // // // }
// // // // // void Init()
// // // // // {
// // // // //     head->next = nullptr;
// // // // //     head->before = nullptr;
// // // // //     for (int i = 10; i >= 1; i--)
// // // // //     {
// // // // //         Insert(i);
// // // // //     }
// // // // // }

// // // // // void Del(int x)
// // // // // {
// // // // //     for (Node *T = head->next; T != nullptr; T = T->next)
// // // // //     {
// // // // //         if (T->data == x)
// // // // //         {
// // // // //             T->before->next = T->next;
// // // // //             T->next->before = T->before;
// // // // //             return;
// // // // //         }
// // // // //     }
// // // // // }
// // // // // void Show(int i)
// // // // // {
// // // // //     // cout << "这是第" << i << "次操作";
// // // // //     for (Node *T = head->next; T != nullptr; T = T->next) //链表的遍历常用写法
// // // // //     {
// // // // //         cout << T->data << " ";
// // // // //     }
// // // // //     cout << endl;
// // // // // }
// // // // // int main(int argc, char const *argv[])
// // // // // {
// // // // //     Init();
// // // // //     int N;
// // // // //     cin >> N;
// // // // //     for (int i = 1; i <= N; i++)
// // // // //     {
// // // // //         int x;
// // // // //         cin >> x;
// // // // //         Del(x);
// // // // //         Insert(x);
// // // // //         Show(i);
// // // // //     }
// // // // //     return 0;
// // // // // }

// // // // // 1/1 + 1/2 + 1/4 + 1/8 + 1/16 + …
// // // // // 分子：1 3 7 15
// // // // // 分母：1 2 4 8
// // // // #include <iostream>
// // // // using namespace std;
// // // // int main()
// // // // {
// // // //     int a = 1, b = 1;
// // // //     for (int i = 1; i < 20; i++) //遍历19次即可，1已结算过了
// // // //     {
// // // //         b *= 2;
// // // //         a += b;
// // // //     }
// // // //     cout << a << "/" << b << endl;
// // // //     return 0;
// // // // }

// // // // /**
// // // //  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// // // //  *
// // // //  *
// // // //  * @param arr int一维数组
// // // //  * @param arrLen int arr数组长度
// // // //  * @param k int
// // // //  * @return int
// // // //  */
// // // // // int FindSingleNumber(int *arr, int arrLen, int k)
// // // // // {
// // // // //     for (int i = 0; i < arrLen; i++)
// // // // //     {
// // // // //         int count = 0;
// // // // //         for (int j = 0; j < arrLen; j++)
// // // // //         {
// // // // //             if (arr[i] == arr[j])
// // // // //             {
// // // // //                 count++;
// // // // //             }
// // // // //         }
// // // // //         if (1 == count)
// // // // //         {
// // // // //             return arr[i];
// // // // //         }
// // // // //     }
// // // // //     return 0;
// // // // // }

// // // // int FindSingleNumber(int *arr, int arrLen, int k)
// // // // {
// // // //     int array[32] = {0};
// // // //     //求每个二进制位的和
// // // //     for (int i = 0; i < 32; i++)
// // // //     {
// // // //         int sum = 0;
// // // //         for (int j = 0; j < arrLen; j++)
// // // //         {
// // // //             sum = sum + ((arr[j] >> 1) & 1);
// // // //         }
// // // //         array[i] = sum;
// // // //     }
// // // //     int ret = 0; //出现1次的数
// // // //     for (int i = 0; i < 32; i++)
// // // //     {
// // // //         if (array[i] % k != 0) //统计ret的二进制位出现1的情况
// // // //         {
// // // //             ret = ret + (1 << i);
// // // //         }
// // // //     }
// // // //     return ret;
// // // // }

// // // // #include <iostream>
// // // // using namespace std;
// // // // //暴力循环
// // // // bool JudgeI(long long x)
// // // // {
// // // //     int a, b, c, d, e, f;
// // // //     a = x % 10;
// // // //     b = x / 10 % 10;
// // // //     c = x / 100 % 10;
// // // //     d = x / 1000 % 10;
// // // //     e = x / 10000 % 10;
// // // //     f = x / 100000 % 10;
// // // //     if (a != b && a != c && a != d && a != e && a != f && b != c && b != d && b != e && b != f && c != d && c != e && c != f && d != e && d != f && e != f)
// // // //     {
// // // //         return true;
// // // //     }
// // // //     else
// // // //     {
// // // //         return false;
// // // //     }
// // // // }
// // // // //判断i 与i*i 是否有相同的数
// // // // bool JudgeII(long long x, long long xx)
// // // // {
// // // //     char str1[10];
// // // //     char str2[20];
// // // //     lltoa(x, str1, 10); //将x按十进制转化为字符串
// // // //     lltoa(xx, str2, 10);
// // // //     for (int i = 0; str1[i] != '\0'; i++)
// // // //     {
// // // //         for (int j = 0; str2[j] != '\0'; j++)
// // // //         {
// // // //             if (str1[i] == str2[j])
// // // //                 return false;
// // // //         }
// // // //     }
// // // //     return true;
// // // // }
// // // // int main()
// // // // {
// // // //     for (int i = 123456; i <= 987654; i++)
// // // //     {
// // // //         //排除掉有重复的数字
// // // //         if (JudgeI(i) && JudgeII(i, i * i))
// // // //         {
// // // //             cout << i << endl;
// // // //         }
// // // //     }

// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // using namespace std;
// // // bool check(long long x, long long xx)
// // // {
// // //     char str1[10];
// // //     char str2[20];
// // //     lltoa(x, str1, 10); //将整数x按十进制转化为字符串str1
// // //     lltoa(xx, str2, 10);
// // //     for (int i = 0; str1[i] != '\0'; i++)
// // //     {
// // //         for (int j = 0; str2[j] != '\0'; j++)
// // //         {
// // //             if (str1[i] == str2[j])
// // //                 return false;
// // //         }
// // //     }
// // //     return true;
// // // }
// // // /* check函数的功能：排查6位数x各位数上的数字与其平方xx各位上的数字是否重合*/
// // // int main()
// // // {
// // //     long long a, b, c, d, e, f;
// // //     for (a = 1; a < 10; a++)
// // //     {
// // //         for (b = 0; b < 10; b++)
// // //         {
// // //             if (b != a)
// // //                 for (c = 0; c < 10; c++)
// // //                 {
// // //                     if (c != a && c != b)
// // //                         for (d = 0; d < 10; d++)
// // //                         {
// // //                             if (d != a && d != b && d != c)
// // //                                 for (e = 0; e < 10; e++)
// // //                                 {
// // //                                     if (e != a && e != b && e != c && e != d)
// // //                                         for (f = 0; f < 10; f++)
// // //                                         {
// // //                                             if (f != a && f != b && f != c && f != d && f != e)
// // //                                             {
// // //                                                 long long x = a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f;
// // //                                                 if (check(x, x * x) && x != 203879)
// // //                                                 {
// // //                                                     cout << x << endl;
// // //                                                 }
// // //                                             }
// // //                                         }
// // //                                 }
// // //                         }
// // //                 }
// // //         }
// // //     }
// // //     return 0;
// // // }

// // // #include <iostream>
// // // using namespace std;
// // // int main(int argc, char const *argv[])
// // // {
// // //     int i = 0;
// // //     int a, b, c, d;
// // //     int count = 0;
// // //     for (i = 2013; i >= 1900; i--)
// // //     {
// // //         int age = 2014 - i;
// // //         a = i % 10;
// // //         b = i / 10 % 10;
// // //         c = i / 100 % 10;
// // //         d = i / 1000 % 10;
// // //         if (a + b + c + d == age)
// // //         {
// // //             count++;
// // //             if (count == 2)//只需要输出表哥小明的出生年月
// // //                 cout << i << endl;
// // //         }
// // //     }
// // //     return 0;
// // // }
// // // //表弟2006 表哥1988

// // #include "reg52.h"

// // void delay(unsigned char t)
// // {
// //     while (t--)
// //         ;
// //     while (t--)
// //         ;
// // }

// // void selectHC573(unsigned char channel)
// // {
// //     switch (channel)
// //     {
// //     case 4:
// //         P2 = (P2 & 0x1f) | 0x80;
// //         break;
// //     case 5:
// //         P2 = (P2 & 0x1f) | 0xa0;
// //         break;
// //     case 6:
// //         P2 = (P2 & 0x1f) | 0xc0;
// //         break;
// //     case 7:
// //         P2 = (P2 & 0x1f) | 0xe0;
// //         break;
// //     }
// // }

// // void mazz()
// // {
// //     selectHC573(5);
// //     P0 = 0x00;
// // }
// // void ledrunning()
// // {
// //     unsigned char i;
// //     selectHC573(4);
// //     for (i = 0; i < 3; i++)
// //     {
// //         P0 = 0x00;
// //         delay(60000);

// //         P0 = 0xff;
// //         delay(60000);
// //     }
// //     for (i = 1; i <= 8; i++)
// //     {
// //         P0 = 0xff << i;
// //         delay(60000);

// //         P0 = ~(0xff << i);
// //         delay(60000);
// //     }
// // }

// // void main()
// // {
// //     while (1)
// //     {
// //         mazz();
// //         ledrunning();
// //     }
// // }

// // #include "reg52.h"

// // sbit HC138_A = P2 ^ 5;
// // sbit HC138_B = P2 ^ 6;
// // sbit HC138_C = P2 ^ 7;

// // void Delay(unsigned int t)
// // {
// //     while (t--)
// //         ;
// //     while (t--)
// //         ;
// // }

// // void LEDRunning()
// // {
// //     unsigned char i;
// //     HC138_C = 1;
// //     HC138_B = 0;
// //     HC138_A = 0;

// //     for (i = 0; i < 3; i++)
// //     {
// //         P0 = 0x00;
// //         Delay(60000);
// //         Delay(60000);
// //         P0 = 0xff;
// //         Delay(60000);
// //         Delay(60000);
// //     }

// //     for (i = 1; i <= 8; i++)
// //     {
// //         P0 = 0xff << i;
// //         Delay(60000);
// //         Delay(60000);
// //     }

// //     for (i = 1; i <= 8; i++)
// //     {
// //         P0 = ~(0xff << i);
// //         Delay(60000);
// //         Delay(60000);
// //     }
// // }

// // void main()
// // {
// //     while (1)
// //     {
// //         LEDRunning();
// //     }
// // }

// /*试根据给出的main测试函数定义CString类，
// 用以处理用户长度不定（使用动态内存处理）的字符串。
// 提供的操作主要有字符串显示（单独占一行）、求字符串长度、在字符串末尾添加一个字符串、字符串拷贝等，其它功能自行分析并定义。
// 本题不得用string类和cstring库函数。main函数不得修改。*/
// #include <iostream>
// using namespace std;
// class CString
// {
// public:
//     void Cat(CString s);
//     CString()
//     {
//         str1 = NULL;
//     }
//     CString(char *s)
//     {
//         str1 = s;
//     };
//     CString(const CString &s);
//     void Copy(CString s);
//     void Print();
//     int Len();

// private:
//     char *str1;
// };
// void CString::Cat(CString s)
// {
//     int i = 0, j = 0, k = 0, m = 0;
//     while (s.str1[i] != '\0')
//     {
//         i++;
//         k++;
//     }
//     while (str1[j] = '\t')
//     {
//         j++;
//         m++;
//     }
//     str1 = new char[m + k + 1];
//     for (i = 0; i <= m + k; i++)
//     {
//         str1[i + m] = s.str1[i];
//     }
// }
// CString::CString(const CString &s)
// {
//     str1 = s.str1;
// }
// void CString::Copy(CString s)
// {
//     str1 = s.str1;
// }
// void CString::Print()
// {
//     cout << str1 << endl;
// }
// int CString::Len()
// {
//     char *p = str1;
//     for (int i = 0;;)
//     {
//         if (*p++ != '\0')
//         {
//             i++;
//         }
//         else if (*p++ == '\0')
//         {
//             return i;
//         }
//     }
// }
// int main()

// {

//     CString str1; //生成str1对象

//     char s[80];

//     cin.getline(s, 80);

//     str1.Cat(s); //字符串s连接到str1中字符串的末尾

//     CString str2(str1); //生成str2对象

//     str2.Print(); //输出str2中保存的字符串

//     cin.getline(s, 80);

//     CString str3(s), str4;

//     str4.Copy(str3); //将str3中保存的字符串拷贝到str4中

//     str4.Cat(str1);

//     cout << str4.Len() << endl; //输出str4中字符串长度

//     str4.Print(); //输出字符串

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 2019;i < 1000000; i += 2019)
//     {
//         int tmp = i;
//         for (; tmp > 0; tmp /= 10)
//         {
//             if (tmp % 10 % 2 == 0)
//             {
//                 break;
//             }
//         }
//         if (tmp == 0)
//             cout << i << endl;
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 2019;i < 1000000; i += 2019)
//     {
//         int tmp = i;
//         for (; tmp > 0; tmp /= 10)
//         {
//             if (tmp % 10 % 2 == 0)
//             {
//                 break;
//             }
//         }
//         if (tmp == 0)
//             cout << i << endl;
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 0; i < 1000; i++)
//     {
//         if (i * 2019 % 2 == 1 && i * 2019 / 10 % 2 == 1 && i * 2019 / 100 % 2 == 1 && i * 2019 / 1000 % 2 == 1 && i * 2019 / 10000 % 2 == 1)
//             cout << i * 2019 << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int count = 0;
//     for (long long i = 3; i <= 45; i++)
//     {
//         long long tmp = i;
//         while (tmp)
//         {
//             if (tmp % 10 == 3 || tmp % 10 == 5 || tmp % 10 == 7)
//             {
//                 tmp /= 10;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         if (tmp == 0)
//         {
//             count++;
//         }
//     }
//     cout << count << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main(int argc, char const *argv[])
// {
//     long long n = 59084709587505;
//     int count = 0;
//     for (long long i = 1; i <= n; i *= 3)
//     {
//         for (long long j = 1; i * j <= n; j *= 5)
//         {
//             for (long long k = 1; i * j * k <= n; k *= 7)
//             {
//                 count++;
//             }
//         }
//     }
//     cout << count - 1 << endl;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e6 + 10;
// int n;
// int q[N], tmp[N];
// // void QuickSort(int q[], int l, int r)
// // {
// //     if (l >= r)
// //         return;                         //当区间里没有数或者只有一个数时，表示已经排好序，用l == r也行的
// //     int x = q[l], i = l - 1, j = r + 1; //不管如何，先让2个指针移动一次，因此指针指向数组外面，避免产生越界
// //     while (i < j)
// //     {
// //         do
// //             i++;
// //         while (q[i] < x);
// //         do
// //             j--;
// //         while (q[j] > x);
// //         if (i < j)
// //             swap(q[i], q[j]);
// //     }
// //     QuickSort(q, l, j);
// //     QuickSort(q, j + 1, r);
// // }
// void QuickSort(int q[], int l, int r)
// {
//     if (l <= r)
//         return;
//     int x = q[l], i = l - 1, j = r + 1;
//     while (i < j)
//     {
//         do
//             i++;
//         while (q[i] < x);
//         do
//             j--;
//         while (q[j] > x);
//         if (i < j)
//             swap(q[i], q[j]);
//         QuickSort(q, l, j);
//         QuickSort(q, j + 1, r);
//     }
// }
// void MergeSort(int q[], int l, int r)
// {
//     if (l >= r)
//         return;
//     int mid = ((r - l) >> 1) + l;
//     MergeSort(q, l, mid), MergeSort(q, mid + 1, r);
//     int k = 0, i = l, j = mid + 1;
//     while (i <= mid && j <= r)
//     {
//         if (q[i] <= q[j])
//             tmp[k++] = q[i++];
//         else
//             tmp[k++] = q[j++];
//     }
//     //总有一方先走完，还没走完的，要继续放到tmp里面
//     while (i <= mid)
//         tmp[k++] = q[i++];
//     while (j <= r)
//         tmp[k++] = q[j++];
//     for (int i = l, j = 0; i <= r; i++, j++)
//         q[i] = tmp[j];
// }
// int main()
// {
//     scanf("%d", &n); //当读取数据比较大时，要用scanf读取
//     for (int i = 0; i < n; i++)
//         scanf("%d", &q[i]);
//     // QuickSort(q, 0, n - 1);
//     MergeSort(q, 0, n - 1);
//     for (int i = 0; i < n; i++)
//         printf("%d ", q[i]);
//     return 0;
// }
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 10;
// int n, d, k;
// int nowLike[N];
// struct node
// {
//     int ts;
//     int id;
// };
// node arr[N];
// bool isHot[N];
// bool Cmp(node x, node y)
// {
//     return x.ts < y.ts;
// }
// int main()
// {
//     cin >> n >> d >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d%d", &arr[i].ts, &arr[i].id);
//     }
//     sort(arr + 1, arr + 1 + n, Cmp);
//     int l = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         nowLike[arr[i].id]++;
//         while (arr[i].ts >= arr[l].ts + d)
//             nowLike[arr[l++].id]--;
//         if (nowLike[arr[i].id] >= k)
//             isHot[arr[i].id] = true;
//     }
//     for (int i = 0; i <= 100005; i++)
//         if (isHot[i])
//             printf("%d\n", i);
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    for (long long i = 1; i <= 1000000007; i++)
    {
        if (i * 2021 % 1000000007 == 999999999)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{

    return 0;
}


