#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// int main(int argc, char const *argv[])
// {
//     //���ļ�
//     FILE* pf = fopen("test.txt","r");//ע����""
//     if (pf == nullptr)
//     {
//         //printf("fopen fail\n");
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //д�ļ�
//     //...

//     //�ر��ļ�
//     fclose(pf);
//     pf = nullptr;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //���ļ�
//     FILE* pf = fopen("data.txt","r");//ע����""
//     if (pf == nullptr)
//     {
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //д�ļ�
//     // int ch = 0;
//     // for (ch  = 'a'; ch < 'z'; ch++)
//     // {
//     //     fputc(ch,pf);//д����Ļ���� abcdefghijklmnopqrstuvwxy
//     // }

//     //���ļ�
//     int ch = 0;//��int���ܽ���ASCII Ҳ�ܽ���EOF
//     while ((ch = fgetc(pf)) != EOF)
//     {
//         printf("%c ",ch);
//     }
//     //�ر��ļ�
//     fclose(pf);
//     pf = nullptr;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //���ļ�
//     FILE* pf = fopen("data.txt","w");//ע����""
//     if (pf == nullptr)
//     {
//         printf("%s\n",strerror(errno));//No such file or directory
//         exit(-1);
//     }
//     //дһ��
//     fputs("hello world\n",stdout);
//     fputs("hello\n",pf);

//     //�ر��ļ�
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //���ļ�
//     FILE *pf = fopen("data.txt", "r"); //ע����""
//     if (pf == nullptr)
//     {
//         printf("%s\n", strerror(errno)); // No such file or directory
//         exit(-1);
//     }
//     //���ļ� ��һ��
//     char buf[1000] = {0};
//     fgets(buf, 1000, pf); //ʵ�ʶ�999��
//     printf("%s",buf);

//     //�ر��ļ�
//     fclose(pf);
//     pf = nullptr;
//     system("pause");
//     return 0;
// }
#include <windows.h>

// //��data.txt����һ�� ����data2.txt
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
//         // pw����ʧ��
//         fclose(pr);
//         pr = NULL;
//         return 0;
//     }
//     //�����ļ�
//     int ch = 0;
//     while ((ch = fgetc(pr)) != EOF)
//     {
//         fputc(ch, pw); //��һ��дһ��
//     }

//     //�ر��ļ�
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
// 	//����ʽ�������� ��data.txt�ж�
// 	fscanf(pf, "%s %d %lf", s.name, &(s.age), &(s.d));

// 	printf("%s %d %lf\n", s.name, s.age, s.d);

// 	fclose(pf);
// 	pf = NULL;

// 	return 0;
// }

// int main()
// {
// 	struct Stu s = { "����", 20, 95.5 };
// 	FILE* pf = fopen("data.txt", "w");
// 	if (pf == NULL)
// 	{
// 		printf("%s\n", strerror(errno));
// 		return 0;
// 	}
// 	//д��ʽ��������
// 	fprintf(stdout, "%s %d %lf", s.name, s.age, s.d);
// 	fprintf(pf, "%s %d %lf", s.name, s.age, s.d);

// 	fclose(pf);
// 	pf = NULL;

// 	return 0;
// }

// //�����Ƶ�д
// int main()
// {
//     struct Stu s[2] = {{"����", 20, 96}, {"����", 20, 86}};
//     FILE *pf = fopen("data.txt", "wb");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     //���ն����Ƶķ�ʽд��
//     fwrite(&s,sizeof(struct Stu),2,pf);//д2��
//     //ע������Ƶķ�ʽд��ȥ��,�ı���ʽ�򿪵�������,��Ҫͨ�������Ʊ༭����
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// //�����ƵĶ�
// int main()
// {
//     struct Stu s[2] = {0};
//     FILE *pf = fopen("data.txt", "rb");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     //���ն����Ƶķ�ʽ������
//     fread(s,sizeof(struct Stu),2,pf);//д2��
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
