#include "Heap.h"

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);

	// �������ֵ��������
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = hp->_capacity = n;
	for (size_t i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}

	//�������� ������и���Ҷ�ӽ�㿪ʼ���µ���
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		// ����ѣ�ѡ���Һ����д���Ǹ� ע�⿼���Һ����п���Խ��
		// �������ӱȽϴ�
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// ���Ӵ��ڸ��ײŽ���
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			// ����֮��Ҫ���е���
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDataType* a, int n, int root)
{
	int child = root;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//���Ӵ��ڸ��׾ͽ��н���
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// �ֲ��ӡ
void HeapPrint(Heap* hp)
{
	assert(hp);
	int num = 0;
	int levelSize = 1; // ��һ��1�������ڶ���2����������
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
		++num;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n");
	printf("\n");
}

// �ѵĲ���
// ����һ��ʼ��С�ѣ�����֮��Ҫ���ֶѵ�����
void HeapPush(Heap* hp, HPDataType x)
{

}
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();