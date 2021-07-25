#include<stdio.h>
void fun(int a, int b, int c)
{
	a = 456; b = 567; c = 678;
}
void main()
{
	int a=0, b=0, c=0;
	int x = 10, y = 20, z = 30;
	fun(x, y, z);
	printf("%d,%d,%d\n", x, y, z);
	printf("%d,%d,%d\n", a, b, c);
}