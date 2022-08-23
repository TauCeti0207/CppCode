#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
//class A
//{
//public:
//	void test(float a)
//	{
//		cout << a;
//	}
//};
//class B :public A
//{
//public: void test(int b)
//{
//	cout << b;
//}
//};
//void main()
//{
//	A* a = new A; B* b = new B; a = b; a->test(1.1);
//}


//class A
//{
//public:
//	A() :m_iVal(0) { test(); }
//	virtual void func() { std::cout << m_iVal << ' '; }
//	void test() { func(); }
//public:
//	int m_iVal;
//};
//
//class B : public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << ' ';
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}


//class A
//{
//public:
//  virtual void f()
//  {
//	cout << "A::f()" << endl;
//  }
//};
//
//class B : public A
//{
//public:
//	virtual void f()
//	{
//		cout << "B::f()" << endl;
//	}
//};
//
//int main()
//{
//	A* pa = (A*)new B;
//	pa->f();
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}

	//operator bool()
	explicit operator bool()
	{
		if (_a < 10)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void Print()
	{
		cout << _a << endl;
	}

	void Set(int a)
	{
		_a = a;
	}

private:
	int _a;
};

void test()
{
	A aa = 2; // 如果构造函数加了explicit 就不允许这样的隐式类型转换

	A a;
	//bool ret = a; // operator bool 加了 explicit 才避免的自定义类型往bool类型的转换
	int x;
	//while (a.operator bool()) 与这个等价
	while (a)
	{
		a.Print();
		cin >> x;
		a.Set(x);
	}
}


namespace LeetCode
{
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:

		bool IsSame(TreeNode* t1, TreeNode* t2)
		{
			if (t1 == nullptr && t2 == nullptr)
				return true;
			if (t1 == nullptr || t2 == nullptr)
				return false;
			// 递归判断左右子树
			return (t1->val == t2->val
				&& IsSame(t1->left, t2->left)
				&& IsSame(t1->right, t2->right));
		}

		bool IsSubTree(TreeNode* tree, TreeNode* subTree)
		{
			// 空树必定是子树
			if (subTree == nullptr)
				return true;
			if (tree == nullptr)
				return false;
			if (IsSame(tree, subTree))
				return true;
			// 递归判断subTree是否是左右子树时候的子树
			return IsSubTree(tree->left, subTree)
				|| IsSubTree(tree->right, subTree);
		}

		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == nullptr)
				return nullptr;
			// 考虑节点是自己祖先的情况
			if (root == p || root == q)
				return root;
			// 判断p、q在root左边还是右边
			bool pInLeft = IsSubTree(root->left, p);
			bool pInRight = !pInLeft;
			bool qInLeft = IsSubTree(root->left, q);
			bool qInRight = !qInLeft;
			// 一个在左、一个在右 我就是公共祖先
			if ((pInLeft && qInRight) || (pInRight && qInLeft))
				return root;
			// 都在左或者都在右
			else if (pInLeft && qInLeft)
				return lowestCommonAncestor(root->left, p, q);
			else if (pInRight && qInRight)
				return lowestCommonAncestor(root->right, p, q);
			else // 不可能去到else
				return nullptr;
		}
	};

	void test()
	{
		TreeNode* root = new TreeNode(3);
		TreeNode* cur = root;
		TreeNode* tmp1 = new TreeNode(5);
		cur->left = tmp1;
		TreeNode* tmp2 = new TreeNode(6);
		cur->left->left = tmp2;
		TreeNode* tmp3 = new TreeNode(2);
		cur->left->right = tmp3;
		TreeNode* tmp4 = new TreeNode(7);
		cur->left->right->left = tmp4;
		TreeNode* tmp5 = new TreeNode(4);
		cur->left->right->right = tmp5;
		TreeNode* tmp6 = new TreeNode(1);
		cur->right = tmp6;
		TreeNode* tmp7 = new TreeNode(0);
		cur->right->left = tmp7;
		TreeNode* tmp8 = new TreeNode(8);
		cur->right->right = tmp8;

		Solution().lowestCommonAncestor(root, tmp1, tmp5);
	}
}

int main()
{
	//BST::TestBSTree5();
	//key_value::TestBSTree2();
	LeetCode::test();
	return 0;
}