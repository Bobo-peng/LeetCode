#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "") return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n)
			return -1;
		for (int i = 0; i < m; ++i)
		{
			int j;
			for (j = 0; j < n; ++j)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == n)
				return i;
		}
		return -1;

	}
};
//KMP算法
//参考：https://blog.csdn.net/v_july_v/article/details/7041827
//1.求next数组，最大前缀后缀公共元素长度
vector<int> GetNext(string p)
{
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}
int KmpSearch(string s, string p)
{
	int i = 0;
	int j = 0;
	int sLen = s.size();
	int pLen = p.size();
	vector<int> next = GetNext(p);
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main()
{

	Solution sl;
	string s1 = "134mississippi", s2 = "ABCABCDEA";
	KmpSearch(s1,s2);
	int res = sl.strStr(s1,s2);

	return 0;

}