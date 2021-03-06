// string.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool isDuplicate(vector<vector<int>> r, int a, int b, int c)
{
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	for (int i = 0; i < r.size(); i++)
	{
		sort(r[i].begin(), r[i].end());
		if (a == r[i][0] && b == r[i][1] && c == r[i][2])
			return true;
	}
	return false;
}
//暴力解法，超时
vector<vector<int>> threeSum1(vector<int>& nums) {
	vector<vector<int>> rets;
	for (int i = 0; i< nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					if (rets.size() > 0 && isDuplicate(rets, nums[i], nums[j], nums[k]))
						break;
					rets.push_back({ nums[i],nums[j],nums[k] });

				}
			}
		}
	}
	return rets;
}

//提交过的
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> rets;
	sort(nums.begin(), nums.end());
	int j, k;
	for (int i = 0; i< nums.size() && nums[i] <= 0; i++)
	{
		k = nums.size() - 1;
		j = i + 1;
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		while (j < k)
		{
			if (-nums[i] == nums[j] + nums[k])
			{
				while (j < k && nums[j] == nums[j + 1])
					j++;
				while (j < k && nums[k] == nums[k - 1])
					k--;
				rets.push_back({ nums[i],nums[j],nums[k] });
				j++;
				k--;
			}
			else if (-nums[i] < nums[j] + nums[k])
				k--;
			else
				j++;

		}

	}
	return rets;
}

int main()
{
	vector<int> test3sum;
	vector<vector<int>> res;
	test3sum = { 1,-2,6,-6,-4,-2,5,-9,-9,8,-4,-10,5,3,-6 };
	res = threeSum1(test3sum);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	getchar();
	return 0;
}

