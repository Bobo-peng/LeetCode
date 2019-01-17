#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		if (n < 1) return "";
		string res = "1";
		while (--n)
		{
			string temp = "";
			for (int i = 0; i < res.size(); ++i)
			{
				int cnt = 1;
				while (i < res.size() - 1 && res[i] == res[i + 1])
				{
					++cnt;
					++i;
				}
				temp += to_string(cnt);
				temp += res[i];
			}
			res = temp;
		}
		return res;
	}
};
int main()
{

	Solution sl;
	
	string res = sl.countAndSay(4);

	return 0;

}