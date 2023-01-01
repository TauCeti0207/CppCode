#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void PrintArr(int* arr, int n);
void Swap(int* pa, int* pb);
void AdjustDown(int* a, size_t size, size_t root);


void InsertSort(int* a, int n);
void BubbleSort1(int* a, int n);
void BubbleSort2(int* a, int n);
void ShellSort(int* a, int n);
void HeapSort(int* a, int size);