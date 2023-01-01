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
			if (_root == nullptr) // 按照二叉搜索树规则插入
			{
				_root = new Node(kv);
				_root->_col = BLACK; // 空节点黑色
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
			cur->_col = RED; // 插入黑色一定会破坏规则4，而且规则4很难维护
			if (parent->_kv.first < kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;
			// 红黑树处理 ...
			while (parent != nullptr && parent->_col == RED) // 存在连续红色节点
			{
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left)
				{
					Node* uncle = grandFather->_right;

					if (uncle && uncle->_col == RED) // 情况一 存在且为红
					{
						parent->_col = uncle->_col = BLACK; // 变色
						grandFather->_col = RED;
						cur = grandFather; // 继续向上处理
						parent = cur->_parent;
					}
					else // uncle 不存在或者 存在且为黑  旋转处理
					{
						if (cur == parent->_left) // 单旋
						{
							//     g
							//   p
							// c
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // 双旋
						{
							//     g
							//   p
							//     c
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // 旋转完成不需要再处理了
					}
				}
				else // parent == grandFather->_right
				{
					Node* uncle = grandFather->_left;

					if (uncle && uncle->_col == RED) // 情况一 存在且为红
					{
						parent->_col = uncle->_col = BLACK; // 变色
						grandFather->_col = RED;
						cur = grandFather; // 继续向上处理
						parent = cur->_parent;
					}
					else // uncle 不存在或者 存在且为黑  旋转处理
					{
						if (cur == parent->_right) // 单旋
						{
							// g
							//   p
							//     c
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // 双旋
						{
							// g
							//   p
							// c
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // 旋转完成不需要再处理了
					}
				}
			}
			_root->_col = BLACK; // 最后要确保根节点为黑色
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
				vector<int> levelV; // levelSize控制一层一层出
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
			// 走到null之后，判断k和black是否相等
			if (nullptr == pRoot)
			{
				if (k != blackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
				return true;
			}

			// 统计黑色节点的个数
			if (BLACK == pRoot->_col)
				++k;

			// 检测当前节点与其双亲是否都为红色
			if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
			{
				cout << "违反性质三：存在连在一起的红色节点" << endl;
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
			cout << "最长路径:" << _maxHeight(_root) << endl;
			cout << "最短路径:" << _minHeight(_root) << endl;
		}
		bool IsValidRBTree() // 检查当前红黑树是否满足红黑树的几条规则
		{
			// 空树也是红黑树
			if (nullptr == _root)
				return true;

			// 检测根节点是否满足情况
			if (BLACK != _root->_col)
			{
				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}

			// 获取任意一条路径中黑色节点的个数 -- 作为比较的基准值
			size_t blackCount = 0;
			Node* pCur = _root;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;

				pCur = pCur->_left; // 取最左路径黑色节点个数作为基准值
			}

			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
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
		cout << "是否平衡?" << t.IsValidRBTree() << endl;
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

		Ref operator*(){ return _node->_data; } // 对应set就是key 对应map就是pair
		Ptr operator->(){ return &_node->_data; }
		Self& operator++(){ // 左根右
			if (_node->_right == nullptr){ // 找孩子是祖先的左的祖先节点

				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_right == cur) { // 如果是右就继续向上
					cur = cur->_parent, parent = parent->_parent;
				}
				_node = parent;
			}
			else { // 非空去找右子树最左节点
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
		Self& operator--() { // 右根左 倒着走
			if (_node->_left == nullptr) { // 找孩子是祖先的右的祖先节点
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_left) {
					cur = cur->_parent, parent = parent->_parent;
				}
				_node = parent;
			}
			else { // _node->_left != nullptr
				Node* subRight = _node->_left; // 最右节点
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
	// KeyOfT 支持取出T对象中key的仿函数
	template<class K, class T, class KeyOfT> // T决定红黑树存什么类型数据
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
			return iterator(subLeft); // RBTree的迭代器用节点指针就可以构造
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
			if (_root == nullptr) // 按照二叉搜索树规则插入
			{
				_root = new Node(data);
				_root->_col = BLACK; // 空节点黑色
				return make_pair(iterator(_root), true);
			}
			KeyOfT kot;
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) < kot(data)) // 取value出来比较
					parent = cur, cur = cur->_right;
				else if (kot(cur->_data) > kot(data))
					parent = cur, cur = cur->_left;
				else
					return make_pair(iterator(cur), true);
			}

			cur = new Node(data);
			Node* newNode = cur; // 保存好新插入的节点
			cur->_col = RED; // 插入黑色一定会破坏规则4，而且规则4很难维护
			if (kot(parent->_data) < kot(data))
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;
			// 红黑树处理 ...
			while (parent != nullptr && parent->_col == RED) // 存在连续红色节点
			{
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left)
				{
					Node* uncle = grandFather->_right;

					if (uncle && uncle->_col == RED) // 情况一 存在且为红
					{
						parent->_col = uncle->_col = BLACK; // 变色
						grandFather->_col = RED;
						cur = grandFather; // 继续向上处理
						parent = cur->_parent;
					}
					else // uncle 不存在或者 存在且为黑  旋转处理
					{
						if (cur == parent->_left) // 单旋
						{
							//     g
							//   p
							// c
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // 双旋
						{
							//     g
							//   p
							//     c
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // 旋转完成不需要再处理了
					}
				}
				else // parent == grandFather->_right
				{
					Node* uncle = grandFather->_left;

					if (uncle && uncle->_col == RED) // 情况一 存在且为红
					{
						parent->_col = uncle->_col = BLACK; // 变色
						grandFather->_col = RED;
						cur = grandFather; // 继续向上处理
						parent = cur->_parent;
					}
					else // uncle 不存在或者 存在且为黑  旋转处理
					{
						if (cur == parent->_right) // 单旋
						{
							// g
							//   p
							//     c
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else // 双旋
						{
							// g
							//   p
							// c
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break; // 旋转完成不需要再处理了
					}
				}
			}
			_root->_col = BLACK; // 最后要确保根节点为黑色
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
					return iterator(cur); // 相等时找到了
			}
			return End(); // 找不到
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
			// 走到null之后，判断k和black是否相等
			if (nullptr == pRoot)
			{
				if (k != blackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
				return true;
			}

			// 统计黑色节点的个数
			if (BLACK == pRoot->_col)
				++k;

			// 检测当前节点与其双亲是否都为红色
			if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
			{
				cout << "违反性质三：存在连在一起的红色节点" << endl;
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
			cout << "最长路径:" << _maxHeight(_root) << endl;
			cout << "最短路径:" << _minHeight(_root) << endl;
		}
		bool IsValidRBTree() // 检查当前红黑树是否满足红黑树的几条规则
		{
			// 空树也是红黑树
			if (nullptr == _root)
				return true;

			// 检测根节点是否满足情况
			if (BLACK != _root->_col)
			{
				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}

			// 获取任意一条路径中黑色节点的个数 -- 作为比较的基准值
			size_t blackCount = 0;
			Node* pCur = _root;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;

				pCur = pCur->_left; // 取最左路径黑色节点个数作为基准值
			}

			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
			size_t k = 0;
			return _IsValidRBTree(_root, k, blackCount);
		}
	};
}