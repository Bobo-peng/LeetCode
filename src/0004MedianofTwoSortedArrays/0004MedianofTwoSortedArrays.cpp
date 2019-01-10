#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int  n = nums1.size();
		int m = nums2.size();
		int arr[2];
		int c = (m + n) / 2;
		if (c < 1)
		{
			if (n > 0) return nums1[0];
			else if (m > 0) return nums2[0];
			else return 0;
		}
		int k1 = 0, k2 = 0;
		int t;
		for (int i = 0; i <= c; ++i)
		{
			if (m == 0)//特殊情况:[2,3],[]
			{
				t = nums1[k1];
				k1++;
			}
			else if (n == 0)//特殊情况:[],[2,3]
			{
				t = nums2[k2];
				k2++;
			}
			else if (k2 > m-1 || k1 < n && nums1[k1] <= nums2[k2])//特殊情况:[1,2], [2,3]
			{
				t = nums1[k1];
				k1++;
			}
		   else if (k1 > n - 1 || k2 < m && nums2[k2] < nums1[k1])
			{
				t = nums2[k2];
				k2++;
			}

			if (i == c - 1) arr[0] = t;
			if (i == c) arr[1] = t;
		}
		return !((m+n) % 2) ? (arr[0] + arr[1]) / 2.0 : arr[1];
	}
};
int main()
{
	vector<int> arr(2),arr1(1);
	arr = {1,3};
	arr1 = {2};
	Solution sl;
	double res = sl.findMedianSortedArrays(arr, arr1);
	return 0;
}