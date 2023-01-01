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

// ���� O(N*logN)�����µ�����logN
void HeapSort1(int* a, int size)
{
	HP hp;
	HeapInit(&hp);
	// ʱ�临�Ӷ�O(N*logN)
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, a[i]); // �Ȱ�����ȫ��push��ȥ  Ĭ����С��
	}

	size_t j = 0;
	// ����ȡ�Ѷ����ݣ��ŵ�������
	// ʱ�临�Ӷ�O(N*logN)
	while (!HeapEmpty(&hp))
	{
		a[j++] = HeapTop(&hp); // Ĭ����С�ѣ��Ѷ���������С��
		HeapPop(&hp);
	}
}
// ȱ�ݣ�O(N)�ռ临�Ӷ�
// ����дһ���ѣ�̫�鷳�˰ɣ�
// ʵ�����ǲ�����ôȡд�ġ�

// �Ż���
// ����Ҫ��С��
// ������Կ�����ȫ��������ֱ�Ӱ����鿴�ɶѣ��������Ͻ���
void HeapSort2(int* a, int size)
{
	// ���� 2�ַ�ʽ
	// 1.ʹ�����ϵ������������ݵ�˼��������
	// ��һ�����ض�Ϊ�ѣ�Ȼ��һ��һ������Ĺ����У�ǰ2���Ƕѣ�ǰ3��Ҳ���Ƕѡ�����
	for (int i = 1; i < size; ++i) // û��Ҫ��0��ʼ����һ��������Ҫ����
	{
		AdjustUp(a, i);
	}
}

void HeapSort3(int* a, int size)
{
	// ���� 2�ַ�ʽ
	// 2.ʹ�����µ������ѣ����µ�����ǰ���������������Ƕѣ�������轨С�ѣ�
	// �ӵ����ĵ�һ����Ҷ�ӽڵ㿪ʼ������Ҳ�������һ���ڵ�ĸ��׽ڵ㣩
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

// ע�����ϵ��������µ����������Ķ���ʵ��һ��
// AdjustDown(a, size, i);  0 2 1 6 5 4 7 8
// AdjustUp(a, i);  0 4 1 6 5 7 2 8

// ����ѣ�8 6 7 4 5 1 0 2
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

// TopK����
// ������K������С��
void PrintTopK(int* a, int n, int k)
{
	// 1. ���ѣ���a��ǰk��������
	int* KminHeap = (int*)malloc(sizeof(int) * k);
	assert(KminHeap);
	for (size_t i = 0; i < k; i++)
	{
		KminHeap[i] = a[i];
	}
	// ��С��
	for (int j = (k - 1 - 1) / 2; j >= 0; --j)
	{
		AdjustDown(KminHeap, k, j);
	}

	// ��ʣ�µ�n-k��Ԫ��������Ѷ�Ԫ�رȽ�
	for (int i = k; i < n; ++i)
	{
		if (a[i] > KminHeap[0]) // ֻҪ��10������С�Ǹ�����滻��ȥ��
		{
			KminHeap[0] = a[i];
			AdjustDown(KminHeap, k, 0); // �Ӹ���ʼ���µ���
		}
	}

	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", KminHeap[i]);
	}
	printf("\n");

	// �ҵ�����ǰ10����������һ��
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
		a[i] = rand() % 1000000; // ��֤�������<1000000
	}
	// ������֤�ҵ�10���������Ƿ���ȷ��
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
	PrintTopK(a, n, 10); // ������ǰ10��
}

int count = 0; // �����ȫ�ֱ���
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
	printf("LeafSize: %d\n", count5); // 3��Ҷ�ӽڵ�
	printf("LeafSize: %d\n", BTreeLeafSize2(tree));
	printf("KLevelSize: %d\n", BTreeKLevelSize(tree, 3));
	printf("BTreeDepthSize: %d\n", BTreeDepth(tree));
}
void TestBinaryTree6()
{
	BTNode* tree = CreatBinaryTree();
	for (int i = 1; i <= 7; ++i)
	{
		printf("Find:%d, %p\n", i, BTreeFind(tree, i)); // 7���Ҳ����ģ�����NULL
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
	tree = NULL; // ע��������ֶ��ÿ�
}

// �������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root) // root ��Ϊ�ղ��������������
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		// �ȰѸ�pop����
		BTNode* front = QueueFront(&q);
		QueuePop(&q); // ֻ�ǰѽ��ָ��pop��ȥ��û�����ٽ�㡣
		printf("%d ", front->data);

		// �Ѹ������ҽ�����ȥ
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

	// �����
	if (root)
	{
		QueuePush(&q, root);
	}

	//��һ������ȥ2��
	while (!QueueEmpty(&q))
	{
		// ��ȡ��ͷ���ݣ�Ȼ��Pop
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		// ����ǿգ���break��Ȼ�����жϿ�֮���Ƿ�ȫΪ��
		if (front == NULL)
		{
			break;
		}

		// �����Ƿ�Ϊ�ն������ҽ�����ȥ����Ҳ���ܱ�֤ĳһ��QueueFrontȡ���Ľ��Ϊ�ղ��ܽ�һ���ж�
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	// �жϵ�һ���պ����Ƿ�ȫΪ�գ��������Ϊ����˵��������ȫ������
	while (!QueueEmpty(&q))
	{
		// ��ȡ��ͷ���ݣ�Ȼ��Pop
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			// return֮ǰһ��Ҫ���ٶ��У���Ȼ�����ڴ�й¶
			QueueDestroy(&q);
			return false;
		}

	}

	QueueDestroy(&q);

	// ����ȫΪ��
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
