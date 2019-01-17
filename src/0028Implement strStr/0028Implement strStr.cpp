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
//KMP�㷨
//�ο���https://blog.csdn.net/v_july_v/article/details/7041827
//1.��next���飬���ǰ׺��׺����Ԫ�س���
vector<int> GetNext(string p)
{
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺
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
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]    
			//next[j]��Ϊj����Ӧ��nextֵ      
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