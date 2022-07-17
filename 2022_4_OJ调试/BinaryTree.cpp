#include "BinaryTree.h"

BTNode *BuyBTNote(BTDataType x)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    assert(node);
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

// 手动构建二叉树
BTNode *CreatBinaryTree()
{
    BTNode *node1 = BuyBTNote(1);
    BTNode *node2 = BuyBTNote(2);
    BTNode *node3 = BuyBTNote(3);
    BTNode *node4 = BuyBTNote(4);
    BTNode *node5 = BuyBTNote(5);
    BTNode *node6 = BuyBTNote(6);

    // 手动链接
    node1->left = node2;
    node2->left = node3;
    // node2->right = NULL;
    node1->right = node4;
    node4->left = node5;
    node4->right = node6;

    // 返回根节点
    return node1;
}

// 根左右
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

// 左根右
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

// 左右根
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
// 这样不合适，每个栈帧都有一个count，没法加到一起。 那我们定义成全局的？

extern int count; // 公用一个全局变量，用extern声明，此处并非定义
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

// 利用静态变量
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

// 传一个变量的地址，最安全的写法
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

//分治算法思想，把大问题拆成小问题
int BTreeSize5(BTNode *root)
{
    //结点个数 = 左+右+我自己
    return root == NULL ? 0 : BTreeSize5(root->left) + BTreeSize5(root->right) + 1;
}

// 传一个变量的地址，最安全的写法
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

//叶子结点个数
int BTreeLeafSize2(BTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BTreeLeafSize2(root->left) + BTreeLeafSize2(root->right);
}

//第k层结点个数，k>=1，k有可能超出树的高度
//左子树的第k-1层 + 右子树的第k-1层
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

// 求二叉树的深度
// 左子树高度和右子树高度大的那个+1
int BTreeDepth(BTNode *root)
{
    if (root == NULL)
        return 0;
    int leftDepth = BTreeDepth(root->left);
    int rightDepth = BTreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// 二叉树查找值为x的结点
// 用前序去找
// 注意要拿到递归的返回值
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
    // 左右子树都没有，返回空
    return NULL;
}

// 一开始不能先干掉根，不然就找不到左右子树了
//一般选择一级指针，为了保持接口一致性,使用者要注意置空
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
//或者C++中使用引用来解决
// void BTreeDestroy(BTNode*& root)