#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     FILE *pf = fopen("test.txt", "r");//abcdef
//     if (pf == nullptr)
//     {
//         cout << strerror(errno) << endl;
//         return 0;
//     }

//     //���ļ�
//     char ch = fgetc(pf);
//     cout << ch << endl;
//     ch = fgetc(pf);
//     cout << ch << endl;
//     //��λ�ļ�ָ��
//     //fseek(pf, 3, SEEK_CUR);
//     //fseek(pf,5,SEEK_SET);//SET��ʾ����ʼλ�ÿ�ʼƫ��
//     fseek(pf, -1, SEEK_END);//END�ӽ���λ�ÿ�ʼƫ�ƣ�ƫ��-1��ָ��end
//     ch = fgetc(pf);
//     cout << ch << endl;//f
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }


// int main(int argc, char const *argv[])
// {
//     FILE *pf = fopen("test.txt", "w");//abcdef
//     if (pf == nullptr)
//     {
//         cout << strerror(errno) << endl;
//         return 0;
//     }
//     //д�ļ�
//     int ch = 0;
//     for (ch = 'a'; ch <= 'z'; ch++)
//     {
//         fputc(ch,pf);
//     }
    
//     //���ļ�
//     fseek(pf, -1, SEEK_END);//END�ӽ���λ�ÿ�ʼƫ�ƣ�ƫ��-1��ָ��end
//     fputc('@',pf);//��z�ĳ�#
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     FILE *pf = fopen("test.txt", "r");//abcdef
//     if (pf == nullptr)
//     {
//         cout << strerror(errno) << endl;
//         return 0;
//     }

//     //���ļ�
//     char ch = fgetc(pf);
//     cout << ch << endl;//a
//     ch = fgetc(pf);
//     cout << ch << endl;//b
    
//     //����ƫ����
//     cout << ftell(pf) << endl;//2

//     rewind(pf);
//     cout << ftell(pf) << endl;//0
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }
// #include <stdio.h>
// #include <windows.h>

// int main()
// {
//     FILE*pf = fopen("test.txt", "w");
//     fputs("abcdef", pf);//�Ƚ�����������������
//     printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//     Sleep(10000);
//     printf("ˢ�»�����\n");
//     fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//     //ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//     printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//     Sleep(10000);
//     fclose(pf);
//     //ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//     pf = NULL;
//     system("pause");
//     return 0; 
// }
#include <stdio.h>
int check_sys()
{
    int i = 1;
    return (*(char *)&i);
}
int main()
{
    int ret = check_sys();
    if(ret == 1)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }
    system("pause");
    return 0;
}