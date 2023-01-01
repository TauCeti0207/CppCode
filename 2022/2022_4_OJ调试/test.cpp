#include "BinaryTree.h"
#include "Heap.h"
#include "Queue.h"

void TestHeap1()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 5);
	HeapPush(&hp, 3);
	HeapPush(&hp, 0);
	HeapPush(&hp, 8);
	HeapPush(&hp, 9);
	HeapPush(&hp, 2);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestroy(&hp);
}

// 升序 O(N*logN)，向下调整是logN
void HeapSort1(int* a, int size)
{
	HP hp;
	HeapInit(&hp);
	// 时间复杂度O(N*logN)
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, a[i]); // 先把数据全部push进去  默认是小堆
	}

	size_t j = 0;
	// 依次取堆顶数据，放到数组里
	// 时间复杂度O(N*logN)
	while (!HeapEmpty(&hp))
	{
		a[j++] = HeapTop(&hp); // 默认是小堆，堆顶数据是最小的
		HeapPop(&hp);
	}
}
// 缺陷，O(N)空间复杂度
// 还得写一个堆，太麻烦了吧！
// 实际中是不会这么取写的。

// 优化：
// 升序要建小堆
// 数组可以看成完全二叉树，直接把数组看成堆，在数组上建堆
void HeapSort2(int* a, int size)
{
	// 建堆 2种方式
	// 1.使用向上调整，插入数据的思想来建堆
	// 第一个数必定为堆，然后一个一个插入的过程中，前2个是堆，前3个也还是堆。。。
	for (int i = 1; i < size; ++i) // 没必要从0开始，第一个数不需要插入
	{
		AdjustUp(a, i);
	}
}

void HeapSort3(int* a, int size)
{
	// 建堆 2种方式
	// 2.使用向下调整建堆，向下调整的前提是左右子树都是堆（这里假设建小堆）
	// 从倒数的第一个非叶子节点开始调整（也就是最后一个节点的父亲节点）
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	size_t end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// 注意向上调整和向下调整建出来的堆其实不一样
// AdjustDown(a, size, i);  0 2 1 6 5 4 7 8
// AdjustUp(a, i);  0 4 1 6 5 7 2 8

// 建大堆：8 6 7 4 5 1 0 2
void TestHeapSort()
{
	int a[] = { 2, 6, 7, 4, 5, 1, 0, 8 };
	HeapSort3(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// TopK问题
// 找最大的K个，建小堆
void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆，用a中前k个数建堆
	int* KminHeap = (int*)malloc(sizeof(int) * k);
	assert(KminHeap);
	for (size_t i = 0; i < k; i++)
	{
		KminHeap[i] = a[i];
	}
	// 建小堆
	for (int j = (k - 1 - 1) / 2; j >= 0; --j)
	{
		AdjustDown(KminHeap, k, j);
	}

	// 将剩下的n-k个元素依次与堆顶元素比较
	for (int i = k; i < n; ++i)
	{
		if (a[i] > KminHeap[0]) // 只要比10个中最小那个大就替换进去。
		{
			KminHeap[0] = a[i];
			AdjustDown(KminHeap, k, 0); // 从根开始向下调整
		}
	}

	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", KminHeap[i]);
	}
	printf("\n");

	// 找到最大的前10个后，再排序一波
	HeapSort3(KminHeap, 10);
	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", KminHeap[i]);
	}
	printf("\n");
}

void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000; // 保证随机数都<1000000
	}
	// 用来验证找的10个最大的数是否正确。
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
	PrintTopK(a, n, 10); // 找最大的前10个
}

int count = 0; // 定义的全局变量
void TestBinaryTree()
{
	BTNode* tree = CreatBinaryTree();
	PrevOrder(tree);
	printf("\n");
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	printf("\n");

	BTreeSize2(tree);
	printf("Size: %d", count);
	printf("\n");

	BTreeSize2(tree);
	printf("Size: %d", count);
	printf("\n");
}

void TestBinaryTree2()
{
	BTNode* tree = CreatBinaryTree();
	printf("%d\n", BTreeSize3(tree));
	printf("%d\n", BTreeSize3(tree));

	count = 0;
	BTreeSize2(tree);
	printf("Size: %d", count);
	printf("\n");

	count = 0;
	BTreeSize2(tree);
	printf("Size: %d", count);
	printf("\n");

	count = 0;
	BTreeSize2(tree);
	printf("Size: %d", count);
	printf("\n");
}

void TestBinaryTree3()
{
	BTNode* tree = CreatBinaryTree();
	int count4 = 0;
	BTreeSize4(tree, &count4);
	printf("Size: %d\n", count4);
	int count5 = 0;
	BTreeSize4(tree, &count5);
	printf("Size: %d\n", count5);
}

void TestBinaryTree4()
{
	BTNode* tree = CreatBinaryTree();
	printf("Size: %d\n", BTreeSize5(tree));
	printf("Size: %d\n", BTreeSize5(tree));
	printf("Size: %d\n", BTreeSize5(tree));
}

void TestBinaryTree5()
{
	BTNode* tree = CreatBinaryTree();
	int count5 = 0;
	BTreeLeafSize1(tree, &count5);
	printf("LeafSize: %d\n", count5); // 3个叶子节点
	printf("LeafSize: %d\n", BTreeLeafSize2(tree));
	printf("KLevelSize: %d\n", BTreeKLevelSize(tree, 3));
	printf("BTreeDepthSize: %d\n", BTreeDepth(tree));
}
void TestBinaryTree6()
{
	BTNode* tree = CreatBinaryTree();
	for (int i = 1; i <= 7; ++i)
	{
		printf("Find:%d, %p\n", i, BTreeFind(tree, i)); // 7是找不到的，返回NULL
	}
	PrevOrder(tree);
	printf("\n");
	BTNode* ret = BTreeFind(tree, 5);
	if (ret)
	{
		ret->data = 50;
	}
	PrevOrder(tree);
	printf("\n");

	BTreeDestroy(tree);
	tree = NULL; // 注意调用者手动置空
}

// 层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root) // root 不为空才往里面插入数据
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		// 先把根pop出来
		BTNode* front = QueueFront(&q);
		QueuePop(&q); // 只是把结点指针pop出去，没有销毁结点。
		printf("%d ", front->data);

		// 把根的左右结点带进去
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestroy(&q);
}

bool BTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	// 先入根
	if (root)
	{
		QueuePush(&q, root);
	}

	//出一个带进去2个
	while (!QueueEmpty(&q))
	{
		// 先取队头数据，然后Pop
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		// 如果是空，就break，然后再判断空之后是否全为空
		if (front == NULL)
		{
			break;
		}

		// 不管是否为空都把左右结点入进去，这也才能保证某一次QueueFront取到的结点为空才能进一步判断
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	// 判断第一个空后面是否全为空，如果不完为空则说明不是完全二叉树
	while (!QueueEmpty(&q))
	{
		// 先取队头数据，然后Pop
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			// return之前一定要销毁队列，不然会有内存泄露
			QueueDestroy(&q);
			return false;
		}

	}

	QueueDestroy(&q);

	// 后面全为空
	return true;
}

int main(int argc, char const* argv[])
{
	// TestHeap1();
	TestHeapSort();
	// TestTopK();
	//BTNode *tree = CreatBinaryTree();

	// LevelOrder(tree);
	//printf("%d\n", BTreeComplete(tree));
	return 0;
}
