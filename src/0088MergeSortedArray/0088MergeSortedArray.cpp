#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			while (nums2[i] > nums1[j] && j < m)
				++j;
			nums1.erase(nums1.end() - 1);
			nums1.insert(nums1.begin() + j, nums2[i]);
			++m;
			j += 1;
		}

	}
};
int main()
{
	vector<int> arr1, arr2;
	arr1 = {1,2,3,0,0,0};
	Solution sl;
	arr2 = {2,5,6};
	sl.merge(arr1,3,arr2,arr2.size());
	return 0;
}