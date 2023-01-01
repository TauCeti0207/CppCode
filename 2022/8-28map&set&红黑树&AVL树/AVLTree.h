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

		// AVL��û�й涨�������balance factor
		int _bf; // balance factor ���������߶Ȳ� ��-��
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
			// �����������Ĺ�����룬������balance factor�жϲ�����ƽ������
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_bf = 0;
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) // �ҵ��ڵ�Ҫ�����λ��
			{
				if (cur->_kv.first < kv.first)
					parent = cur, cur = cur->_right;
				else if (cur->_kv.first > kv.first)
					parent = cur, cur = cur->_left;
				else
					return false; // ������
			}
			cur = new Node(kv); // ׼�����ӽڵ�
			if (parent->_kv.first < kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent; // ע����������

			// ����balance factor
			while (parent != nullptr) // ��Զ���µ����ڵ�
			{
				if (cur == parent->_right) // parent�� bf�������
					parent->_bf++;
				else
					parent->_bf--;
				// ���ж��Ƿ�Ҫ�����������ȵ�bf
				if (parent->_bf == 0) // 1 or -1 --> 0 ˵������Ľڵ������˰����Ǳ�
					break; // �߶Ȳ��䣬���½���
				else if (parent->_bf == 1 || parent->_bf == -1) // 0 --> 1 or -1 ����ڵ㵼��һ�߱����
					cur = cur->_parent, parent = parent->_parent; // �����߶ȱ��� ������������
				else if (parent->_bf == 2 || parent->_bf == -2) // 1 or -1 --> 2 or -2 ����ڵ㵼�±����ߵ��Ǳ߸�����
				{
					// ������ƽ���ˣ���Ҫ��ת
					if (parent->_bf == 2 && cur->_bf == 1) // �ұ߸� ���� ˵��cur��parent��
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1) // ��߸� �ҵ���
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1) // ����˫��
						RotateLR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1) // ����˫��
						RotateRL(parent);
					break; // ��ת��ɺ� �߶Ȳ����� ����Ҫ��������
				}
				else
					assert(false); // �ߵ���˵������֮ǰAVL�Ͳ�ƽ����
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
				// levelSize����һ��һ���
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

				// ��һ����꣬��һ��Ͷ�������
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
			// ˫����֮�����bf
			if (bf == 0) // h == 0 �����
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = 0;
			else if (bf == -1) // h >= 1 ��һ������������ڵ���subRL�����
				subRL->_bf = 0, subR->_bf = 1, parent->_bf = 0;
			else if (bf == 1) // h >= 1 ��һ������������ڵ���subRL���ұ�
				subRL->_bf = 0, subR->_bf = 0, parent->_bf = -1;
			else
				assert(false); // �ߵ���˵����תǰ�Ͳ���ƽ����
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
			else if (bf == 1) // ��subRL���������ڵ�
				subLR->_bf = 0, subL->_bf = -1, parent->_bf = 0;
			else if (bf == -1) // ��subRL���������ڵ�
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
			if (parent == _root) // parent����Ϊ���ڵ� ��ת�����root
				_root = subL, _root->_parent = nullptr;
			else
			{
				if (parent == ppNode->_left)
					ppNode->_left = subL;
				else
					ppNode->_right = subL;
				subL->_parent = ppNode;
			}
			parent->_bf = 0, subL->_bf = 0; // ��ת�����ƽ������
		}

		void RotateL(Node* parent)
		{
			Node* ppNode = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			parent->_parent = subR;
			if (subRL != nullptr) // 30������������Ϊ��
				subRL->_parent = parent;
			subR->_left = parent;
			if (parent == _root) // parent����Ϊ���ڵ� ��ת��ɺ�Ҫ����root
				_root = subR, _root->_parent = nullptr;
			else // ����������������һ����� Ҫ����ppNode �� subR
			{
				if (parent == ppNode->_left)
					ppNode->_left = subR;
				else
					ppNode->_right = subR;
				subR->_parent = ppNode;
			}

			parent->_bf = 0, subR->_bf = 0; // ��ת�����ƽ������
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

			return lh > rh ? lh + 1 : rh + 1; // ���������ߵ�+1
		}

		bool _IsBalanceTree(Node* root)
		{
			// ����Ҳ��AVL��
			if (nullptr == root)
				return true;
			// ����root �ڵ��ƽ������
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int diff = rightHeight - leftHeight;

			// ����������ƽ��������root��ƽ�����Ӳ���ȣ�����
			// root ƽ�����ӵľ���ֵ����1����һ������AVL��
			if (abs(diff) >= 2)
			{
				cout << root->_kv.first << "�ڵ�ƽ�������쳣" << endl;
				return false;
			}

			if (diff != root->_bf)
			{
				cout << root->_kv.first << "�ڵ�ƽ�����Ӳ�����ʵ��" << endl;
				return false;
			}

			// root��������������AVL���������һ����AVL��
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
		// ��Ϊ����
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

		cout << "�Ƿ�ƽ��?" << t.IsBalanceTree() << endl;
		cout << "�߶�:" << t.Height() << endl;
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
		int _bf;   // �ڵ��ƽ������
	};


	// AVL: ���������� + ƽ�����ӵ�����
	template<class T>
	class AVLTree
	{
		typedef AVLTreeNode<T> Node;
	public:
		AVLTree()
			: _pRoot(nullptr)
		{}

		// ��AVL���в���ֵΪdata�Ľڵ�
		bool Insert(const T& data)
		{
			// �����������������
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_bf = 0;
				return true;
			}
			// �ҵ�Ҫ�����λ��
			Node* parent = nullptr;
			Node* cur = _pRoot;
			while (cur)
			{
				if (cur->_data < data)
					parent = cur, cur = cur->_pRight;
				else if (cur->_data > data)
					parent = cur, cur = cur->_pLeft;
				else
					return false; // ����
			}
			cur = new Node(data); // ��������
			if (parent->_data < data)
				parent->_pRight = cur;
			else
				parent->_pLeft = cur;
			cur->_pParent = parent; // ע�⣡����
			while (parent != nullptr) // ����bf
			{
				if (cur == parent->_pRight)
					parent->_bf++;
				else
					parent->_bf--;
				if (parent->_bf == 0) // �߶Ȳ����������
					break;
				else if (parent->_bf == 1 || parent->_bf == -1)
					parent = parent->_pParent, cur = cur->_pParent;
				else if (parent->_bf == 2 || parent->_bf == -2) // ��ƽ���� ��ת����
				{
					if (parent->_bf == 2 && cur->_bf == 1)
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1)
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1)
						RotateLR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1)
						RotateRL(parent);
					break; // ��ת��� ����Ҫ����������
				}
				else
					assert(false);
			}
		}

		// AVL������֤
		bool IsAVLTree()
		{
			return _IsAVLTree(_pRoot);
		}
		size_t Height()
		{
			return _Height(_pRoot);
		}

	private:
		// ����AVL���ĸ�����֤pRoot�Ƿ�Ϊ��Ч��AVL��
		bool _IsAVLTree(Node* pRoot)
		{
			if (pRoot == nullptr)
				return true;
			int leftHeight = _Height(pRoot->_pLeft);
			int rightHeight = _Height(pRoot->_pRight);
			int diff = rightHeight - leftHeight;
			if (abs(diff) >= 2)
			{
				cout << pRoot->_data << "�ڵ�ƽ�������쳣" << endl;
				return false;
			}
			if (diff != pRoot->_bf)
			{
				cout << pRoot->_data << "�ڵ�ƽ�����Ӳ�����ʵ��" << endl;
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
		// �ҵ���
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
			else // ���Ǹ��ڵ� ����ppNode
			{
				subL->_pParent = ppNode;
				if (pParent == ppNode->_pLeft)
					ppNode->_pLeft = subL;
				else
					ppNode->_pRight = subL;
			}
			pParent->_bf = 0, subL->_bf = 0;
		}
		// ����
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
		// ����˫��
		void RotateRL(Node* pParent)
		{
			Node* subR = pParent->_pRight;
			Node* subRL = subR->_pLeft;
			int bf = subRL->_bf;
			RotateR(pParent->_pRight);
			RotateL(pParent);
			// ����bf
			if (bf == 0)
				pParent->_bf = 0, subR->_bf = 0, subRL->_bf = 0;
			else if (bf == -1)
				pParent->_bf = 0, subR->_bf = 1, subRL->_bf = 0;
			else if (bf == 1)
				pParent->_bf = -1, subR->_bf = 0, subRL->_bf = 0;
			else
				assert(false);
		}
		// ����˫��
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

		cout << "�Ƿ�ƽ��?" << t.IsAVLTree() << endl;
		cout << "�߶ȣ�" << t.Height() << endl;
	}
}