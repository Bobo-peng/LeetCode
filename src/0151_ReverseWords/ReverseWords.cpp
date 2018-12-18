#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void prestr(string &s);
void reverseWords(string &s) {

	prestr(s);
	int len = s.size();
	for (int i = 0; i < len / 2; i++)
	{
		swap(s[i], s[len - 1 - i]);
	}
	int j = 0;
	int k = 0;
	while (j <= len)
	{
		if (s[j] == ' ' || s[j] == '\0')
		{
			for (int i = k; i < (k + j) / 2 ; i++)
			{
				swap(s[i], s[j-i-1+k]);
			}
			k = j + 1;
		}
		j++;
	}
}
void prestr(string &s)
{ 
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			i++;
			while (s[i] == ' ' && s[i] != '\0')
			{
				s.erase(i,1);
			}
		}
		if(s[i] != '\0')
		i++;
	}
	
	if (s[0] == ' ') s.erase(0,1);
	int len = s.size();
	if (s[len-1] == ' ') s.erase(len-1, 1);
}
int main()
{

	string s = "    me love       you    ";
	reverseWords(s);
	reverseWords(s);
	return 0;
}