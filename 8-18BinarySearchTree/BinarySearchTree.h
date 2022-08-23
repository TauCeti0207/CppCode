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
			// �ݹ鿽����������
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

		// ǿ�Ʊ������Լ�����Ĭ�Ϲ��� C++11��֧��
		// ��Ϊ�����Լ�д�˿������죬�������Ͳ���������Ĭ�Ϲ��죬������д���ֲ���Ĭ�Ϲ���
		// ��˱�����һ��Ĭ�Ϲ��������ɱ���
		BSTree() = default;

		// ��������
		BSTree(const BSTree<K>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2  �ִ�д��
		BSTree<K>& operator=(BSTree<K> t)
		{
			// t��t2�Ŀ��� t1��ֵ��*this
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
					// ����������
					return false;
				}
			}

			// ��������
			cur = new Node(key);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		// ��װһ�㣬�Ա�����Ҳ��ʹ��
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
					return true; // �ҵ���
			}
			return false; // �Ҳ���
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			// �ȿ�������Ҫ�ҵĽڵ�
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
					// �ҵ��� key���
					// 3�����
					// 1.��Ϊ�� Ҷ�ӽڵ�Ҳ�����������
					if (cur->_left == nullptr)
					{
						//�������Ǹ��ڵ�Ҳֻ��һ�����ӵ����
						if (cur == _root) // if(parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							// ����Ҫ����parent������ָ������ָ��
							// Ҳ���Աȴ�С���ж�
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_right;
							}
						}

						// ɾ��cur�ڵ�
						delete cur;
					}

					// 2.��Ϊ��
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

					// 2������ �滻��
					else
					{
						// ������������Сֵ�ڵ����

						// ����������ĵ�һ���ڵ������Сֵ�ڵ㣬��ô����minRight����Ϊ�� ѭ��������ȥ
						// ����ͻ������ָ������õ����� ���minParent������nullptr��ʼ��
						//Node* minParent = nullptr; // ɾ��8�����
						Node* minParent = cur; // �ҵ�minRight����һ��Ϊ�գ������ܻ������Һ��ӣ���˲���ֱ��delete minRight
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minParent = minRight;
							minRight = minRight->_left;
						}
						// �ҵ���������Сֵ
						// ����Ҳ����
						// swap(cur->_key, minRight->_key);
						cur->_key = minRight->_key;
						// ��Ҫ����minParent����ָ������ָ��
						// ����������Сֵ�ڵ������������ڵ�����һ��������� ����ɾ��8
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

					// �ɹ�ɾ���ڵ�
					return true;
				}
			}
			// ����ʱcur Ϊ�գ�˵���Ҳ���
			return false;
		}



		// �ݹ�汾
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
			if (root == nullptr) //�Ҳ���
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// ��Ϊ��
				if (root->_left == nullptr)
					root = root->_right; // ��ǡ��Ҳ�ܽ�� Ҫɾ��������Ǹ��ڵ��Ҹ��ڵ�Ҳֻ��һ�����ӵ�����
				// ��Ϊ��
				else if (root->_right == nullptr)
					root = root->_left;
				// ��2������
				else
				{
					// �滻�� ��������Сֵ�ڵ�
					// ���ò��ܸı�ָ����˲��ܸ�minRight �����ý������
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// ���ò��������ˣ���ôɾ���� �ټӸ�parent�� ̫�鷳��
					// ��������ֵ�϶�������������С�ģ����ֱ��ȥ��������ɾ������
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // �ɹ�ɾ��
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				// root�Ǹ��ڵ����ָ�����û���ָ�����ã�����������
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false; // ����������
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // �Ҳ���
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
		t.InOrder(); // ��
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
		t.InOrder(); // ��
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
			// �ݹ鿽����������
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

		// ǿ�Ʊ������Լ�����Ĭ�Ϲ��� C++11��֧��
		// ��Ϊ�����Լ�д�˿������죬�������Ͳ���������Ĭ�Ϲ��죬������д���ֲ���Ĭ�Ϲ���
		// ��˱�����һ��Ĭ�Ϲ��������ɱ���
		BSTree() = default;

		// ��������
		BSTree(const BSTree<K>& t)
		{
			_root = CopyTree(t._root);
		}

		// t1 = t2  �ִ�д��
		BSTree<K>& operator=(BSTree<K> t)
		{
			// t��t2�Ŀ��� t1��ֵ��*this
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
					// ����������
					return false;
				}
			}

			// ��������
			cur = new Node(key);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		// ��װһ�㣬�Ա�����Ҳ��ʹ��
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
					return true; // �ҵ���
			}
			return false; // �Ҳ���
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			// �ȿ�������Ҫ�ҵĽڵ�
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
					// �ҵ��� key���
					// 3�����
					// 1.��Ϊ�� Ҷ�ӽڵ�Ҳ�����������
					if (cur->_left == nullptr)
					{
						//�������Ǹ��ڵ�Ҳֻ��һ�����ӵ����
						if (cur == _root) // if(parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							// ����Ҫ����parent������ָ������ָ��
							// Ҳ���Աȴ�С���ж�
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else if (cur == parent->_right)
							{
								parent->_right = cur->_right;
							}
						}

						// ɾ��cur�ڵ�
						delete cur;
					}

					// 2.��Ϊ��
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

					// 2������ �滻��
					else
					{
						// ������������Сֵ�ڵ����

						// ����������ĵ�һ���ڵ������Сֵ�ڵ㣬��ô����minRight����Ϊ�� ѭ��������ȥ
						// ����ͻ������ָ������õ����� ���minParent������nullptr��ʼ��
						//Node* minParent = nullptr; // ɾ��8�����
						Node* minParent = cur; // �ҵ�minRight����һ��Ϊ�գ������ܻ������Һ��ӣ���˲���ֱ��delete minRight
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minParent = minRight;
							minRight = minRight->_left;
						}
						// �ҵ���������Сֵ
						// ����Ҳ����
						// swap(cur->_key, minRight->_key);
						cur->_key = minRight->_key;
						// ��Ҫ����minParent����ָ������ָ��
						// ����������Сֵ�ڵ������������ڵ�����һ��������� ����ɾ��8
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

					// �ɹ�ɾ���ڵ�
					return true;
				}
			}
			// ����ʱcur Ϊ�գ�˵���Ҳ���
			return false;
		}



		// �ݹ�汾
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
			if (root == nullptr) //�Ҳ���
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// ��Ϊ��
				if (root->_left == nullptr)
					root = root->_right; // ��ǡ��Ҳ�ܽ�� Ҫɾ��������Ǹ��ڵ��Ҹ��ڵ�Ҳֻ��һ�����ӵ�����
				// ��Ϊ��
				else if (root->_right == nullptr)
					root = root->_left;
				// ��2������
				else
				{
					// �滻�� ��������Сֵ�ڵ�
					// ���ò��ܸı�ָ����˲��ܸ�minRight �����ý������
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// ���ò��������ˣ���ôɾ���� �ټӸ�parent�� ̫�鷳��
					// ��������ֵ�϶�������������С�ģ����ֱ��ȥ��������ɾ������
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // �ɹ�ɾ��
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				// root�Ǹ��ڵ����ָ�����û���ָ�����ã�����������
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false; // ����������
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // �Ҳ���
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

		const K _key; // key �����޸ģ�value�����޸�
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
		// ��װһ�㣬�Ա�����Ҳ��ʹ��
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		// ֻ�����ݹ�汾
		// ֻ��ͨ������key�����ҵ�value����Ҫ���޸�
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
			if (root == nullptr) //�Ҳ���
				return false;
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;
				// ��Ϊ��
				if (root->_left == nullptr)
					root = root->_right; // ��ǡ��Ҳ�ܽ�� Ҫɾ��������Ǹ��ڵ��Ҹ��ڵ�Ҳֻ��һ�����ӵ�����
				// ��Ϊ��
				else if (root->_right == nullptr)
					root = root->_left;
				// ��2������
				else
				{
					// �滻�� ��������Сֵ�ڵ�
					// ���ò��ܸı�ָ����˲��ܸ�minRight �����ý������
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					// ���ò��������ˣ���ôɾ���� �ټӸ�parent�� ̫�鷳��
					// ��������ֵ�϶�������������С�ģ����ֱ��ȥ��������ɾ������
					return _EraseR(root->_right, key);
				}
				delete del;
				return true; // �ɹ�ɾ��
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				// root�Ǹ��ڵ����ָ�����û���ָ�����ã�����������
				root = new Node(key, value);
				return true;
			}
			if (root->_key < key)
				return _InsertR(root->_right, key, value);
			else if (root->_key > key)
				return _InsertR(root->_left, key, value);
			else
				return false; // ����������
		}

		// �ҵ�֮��Ҫ���޸�value
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr) // �Ҳ���
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

	// ��Ӣ���ֵ�
	void TestBSTree1()
	{
		BSTree<string, string> EToCDict;
		EToCDict.InsertR("root", "��");
		EToCDict.InsertR("left", "���");
		EToCDict.InsertR("right", "�ұ�");
		EToCDict.InsertR("man", "����");
		EToCDict.InsertR("vector", "����");
		EToCDict.InsertR("string", "�ַ���");
		EToCDict.InsertR("file", "�ļ�");
		EToCDict.InsertR("project", "��Ŀ");
		EToCDict.InsertR("debug", "����");
		// ������
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = EToCDict.FindR(str);
			if (ret != nullptr)
			{
				cout << "��Ӧ������: " << ret->_value << endl;
				// Ҳ�����޸�value �������޸�key
				ret->_value = "****";
			}
			else
			{
				cout << "�޴˵��ʣ����������룺" << endl;
			}
		}
	}


	// ͳ��ˮ�����ִ���
	void TestBSTree2()
	{
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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
		// ���ͳ�ƽ��
		countTree.InOrder();
	}
}