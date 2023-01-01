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
	// 多趟排序，end下标从0~n-2
	for (int i = 0; i < n - 1; ++i)
	{
		// 先写单趟排序  [0, end] end+1  把tmp插入到数组[0,end]的有序区间中
		int end = i;
		// 先保存要插入的数据
		int tmp = a[end + 1];

		while (end >= 0)
		{
			// 比你小就放前面，比你大就放在后面
			if (tmp < a[end])
			//if (tmp > a[end]) // 降序,比你大就去你前面
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		// 还要考虑到end走到-1的情况，也就是tmp比数组中的数都要小
		a[end + 1] = tmp; // 此时end+1 恰好就是0
		//tmp>=a[end] 也需要把tmp放到a[end+1]里面
	}
}
// 时间复杂度O(N*N)
// 最坏情况：逆序 1+2+3+4+……+N --》O(N*N)
// 最好情况：顺序 O(N)
// 插入排序，在有序或接近有序的情况下才比较好。


void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


// 冒泡排序是一种交换排序
void BubbleSort1(int* a, int n)
{
	// 再写多趟排序
	for (int j = 0; j < n; ++j)
	{
		// 利用exchange优化一下
		int exchange = 0;
		// 先写单趟排序
		for (int i = 1; i < n - j; ++i)
		{
			// 把最大的数冒到最后面，也就是完成了升序
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			// 说明没有发生交换，也就是前面的恰好是有序的
			break;
		}
	}
}
// 优化之后的冒泡，最好情况：顺序有序，O(N)
// 最坏情况：逆序，O(N*N)

// 不作优化的BubbleSort
void BubbleSort2(int* a, int n)
{
	// 再写多趟排序
	for (int j = 0; j < n; ++j)
	{
		// 先写单趟排序
		for (int i = 1; i < n - j; ++i)
		{
			// 把最大的数冒到最后面，也就是完成了升序
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}
}


void ShellSort(int* a, int n)
{
	// gap > 1  预排序
	// gap = 1 直接插入排序
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -》 3^x = n  x就是这个while循环跑的次数
	{
		// 保证最后一次gap为1
		gap = gap / 3 + 1;

		// 第一组的最后一个数下标是n-gap-1
		for (int i = 0; i < n - gap; ++i) // 多组同时开始排，不需要再套一层循环，i+=gap
		{
			int end = i;

			// 保存end后面的数据
			int tmp = a[end + gap];

			// 先写单次预排序
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
			//end移到<0时，要把tmp放到a[end+gap]里面
			//tmp>=a[end]也需要把tmp放到a[end+gap]后面
			a[end + gap] = tmp;
		}
	}
}
// 平均时间复杂度O(N^1.3)  因为gap不确定
// gap为3的情况：O(log3(N) * N) 这里log3(N)是以3为底N的对数
// 预排序的复杂度差不多是O(N) gap很大时，差不多是O(N); gap很小时，很接近有序了，也差不多是O(N)


void HeapSort(int* a, int size)
{
	// 建堆 2种方式
	// 2.使用向下调整建堆，向下调整的前提是左右子树都是堆（这里假设建小堆）
	// 从倒数的第一个非叶子节点开始调整（也就是最后一个节点的父亲节点）

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
//总体时间复杂度还是O(N*LogN)

void AdjustDown(int* a, size_t size, size_t root)
{
	assert(a);
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		// 选出左右孩子小的一个，注意考虑右孩子不存在的情况
		// 大堆就要选出大的那个
		if (child + 1 < size && a[child + 1] < a[child]) // 小堆
		// if (child + 1 < size && a[child + 1] > a[child])  // 大堆
		{
			++child;
		}
		// 孩子小于父亲才交换，并继续往下调整
		if (a[child] < a[parent]) // 小堆
		// if (a[child] > a[parent]) // 大堆
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