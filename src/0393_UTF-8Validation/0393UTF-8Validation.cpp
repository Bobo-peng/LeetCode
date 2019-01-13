#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int n = data.size();
		if (n < 1) return false;
		for (int i = 0; i < n; ++i)
		{
			if ((data[i] & 0x80) == 0)
				continue;
			else
			{
				int cnt = 0;
				while (i < n && (data[i] & (0x80 >> cnt)))
					++cnt;
				if (cnt > 4) return false;
				if (cnt  == 1) return false;
				for (int j = 1; j < cnt; j++)
				{
					if (!(data[i+j] & 0x80 && (data[i+j] & 0x40) == 0))
						return false;
				}
				i += cnt-1;
			}
		}
		return true;
	}
};
int main()
{
	vector<int> arr;
	//arr1 = {1,2};
	arr = { 115,100,102,231,154,132,13,10};
	Solution sl;
	double res = sl.validUtf8(arr);
	return 0;
}