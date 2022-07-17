#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    BTDataType data;
} BTNode;

BTNode *CreatBinaryTree();
BTNode *BuyBTNote(BTDataType x);
void PrevOrder(BTNode *root);
void InOrder(BTNode *root);
void PostOrder(BTNode *root);

void BTreeSize2(BTNode *root);
void BTreeSize1(BTNode *root);
int BTreeSize3(BTNode *root);
void BTreeSize4(BTNode *root, int *pCount);
int BTreeSize5(BTNode *root);

void BTreeLeafSize1(BTNode *root, int *pCount);
int BTreeLeafSize2(BTNode *root);

int BTreeKLevelSize(BTNode *root, int k);

int BTreeDepth(BTNode *root);

BTNode* BTreeFind(BTNode* root, BTDataType x);

void BTreeDestroy(BTNode *root);