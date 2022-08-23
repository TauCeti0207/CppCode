#pragma once
#include <algorithm>
#include <string>
namespace BST
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
	private:
		typedef BSTreeNode<K> Node;
		Node* _root = nullptr;

		void DestroyTree(Node* root)
		{
			if (root == nullptr)
				return;
			DestroyTree(root->_left);
			DestroyTree(root->_right);
			delete root;
		}

		Node* CopyTree(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* copyNode = new Node(root->_key);
			// 递归拷贝左右子树
			copyNode->_left = CopyTree(root->_left);
			copyNode->_right = CopyTree(root->_right);

			return copyNode;
		}
	public:
		~BSTree()
		{
			DestroyTree(_root);
			_root = nullptr;
		}

		// 强制编译器自己生成默认构造 C++11才支持
		// 因为我们自己写了拷贝构造，编译器就不会再生成默认构造，而我们写的又不是默认构造
		// 因此必须有一个默认构造才能完成编译
		BSTree() = default;

		// 拷贝构造
		BSTree(const BSTree<K>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2  现代写法
		BSTree<K>& operator=(BSTree<K> t)
		{
			// t是t2的拷贝 t1赋值给*this
			swap(_root, t._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 不允许冗余
					return false;
				}
			}

			// 链接起来
			cur = new Node(key);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		// 封装一层，以便外面也能使用
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return true; // 找到了
			}
			return false; // 找不到
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			// 先看看有无要找的节点
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 找到了 key相等
					// 3种情况
					// 1.左为空 叶子节点也满足这种情况
					if (cur->_left == nullptr)
					{
						//单独考虑根节点也只有一个孩子的情况
						if (cur == _root) // if(parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							// 还需要考虑parent的是左指向还是右指向
							// 也可以比大小来判断
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_right;
							}
						}

						// 删除cur节点
						delete cur;
					}

					// 2.右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}

					// 2个孩子 替换法
					else
					{
						// 用右子树的最小值节点替代

						// 如果右子树的第一个节点就是最小值节点，那么就是minRight的左为空 循环都不进去
						// 后面就会产生空指针解引用的问题 因此minParent不能用nullptr初始化
						//Node* minParent = nullptr; // 删除8的情况
						Node* minParent = cur; // 找到minRight后，左一定为空，但可能还会有右孩子，因此不能直接delete minRight
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minParent = minRight;
							minRight = minRight->_left;
						}
						// 找到右子树最小值
						// 交换也可以
						// swap(cur->_key, minRight->_key);
						cur->_key = minRight->_key;
						// 需要考虑minParent的左指向还是右指向
						// 右子树的最小值节点是右子树根节点又是一个特殊情况 例如删除8
						if (minParent->_left == minRight)
						{
							minParent->_left = minRight->_right;
						}
						else if (minParent->_right == minRight)
						{
							minParent->_right = minRight->_right;
						}
						delete minRight;
					}

					// 成功删除节点
					return true;
				}
			}
			// 出来时cur 为空，说明找不到
			return false;
		}



		// 递归版本
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr) //找不到
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// 左为空
				if (root->_left == nullptr)
					root = root->_right; // 这恰巧也能解决 要删除的如果是根节点且根节点也只有一个孩子的问题
				// 右为空
				else if (root->_right == nullptr)
					root = root->_left;
				// 有2个孩子
				else
				{
					// 替换法 右子树最小值节点
					// 引用不能改变指向，因此不能给minRight 加引用解决问题
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// 引用不起作用了，怎么删除呢 再加个parent？ 太麻烦了
					// 换下来的值肯定是右子树中最小的，因此直接去右子树中删就行了
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // 成功删除
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				// root是父节点的左指针引用或右指针引用，能链接起来
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false; // 不允许冗余
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // 找不到
				return false;
			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return true;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	};

	void TestBSTree1()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder(); // 1 3 4 6 7 8 10 13 14

		t.Insert(16);
		t.Insert(9);
		t.InOrder(); // 1 3 4 6 7 8 9 10 13 14 16
	}

	void TestBSTree2()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder(); // 1 3 4 6 7 8 10 13 14
		t.Erase(3);
		t.Erase(8);

		t.InOrder(); // 1 3 4 6 7 10 13 14

		t.Erase(14);
		t.Erase(7);
		t.InOrder(); // 1 4 6 10 13

		for (auto e : a)
		{
			t.Erase(e);
		}
		t.InOrder(); // 空
	}

	void TestBSTree3()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder();

		BSTree<int> copy(t);
		copy.InOrder();

		BSTree<int> copy2 = copy;
		copy2.InOrder();
	}

	void TestBSTree4()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.InsertR(e);
		}
		t.InOrder();

		BSTree<int> copy(t);
		copy.InOrder();

		BSTree<int> copy2 = copy;
		copy2.InOrder();
	}

	void TestBSTree5()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder(); // 1 3 4 6 7 8 10 13 14
		t.EraseR(3);
		t.EraseR(8);

		t.InOrder(); // 1 3 4 6 7 10 13 14

		t.EraseR(14);
		t.EraseR(7);
		t.InOrder(); // 1 4 6 10 13

		for (auto e : a)
		{
			t.Erase(e);
		}
		t.InOrder(); // 空
	}
}

namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
	private:
		typedef BSTreeNode<K> Node;
		Node* _root = nullptr;

		void DestroyTree(Node* root)
		{
			if (root == nullptr)
				return;
			DestroyTree(root->_left);
			DestroyTree(root->_right);
			delete root;
		}

		Node* CopyTree(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* copyNode = new Node(root->_key);
			// 递归拷贝左右子树
			copyNode->_left = CopyTree(root->_left);
			copyNode->_right = CopyTree(root->_right);

			return copyNode;
		}
	public:
		~BSTree()
		{
			DestroyTree(_root);
			_root = nullptr;
		}

		// 强制编译器自己生成默认构造 C++11才支持
		// 因为我们自己写了拷贝构造，编译器就不会再生成默认构造，而我们写的又不是默认构造
		// 因此必须有一个默认构造才能完成编译
		BSTree() = default;

		// 拷贝构造
		BSTree(const BSTree<K>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2  现代写法
		BSTree<K>& operator=(BSTree<K> t)
		{
			// t是t2的拷贝 t1赋值给*this
			swap(_root, t._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 不允许冗余
					return false;
				}
			}

			// 链接起来
			cur = new Node(key);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		// 封装一层，以便外面也能使用
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return true; // 找到了
			}
			return false; // 找不到
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			// 先看看有无要找的节点
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 找到了 key相等
					// 3种情况
					// 1.左为空 叶子节点也满足这种情况
					if (cur->_left == nullptr)
					{
						//单独考虑根节点也只有一个孩子的情况
						if (cur == _root) // if(parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							// 还需要考虑parent的是左指向还是右指向
							// 也可以比大小来判断
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_right;
							}
						}

						// 删除cur节点
						delete cur;
					}

					// 2.右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}

					// 2个孩子 替换法
					else
					{
						// 用右子树的最小值节点替代

						// 如果右子树的第一个节点就是最小值节点，那么就是minRight的左为空 循环都不进去
						// 后面就会产生空指针解引用的问题 因此minParent不能用nullptr初始化
						//Node* minParent = nullptr; // 删除8的情况
						Node* minParent = cur; // 找到minRight后，左一定为空，但可能还会有右孩子，因此不能直接delete minRight
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minParent = minRight;
							minRight = minRight->_left;
						}
						// 找到右子树最小值
						// 交换也可以
						// swap(cur->_key, minRight->_key);
						cur->_key = minRight->_key;
						// 需要考虑minParent的左指向还是右指向
						// 右子树的最小值节点是右子树根节点又是一个特殊情况 例如删除8
						if (minParent->_left == minRight)
						{
							minParent->_left = minRight->_right;
						}
						else if (minParent->_right == minRight)
						{
							minParent->_right = minRight->_right;
						}
						delete minRight;
					}

					// 成功删除节点
					return true;
				}
			}
			// 出来时cur 为空，说明找不到
			return false;
		}



		// 递归版本
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr) //找不到
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// 左为空
				if (root->_left == nullptr)
					root = root->_right; // 这恰巧也能解决 要删除的如果是根节点且根节点也只有一个孩子的问题
				// 右为空
				else if (root->_right == nullptr)
					root = root->_left;
				// 有2个孩子
				else
				{
					// 替换法 右子树最小值节点
					// 引用不能改变指向，因此不能给minRight 加引用解决问题
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// 引用不起作用了，怎么删除呢 再加个parent？ 太麻烦了
					// 换下来的值肯定是右子树中最小的，因此直接去右子树中删就行了
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // 成功删除
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				// root是父节点的左指针引用或右指针引用，能链接起来
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false; // 不允许冗余
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // 找不到
				return false;
			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return true;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	};
}

namespace key_value
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;

		const K _key; // key 不能修改，value可以修改
		V _value;

		BSTreeNode(const K& key, const V& value)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
	private:
		typedef BSTreeNode<K, V> Node;
		Node* _root = nullptr;

	public:
		// 封装一层，以便外面也能使用
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		// 只保留递归版本
		// 只需通过查找key就能找到value，且要能修改
		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr) //找不到
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// 左为空
				if (root->_left == nullptr)
					root = root->_right; // 这恰巧也能解决 要删除的如果是根节点且根节点也只有一个孩子的问题
				// 右为空
				else if (root->_right == nullptr)
					root = root->_left;
				// 有2个孩子
				else
				{
					// 替换法 右子树最小值节点
					// 引用不能改变指向，因此不能给minRight 加引用解决问题
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// 引用不起作用了，怎么删除呢 再加个parent？ 太麻烦了
					// 换下来的值肯定是右子树中最小的，因此直接去右子树中删就行了
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // 成功删除
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				// root是父节点的左指针引用或右指针引用，能链接起来
				root = new Node(key, value);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key, value);
			else if (root->_key > key)
				return _InsertR(root->_left, key, value);
			else
				return false; // 不允许冗余
		}

		// 找到之后要能修改value
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // 找不到
				return nullptr;
			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return root;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << ": " << root->_value << endl;
			_InOrder(root->_right);
		}
	};

	// 中英文字典
	void TestBSTree1()
	{
		BSTree<string, string> EToCDict;
		EToCDict.InsertR("root", "根");
		EToCDict.InsertR("left", "左边");
		EToCDict.InsertR("right", "右边");
		EToCDict.InsertR("man", "男人");
		EToCDict.InsertR("vector", "容器");
		EToCDict.InsertR("string", "字符串");
		EToCDict.InsertR("file", "文件");
		EToCDict.InsertR("project", "项目");
		EToCDict.InsertR("debug", "调试");
		// 。。。
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = EToCDict.FindR(str);
			if (ret != nullptr)
			{
				cout << "对应的中文: " << ret->_value << endl;
				// 也可以修改value 但不能修改key
				ret->_value = "****";
			}
			else
			{
				cout << "无此单词，请重新输入：" << endl;
			}
		}
	}


	// 统计水果出现次数
	void TestBSTree2()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			BSTreeNode<string, int>* ret = countTree.FindR(str);
			if (ret == nullptr)
			{
				countTree.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		// 输出统计结果
		countTree.InOrder();
	}
}