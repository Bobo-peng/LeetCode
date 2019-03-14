#include"pch.h"
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int a_size = a.size();
		int b_size = b.size();
		if (!a_size || !b_size)
			return !a_size ? a : b;
		int n = max(a_size, b_size);
		int c = 0;
		int j = a_size - 1, k = b_size - 1;
		stack<int> s;
		for (int i = n - 1; i >= 0; --i)
		{
			if (j >= 0 && k >= 0)
			{
				if (a[j] == '1' && b[k] == '1')
				{

					s.push(c);
					c = 1;
					--j;
					--k;
				}
				else
				{
					int t = c + a[j] + b[k];
					/*if (t > 1)*/
					if (t > 97)
					{
						s.push(0);
						c = 1;
					}
					else if (t == 97)
					{
						s.push(1);
						c = 0;
					}
					else
					{
						s.push(0);
						c = 0;
					}
					--j;
					--k;
				}
			}
			else if (j < 0)
			{
				int t = c + b[k];
				/*if (t > 1)*/
				if (t > 49)
				{
					s.push(0);
					c = 1;
				}
				else
				{
					if(t == 49)
					s.push(1);
					else
						s.push(0);
					c = 0;
					
				}
				--k;

			}
			else if (k < 0)
			{
				int t = c + a[j];
				if (t > 49)
				{
					s.push(0);
					c = 1;
				}
				else
				{
					
					if (t == 49)
						s.push(1);
					else
						s.push(0);
					c = 0;
					
				}
				--j;

			}

		}

		if (c == 1)
		{
			s.push(1);
		}
		while (!s.empty())
		{
			int t = s.top();
			s.pop();
			if (t == 1)
				res += "1";
			else
				res += "0";
		}
		return res;

	}
};
int main()
{
	Solution sl;
	string a = "101111";
	string b = "10";
	sl.addBinary(a, b);
	return 0;
}