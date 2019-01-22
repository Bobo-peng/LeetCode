#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, int> m;
		int j = 0;
			for (int i = 0; i < strs.size();++i)
			{
				string s = strs[i];
				sort(s.begin(), s.end());
				if (m.count(s))
				{
					res[m[s]].push_back(strs[i]);
				}
				else
				{
					m[s] = j++;
					res.push_back(vector<string>{strs[i]});
				}
			}

			return res;
	}
};
//int main()
//{
//	Solution sl;
//	vector<string> s1;
//	s1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	sl.groupAnagrams(s1);
//	return 0;
//
//}