#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char> >& matrix) {
		int res = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			vector<int> v(matrix[i].size(), 0);
			for (int j = i; j < matrix.size(); ++j) {
				for (int k = 0; k < matrix[j].size(); ++k) {
					if (matrix[j][k] == '1') ++v[k];
				}
				res = max(res, getSquareArea(v, j - i + 1));
			}
		}
		return res;
	}
	int getSquareArea(vector<int> &v, int k) {
		if (v.size() < k) return 0;
		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] != k) count = 0;
			else ++count;
			if (count == k) return k * k;
		}
		return 0;
	}
	//¶¯Ì¬µÝÍÆ
	int maximalSquare1(vector<vector<char> >& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), res = 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == 0 || j == 0)
					dp[i][j] = matrix[i][j] - '0';
				else if (dp[i][j] = matrix[i][j] == '1')
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				res = max(dp[i][j], res);
			}

		}
		return res * res;
	}
};
int main()
{
	vector<vector<char>> arr;
	arr = { { '1' ,'0' ,'1' ,'0', '0' },
			{ '1' ,'0' ,'1', '1', '1' },
			{ '1', '1', '1' ,'1', '1' },
			{ '1', '0' ,'1', '1', '0' }};
	Solution sl;
	double res = sl.maximalSquare(arr);
	return 0;
}