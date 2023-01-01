#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// int main(int argc, char const *argv[])
// {
//     //打开文件
//     FILE* pf = fopen("test.txt","r");//注意是""
//     if (pf == nullptr)
//     {
//         //printf("fopen fail\n");
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //写文件
//     //...

//     //关闭文件
//     fclose(pf);
//     pf = nullptr;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //打开文件
//     FILE* pf = fopen("data.txt","r");//注意是""
//     if (pf == nullptr)
//     {
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //写文件
//     // int ch = 0;
//     // for (ch  = 'a'; ch < 'z'; ch++)
//     // {
//     //     fputc(ch,pf);//写到屏幕上了 abcdefghijklmnopqrstuvwxy
//     // }

//     //读文件
//     int ch = 0;//用int既能接受ASCII 也能接受EOF
//     while ((ch = fgetc(pf)) != EOF)
//     {
//         printf("%c ",ch);
//     }
//     //关闭文件
//     fclose(pf);
//     pf = nullptr;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //打开文件
//     FILE* pf = fopen("data.txt","w");//注意是""
//     if (pf == nullptr)
//     {
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //写一行
//     fputs("hello world\n",stdout);
//     fputs("hello\n",pf);

//     //关闭文件
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //打开文件
//     FILE *pf = fopen("data.txt", "r"); //注意是""
//     if (pf == nullptr)
//     {
//         printf("%s\n", strerror(errno)); // No such file or directory
//         exit(-1);
//     }
//     //读文件 读一行
//     char buf[1000] = {0};
//     fgets(buf, 1000, pf); //实际读999个
//     printf("%s",buf);

//     //关闭文件
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }
#include <windows.h>

// //将data.txt拷贝一份 生成data2.txt
// int main(int argc, char const *argv[])
// {
//     FILE *pr = fopen("data.txt", "r");
//     if (pr == NULL)
//     {
//         printf("open for reading::%s", strerror(errno));
//         return 0;
//     }
//     FILE *pw = fopen("data2.txt", "w");
//     if (pw == NULL)
//     {
//         printf("open for writing::%s", strerror(errno));
//         // pw开辟失败
//         fclose(pr);
//         pr = NULL;
//         return 0;
//     }
//     //拷贝文件
//     int ch = 0;
//     while ((ch = fgetc(pr)) != EOF)
//     {
//         fputc(ch, pw); //读一个写一个
//     }

//     //关闭文件
//     fclose(pr);
//     pr = NULL;
//     fclose(pw);
//     pw = NULL;
//     system("pause");
//     return 0;
// }

struct Stu
{
    char name[20];
    int age;
    double d;
};

// int main()
// {
// 	struct Stu s = { 0 };
// 	FILE* pf = fopen("data.txt", "r");
// 	if (pf == NULL)
// 	{
// 		printf("%s\n", strerror(errno));
// 		return 0;
// 	}
// 	//读格式化的数据 从data.txt中读
// 	fscanf(pf, "%s %d %lf", s.name, &(s.age), &(s.d));

// 	printf("%s %d %lf\n", s.name, s.age, s.d);

// 	fclose(pf);
// 	pf = NULL;

// 	return 0;
// }

// int main()
// {
// 	struct Stu s = { "张三", 20, 95.5 };
// 	FILE* pf = fopen("data.txt", "w");
// 	if (pf == NULL)
// 	{
// 		printf("%s\n", strerror(errno));
// 		return 0;
// 	}
// 	//写格式化的数据
// 	fprintf(stdout, "%s %d %lf", s.name, s.age, s.d);
// 	fprintf(pf, "%s %d %lf", s.name, s.age, s.d);

// 	fclose(pf);
// 	pf = NULL;

// 	return 0;
// }

// //二进制的写
// int main()
// {
//     struct Stu s[2] = {{"张三", 20, 96}, {"李四", 20, 86}};
//     FILE *pf = fopen("data.txt", "wb");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     //按照二进制的方式写入
//     fwrite(&s,sizeof(struct Stu),2,pf);//写2组
//     //注意二进制的方式写进去后,文本方式打开的是乱码,需要通过二进制编辑器打开
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// //二进制的读
// int main()
// {
//     struct Stu s[2] = {0};
//     FILE *pf = fopen("data.txt", "rb");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     //按照二进制的方式读出来
//     fread(s,sizeof(struct Stu),2,pf);//写2组
//     printf("%s %d %lf\n",s[0].name,s[0].age,s[0].d);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

int main(int argc, char const *argv[])
{
    struct Stu s = {"Tom", 20, 98};
    struct Stu tmp = {0};
    char buf[100] = {0};
    sprintf(buf,"%s %d %lf",s.name,s.age,s.d);
    printf("%s\n",buf);//Tom 20 98.000000

    sscanf(buf,"%s %d %lf",s.name,&(s.age),&(s.d));
    printf(buf,"%s %d %lf",tmp.name,tmp.age,tmp.d);//Tom 20 98.000000

    return 0;
}
