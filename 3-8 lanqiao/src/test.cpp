

// // // // // //�������ÿһ����λ��������ֶ�������
// // // // // //������Լ�����Ҳ�Ǹ�����
// // // // // // #include <iostream>
// // // // // // #include <math.h>
// // // // // // using namespace std;
// // // // // // bool IsPurePrime(int i) //�ж�ÿһλ�Ƿ��� 0 1 4 6 8 9
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
// // // // // //     //�ȱ���1 ~ 20210605
// // // // // //     for (int i = 1; i <= 20210605; i += 2) //ż��������������
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

// // // // // // 1.�����һ�����ж��ٸ�ˮ�ܣ�����˶��ٿ��
// // // // // // 2.����ʣ��k-1�������Ӷ��ٴ�
// // // // // // 3.ͳ���ܹ��ж��ٿ�ر�����ˮ
// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // static int arr[110][110] = {0};
// // // // // // void water(int x, int y) //���ӽ�ˮ
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
// // // // // //     cin >> n >> m; // n��m�е����
// // // // // //     cin >> t;      // t��ˮ��
// // // // // //     while (t--)    // t��ˮ�ܣ���һ������ɵĽ�ˮ��
// // // // // //     {
// // // // // //         int x, y;
// // // // // //         cin >> x >> y;
// // // // // //         water(x, y);
// // // // // //     }
// // // // // //     //���뽽ˮʱ��k
// // // // // //     int k;
// // // // // //     cin >> k;
// // // // // //     int curK = k - 1; //ʣ��ʱ��
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
// // // // // //     //ͳ�ƽ�ˮ���
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

// // // // // // // Դ���룺
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
// // // // // //��֪����ɶ���⣬���н����18���������пտ�����

// // // // // // #include <iostream>
// // // // // // using�0�2namespace�0�2std;
// // // // // // bool�0�2getprime(int�0�2n)
// // // // // // {
// // // // // //     int�0�2i, j;
// // // // // //     bool�0�2m;
// // // // // //     for (i = 1; i <= n; i++)
// // // // // //     {
// // // // // //         �0�2�0�2�0�2�0�2m = true;
// // // // // //         �0�2�0�2�0�2�0�2for (j = 2; j < i; j++)
// // // // // //         {
// // // // // //             �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2if (i % j == 0)
// // // // // //             {
// // // // // //                 �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2m = false;
// // // // // //                 �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2break;
// // // // // //                 �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
// // // // // //             }
// // // // // //             �0�2�0�2�0�2�0�2
// // // // // //         }
// // // // // //         �0�2�0�2�0�2�0�2return�0�2m;
// // // // // //     }
// // // // // // }
// // // // // // int�0�2num[20210610];
// // // // // // int�0�2main()
// // // // // // {
// // // // // //     �0�2�0�2�0�2�0�2int�0�2n = 0, cont = 0;
// // // // // //     �0�2�0�2�0�2�0�2for (int�0�2i = 1; i <= 20210605 /*20210605*/; i++)
// // // // // //     {
// // // // // //         �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2if (getprime(i))
// // // // // //         {
// // // // // //             �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2num[n++] = i;
// // // // // //             �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
// // // // // //         }
// // // // // //         �0�2�0�2�0�2�0�2
// // // // // //     }
// // // // // //     �0�2�0�2�0�2�0�2for (int�0�2i = 0; i < n; i++)
// // // // // //     {
// // // // // //         �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2num[i] %= 100;
// // // // // //         �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2num[i] /= 10;
// // // // // //         �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2if (num[i] == 2 || num[i] == 3 || num[i] == 5 || num[i] == 7)
// // // // // //         {
// // // // // //             �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2cont++;
// // // // // //             �0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
// // // // // //         }
// // // // // //         �0�2�0�2�0�2�0�2
// // // // // //     }
// // // // // //     �0�2�0�2�0�2�0�2cont += 4;
// // // // // //     �0�2�0�2�0�2�0�2cout << cont << endl;
// // // // // //     �0�2�0�2�0�2�0�2return�0�20;
// // // // // // }

// // // // // // // 1.����ѭ������
// // // // // // // 2.Ѱ�ұ������
// // // // // // // 3.��˳�����γ���
// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // struct Node
// // // // // // {
// // // // // //     int data;
// // // // // //     Node *pNext;
// // // // // // };

// // // // // // int main()
// // // // // // {
// // // // // //     int n, k, m; // n���˴�kλ�ÿ�ʼ����������m�ͳ���
// // // // // //     cin >> n >> k >> m;
// // // // // //     Node *p, *q, *head;
// // // // // //     //����ѭ���б�
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
// // // // // //     p->pNext = first; //ѭ������βָ��ͷ

// // // // // //     //Ѱ�ұ��������
// // // // // //     p = first; // firstҲ���һ���ˣ�ֻ��������k-1�α�������
// // // // // //     for (size_t i = 1; i <= k - 1; i++)
// // // // // //     {
// // // // // //         p = p->pNext;
// // // // // //     }
// // // // // //     // ���α���������m���Ǹ��˳��У�Ҫ���ϵ�һ���˿�ʼ
// // // // // //     // Ҳ���Ǳ�m-1�Σ���Ҫ����m-2��λ�ã�ֻ��ѭ��m-2��
// // // // // //     while (p != p->pNext) //ֻʣ��һ������ֹͣ
// // // // // //     {
// // // // // //         for (size_t i = 1; i <= m - 2; i++)
// // // // // //         {
// // // // // //             p = p->pNext;
// // // // // //         }
// // // // // //         q = p->pNext; // q����Ҫ���е��Ǹ���,��ʱp�ǵ�m-1����
// // // // // //         cout << q->data << endl;
// // // // // //         p->pNext = q->pNext; // pҪָ��q�������
// // // // // //         delete q;
// // // // // //         p = p->pNext;
// // // // // //     }
// // // // // //     cout << p->data << endl; //������һ��Ԫ��
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
// // // // //         temp->next->before = temp; //�ڶ��δ����ڵ�ʱ��Ҫ��֮ǰ�Ľڵ��beforeָ����������Ľڵ�
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
// // // // //     // cout << "���ǵ�" << i << "�β���";
// // // // //     for (Node *T = head->next; T != nullptr; T = T->next) //����ı�������д��
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

// // // // // 1/1 + 1/2 + 1/4 + 1/8 + 1/16 + ��
// // // // // ���ӣ�1 3 7 15
// // // // // ��ĸ��1 2 4 8
// // // // #include <iostream>
// // // // using namespace std;
// // // // int main()
// // // // {
// // // //     int a = 1, b = 1;
// // // //     for (int i = 1; i < 20; i++) //����19�μ��ɣ�1�ѽ������
// // // //     {
// // // //         b *= 2;
// // // //         a += b;
// // // //     }
// // // //     cout << a << "/" << b << endl;
// // // //     return 0;
// // // // }

// // // // /**
// // // //  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// // // //  *
// // // //  *
// // // //  * @param arr intһά����
// // // //  * @param arrLen int arr���鳤��
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
// // // //     //��ÿ��������λ�ĺ�
// // // //     for (int i = 0; i < 32; i++)
// // // //     {
// // // //         int sum = 0;
// // // //         for (int j = 0; j < arrLen; j++)
// // // //         {
// // // //             sum = sum + ((arr[j] >> 1) & 1);
// // // //         }
// // // //         array[i] = sum;
// // // //     }
// // // //     int ret = 0; //����1�ε���
// // // //     for (int i = 0; i < 32; i++)
// // // //     {
// // // //         if (array[i] % k != 0) //ͳ��ret�Ķ�����λ����1�����
// // // //         {
// // // //             ret = ret + (1 << i);
// // // //         }
// // // //     }
// // // //     return ret;
// // // // }

// // // // #include <iostream>
// // // // using namespace std;
// // // // //����ѭ��
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
// // // // //�ж�i ��i*i �Ƿ�����ͬ����
// // // // bool JudgeII(long long x, long long xx)
// // // // {
// // // //     char str1[10];
// // // //     char str2[20];
// // // //     lltoa(x, str1, 10); //��x��ʮ����ת��Ϊ�ַ���
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
// // // //         //�ų������ظ�������
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
// // //     lltoa(x, str1, 10); //������x��ʮ����ת��Ϊ�ַ���str1
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
// // // /* check�����Ĺ��ܣ��Ų�6λ��x��λ���ϵ���������ƽ��xx��λ�ϵ������Ƿ��غ�*/
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
// // //             if (count == 2)//ֻ��Ҫ������С���ĳ�������
// // //                 cout << i << endl;
// // //         }
// // //     }
// // //     return 0;
// // // }
// // // //���2006 ���1988

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

// /*�Ը��ݸ�����main���Ժ�������CString�࣬
// ���Դ����û����Ȳ�����ʹ�ö�̬�ڴ洦�����ַ�����
// �ṩ�Ĳ�����Ҫ���ַ�����ʾ������ռһ�У������ַ������ȡ����ַ���ĩβ���һ���ַ������ַ��������ȣ������������з��������塣
// ���ⲻ����string���cstring�⺯����main���������޸ġ�*/
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

//     CString str1; //����str1����

//     char s[80];

//     cin.getline(s, 80);

//     str1.Cat(s); //�ַ���s���ӵ�str1���ַ�����ĩβ

//     CString str2(str1); //����str2����

//     str2.Print(); //���str2�б�����ַ���

//     cin.getline(s, 80);

//     CString str3(s), str4;

//     str4.Copy(str3); //��str3�б�����ַ���������str4��

//     str4.Cat(str1);

//     cout << str4.Len() << endl; //���str4���ַ�������

//     str4.Print(); //����ַ���

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
// //         return;                         //��������û��������ֻ��һ����ʱ����ʾ�Ѿ��ź�����l == rҲ�е�
// //     int x = q[l], i = l - 1, j = r + 1; //������Σ�����2��ָ���ƶ�һ�Σ����ָ��ָ���������棬�������Խ��
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
//     //����һ�������꣬��û����ģ�Ҫ�����ŵ�tmp����
//     while (i <= mid)
//         tmp[k++] = q[i++];
//     while (j <= r)
//         tmp[k++] = q[j++];
//     for (int i = l, j = 0; i <= r; i++, j++)
//         q[i] = tmp[j];
// }
// int main()
// {
//     scanf("%d", &n); //����ȡ���ݱȽϴ�ʱ��Ҫ��scanf��ȡ
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


