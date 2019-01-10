#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN, sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum = max(nums[i] + sum, nums[i]);
			res = max(res, sum);
		}
		return res;
	}
};
//int main()
//{
//	vector<int> arr;
//	arr = { -2,1,-3,4,-1,2,1,-5,4 };
//	Solution sl;
//	double res = sl.maxSubArray(arr);
//	return 0;
//}