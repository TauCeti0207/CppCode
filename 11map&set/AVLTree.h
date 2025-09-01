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

namespace yzq
{
	template <class K, class V>
	struct AVLTreeNode
	{
		std::pair<K, V> _kv;
		AVLTreeNode<K, V> *_left;
		AVLTreeNode<K, V> *_right;
		AVLTreeNode<K, V> *_parent;

		// AVL树没有规定必须设计balance factor 平衡因子
		int _bf; // balance factor 左右子树高度差 右-左
		AVLTreeNode(const std::pair<K, V> &kv)
			: _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0)
		{
		}
	};

	template <class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
		Node *_root = nullptr;

	public:
		bool Insert(const std::pair<K, V> &kv)
		{
			// 按照搜索树的规则插入，再利用balance factor判断并处理不平衡的情况
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_bf = 0;
				return true;
			}
			Node *parent = nullptr;
			Node *cur = _root;
			while (cur) // 找到节点要插入的位置
			{
				if (cur->_kv.first < kv.first)
					parent = cur, cur = cur->_right;
				else if (cur->_kv.first > kv.first)
					parent = cur, cur = cur->_left;
				else
					return false; // 冗余了
			}
			// 找到空位置了，准备链接节点
			cur = new Node(kv);
			if (parent->_kv.first < kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent; // 注意是三叉链

			// 更新balance factor
			while (parent != nullptr) // 最远更新到根节点
			{
				// 新增节点在右子树，父亲bf++
				if (cur == parent->_right) // parent的 bf必须更新
					parent->_bf++;
				// 新增节点在左子树，父亲bf--
				else
					parent->_bf--;
				// 判断是否要继续更新祖先的bf
				if (parent->_bf == 0)							  // 1 or -1 --> 0 说明插入的节点填上了矮的那边
					break;										  // 高度不变，更新结束
				else if (parent->_bf == 1 || parent->_bf == -1)	  // 0 --> 1 or -1 插入节点导致一边变高了
					cur = cur->_parent, parent = parent->_parent; // 子树高度变了 继续更新祖先
				else if (parent->_bf == 2 || parent->_bf == -2)	  // 1 or -1 --> 2 or -2 插入节点导致本来高的那边更高了
				{
					// 这时子树不平衡了，需要旋转节点，调整结构
					if (parent->_bf == 2 && cur->_bf == 1) // 右边高 左单旋 说明cur在parent右
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1) // 左边高 右单旋
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
						RotateLR(parent);
					// 整体是右边高，局部是左边高，会导致parent的bf=-2，cur的bf=-1
					else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
						RotateRL(parent);
					break; // 旋转完成后 高度不变了 不需要继续更新
				}
				else
					assert(false); // 走到这说明插入之前AVL就不平衡了
			}
			return true;
		}

		std::vector<std::vector<int>> levelOrder()
		{
			std::vector<std::vector<int>> vv;
			if (_root == nullptr)
				return vv;

			std::queue<Node *> q;
			int levelSize = 1;
			q.push(_root);

			while (!q.empty())
			{
				// levelSize控制一层一层出
				std::vector<int> levelV;
				while (levelSize--)
				{
					Node *front = q.front();
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
					std::cout << e << " ";
				}
				std::cout << std::endl;

				// 上一层出完，下一层就都进队列
				levelSize = q.size();
			}

			return vv;
		}

		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}
		bool IsBalanceTree() { return _IsBalanceTree(_root); }
		int Height() { return _Height(_root); }
		size_t size()
		{
			// 求节点数量
			return _size(_root);
		}

		Node *find(const K &key)
		{
			Node *cur = _root;
			while (cur)
			{
				if (cur->_kv.first > key)
					cur = cur->_left;
				else if (cur->_kv.first < key)
					cur = cur->_right;
				else
					return cur;
			}
			// 没找到返回空
			return nullptr;
		}

	private:
		size_t _size(Node *root)
		{
			if (root == nullptr)
				return 0;
			return _size(root->_left) + _size(root->_right) + 1;
		}

		void RotateRL(Node *parent)
		{
			Node *subR = parent->_right;
			Node *subRL = subR->_left;
			int bf = subRL->_bf;
			// 根是30，根的右是90，90的左是60 以90为旋转点进行右旋
			RotateR(parent->_right);
			// 再以30为旋转点进行左旋
			RotateL(parent);
			// 双旋完之后更新bf 根据60的平衡因子区分情况
			// 如果60自己就是新增的节点，那么60的bf=0，如果在60的左子树新增节点，60的bf=-1
			// 如果在60的右子树新增节点，60的bf=1
			if (bf == 0) // h == 0 的情况 60自己就是新增的节点
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = 0;
			else if (bf == -1) // h >= 1 的一种情况，新增节点在subRL的左边
				subRL->_bf = 0, subR->_bf = 1, parent->_bf = 0;
			else if (bf == 1) // h >= 1 的一种情况，新增节点在subRL的右边
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = -1;
			else
				assert(false); // 走到这说明旋转前就不是平衡树
		}

		void RotateLR(Node *parent)
		{
			Node *subL = parent->_left;
			Node *subLR = subL->_right;
			int bf = subLR->_bf;
			// 先以subL为旋转点
			RotateL(parent->_left);
			// 再以parent为旋转点
			RotateR(parent);
			if (bf == 0) // h == 0
				subLR->_bf = 0, subL->_bf = 0, parent->_bf = 0;
			else if (bf == 1) // 在subLR的右子树新增节点
				subLR->_bf = 0, subL->_bf = -1, parent->_bf = 0;
			else if (bf == -1) // 在subLR的左子树新增节点
				subLR->_bf = 0, subL->_bf = 0, parent->_bf = 1;
			else
				assert(false);
		}

		void RotateR(Node *parent)
		{
			// 提前定义parent的parent
			Node *ppNode = parent->_parent;
			Node *subL = parent->_left;
			Node *subLR = subL->_right;

			// 处理subL
			parent->_parent = subL;
			subL->_right = parent;

			// 处理subLR
			parent->_left = subLR;
			if (subLR != nullptr) // subLR可能为空，需要判空
				subLR->_parent = parent;

			// 处理根节点 parent可能就是_root
			if (parent == _root)
				_root = subL, _root->_parent = nullptr;
			else
			{
				// parent可能是局部的一个节点 考虑parent相对于ppNode的左右
				if (parent == ppNode->_left)
					ppNode->_left = subL;
				else
					ppNode->_right = subL;
				subL->_parent = ppNode;
			}

			// 旋转完更新平衡因子
			parent->_bf = 0, subL->_bf = 0;
		}

		void RotateL(Node *parent)
		{
			// 需要提前记录parent的parent节点
			Node *ppNode = parent->_parent;
			Node *subR = parent->_right;
			Node *subRL = subR->_left;

			// 处理subR
			subR->_left = parent;
			parent->_parent = subR;

			// 处理subRL
			parent->_right = subRL;
			if (subRL != nullptr) // 30的右子树可能为空
				subRL->_parent = parent;

			// 处理根节点
			if (parent == _root) // parent可能为根节点 旋转完成后要更新root
				_root = subR, _root->_parent = nullptr;
			else // parent也可能只是局部的一个节点 需要链接到parent的parent
			{
				// 考虑清楚是子树的右还是左 要让ppNode链接上subR
				if (parent == ppNode->_left)
					ppNode->_left = subR;
				else
					ppNode->_right = subR;
				// 最后，subR也要指向parent
				subR->_parent = ppNode;
			}

			// 旋转完更新平衡因子
			parent->_bf = 0, subR->_bf = 0;
		}

		void _InOrder(Node *root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			std::cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		int _Height(Node *root)
		{
			if (root == nullptr)
				return 0;

			int lh = _Height(root->_left);
			int rh = _Height(root->_right);

			return lh > rh ? lh + 1 : rh + 1; // 左右子树高的+1
		}

		bool _IsBalanceTree(Node *root)
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
				std::cout << root->_kv.first << "节点平衡因子异常" << std::endl;
				return false;
			}

			if (diff != root->_bf)
			{
				std::cout << root->_kv.first << "节点平衡因子不符合实际" << std::endl;
				return false;
			}

			// root的左和右如果都是AVL树，则该树一定是AVL树
			return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
		}
	};

	void TestAVLTree1()
	{
		AVLTree<int, int> t;
		t.Insert(std::make_pair(1, 1));
		t.Insert(std::make_pair(2, 2));
		t.Insert(std::make_pair(3, 3));
		t.Insert(std::make_pair(3, 3));
	}

	void TestAVLTree2()
	{
		// int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		int a[] = {30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1};
		// int a[] = { 8,7,6,5,4,3,2,1 };
		AVLTree<int, int> t;
		for (auto e : a)
		{
			t.Insert(std::make_pair(e, e));
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
		std::vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			v.push_back(rand());
			// v.push_back(i);
		}

		AVLTree<int, int> t;
		for (auto e : v)
		{
			t.Insert(std::make_pair(e, e));
		}

		std::cout << "是否平衡?" << t.IsBalanceTree() << std::endl;
		std::cout << "高度:" << t.Height() << std::endl;
		// t.levelOrder();
	}
}
