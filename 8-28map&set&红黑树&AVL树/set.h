#pragma once
#include "RedBlueTree.h"
namespace yzq {
	template<class K>
	class set {
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		};
	public:
		// 取的是类模板里面的内嵌类型，里面可以带有某些没被实例化的参数
		// 需要用typename 声明这些是类型，等实例化了再去对应的类模板里面取值。
		typedef typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const { // 这里begin的iterator是const迭代器，
			// 如果不加const，那么调用的是普通版本Begin，返回的又是普通迭代器，
			// const迭代器转化成普通迭代器，编不过，因此得加const，const修饰的this指针，这样就会去调用const版本Begin
			// 而且普通对象也是可以调用const修饰过的begin
			return _t.Begin();
		}
		iterator end() const {
			return _t.End();
		}
		pair<iterator, bool> insert(const K& key) {
			pair<typename RBTree_for_map_set::RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
			// auto ret = _t.Insert(key);
			return pair<iterator, bool>(iterator(ret.first._node), ret.second); 
			// node 是__RBTreeIterator 中的对象
		}
		iterator find(const K& key) {
			return _t.Find(key);
		}
	private:
		RBTree_for_map_set::RBTree<K, K, SetKeyOfT> _t;
	};
	void test_set1() {
		set<int> s;
		s.insert(8);
		s.insert(6);
		s.insert(11);
		s.insert(5);
		s.insert(6);
		s.insert(7);
		s.insert(10);
		s.insert(13);
		s.insert(12);
		s.insert(15);
		
		set<int>::iterator it = s.begin();
		while (it != s.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : s) {
			cout << e << " ";
		}
		cout << endl;
	}
}