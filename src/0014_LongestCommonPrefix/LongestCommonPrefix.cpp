#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	string res = "";
	int minsize = INT_MAX;
	for (int i = 0; i < strs.size(); i++)
	{
		if (strs[i].size() < minsize)
			minsize = strs[i].size();
	}
	int j = 0;
	while (j < minsize)
	{
		int i = 0;
		for ( i = 0; j < strs[i].size() && i < strs.size() - 1; i++)
		{
			if (strs[i][j] != strs[i + 1][j]) return res;
		}
		res += strs[i][j++];
	}
	return res;
}
int main()
{
	vector<string> strs, strs1;
	strs = { "flower","flow","flight" };
	strs1 = {};
	string str = longestCommonPrefix(strs);
	string str1 = longestCommonPrefix(strs1);
	return 0;
}