#include "Sort.h"

void PrintArr(int* arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	// ��������end�±��0~n-2
	for (int i = 0; i < n - 1; ++i)
	{
		// ��д��������  [0, end] end+1  ��tmp���뵽����[0,end]������������
		int end = i;
		// �ȱ���Ҫ���������
		int tmp = a[end + 1];

		while (end >= 0)
		{
			// ����С�ͷ�ǰ�棬�����ͷ��ں���
			if (tmp < a[end])
			//if (tmp > a[end]) // ����,������ȥ��ǰ��
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		// ��Ҫ���ǵ�end�ߵ�-1�������Ҳ����tmp�������е�����ҪС
		a[end + 1] = tmp; // ��ʱend+1 ǡ�þ���0
		//tmp>=a[end] Ҳ��Ҫ��tmp�ŵ�a[end+1]����
	}
}
// ʱ�临�Ӷ�O(N*N)
// ���������� 1+2+3+4+����+N --��O(N*N)
// ��������˳�� O(N)
// ���������������ӽ����������²űȽϺá�


void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


// ð��������һ�ֽ�������
void BubbleSort1(int* a, int n)
{
	// ��д��������
	for (int j = 0; j < n; ++j)
	{
		// ����exchange�Ż�һ��
		int exchange = 0;
		// ��д��������
		for (int i = 1; i < n - j; ++i)
		{
			// ��������ð������棬Ҳ�������������
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			// ˵��û�з���������Ҳ����ǰ���ǡ���������
			break;
		}
	}
}
// �Ż�֮���ð�ݣ���������˳������O(N)
// ����������O(N*N)

// �����Ż���BubbleSort
void BubbleSort2(int* a, int n)
{
	// ��д��������
	for (int j = 0; j < n; ++j)
	{
		// ��д��������
		for (int i = 1; i < n - j; ++i)
		{
			// ��������ð������棬Ҳ�������������
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}
}


void ShellSort(int* a, int n)
{
	// gap > 1  Ԥ����
	// gap = 1 ֱ�Ӳ�������
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -�� 3^x = n  x�������whileѭ���ܵĴ���
	{
		// ��֤���һ��gapΪ1
		gap = gap / 3 + 1;

		// ��һ������һ�����±���n-gap-1
		for (int i = 0; i < n - gap; ++i) // ����ͬʱ��ʼ�ţ�����Ҫ����һ��ѭ����i+=gap
		{
			int end = i;

			// ����end���������
			int tmp = a[end + gap];

			// ��д����Ԥ����
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//end�Ƶ�<0ʱ��Ҫ��tmp�ŵ�a[end+gap]����
			//tmp>=a[end]Ҳ��Ҫ��tmp�ŵ�a[end+gap]����
			a[end + gap] = tmp;
		}
	}
}
// ƽ��ʱ�临�Ӷ�O(N^1.3)  ��Ϊgap��ȷ��
// gapΪ3�������O(log3(N) * N) ����log3(N)����3Ϊ��N�Ķ���
// Ԥ����ĸ��ӶȲ����O(N) gap�ܴ�ʱ�������O(N); gap��Сʱ���ܽӽ������ˣ�Ҳ�����O(N)


void HeapSort(int* a, int size)
{
	// ���� 2�ַ�ʽ
	// 2.ʹ�����µ������ѣ����µ�����ǰ���������������Ƕѣ�������轨С�ѣ�
	// �ӵ����ĵ�һ����Ҷ�ӽڵ㿪ʼ������Ҳ�������һ���ڵ�ĸ��׽ڵ㣩

	//O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	//O(N*LogN)
	size_t end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//����ʱ�临�ӶȻ���O(N*LogN)

void AdjustDown(int* a, size_t size, size_t root)
{
	assert(a);
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		// ѡ�����Һ���С��һ����ע�⿼���Һ��Ӳ����ڵ����
		// ��Ѿ�Ҫѡ������Ǹ�
		if (child + 1 < size && a[child + 1] < a[child]) // С��
		// if (child + 1 < size && a[child + 1] > a[child])  // ���
		{
			++child;
		}
		// ����С�ڸ��ײŽ��������������µ���
		if (a[child] < a[parent]) // С��
		// if (a[child] > a[parent]) // ���
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}