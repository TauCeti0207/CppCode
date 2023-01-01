#pragma once
#include <utility>
#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

namespace yzq
{
	template<class K, class V>
	struct AVLTreeNode
	{
		pair<K, V> _kv;
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;

		// AVL树没有规定必须设计balance factor
		int _bf; // balance factor 左右子树高度差 右-左
		AVLTreeNode(const pair<K, V>& kv)
			: _kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
		{}
	};

	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			// 按照搜索树的规则插入，再利用balance factor判断并处理不平衡的情况
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_bf = 0;
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) // 找到节点要插入的位置
			{
				if (cur->_kv.first < kv.first)
					parent = cur, cur = cur->_right;
				else if (cur->_kv.first > kv.first)
					parent = cur, cur = cur->_left;
				else
					return false; // 冗余了
			}
			cur = new Node(kv); // 准备链接节点
			if (parent->_kv.first < kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent; // 注意是三叉链

			// 更新balance factor
			while (parent != nullptr) // 最远更新到根节点
			{
				if (cur == parent->_right) // parent的 bf必须更新
					parent->_bf++;
				else
					parent->_bf--;
				// 再判断是否要继续更新祖先的bf
				if (parent->_bf == 0) // 1 or -1 --> 0 说明插入的节点填上了矮的那边
					break; // 高度不变，更新结束
				else if (parent->_bf == 1 || parent->_bf == -1) // 0 --> 1 or -1 插入节点导致一边变高了
					cur = cur->_parent, parent = parent->_parent; // 子树高度变了 继续更新祖先
				else if (parent->_bf == 2 || parent->_bf == -2) // 1 or -1 --> 2 or -2 插入节点导致本来高的那边更高了
				{
					// 子树不平衡了，需要旋转
					if (parent->_bf == 2 && cur->_bf == 1) // 右边高 左单旋 说明cur在parent右
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1) // 左边高 右单旋
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
						RotateLR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
						RotateRL(parent);
					break; // 旋转完成后 高度不变了 不需要继续更新
				}
				else
					assert(false); // 走到这说明插入之前AVL就不平衡了
			}
			return true;
		}

		vector<vector<int>> levelOrder() {
			vector<vector<int>> vv;
			if (_root == nullptr)
				return vv;

			queue<Node*> q;
			int levelSize = 1;
			q.push(_root);

			while (!q.empty())
			{
				// levelSize控制一层一层出
				vector<int> levelV;
				while (levelSize--)
				{
					Node* front = q.front();
					q.pop();
					levelV.push_back(front->_kv.first);
					if (front->_left)
						q.push(front->_left);

					if (front->_right)
						q.push(front->_right);
				}
				vv.push_back(levelV);
				for (auto e : levelV)
				{
					cout << e << " ";
				}
				cout << endl;

				// 上一层出完，下一层就都进队列
				levelSize = q.size();
			}

			return vv;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		bool IsBalanceTree() { return _IsBalanceTree(_root); }
		int Height() { return _Height(_root); }


	private:
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;
			RotateR(parent->_right);
			RotateL(parent);
			// 双旋完之后更新bf
			if (bf == 0) // h == 0 的情况
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = 0;
			else if (bf == -1) // h >= 1 的一种情况，新增节点再subRL的左边
				subRL->_bf = 0, subR->_bf = 1, parent->_bf = 0;
			else if (bf == 1) // h >= 1 的一种情况，新增节点再subRL的右边
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = -1;
			else
				assert(false); // 走到这说明旋转前就不是平衡树
		}

		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;
			RotateL(parent->_left);
			RotateR(parent);
			if (bf == 0) // h == 0
				subLR->_bf = 0, subL->_bf = 0, parent->_bf = 0;
			else if (bf == 1) // 在subRL的右新增节点
				subLR->_bf = 0, subL->_bf = -1, parent->_bf = 0;
			else if (bf == -1) // 在subRL的左新增节点
				subLR->_bf = 0, subL->_bf = 0, parent->_bf = 1;
			else
				assert(false);
		}

		void RotateR(Node* parent)
		{
			Node* ppNode = parent->_parent;
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;
			parent->_parent = subL;
			if (subLR != nullptr)
				subLR->_parent = parent;
			subL->_right = parent;
			if (parent == _root) // parent可能为根节点 旋转后更新root
				_root = subL, _root->_parent = nullptr;
			else
			{
				if (parent == ppNode->_left)
					ppNode->_left = subL;
				else
					ppNode->_right = subL;
				subL->_parent = ppNode;
			}
			parent->_bf = 0, subL->_bf = 0; // 旋转完更新平衡因子
		}

		void RotateL(Node* parent)
		{
			Node* ppNode = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			parent->_parent = subR;
			if (subRL != nullptr) // 30的右子树可能为空
				subRL->_parent = parent;
			subR->_left = parent;
			if (parent == _root) // parent可能为根节点 旋转完成后要更新root
				_root = subR, _root->_parent = nullptr;
			else // 考虑清楚是子树的右还是左 要连接ppNode 和 subR
			{
				if (parent == ppNode->_left)
					ppNode->_left = subR;
				else
					ppNode->_right = subR;
				subR->_parent = ppNode;
			}

			parent->_bf = 0, subR->_bf = 0; // 旋转完更新平衡因子
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int lh = _Height(root->_left);
			int rh = _Height(root->_right);

			return lh > rh ? lh + 1 : rh + 1; // 左右子树高的+1
		}

		bool _IsBalanceTree(Node* root)
		{
			// 空树也是AVL树
			if (nullptr == root)
				return true;
			// 计算root 节点的平衡因子
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int diff = rightHeight - leftHeight;

			// 如果计算出的平衡因子与root的平衡因子不相等，或者
			// root 平衡因子的绝对值超过1，则一定不是AVL树
			if (abs(diff) >= 2)
			{
				cout << root->_kv.first << "节点平衡因子异常" << endl;
				return false;
			}

			if (diff != root->_bf)
			{
				cout << root->_kv.first << "节点平衡因子不符合实际" << endl;
				return false;
			}

			// root的左和右如果都是AVL树，则该树一定是AVL树
			return _IsBalanceTree(root->_left)
				&& _IsBalanceTree(root->_right);
		}
		Node* _root = nullptr;
	};

	void TestAVLTree1()
	{
		AVLTree<int, int> t;
		t.Insert(make_pair(1, 1));
		t.Insert(make_pair(2, 2));
		t.Insert(make_pair(3, 3));
		t.Insert(make_pair(3, 3));
	}

	void TestAVLTree2()
	{
		//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		int a[] = { 30,29,28,27,26,25,24,11,8,7,6,5,4,3,2,1 };
		//int a[] = { 8,7,6,5,4,3,2,1 };
		AVLTree<int, int> t;
		for (auto e : a)
		{
			t.Insert(make_pair(e, e));
		}
		t.levelOrder();
		/*
		11
		5 27
		3 7 25 29
		2 4 6 8 24 26 28 30
		1
		*/
		// 较为有序
	}

	void TestAVLTree3()
	{
		const size_t N = 1024;
		vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			v.push_back(rand());
			//v.push_back(i);
		}

		AVLTree<int, int> t;
		for (auto e : v)
		{
			t.Insert(make_pair(e, e));
		}

		cout << "是否平衡?" << t.IsBalanceTree() << endl;
		cout << "高度:" << t.Height() << endl;
		//t.levelOrder();
	}
}

namespace bit_homework
{
	template<class T>
	struct AVLTreeNode
	{
		AVLTreeNode(const T& data = T())
			: _pLeft(nullptr)
			, _pRight(nullptr)
			, _pParent(nullptr)
			, _data(data)
			, _bf(0)
		{}

		AVLTreeNode<T>* _pLeft;
		AVLTreeNode<T>* _pRight;
		AVLTreeNode<T>* _pParent;
		T _data;
		int _bf;   // 节点的平衡因子
	};


	// AVL: 二叉搜索树 + 平衡因子的限制
	template<class T>
	class AVLTree
	{
		typedef AVLTreeNode<T> Node;
	public:
		AVLTree()
			: _pRoot(nullptr)
		{}

		// 在AVL树中插入值为data的节点
		bool Insert(const T& data)
		{
			// 按照搜索树规则插入
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_bf = 0;
				return true;
			}
			// 找到要插入的位置
			Node* parent = nullptr;
			Node* cur = _pRoot;
			while (cur)
			{
				if (cur->_data < data)
					parent = cur, cur = cur->_pRight;
				else if (cur->_data > data)
					parent = cur, cur = cur->_pLeft;
				else
					return false; // 冗余
			}
			cur = new Node(data); // 连接起来
			if (parent->_data < data)
				parent->_pRight = cur;
			else
				parent->_pLeft = cur;
			cur->_pParent = parent; // 注意！！！
			while (parent != nullptr) // 更新bf
			{
				if (cur == parent->_pRight)
					parent->_bf++;
				else
					parent->_bf--;
				if (parent->_bf == 0) // 高度不变结束更新
					break;
				else if (parent->_bf == 1 || parent->_bf == -1)
					parent = parent->_pParent, cur = cur->_pParent;
				else if (parent->_bf == 2 || parent->_bf == -2) // 不平衡了 旋转处理
				{
					if (parent->_bf == 2 && cur->_bf == 1)
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1)
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1)
						RotateLR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1)
						RotateRL(parent);
					break; // 旋转完成 不需要继续更新了
				}
				else
					assert(false);
			}
		}

		// AVL树的验证
		bool IsAVLTree()
		{
			return _IsAVLTree(_pRoot);
		}
		size_t Height()
		{
			return _Height(_pRoot);
		}

	private:
		// 根据AVL树的概念验证pRoot是否为有效的AVL树
		bool _IsAVLTree(Node* pRoot)
		{
			if (pRoot == nullptr)
				return true;
			int leftHeight = _Height(pRoot->_pLeft);
			int rightHeight = _Height(pRoot->_pRight);
			int diff = rightHeight - leftHeight;
			if (abs(diff) >= 2)
			{
				cout << pRoot->_data << "节点平衡因子异常" << endl;
				return false;
			}
			if (diff != pRoot->_bf)
			{
				cout << pRoot->_data << "节点平衡因子不符合实际" << endl;
				return false;
			}
			return _IsAVLTree(pRoot->_pLeft)
				&& _IsAVLTree(pRoot->_pRight);
		}
		size_t _Height(Node* pRoot)
		{
			if (pRoot == nullptr)
				return 0;
			int lh = _Height(pRoot->_pLeft);
			int rh = _Height(pRoot->_pRight);
			return lh > rh ? lh + 1 : rh + 1;
		}
		// 右单旋
		void RotateR(Node* pParent)
		{
			Node* ppNode = pParent->_pParent;
			Node* subL = pParent->_pLeft;
			Node* subLR = subL->_pRight;
			pParent->_pLeft = subLR;
			if (subLR != nullptr)
				subLR->_pParent = pParent;
			subL->_pRight = pParent, pParent->_pParent = subL;
			if (pParent == _pRoot)
				_pRoot = subL, subL->_pParent = nullptr;
			else // 不是根节点 处理ppNode
			{
				subL->_pParent = ppNode;
				if (pParent == ppNode->_pLeft)
					ppNode->_pLeft = subL;
				else
					ppNode->_pRight = subL;
			}
			pParent->_bf = 0, subL->_bf = 0;
		}
		// 左单旋
		void RotateL(Node* pParent)
		{
			Node* ppNode = pParent->_pParent;
			Node* subR = pParent->_pRight;
			Node* subRL = subR->_pLeft;
			pParent->_pRight = subRL;
			if (subRL != nullptr)
				subRL->_pParent = pParent;
			subR->_pLeft = pParent, pParent->_pParent = subR;
			if (pParent == _pRoot)
				_pRoot = subR, subR->_pParent = nullptr;
			else
			{
				subR->_pParent = ppNode;
				if (pParent == ppNode->_pLeft)
					ppNode->_pLeft = subR;
				else
					ppNode->_pRight = subR;
			}
			pParent->_bf = 0, subR->_bf = 0;
		}
		// 右左双旋
		void RotateRL(Node* pParent)
		{
			Node* subR = pParent->_pRight;
			Node* subRL = subR->_pLeft;
			int bf = subRL->_bf;
			RotateR(pParent->_pRight);
			RotateL(pParent);
			// 更新bf
			if (bf == 0)
				pParent->_bf = 0, subR->_bf = 0, subRL->_bf = 0;
			else if (bf == -1)
				pParent->_bf = 0, subR->_bf = 1, subRL->_bf = 0;
			else if (bf == 1)
				pParent->_bf = -1, subR->_bf = 0, subRL->_bf = 0;
			else
				assert(false);
		}
		// 左右双旋
		void RotateLR(Node* pParent)
		{
			Node* subL = pParent->_pLeft;
			Node* subLR = subL->_pRight;
			int bf = subLR->_bf;
			RotateL(pParent->_pLeft);
			RotateR(pParent);
			if (bf == 0)
				pParent->_bf = 0, subL->_bf = 0, subLR->_bf = 0;
			else if (bf == -1)
				pParent->_bf = 1, subL->_bf = 0, subLR->_bf = 0;
			else if (bf == 1)
				pParent->_bf = 0, subL->_bf = -1, subLR->_bf = 0;
			else
				assert(false);
		}

	private:
		Node* _pRoot;
	};

	void TestAVLTree()
	{
		const size_t N = 1024 * 1024;
		vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			//v.push_back(rand());
			v.push_back(i);
		}

		AVLTree<int> t;
		for (auto e : v)
		{
			t.Insert(e);
		}

		cout << "是否平衡?" << t.IsAVLTree() << endl;
		cout << "高度：" << t.Height() << endl;
	}
}