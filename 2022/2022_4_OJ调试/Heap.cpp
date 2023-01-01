#include "Heap.h"

void HeapInit(HP *php)
{
    assert(php);
    php->a = NULL;
    php->capacity = php->size = 0;
}
void HeapDestroy(HP *php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}
void Swap(HPDataType *pa, HPDataType *pb)
{
    HPDataType tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

// 为了保持小堆
void AdjustUp(HPDataType *a, size_t child)
{
    size_t parent = (child - 1) / 2;
    while (child > 0) // child = 0时结束，
    {
        // 要保持小堆，父亲必须比孩子小
        if (a[child] < a[parent])
        // if (a[child] > a[parent])  // 大堆
        {
            Swap(&a[child], &a[parent]);
            // 迭代
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break; //满足小堆时就break
        }
    }
}

// 假设一开始是小堆
// 插入之后要尽可能不影响堆，还要保持堆的性质，因此尾插最好，头插不可取。
// 如果有影响，只会影响他的祖先节点，因此需要和祖先节点依次比较。
void HeapPush(HP *php, HPDataType x)
{
    assert(php);
    // 先判断是否满
    if (php->size == php->capacity)
    {
        size_t newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
        HPDataType *tmp = (HPDataType *)realloc(php->a, sizeof(HPDataType) * newCapacity);
        assert(tmp);
        php->a = tmp;
        php->capacity = newCapacity;
    }
    php->a[php->size++] = x;

    // 插完之后考虑向上调整，保持小堆
    AdjustUp(php->a, php->size - 1); // 最后一个元素的坐标
}

// 1.找左右孩子小的那个
// 2.和父亲比较，比父亲小就交换
// 3.继续向下调整
// void AdjustDown(HPDataType *a, size_t size, size_t root)
// {
//     assert(a);
//     size_t parent = root;
//     size_t leftChild = parent * 2 + 1, rightChild = parent * 2 + 2;
//     // 注意右孩子不一定存在
//     while (rightChild < size && leftChild < size && parent < size)
//     {
//         // 选出左右孩子小的那个
//         size_t minChild = a[leftChild] < a[rightChild] ? leftChild : rightChild;
//         if (a[minChild] < a[parent])
//         {
//             // 孩子小于父亲才交换
//             Swap(&a[minChild], &a[parent]);
//             // 迭代
//             parent = minChild;
//             leftChild = parent * 2 + 1;
//             rightChild = parent * 2 + 2;
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// 1.找左右孩子小的那个
// 2.和父亲比较，比父亲小就交换
// 3.继续向下调整
void AdjustDown(HPDataType *a, size_t size, size_t root)
{
    assert(a);
    size_t parent = root;
    size_t child = parent * 2 + 1;
    while (child < size)
    {
        // 选出左右孩子小的一个，注意考虑右孩子不存在的情况
        // 大堆就要选出大的那个
        if (child + 1 < size && a[child + 1] < a[child]) // 小堆
        // if (child + 1 < size && a[child + 1] > a[child]) // 大堆
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

// 删除之后依旧保持堆的性质，删除堆顶的数据（最小/最大）
// 思路一：数组的数据挪动，
// 效率低，O（N）；堆结构破坏，父子间关系乱了。
// 思路二：交换首尾数据，--size，然后向下调整，复杂度是完全二叉树高度 log2*N
void HeapPop(HP *php)
{
    assert(php);
    assert(php->size > 0);
    Swap(&php->a[0], &php->a[php->size - 1]);
    --php->size;
    AdjustDown(php->a, php->size, 0); // 从根开始调
}

void HeapPrint(HP *php)
{
    assert(php);
    int num = 0;
    int levelSize = 1; // 第一层1个数，第二个2个数。。。
    for (size_t i = 0; i < php->size; i++)
    {
        printf("%d ", php->a[i]);
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

bool HeapEmpty(HP *php)
{
    assert(php);
    return php->size == 0;
}
size_t HeapSize(HP *php)
{
    assert(php);
    return php->size;
}
HPDataType HeapTop(HP *php)
{
    assert(php);
    assert(php->size > 0);
    return php->a[0];
}