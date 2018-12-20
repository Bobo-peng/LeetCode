#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
string simplifyPath(string path) {
	vector<string> s;
	int j = 0;
	int len = path.size();
	if (len == 0) return path;	
	for (int i = 0; i < len; i++)
	{
		vector<char> temp;
		while(i < len && path[i] != '/')
		{
			temp.push_back(path[i++]);
		}
		if (temp.size() > 0)
		{
			string stemp;
			for (int k = 0; k < temp.size(); k++)
			{
				stemp += temp[k];
			}
			if (stemp.compare("..") == 0 && s.size() > 0)//如果为..则删除上层目录
			{
				s.erase(s.end()-1);
			}	
			if (stemp.compare(".") != 0 && stemp.compare("..") != 0)//compare相同返回0，既不为.也不为..
			{
				s.push_back(stemp);
			}
		}
	}
	if (s.size() == 0) return "/";
	string res;
	vector<int> arr(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		res += "/";
		res += s[i];
	}
	return res;
}
int main()
{

	string  path1 = "/home/";
	string	path2 = "/a/./b/../../c/";
	string	path3 = "/a/../../b/../c//.//";
	string	path4 = "/a//b////c/d//././/..";
	string	path5 = "////";
	string path = simplifyPath(path5);
	getchar();
	return 0;

}