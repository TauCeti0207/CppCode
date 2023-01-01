#include "Heap.h"



void Test1()
{
	Heap hp;
	HPDataType a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	HeapCreate(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 11);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	printf("IsEmpty:%d Size:%d HeapTop:%d\n", HeapEmpty(&hp), HeapSize(&hp), HeapTop(&hp));

	TestTopk();

	HeapDestory(&hp);
}

int main()
{
	Test1();
	return 0;
}