#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int search(vector<int>& nums, int target) {
	if (nums.size() > 0)
	{
		int l = 0;
		int r = nums.size() - 1;
		int mid;
		while (l <= r)
		{
			mid = (r + l) / 2;
			if (target == nums[mid]) return mid;
			if (nums[l] <= nums[mid])
			{
				if (nums[l] <= target && target < nums[mid])
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			else
			{
				if (nums[mid] < target && target <= nums[r])
				{
					l = mid;
				}
				else
				{
					r = mid - 1;
				}
			}


		}

	}
	return -1;

}
int func()
{
	int i = 3;
	return i;
}
//��ת���е���Сֵ��3 4 5 1 2������1
int MinNumber(int arr[], int len)
{
	int l = 0;
	int r = len - 1;
	int mid = 0;
	while (arr[l] >= arr[r])
	{
		if (r - l == 1)
		{
			mid = r;
			break;
		}
		mid = (r + l) / 2;
		if (arr[mid] >= arr[l])
			l = mid;
		if(arr[mid] <= arr[r])
			r = mid;
	}
	return arr[mid];
}
//�ֲ���������ָ�����
/*
char p[] = "hello world!";//����ջ��
char *p = "hello world!";//��������vs2017����д�� const char *p = "hello world!";
*/
 char *returnStr()
{
	char p[] = "hello world!";
	 //char *p = "hello world!";
	return p;
}
int main()
{
	int arr[9] = {30,40,50,60,80,6,20,23,24};
	int min =  MinNumber(arr, 9);
	 char *str;
	str = returnStr();
	//cout << *str << endl;
	int ii =func();
	vector<int> nums(7);
	int a = sizeof(long);
	nums = { 4,5,6,7,0,1,2 };
	search(nums, 0);
	return 0;
}