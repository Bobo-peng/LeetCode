
#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(256, -1);
		int j = -1;
		int ret = 0;
		for (int i = 0; i < s.size(); i++)//滑动窗口,哈希表key记录字母，value记录上次字母的位置
		{
			j = max(j, m[s[i]]);
			m[s[i]] = i;
			ret = max(ret, i - j);
		}
		return ret;

	}
	int lengthOfLongestSubstring1(string s) {
		int res = 0, left = 0, i = 0, n = s.size();
		unordered_set<char> t;
		while (i < n) {
			if (!t.count(s[i])) 
			{
				t.insert(s[i++]);
				res = max(res, (int)t.size());
			}
			else {
				t.erase(s[left++]);
			}
		}
		return res;
	}
	int lengthOfLongestSubstring2(string s) {
		int res = 0, left = -1, n = s.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (m.count(s[i]) && m[s[i]] > left) {
				left = m[s[i]];
			}
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
	//
};
//int main()
//{
//	Solution sl;
//	string s1 = "abcadeb", s2 = "abba";
//	sl.lengthOfLongestSubstring2(s2);
//	return 0;
//
//}