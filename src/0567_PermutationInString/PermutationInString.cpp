#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//Ë³ÐòºÍÄæÐò
bool checkInclusion1(string s1, string s2) {
	if (s1 == "") return true;
	if (s1 != "" && s2 == "") return false;
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	while (j < s2.size())
	{
		if (s1[i] == s2[j])
		{
			k = j;
			n = i;
			while (i < s1.size() && j < s2.size())
			{
				if (s1[i] != s2[j]) break;
				i++;
				j++;
			}
			while (n < s1.size() && k >= 0)
			{
				
				if (s1[n] != s2[k]) break;
				n++;
				k--;
			}
			if (i == s1.size() || n == s1.size()) return true;
			else i = 0;
			j--;
		}
		j++;
	}
	return false;
}
bool checkInclusion(string s1, string s2) {
	if (s1 == "") return true;
	if (s1 != "" && s2 == "") return false;
	vector<char> c1(26);
	vector<char> c2(26);
	for (int i = 0; i < s1.size(); i++)
	{
		c1[s1[i] - 'a']++;
	}
	int j = 0;
	while(j + s1.size() <= s2.size())
	{
		for (int k = j; k < s1.size(); k++)
		{
			c2[s2[k] - 'a']++;
		}
		if (c1 == c2) return true;
		c2.clear();
	}
	return false;
}
int main()
{
	//string s1 = "ab", s2 = "eidbaooo";
	//string s1 = "ab", s2 = "eidboaoo";
	//string s1 = "adc", s2 = "dcda";
	string s1 = "ab", s2 = "ba";
	bool ret = checkInclusion(s1, s2);
	return 0;
}