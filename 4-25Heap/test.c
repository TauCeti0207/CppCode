#include "Heap.h"



void Test1()
{
	Heap hp;
	HPDataType a[] = { 1, 3, 2, 4, 5, 8, 9, 10 };
	HeapCreate(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

	HeapDestory(&hp);
}

int main()
{
	Test1();
	return 0;
}