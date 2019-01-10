#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		vector<int> dp(triangle.back());
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j <= i; ++j) {
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}
		return dp[0];
	}
};
//int main()
//{
//	vector<vector<int>> arr;
//	arr = { {2},
//		   {3,4},
//		  {6,5,7},
//		 {4,1,8,3} };
//	Solution sl;
//	int res = sl.minimumTotal(arr);
//	return 0;
//}