#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
public:
	
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		
		auto it = cache.find(key);
		if (it == cache.end())
			return -1;
		lis.splice(lis.begin(), lis, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end())//�ظ�key����
			lis.erase(it->second);
		lis.push_front(make_pair(key, value));
		cache[key] = lis.begin();
		if (cache.size() > size) 
		{
			int k = lis.rbegin()->first;
			lis.pop_back();
			cache.erase(k);
		}

	}
private:
	int size = 0;
	list<pair<int, int>> lis;
	unordered_map<int, list<pair<int,int>>::iterator> cache;
};
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		auto it = m.find(key);
//		if (it == m.end()) return -1;
//		l.splice(l.begin(), l, it->second);
//		return it->second->second;
//	}
//
//	void put(int key, int value) {
//		auto it = m.find(key);
//		if (it != m.end()) l.erase(it->second);
//		l.push_front(make_pair(key, value));
//		m[key] = l.begin();
//		if (m.size() > cap) {
//			int k = l.rbegin()->first;
//			l.pop_back();
//			m.erase(k);
//		}
//	}
//
//private:
//	int cap;
//	list<pair<int, int>> l;
//	unordered_map<int, list<pair<int, int>>::iterator> m;
//};
int main()
{
	LRUCache cache =  LRUCache(2 /* �������� */);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // ����  1
	cache.put(3, 3);    // �ò�����ʹ����Կ 2 ����
	cache.get(2);       // ���� -1 (δ�ҵ�)
	cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
	cache.get(1);       // ���� -1 (δ�ҵ�)
	cache.get(3);       // ����  3
	cache.get(4);       // ����  4
	return 0;
}