#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
	int n = height.size();
	int res = 0, max = 0;
	vector<int> mem(n, 0);
	for (int i = 0; i < n; ++i)
	{
		mem[i] = max;
		max = height[i] > max ? height[i] : max;	
	}
	max = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		mem[i] = mem[i] < max ? mem[i] : max;
		max = height[i] > max ? height[i] : max;
		if (mem[i] > height[i])
			res += mem[i] - height[i];
	}
	return res;
}
int main()
{
	vector<int> arr(12);
	arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int ret = trap(arr);
	return 0;
}