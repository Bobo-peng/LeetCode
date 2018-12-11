#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> val;
	MinStack() {

	}

	void push(int x) {
		val.push_back(x);
	}

	void pop() {
		val.pop_back();

	}

	int top() {
		int len = val.size();
		return val[len - 1];

	}

	int getMin() {
		int min = val[0];
		if (val.size() == 0)
			return -1;
		else
		{

			for (int i = 1; i < val.size(); i++)
			{
				if (val[i] < min)
				{
					min = val[i];
				}
			}
		}
		return min;

	}
	
};
int main()
{
	MinStack obj;// = new MinStack();
	obj.push(2);
	obj.push(0);
	obj.push(3);
	obj.push(0);
	int param_4 = obj.getMin();
	obj.pop();
	param_4 = obj.getMin();
	obj.pop();
	param_4 = obj.getMin();
	obj.pop();
	param_4 = obj.getMin();
	
	return 0;
}