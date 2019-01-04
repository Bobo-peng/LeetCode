#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int getgroup(int num, int k)//count为每个组元素个数；
{
	if (k % num == 0) return k / num;
	else
		return k / num + 1;
}
int getk(int num, int k)
{
	if (k < num) return k;
	else
	{
		if (k % num == 0)
			return num;
		else
			return k % num;
	}		
}
string getPermutation(int n, int k) {
	if (n < 1) return "";
	int count = 1;//n的总共排列数量
	vector<int> vct;
	string res("");
	for (int i = 1; i <= n; i++)
	{
		vct.push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		count *= i;
	}
	while (n > 0)
	{
		//每组的个数
		int num = count / n;
		//落在哪一组
		int group = getgroup(num, k);
		//计算下一次的k值
		k = getk(num, k);
		//结果追加到字符串
		res += vct[group - 1] + '0';
		//下一次的序列总数
		count /= n;
		//删除元素
		vct.erase(vct.begin() + group - 1);
		//n = vct.size();	
		n--;
	}
	return res;
}
int main()
{
	getPermutation(4, 9);
	getPermutation(3, 6);
	getPermutation(3, 1);
	getPermutation(3, 2);
	return 0;
}