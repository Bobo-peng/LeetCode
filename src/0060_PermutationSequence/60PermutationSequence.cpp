#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int getgroup(int num, int k)//countΪÿ����Ԫ�ظ�����
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
	int count = 1;//n���ܹ���������
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
		//ÿ��ĸ���
		int num = count / n;
		//������һ��
		int group = getgroup(num, k);
		//������һ�ε�kֵ
		k = getk(num, k);
		//���׷�ӵ��ַ���
		res += vct[group - 1] + '0';
		//��һ�ε���������
		count /= n;
		//ɾ��Ԫ��
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