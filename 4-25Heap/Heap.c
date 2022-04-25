#include "Heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);

	// 把数组的值拷到堆里
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = hp->_capacity = n;
	for (size_t i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}

	//调整建堆 从最后有个非叶子结点开始向下调整
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

// 堆的销毁
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
		// 建大堆，选左右孩子中大的那个 注意考虑右孩子有可能越界
		// 假设左孩子比较大
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// 孩子大于父亲才交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			// 交换之后要进行迭代
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
		//孩子大于父亲就进行交换
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

// 分层打印
void HeapPrint(Heap* hp)
{
	assert(hp);
	int num = 0;
	int levelSize = 1; // 第一层1个数，第二层2个数。。。
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

// 堆的插入
// 假设一开始是小堆，插入之后还要保持堆的性质
void HeapPush(Heap* hp, HPDataType x)
{

}
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();