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
	//从左到右，记录i之前的最大值
	for (int i = 0; i < n; ++i)
	{
		mem[i] = max;
		max = height[i] > max ? height[i] : max;	
	}
	max = 0;
	//从右到左，记录i后面最大值，然后和mem[i]中的值比较，取小的值；然后i位置上的值和mem[i]差值就是i位置上存的雨水量。
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