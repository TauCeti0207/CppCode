#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>

//// ������������
//typedef struct BinaryTreeNode
//{
//    char data;
//    struct BinaryTreeNode* left;
//    struct BinaryTreeNode* right;
//}BTNode;
//
//BTNode* CreateTree(char* a, int* pi)
//{
//    // ����ֱ��return��
//    if (a[*pi] == '#')
//    {
//        // ��������ҲҪ��i++
//        (*pi)++;
//        return NULL;
//    }
//
//    //�������ڵ�
//    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//    assert(root);
//    root->data = a[(*pi)++];
//
//    // �ݹ鴴����������
//    root->left = CreateTree(a, pi);
//    root->right = CreateTree(a, pi);
//
//    // ���ظ��ڵ�
//    return root;
//}
//
//// ����������
//void InOrder(BTNode* root)
//{
//    // ����ֱ��return
//    if (root == NULL)
//        return;
//
//    // �� �� �� 
//    InOrder(root->left);
//    printf("%c ", root->data);
//    InOrder(root->right);
//}
//
//int main()
//{
//    // �����ַ���
//    char a[100];
//    scanf("%s", a);
//    int i = 0;
//
//    // ������
//    BTNode* tree = CreateTree(a, &i);
//
//    //�������
//    InOrder(tree);
//
//    return 0;
//}

//����

