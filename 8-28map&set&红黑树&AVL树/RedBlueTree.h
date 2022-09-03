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
namespace yzq_rbTree
{
	enum Colour
	{
		RED,
		BLACK,
	};

	template<class K, class V>
	struct RBTreeNode
	{
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;

		Colour _col;

		RBTreeNode(const pair<K, V>& kv)
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(RED)
		{}
	};

	template<class K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr) // ���ն����������������
			{
				_root = new Node(kv);
				_root->_col = BLACK; // �սڵ��ɫ
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
					parent = cur, cur = cur->_right;
				else if (cur->_kv.first > kv.first)
					parent = cur, cur = cur->_left;
				else
					return false;
			}

			cur = new Node(kv);
			cur->_col = RED; // �����ɫһ�����ƻ�����4�����ҹ���4����ά��
			if (parent->_kv.first < kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;
			// ��������� ...
			while (parent != nullptr && parent->_col == RED) // ����������ɫ�ڵ�
			{
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left)
				{
					Node* uncle = grandFather->_right;

					if (uncle && uncle->_col == RED) // ���һ ������Ϊ��
					{
						parent->_col = uncle->_col = BLACK; // ��ɫ
						grandFather->_col = RED;
						cur = grandFather; // �������ϴ���
						parent = cur->_parent;
					}
					else // uncle �����ڻ��� ������Ϊ��  ��ת����
					{
						if (cur == parent->_left) // ����
						{
							//     g
							//   p
							// c
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // ˫��
						{
							//     g
							//   p
							//     c
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // ��ת��ɲ���Ҫ�ٴ�����
					}
				}
				else // parent == grandFather->_right
				{
					Node* uncle = grandFather->_left;

					if (uncle && uncle->_col == RED) // ���һ ������Ϊ��
					{
						parent->_col = uncle->_col = BLACK; // ��ɫ
						grandFather->_col = RED;
						cur = grandFather; // �������ϴ���
						parent = cur->_parent;
					}
					else // uncle �����ڻ��� ������Ϊ��  ��ת����
					{
						if (cur == parent->_right) // ����
						{
							// g
							//   p
							//     c
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // ˫��
						{
							// g
							//   p
							// c
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // ��ת��ɲ���Ҫ�ٴ�����
					}
				}
			}
			_root->_col = BLACK; // ���Ҫȷ�����ڵ�Ϊ��ɫ
			return true;
		}

		vector<vector<int>> levelOrder()
		{
			vector<vector<int>> vv;
			if (_root == nullptr)
				return vv;
			queue<Node*> q;
			int levelSize = 1;
			q.push(_root);
			while (!q.empty())
			{
				vector<int> levelV; // levelSize����һ��һ���
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
					cout << e << " ";
				cout << endl;
				levelSize = q.size();
			}
			return vv;
		}

	private:
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
		}

		int _maxHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int lh = _maxHeight(root->_left);
			int rh = _maxHeight(root->_right);
			return lh > rh ? lh + 1 : rh + 1;
		}

		int _minHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int lh = _minHeight(root->_left);
			int rh = _minHeight(root->_right);
			return lh < rh ? lh + 1 : rh + 1;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
		{
			// �ߵ�null֮���ж�k��black�Ƿ����
			if (nullptr == pRoot)
			{
				if (k != blackCount)
				{
					cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
					return false;
				}
				return true;
			}

			// ͳ�ƺ�ɫ�ڵ�ĸ���
			if (BLACK == pRoot->_col)
				++k;

			// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
			if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
			{
				cout << "Υ������������������һ��ĺ�ɫ�ڵ�" << endl;
				return false;
			}

			return _IsValidRBTree(pRoot->_left, k, blackCount) &&
				_IsValidRBTree(pRoot->_right, k, blackCount);
		}

		Node* _root = nullptr;

	public:
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		void Height()
		{
			cout << "�·��:" << _maxHeight(_root) << endl;
			cout << "���·��:" << _minHeight(_root) << endl;
		}
		bool IsValidRBTree() // ��鵱ǰ������Ƿ����������ļ�������
		{
			// ����Ҳ�Ǻ����
			if (nullptr == _root)
				return true;

			// �����ڵ��Ƿ��������
			if (BLACK != _root->_col)
			{
				cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
				return false;
			}

			// ��ȡ����һ��·���к�ɫ�ڵ�ĸ��� -- ��Ϊ�ȽϵĻ�׼ֵ
			size_t blackCount = 0;
			Node* pCur = _root;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;

				pCur = pCur->_left; // ȡ����·����ɫ�ڵ������Ϊ��׼ֵ
			}

			// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
			size_t k = 0;
			return _IsValidRBTree(_root, k, blackCount);
		}

	};

	void TestRBTree1()
	{
		//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		int a[] = { 30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1 };
		RBTree<int, int> t;
		for (auto e : a)
		{
			t.Insert(make_pair(e, e));
		}
		t.levelOrder();
		t.InOrder();
		t.Height();
	}

	void TestRBTree2()
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

		RBTree<int, int> t;
		for (auto e : v)
		{
			t.Insert(make_pair(e, e));
		}

		//t.levelOrder();
		//cout << endl;
		cout << "�Ƿ�ƽ��?" << t.IsValidRBTree() << endl;
		t.Height();

		//t.InOrder();
	}
}

namespace RBTree_for_map_set
{
	enum Colour
	{
		RED,
		BLACK,
	};

	template<class T>
	struct RBTreeNode{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;

		Colour _col;

		RBTreeNode(const T& data)
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(RED)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef __RBTreeIterator<T, Ref, Ptr> Self;
		Node* _node;

		__RBTreeIterator(Node* node)
			:_node(node)
		{}

		Ref operator*(){ return _node->_data; } // ��Ӧset����key ��Ӧmap����pair
		Ptr operator->(){ return &_node->_data; }
		Self& operator++(){ // �����
			if (_node->_right == nullptr){ // �Һ��������ȵ�������Ƚڵ�

				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_right == cur) { // ������Ҿͼ�������
					cur = cur->_parent, parent = parent->_parent;
				}
				_node = parent;
			}
			else { // �ǿ�ȥ������������ڵ�
				Node* subLeft = _node->_right;
				while (subLeft->_left)
					subLeft = subLeft->_left;
				_node = subLeft;
			}
			return *this;
		}
		Self operator++(int) {
			Self tmp(*this);
			++(*this);
			return tmp;
		}
		Self& operator--() { // �Ҹ��� ������
			if (_node->_left == nullptr) { // �Һ��������ȵ��ҵ����Ƚڵ�
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_left) {
					cur = cur->_parent, parent = parent->_parent;
				}
				_node = parent;
			}
			else { // _node->_left != nullptr
				Node* subRight = _node->_left; // ���ҽڵ�
				while (subRight->_right)
					subRight = subRight->_right;
				_node = subRight;
			}
			return *this;
		}
		Self operator--(int) {
			Self tmp(*this);
			--(*this);
			return tmp;
		}
		bool operator==(const Self& s) const {
			return _node == s._node;
		}
		bool operator!=(const Self& s) const {
			return _node != s._node;
		}
	};

	// set RBTree<K, K>
	// map RBTree<K, pair<K, V>>
	// KeyOfT ֧��ȡ��T������key�ķº���
	template<class K, class T, class KeyOfT> // T�����������ʲô��������
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

		iterator Begin() {
			Node* subLeft = _root;
			while (subLeft && subLeft->_left)
				subLeft = subLeft->_left;
			return iterator(subLeft); // RBTree�ĵ������ýڵ�ָ��Ϳ��Թ���
		}
		iterator End() {
			return iterator(nullptr);
		}
		const_iterator Begin() const {
			Node* subLeft = _root;
			while (subLeft && subLeft->_left)
				subLeft = subLeft->_left;
			return const_iterator(subLeft);
		}
		const_iterator End() const {
			return const_iterator(nullptr);
		}

		pair<iterator, bool> Insert(const T& data){
			if (_root == nullptr) // ���ն����������������
			{
				_root = new Node(data);
				_root->_col = BLACK; // �սڵ��ɫ
				return make_pair(iterator(_root), true);
			}
			KeyOfT kot;
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) < kot(data)) // ȡvalue�����Ƚ�
					parent = cur, cur = cur->_right;
				else if (kot(cur->_data) > kot(data))
					parent = cur, cur = cur->_left;
				else
					return make_pair(iterator(cur), true);
			}

			cur = new Node(data);
			Node* newNode = cur; // ������²���Ľڵ�
			cur->_col = RED; // �����ɫһ�����ƻ�����4�����ҹ���4����ά��
			if (kot(parent->_data) < kot(data))
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;
			// ��������� ...
			while (parent != nullptr && parent->_col == RED) // ����������ɫ�ڵ�
			{
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left)
				{
					Node* uncle = grandFather->_right;

					if (uncle && uncle->_col == RED) // ���һ ������Ϊ��
					{
						parent->_col = uncle->_col = BLACK; // ��ɫ
						grandFather->_col = RED;
						cur = grandFather; // �������ϴ���
						parent = cur->_parent;
					}
					else // uncle �����ڻ��� ������Ϊ��  ��ת����
					{
						if (cur == parent->_left) // ����
						{
							//     g
							//   p
							// c
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // ˫��
						{
							//     g
							//   p
							//     c
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // ��ת��ɲ���Ҫ�ٴ�����
					}
				}
				else // parent == grandFather->_right
				{
					Node* uncle = grandFather->_left;

					if (uncle && uncle->_col == RED) // ���һ ������Ϊ��
					{
						parent->_col = uncle->_col = BLACK; // ��ɫ
						grandFather->_col = RED;
						cur = grandFather; // �������ϴ���
						parent = cur->_parent;
					}
					else // uncle �����ڻ��� ������Ϊ��  ��ת����
					{
						if (cur == parent->_right) // ����
						{
							// g
							//   p
							//     c
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // ˫��
						{
							// g
							//   p
							// c
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // ��ת��ɲ���Ҫ�ٴ�����
					}
				}
			}
			_root->_col = BLACK; // ���Ҫȷ�����ڵ�Ϊ��ɫ
			return make_pair(iterator(newNode), true);
		}

		iterator Find(const K& key) {
			Node* cur = _root;
			KeyOfT kot;
			while (cur) {
				if (kot(cur->_data) < key)
					cur = cur->_right;
				else if (kot(cur->_data) > key)
					cur = cur->_left;
				else
					return iterator(cur); // ���ʱ�ҵ���
			}
			return End(); // �Ҳ���
		}
	private:
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
		}

		int _maxHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int lh = _maxHeight(root->_left);
			int rh = _maxHeight(root->_right);
			return lh > rh ? lh + 1 : rh + 1;
		}

		int _minHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int lh = _minHeight(root->_left);
			int rh = _minHeight(root->_right);
			return lh < rh ? lh + 1 : rh + 1;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
		{
			// �ߵ�null֮���ж�k��black�Ƿ����
			if (nullptr == pRoot)
			{
				if (k != blackCount)
				{
					cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
					return false;
				}
				return true;
			}

			// ͳ�ƺ�ɫ�ڵ�ĸ���
			if (BLACK == pRoot->_col)
				++k;

			// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
			if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
			{
				cout << "Υ������������������һ��ĺ�ɫ�ڵ�" << endl;
				return false;
			}

			return _IsValidRBTree(pRoot->_left, k, blackCount) &&
				_IsValidRBTree(pRoot->_right, k, blackCount);
		}

		Node* _root = nullptr;

	public:
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		void Height()
		{
			cout << "�·��:" << _maxHeight(_root) << endl;
			cout << "���·��:" << _minHeight(_root) << endl;
		}
		bool IsValidRBTree() // ��鵱ǰ������Ƿ����������ļ�������
		{
			// ����Ҳ�Ǻ����
			if (nullptr == _root)
				return true;

			// �����ڵ��Ƿ��������
			if (BLACK != _root->_col)
			{
				cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
				return false;
			}

			// ��ȡ����һ��·���к�ɫ�ڵ�ĸ��� -- ��Ϊ�ȽϵĻ�׼ֵ
			size_t blackCount = 0;
			Node* pCur = _root;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;

				pCur = pCur->_left; // ȡ����·����ɫ�ڵ������Ϊ��׼ֵ
			}

			// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
			size_t k = 0;
			return _IsValidRBTree(_root, k, blackCount);
		}
	};
}