/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-10 17:05:13
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <time.h>
#include <stack>
#include <queue>
#include <memory>
#include <cstddef>
#include <cstdio>
#include <cstdint>
#include "BinarySearchTree.h"

void testBSTree1()
{
	int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
	yzq::BSTree<int> bst;
	for (auto e : a)
	{
		bst.Insert(e);
	}
	bst.InOrder();

	for (auto e : a)
	{
		bst.Erase(e);
		bst.InOrder();
	}
}

void testBSTree2()
{
	int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
	yzq::BSTree<int> bst;
	for (auto e : a)
	{
		bst.InsertR(e);
	}
	bst.InOrder();

	for (auto e : a)
	{
		bst.EraseR(e);
		bst.InOrder();
	}
	bst.InsertR(8);

	yzq::BSTree<int> copyBst = bst;
	copyBst.InOrder();
}

int main(int argc, char const *argv[])
{
	// testBSTree2();
	key_value::testBSTree2();
	return 0;
}
