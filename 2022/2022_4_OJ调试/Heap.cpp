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

// Ϊ�˱���С��
void AdjustUp(HPDataType *a, size_t child)
{
    size_t parent = (child - 1) / 2;
    while (child > 0) // child = 0ʱ������
    {
        // Ҫ����С�ѣ����ױ���Ⱥ���С
        if (a[child] < a[parent])
        // if (a[child] > a[parent])  // ���
        {
            Swap(&a[child], &a[parent]);
            // ����
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break; //����С��ʱ��break
        }
    }
}

// ����һ��ʼ��С��
// ����֮��Ҫ�����ܲ�Ӱ��ѣ���Ҫ���ֶѵ����ʣ����β����ã�ͷ�岻��ȡ��
// �����Ӱ�죬ֻ��Ӱ���������Ƚڵ㣬�����Ҫ�����Ƚڵ����αȽϡ�
void HeapPush(HP *php, HPDataType x)
{
    assert(php);
    // ���ж��Ƿ���
    if (php->size == php->capacity)
    {
        size_t newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
        HPDataType *tmp = (HPDataType *)realloc(php->a, sizeof(HPDataType) * newCapacity);
        assert(tmp);
        php->a = tmp;
        php->capacity = newCapacity;
    }
    php->a[php->size++] = x;

    // ����֮�������ϵ���������С��
    AdjustUp(php->a, php->size - 1); // ���һ��Ԫ�ص�����
}

// 1.�����Һ���С���Ǹ�
// 2.�͸��ױȽϣ��ȸ���С�ͽ���
// 3.�������µ���
// void AdjustDown(HPDataType *a, size_t size, size_t root)
// {
//     assert(a);
//     size_t parent = root;
//     size_t leftChild = parent * 2 + 1, rightChild = parent * 2 + 2;
//     // ע���Һ��Ӳ�һ������
//     while (rightChild < size && leftChild < size && parent < size)
//     {
//         // ѡ�����Һ���С���Ǹ�
//         size_t minChild = a[leftChild] < a[rightChild] ? leftChild : rightChild;
//         if (a[minChild] < a[parent])
//         {
//             // ����С�ڸ��ײŽ���
//             Swap(&a[minChild], &a[parent]);
//             // ����
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

// 1.�����Һ���С���Ǹ�
// 2.�͸��ױȽϣ��ȸ���С�ͽ���
// 3.�������µ���
void AdjustDown(HPDataType *a, size_t size, size_t root)
{
    assert(a);
    size_t parent = root;
    size_t child = parent * 2 + 1;
    while (child < size)
    {
        // ѡ�����Һ���С��һ����ע�⿼���Һ��Ӳ����ڵ����
        // ��Ѿ�Ҫѡ������Ǹ�
        if (child + 1 < size && a[child + 1] < a[child]) // С��
        // if (child + 1 < size && a[child + 1] > a[child]) // ���
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

// ɾ��֮�����ɱ��ֶѵ����ʣ�ɾ���Ѷ������ݣ���С/���
// ˼·һ�����������Ų����
// Ч�ʵͣ�O��N�����ѽṹ�ƻ������Ӽ��ϵ���ˡ�
// ˼·����������β���ݣ�--size��Ȼ�����µ��������Ӷ�����ȫ�������߶� log2*N
void HeapPop(HP *php)
{
    assert(php);
    assert(php->size > 0);
    Swap(&php->a[0], &php->a[php->size - 1]);
    --php->size;
    AdjustDown(php->a, php->size, 0); // �Ӹ���ʼ��
}

void HeapPrint(HP *php)
{
    assert(php);
    int num = 0;
    int levelSize = 1; // ��һ��1�������ڶ���2����������
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