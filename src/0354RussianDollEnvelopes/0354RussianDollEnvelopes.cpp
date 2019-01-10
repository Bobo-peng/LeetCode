#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end());
		int n = envelopes.size();
		int res = 0;
		vector<int> dp(n, 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
					dp[i] = max(dp[i], dp[j]+1);
			}
			res = max(dp[i], res);
		}
		return res;
	}
};
//int main()
//{
//	vector<pair<int, int>> arr;
//	arr = { { 5, 4 },{ 6, 4 },{ 6, 7 },{ 2, 3 } };
//	Solution sl;
//	int res = sl.maxEnvelopes(arr);
//	return 0;
//}