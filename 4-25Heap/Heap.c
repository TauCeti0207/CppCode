#include "Heap.h"


// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);

	// �������ֵ��������
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(hp->_a);
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

	while (child < n) // = nʱ�Ѿ�Խ��
	{
		// ����ѣ�ѡ���Һ����д���Ǹ� ע�⿼���Һ����п���Խ��
		// �������ӱȽϴ�
		//if (child + 1 < n && a[child + 1] > a[child])
		if (child + 1 < n && a[child + 1] < a[child]) // С��
		{
			++child;
		}

		// ���Ӵ��ڸ��ײŽ���
		//if (a[child] > a[parent])
		if (a[child] < a[parent]) // С��
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
		//if (a[child] > a[parent])
		if (a[child] < a[parent]) // С��
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
	assert(hp);

	// ���ж��Ƿ�����
	if (hp->_size == hp->_capacity)
	{
		size_t newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		assert(tmp);
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}

	// ����ֵ��ȥ
	hp->_a[hp->_size++] = x;

	// ����֮��Ҫ���ϵ���
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}


// �ѵ�ɾ��
// ������β���ݣ�--size��Ȼ�����µ���
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0); // size > 0 ����Pop

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);

	hp->_size--;

	// ��0�ſ�ʼ���µ���
	AdjustDown(hp->_a, hp->_size, 0);
}


// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);

	return hp->_a[0];
}


// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}


// �ѵ��п�
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0;
}


// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	// ��a�е�ǰk�����ݽ�С�ѣ�������k����

	// �������鲢�����������
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	assert(kMinHeap);
	for (size_t i = 0; i < k; i++)
	{
		kMinHeap[i] = a[i];
	}

	// ǰk��������
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(kMinHeap, k, i);
	}

	// ��ʣ��n-k �����ͶѶ�Ԫ�رȽ�
	for (int i = k; i < n; i++)
	{
		// �ȶѶ�Ԫ�ش�ͽ�ȥ��С�ѣ��Ѷ���k��Ԫ������С��
		if (a[i] > kMinHeap[0])
		{
			kMinHeap[0] = a[i];

			// �滻֮�����µ������Ӹ���ʼ����
			AdjustDown(kMinHeap, k, 0);
		}
	}

	// ��ʾ���
	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");
}


void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand((unsigned)time(0));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}

	// ��֤���ҵ�����10����
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[523] = 1000000 + 3;
	a[223] = 1000000 + 4;
	a[4545] = 1000000 + 5;
	a[999] = 1000000 + 6;
	a[87] = 1000000 + 7;
	a[993] = 1000000 + 8;
	a[528] = 1000000 + 9;
	a[53] = 1000000 + 10;

	PrintTopK(a, n, 10); // �ҳ�����10����
}

