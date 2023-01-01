#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	assert(a1);
	int* a2 = (int*)malloc(sizeof(int) * N);
	assert(a2);
	int* a3 = (int*)malloc(sizeof(int) * N);
	assert(a3);
	int* a4 = (int*)malloc(sizeof(int) * N);
	assert(a4);
	int* a5 = (int*)malloc(sizeof(int) * N);
	assert(a5);
	int* a6 = (int*)malloc(sizeof(int) * N);
	assert(a6);
	int* a7 = (int*)malloc(sizeof(int) * N);
	assert(a7);
	int* a8 = (int*)malloc(sizeof(int) * N);
	assert(a8);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();

	//int begin7 = clock();
	//BubbleSort1(a7, N);
	//int end7 = clock();

	//int begin8 = clock();
	//BubbleSort2(a8, N);
	//int end8 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	//int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	//int end5 = clock();

	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();

	//printf("InsertSort:%d\n", end1 - begin1); 
	//printf("BubbleSort1:%d\n", end7 - begin7); 
	//printf("BubbleSort2:%d\n", end8 - begin8); 
	printf("ShellSort:%d\n", end2 - begin2); 
	//printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
}

void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, 10);
}

void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	BubbleSort1(a, sizeof(a) / sizeof(int));
	PrintArr(a, 10);
}

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, 10);
}

int main()
{
	TestOP();
	//TestShellSort();
	//TestBubbleSort();
	return 0;
}