#include "BinaryTree.h"

BTNode *BuyBTNote(BTDataType x)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    assert(node);
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

// �ֶ�����������
BTNode *CreatBinaryTree()
{
    BTNode *node1 = BuyBTNote(1);
    BTNode *node2 = BuyBTNote(2);
    BTNode *node3 = BuyBTNote(3);
    BTNode *node4 = BuyBTNote(4);
    BTNode *node5 = BuyBTNote(5);
    BTNode *node6 = BuyBTNote(6);

    // �ֶ�����
    node1->left = node2;
    node2->left = node3;
    // node2->right = NULL;
    node1->right = node4;
    node4->left = node5;
    node4->right = node6;

    // ���ظ��ڵ�
    return node1;
}

// ������
void PrevOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

// �����
void InOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

// ���Ҹ�
void PostOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

void BTreeSize1(BTNode *root)
{
    int count1 = 0;
    if (root == NULL)
    {
        return;
    }
    ++count1;
    BTreeSize1(root->left);
    BTreeSize1(root->right);
}
// ���������ʣ�ÿ��ջ֡����һ��count��û���ӵ�һ�� �����Ƕ����ȫ�ֵģ�

extern int count; // ����һ��ȫ�ֱ�������extern�������˴����Ƕ���
void BTreeSize2(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    ++count;
    BTreeSize2(root->left);
    BTreeSize2(root->right);
}

// ���þ�̬����
int BTreeSize3(BTNode *root)
{
    static int count3 = 0;
    if (root == NULL)
    {
        return count3;
    }
    ++count3;
    BTreeSize3(root->left);
    BTreeSize3(root->right);
    return count3;
}

// ��һ�������ĵ�ַ���ȫ��д��
void BTreeSize4(BTNode *root, int *pCount)
{
    if (root == NULL)
    {
        return;
    }
    ++(*pCount);
    BTreeSize4(root->left, pCount);
    BTreeSize4(root->right, pCount);
}

//�����㷨˼�룬�Ѵ�������С����
int BTreeSize5(BTNode *root)
{
    //������ = ��+��+���Լ�
    return root == NULL ? 0 : BTreeSize5(root->left) + BTreeSize5(root->right) + 1;
}

// ��һ�������ĵ�ַ���ȫ��д��
void BTreeLeafSize1(BTNode *root, int *pCount)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
        ++(*pCount);
    BTreeLeafSize1(root->left, pCount);
    BTreeLeafSize1(root->right, pCount);
}

//Ҷ�ӽ�����
int BTreeLeafSize2(BTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BTreeLeafSize2(root->left) + BTreeLeafSize2(root->right);
}

//��k���������k>=1��k�п��ܳ������ĸ߶�
//�������ĵ�k-1�� + �������ĵ�k-1��
int BTreeKLevelSize(BTNode *root, int k)
{
    assert(k >= 1);
    if (root == NULL)
        return 0;
    if (1 == k)
        return 1;
    return BTreeKLevelSize(root->left, k - 1) +
           BTreeKLevelSize(root->right, k - 1);
}

// ������������
// �������߶Ⱥ��������߶ȴ���Ǹ�+1
int BTreeDepth(BTNode *root)
{
    if (root == NULL)
        return 0;
    int leftDepth = BTreeDepth(root->left);
    int rightDepth = BTreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// ����������ֵΪx�Ľ��
// ��ǰ��ȥ��
// ע��Ҫ�õ��ݹ�ķ���ֵ
BTNode *BTreeFind(BTNode *root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    BTNode *lRet = BTreeFind(root->left, x);
    if (lRet)
        return lRet;
    BTNode *rRet = BTreeFind(root->right, x);
    if (rRet)
        return rRet;
    // ����������û�У����ؿ�
    return NULL;
}

// һ��ʼ�����ȸɵ�������Ȼ���Ҳ�������������
//һ��ѡ��һ��ָ�룬Ϊ�˱��ֽӿ�һ����,ʹ����Ҫע���ÿ�
void BTreeDestroy(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    BTreeDestroy(root->left);
    BTreeDestroy(root->right);
    free(root);
}
//����C++��ʹ�����������
// void BTreeDestroy(BTNode*& root)