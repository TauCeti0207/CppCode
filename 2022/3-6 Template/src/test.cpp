#include <iostream>
using namespace std;
#include <vector>
#include <assert.h>

// //����ģ��
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
//     //���ñ������������٣���ʾָ������
//     //��ʾʵ����
//     cout << Add<int>(a, c) << endl;
//     cout << Add<double>(a, c) << endl;
//     system("pause");
//     return 0;
// }

// //ר�Ŵ���int�ļӷ�����
// int Add(int left, int right)
// {
//     return left + right;
// }

// // ͨ�üӷ�����
// template <class T>
// T Add(T left, T right)
// {
//     return left + right;
// }

// int main()
// {
//     Add(1, 2);      // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//     Add<int>(1, 2); // ���ñ������ػ���Add�汾
//     return 0;
// }

// int Add(int left, int right)
// {
// 	return left + right;
// }

// // ͨ�üӷ�����
// template<class T1, class T2>
// T1 Add(T1 left, T2 right)
// {
// 	return left + right;
// }

// // ģ����ã����ֳ�ƥ�亯�������Բ�ȥʵ����ģ��
// // �и�ƥ��ģ�����ƥ����������ʵ�
// int main()
// {
// 	Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
// 	Add(1, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//     return 0;
// }

// typedef double VDataType;

//��ģ��
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
//         T &operator[](size_t pos); //�����÷��ؿ����޸�ֵҲ�ܼ��ٿ���

//         size_t size();

//     private:
//         T *_a;
//         int _size;
//         int _capacity;
//     };
//     template <class T>
//     T &vector<T>::operator[](size_t pos)
//     {
//         assert(pos < _size); //Խ����
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

//     //�ȼ� v1.operator[](3);
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
//     //�����ж�����,��������
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
// #include <iostream>
// #include <memory.h>
// using namespace std;
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
    int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return 0;
}
