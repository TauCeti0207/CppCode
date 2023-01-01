#include "Heap.h"


// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);

	// 把数组的值拷到堆里
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(hp->_a);
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

	while (child < n) // = n时已经越界
	{
		// 建大堆，选左右孩子中大的那个 注意考虑右孩子有可能越界
		// 假设左孩子比较大
		//if (child + 1 < n && a[child + 1] > a[child])
		if (child + 1 < n && a[child + 1] < a[child]) // 小堆
		{
			++child;
		}

		// 孩子大于父亲才交换
		//if (a[child] > a[parent])
		if (a[child] < a[parent]) // 小堆
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
		//if (a[child] > a[parent])
		if (a[child] < a[parent]) // 小堆
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
	assert(hp);

	// 先判断是否满了
	if (hp->_size == hp->_capacity)
	{
		size_t newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		assert(tmp);
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}

	// 拷贝值进去
	hp->_a[hp->_size++] = x;

	// 插完之后要向上调整
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}


// 堆的删除
// 交换首尾数据，--size，然后向下调整
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0); // size > 0 才能Pop

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);

	hp->_size--;

	// 从0才开始向下调整
	AdjustDown(hp->_a, hp->_size, 0);
}


// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);

	return hp->_a[0];
}


// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}


// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0;
}


// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	// 用a中的前k个数据建小堆，找最大的k个数

	// 创建数组并拷贝相关数据
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	assert(kMinHeap);
	for (size_t i = 0; i < k; i++)
	{
		kMinHeap[i] = a[i];
	}

	// 前k个数建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(kMinHeap, k, i);
	}

	// 将剩下n-k 个数和堆顶元素比较
	for (int i = k; i < n; i++)
	{
		// 比堆顶元素大就进去，小堆，堆顶是k个元素中最小的
		if (a[i] > kMinHeap[0])
		{
			kMinHeap[0] = a[i];

			// 替换之后向下调整，从根开始调整
			AdjustDown(kMinHeap, k, 0);
		}
	}

	// 显示结果
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

	// 验证能找到最大的10个数
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

	PrintTopK(a, n, 10); // 找出最大的10个数
}

