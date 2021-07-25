//#include<stdio.h>
//int main()
//{
//	int a[10], i, j, t;
//	for (i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//		for (i = 1; i <=9; i++)
//		{
//			for (j = 0; j < 10 - i; j++)
//			{
//				if (a[j] > a[j + 1])
//				{
//					t = a[j];
//					a[j] = a[j + 1];
//					a[j + 1] = t;
//				}
//			
//			}
//		
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d", a[i]);
//		}
//	
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[], int len)
{
	int i, j, temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
	}
}

int main()
{
	int arr[] = { 5, 8, 6, 3, 9, 2, 1, 7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	printf("≈≈–Ú«∞£∫");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	BubbleSort(arr, len);
	printf("≈≈–Ú∫Û£∫");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}