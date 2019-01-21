#include "pch.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		queue<int> s;
		int res = 0;
		int y = x;
		bool u = false;
		if (x < 0)
		{
			x = -x;
			u = true;
		}

		while (x >= 10)
		{
			int t = x % 10;
			s.push(t);
			x = (x - t) / 10;
		}
		s.push(x);
		while (!s.empty())
		{
			if (s.front() == 0)
				s.pop();
			else
			{
				int m = s.size();
				res += s.front() * pow(10, m - 1);
				s.pop();
			}

		}
		if (u)
			res = -res;
		if (y > 0 && res < 0)
			return 0;
		if (y < 0 && res > 0)
			return 0;
		return res;
	}
};
//int main()
//{
//	
//	Solution sl;
//	int res = sl.reverse(-123);
//	return 0;
//}