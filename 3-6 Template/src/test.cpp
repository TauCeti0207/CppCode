// #include <iostream>
// using namespace std;

// //����ģ��
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
//     for (int i = 1; i <= 2020; i++) //�ȱ���1-2020
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
// //��1�����ʱ�������������
// int main(int argc, char const *argv[])
// {
//     int card = 2021; // 1�ſ�Ƭʣ������
//     //��1��ʼ
//     int i = 1;
//     while (1)
//     {
//         int count = 0;
//         int tmp = i;
//         while (tmp) // tmp�м���1
//         {
//             if (tmp % 10 == 1)
//             {
//                 count++;
//             }
//             tmp /= 10;
//         }
//         card -= count; //ÿһ�ζ�Ҫ��ȥcount
//         if (card < 0)//card = 0ʱ��ʾ�պ�����
//         {
//             i--; //������if����˵����ʱ��i�ǲ���˳��ƴ�����ģ�ֻ����һ��i��ƴ�����ġ�
//             cout << i << endl;
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// //ģ��
// int main(int argc, char const *argv[])
// {
//     int i = 1;
//     int arr[10] = {2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021};
//     while (1)
//     {
//         int tmp = i; //��ʱ����i����һλһλ������
//         while (tmp)
//         {
//             if (arr[tmp % 10] == 0) //��һ�ֿ�Ƭ��������
//             {
//                 cout << i - 1 << endl; //ǡ��=0ʱ������ǰ��i�ǲ����������ģ�ǰһ��iǡ����ƴ�ɹ�
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
//     int card = 2021; // ��¼ʣ��Ŀ�Ƭ��������ʣ�࿨Ƭ����С��0ʱ���˳�ѭ��
//     int i = 1;
//     while (1)
//     {
//         int count = 0; // ��¼��ǰ���ֺ���1�ĸ���
//         int m = i;
//         while (m)
//         {
//             int temp = m % 10;
//             // ��temp�������յ�ǰ���ֵ����һλ���ж������1��countֵ��һ
//             // ����ͨ�������ó���һ���ǿ�Ƭ1�����꣬�����ж�ÿ�������ﺬ��1�ĸ���
//             // �ÿ�Ƭ����2021��ȥÿ�������ﺬ��1�ĸ���
//             // �ٽ�ֵ�жϣ������һ���Ϸ�������ƴ��ʱ��1�ſ�Ƭʣ�����Ӧ�õ���0�����0
//             // ���ҽ�����һ��ѭ����i��ֵ���ټ�һ�����i���������������˳�ѭ��
//             // ������Ҫ��������������ii��Ҳ�����˳�ѭ����i����һ��ֵ����i-1
//             // �õ�����Ҫ��ֵ��Ҳ����2021�ſ�Ƭ��ƴ������������
//             if (temp == 1)
//             {
//                 count++;
//             }
//             m = m / 10;
//             // ����ǰ���ֳ���10���൱��ȥ�������һλ�������11����10���õ������־���1��ֱ��m��ֵΪ0ʱ���˳�
//         }
//         card -= count;
//         if (card < 0)
//         { // ��ʣ�࿨Ƭ����С��0ʱ���˳�ѭ��
//             i--;
//             cout << i << endl;
//             return 0;
//         }
//         i++; //��ǰ������������֮��ȡ��һ�����֣�������i��ֵ��1
//     }
//     return 0;
// }
#include <iostream>
#include <memory.h>
using namespace std;
// //��ά����ģ�����
// int main(int argc, char const *argv[])
// {
//     int m, n;
//     cin >> m >> n; // m��n��
//     int arr[201][201];
//     memset(arr, -1, sizeof(arr)); // memset�����òź�
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     int total = 0; //����
//     int i = 0, j = 0;
//     while (total < m * n)
//     {
//         //���´�ӡ
//         while (i <= m - 1 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             i++;
//             total++;
//         }
//         //���Ҵ�ӡ
//         i--; // i�����һ�Σ���������Χ��Ҫ����
//         j++; // jȥ��һ��
//         while (j <= n - 1 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             j++;
//             total++;
//         }
//         //���ϴ�ӡ
//         j--; //ͬ����Ҫ��ȥ���һ�ε�j
//         i--; //ָ����һ��
//         while (i >= 0 && arr[i][j] != -1)
//         {
//             cout << arr[i][j] << " ";
//             arr[i][j] = -1;
//             i--;
//             total++;
//         }
//         //�����ӡ
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
//         i++; //�������±���һ��
//     }
//     cout << endl;
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int md[11] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return 0;
}
