#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		int n = prices.size()-1;
		
		for (int i = 0; i < n; ++i)
		{
			if (prices[i] < prices[i + 1])
				res += prices[i + 1] - prices[i];
		}
		return res;

	}
};
//int main()
//{
//	vector<int> arr(6);
//	arr = { 7,1,5,3,6,4 };
//	vector<int> arr0;
//	Solution sl;
//	int res = sl.maxProfit(arr0);
//	return 0;
//}