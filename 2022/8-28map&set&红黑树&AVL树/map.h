/*
 * @Descripttion: 
 * @Author: tauceti0207
 * @version: 
 * @Date: 2025-05-03 21:00:10
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-13 20:19:33
 */
#pragma once
#include "RedBlueTree.h"
namespace yzq {
	template<class K, class V>
	class map {
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		// 取的是类模板里面的内嵌类型，里面可以带有某些没被实例化的参数
		// 需要用typename 声明这些是类型，等实例化了再去对应的类模板里面取值。
		typedef typename RBTree_for_map_set::RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree_for_map_set::RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin() {
			return _t.Begin();
		}
		iterator end() {
			return _t.End();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}
		iterator find(const K& key) {
			return _t.Find(key);
		}
		V& operator[](const K& key) {
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree_for_map_set::RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};
	void test_map1() {
		map<string, int> m;
		m.insert(make_pair("111", 1));
		m.insert(make_pair("555", 5));
		m.insert(make_pair("333", 3));
		m.insert(make_pair("222", 2));
		m.insert(make_pair("999", 9));

		map<string, int>::iterator it = m.begin();
		while (it != m.end()) {
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
		for (auto kv : m) {
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	void test_map2()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		map<string, int> countMap;
		for (auto& str : arr)
			countMap[str]++;

		for (const auto& kv : countMap)
			cout << kv.first << ":" << kv.second << endl;
		//苹果:6
		//西瓜 : 3
		//香蕉 : 2
	}

	void test_map3()
	{
		map<string, string> dict;
		dict["insert"];
		dict["insert"] = "";
		dict["left"] = "";
	}
}