#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n == 0)
			return;
		int m = matrix[0].size();
		vector<vector<int>> zero;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < m; ++j)
			{
				if (matrix[i][j] == 0)
				{
					vector<int> t;
					t = { i, j };
					zero.push_back(t);
				}

			}
		}
		for (int i = 0; i < zero.size(); ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				matrix[zero[i][0]][j] = 0;//ÁÐ
			}
			for (int j = 0; j < n; ++j)
			{
				matrix[j][zero[i][1]] = 0;//ÐÐ
			}
		}

	}
};
int main()
{
	
	Solution sl;
	vector<vector<int>> arr;
	arr = { {1} ,{0} };
	sl.setZeroes(arr);
	return 0;
}