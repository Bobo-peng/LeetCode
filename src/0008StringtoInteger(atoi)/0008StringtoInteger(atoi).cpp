#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isNumChar(char c)
	{
		if (c >= '0' && c <= '9')
			return true;
		else
			return false;
	}
	int myAtoi(string str) {
		bool neg = false;
		int res = 0;
		int n = str.size();
		if (n == 0)
			return 0;
		int i = 0;
		while (i < n && str[i] == ' ')
			++i;
		if (str[i] == '+' || str[i] == '-')
			neg = (str[i++] == '+') ? false : true;
		while (i < n && isNumChar(str[i]))
		{

			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
				return neg ? INT_MIN : INT_MAX;
			}
			res = res * 10 + str[i++] - '0';

		}
		res = neg ? -res : res;
		return res;
	}
};
int main()
{
	string s1 = "4193 with words", s2 = "words and 987", s3 = "-91283472332",s4 = "   -42",s5 = "+1",s6 = "  0-2";
	Solution sl;
	int res = sl.myAtoi(s1);
	res = sl.myAtoi(s2);
	res = sl.myAtoi(s3);
	res = sl.myAtoi(s4);
	res = sl.myAtoi(s5);
	res = sl.myAtoi(s6);
	return 0;
}