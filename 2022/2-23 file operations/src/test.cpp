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

//     //读文件
//     char ch = fgetc(pf);
//     cout << ch << endl;
//     ch = fgetc(pf);
//     cout << ch << endl;
//     //定位文件指针
//     //fseek(pf, 3, SEEK_CUR);
//     //fseek(pf,5,SEEK_SET);//SET表示从起始位置开始偏移
//     fseek(pf, -1, SEEK_END);//END从结束位置开始偏移，偏移-1就指向end
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
//     //写文件
//     int ch = 0;
//     for (ch = 'a'; ch <= 'z'; ch++)
//     {
//         fputc(ch,pf);
//     }
    
//     //读文件
//     fseek(pf, -1, SEEK_END);//END从结束位置开始偏移，偏移-1就指向end
//     fputc('@',pf);//把z改成#
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

//     //读文件
//     char ch = fgetc(pf);
//     cout << ch << endl;//a
//     ch = fgetc(pf);
//     cout << ch << endl;//b
    
//     //返回偏移量
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
//     fputs("abcdef", pf);//先将代码放在输出缓冲区
//     printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//     Sleep(10000);
//     printf("刷新缓冲区\n");
//     fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//     //注：fflush 在高版本的VS上不能使用了
//     printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//     Sleep(10000);
//     fclose(pf);
//     //注：fclose在关闭文件的时候，也会刷新缓冲区
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
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    system("pause");
    return 0;
}