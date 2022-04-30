#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>

//// 定义二叉树结点
//typedef struct BinaryTreeNode
//{
//    char data;
//    struct BinaryTreeNode* left;
//    struct BinaryTreeNode* right;
//}BTNode;
//
//BTNode* CreateTree(char* a, int* pi)
//{
//    // 空树直接return空
//    if (a[*pi] == '#')
//    {
//        // 遇到空树也要让i++
//        (*pi)++;
//        return NULL;
//    }
//
//    //创建根节点
//    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//    assert(root);
//    root->data = a[(*pi)++];
//
//    // 递归创建左右子树
//    root->left = CreateTree(a, pi);
//    root->right = CreateTree(a, pi);
//
//    // 返回根节点
//    return root;
//}
//
//// 中序遍历输出
//void InOrder(BTNode* root)
//{
//    // 空树直接return
//    if (root == NULL)
//        return;
//
//    // 左 根 右 
//    InOrder(root->left);
//    printf("%c ", root->data);
//    InOrder(root->right);
//}
//
//int main()
//{
//    // 读入字符串
//    char a[100];
//    scanf("%s", a);
//    int i = 0;
//
//    // 创建树
//    BTNode* tree = CreateTree(a, &i);
//
//    //中序输出
//    InOrder(tree);
//
//    return 0;
//}

//。。

