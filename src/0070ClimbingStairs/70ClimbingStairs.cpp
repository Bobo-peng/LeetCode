#include "pch.h"
#include<iostream>
int climbStairs1(int n) {
	if (n < 2) return n;
	int *mem = new int[n];
	int ret;
	mem[0] = 1;
	mem[1] = 2;
	for (int i = 2; i < n; i++)
	{
		mem[i] = mem[i - 1] + mem[i - 2];
	}
	return  mem[n - 1];
}
int climbStairs2(int n) {
	if (n <= 2) return n;
	int one_step_before = 2;
	int two_step_before = 1;
	int ret;
	for (int i = 2; i < n; i++)
	{
		ret = one_step_before + two_step_before;
		two_step_before = one_step_before;
		one_step_before = ret;

	}
	return  ret;
}
int main()
{
	climbStairs1(6);
	climbStairs2(6);
	return 0;
}