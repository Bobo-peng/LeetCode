#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isValid(char c)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			return true;
		else
			return false;
	}
	bool isChar(char c)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
		else
			return false;
	}
	bool isPalindrome(string s) {
		if (s.size() < 1)
			return true;
		int i = 0, j = s.size() - 1;
		while (i <= j)
		{
			while (!isValid(s[i]))
				++i;
			while (!isValid(s[j]))
				--j;
			if (i>j)
				return true;

			if (s[i] == s[j] || (isChar(s[i]) && isChar(s[j]) && abs(s[i] - s[j]) == 'a' - 'A'))
			{
				++i;
				--j;
			}
			else
				return false;

		}
		return true;
	}

};
int main()
{
	string s = "A man, a plan, a canal: Panama",s1 = "0P";
	Solution sl;
	bool res = sl.isPalindrome(s1);

	return 0;
}