#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] >= 3) return true;
				}
			}
		}
		return false;
	}
	
		bool increasingTriplet1(vector<int>& nums) {
			int m1 = INT_MAX, m2 = INT_MAX;
			for (auto a : nums) {
				if (m1 >= a) m1 = a;
				else if (m2 >= a) m2 = a;
				else return true;
			}
			return false;
		}
	};
int main()
{
	Solution sl;
	
	return 0;

}