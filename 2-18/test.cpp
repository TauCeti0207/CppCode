// #include <iostream>
// using namespace std;
// //C++����C���﷨
// int main(int argc, char const *argv[])
// {
//     cout << "hello wordld" << endl;
//     return 0;
// }

// namespace ����һ����
//�����ǽ��C����������ͻ����
// #include <stdio.h>
// #include <windows.h>
// #include "List.h"
// //C++���������ռ�Ļ���

// // int main(int argc, char const *argv[])
// // {
// //     //������ͻ
// //     //c���Կ�����,��2����������scanf ��strlen����
// //     // int scanf = 0;
// //     // int strlen = 10;
// //     //��������ʱ��ͨ��,���������scanfʱ�Ͳ���,����scanf�Ǿͽ���ȡ
// //     //C���Խ�����������ͻ����
// //     //scanf("%d ",&scanf);
// //     printf("%p\n",scanf);
// //     system("pause");
// //     return 0;
// // }

// namespace yzq
// {
//     int scanf = 0;
//     int strlen = 10;
// }
// int main(int argc, char const *argv[])
// {
//     //Ĭ�Ϸ��ʵ��Ǿֲ���ȫ��
//     printf("%x\n",scanf); //2d312e90 �������scanf�����ĵ�ַ
//     //����scanfʱ�Ǿͽ�ԭ��,���ᵽnamespace����ȥ����,�ͽ��Ҳ�����ȥȫ������,ͷ�ļ�����

//     //ָ������yzq�ռ��е�
//     printf("%x\n",yzq::scanf); //0
//     printf("%d\n",bit::scanf); //30

//     bit::ListNode* pHead = NULL;
//     system("pause");
//     return 0;
// }

// namespace bit
// {
// 	int scanf = 10;
// 	int strlen = 20;

// 	int Add(int left, int right)
// 	{
// 		return left + right;
// 	}

// 	// Ƕ�׶��������ռ�
// 	namespace N3
// 	{
// 		int c;
// 		int d;
// 		int Sub(int left, int right)
// 		{
// 			return left - right;
// 		}

// 		// ����������
// 	}
// }

// C++��Ϊ�˷�ֹ������ͻ,���Լ������涨��Ķ�����������һ��std�������ռ���
//ʹ�ñ�׼���еĶ��� 3�ַ�ʽ

// 1.ָ�������ռ� ��ʹ�� using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      std::cout << "hello world" << std::endl;
//      system("pause");
//      return 0;
//  }

// using namespace std;
// C++����C���﷨
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello wordld" << endl;
//      system("pause");
//      return 0;
//  }

// 2.��std����չ��,�൱�ڿ�����Ķ�������ȫ������
//������������,������������Լ�����Ķ��������ͻ�˾�û�����
//�淶�Ĺ�����Ŀ���ǲ��Ƽ����ַ�ʽ��  �ճ���ϰ�ȽϷ���
//  using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// //3.�Բ��ֳ��õĿ���Ķ���չ��
// //���з���,��Ŀ��Ҳ������
// using std::cout;
// using std::cin;
// using std::endl;

#include <iostream>
#include <windows.h>

using namespace std;
int main(int argc, char const *argv[])
{
    cout << "hello world" << endl;
    //�Ա�C����printf scanf ����: �Զ�ʶ������
    int a = 10;
    system("pause");
    return 0;
}
