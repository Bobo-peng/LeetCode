#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int n = s.size();
		int maxLen = 0, left = 0, right = 0, start = 0;
		for (int i = 0; i < n;)
		{
			left = i, right = i;
			if ((n - i) / 2 < maxLen)
				break;
			while (i < n - 1 && s[right + 1] == s[right])
				right++;
			i = right + 1;
			while (i < n - 1 && left>0 && s[right + 1] == s[left - 1])
			{
				left--;
				right++;
			}
			if (maxLen < right - left + 1)
			{
				maxLen = right - left + 1;
				start = left;
			}

		}
		return s.substr(start, maxLen);
	}
};
int main()
{
	Solution sl;
	string s1 = "babad";
	sl.longestPalindrome(s1);
	return 0;

}