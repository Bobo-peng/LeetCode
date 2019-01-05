#include "pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class KthLargest {
public:
	KthLargest(int k, vector<int> nums) {
		int n = nums.size();
		this->k = k;
			
			for (int i = 0; i < n; i++)
			{
				q.push(nums[i]);
				if (i > k - 1)
					q.pop();
			}
	}
	priority_queue <int, vector<int>, greater<int> > q;//ÉýÐò
	int k;
	int add(int val) {
		if (q.size() < k)
			q.push(val);
		else
		{
			q.push(val);
			q.pop();
		}
		return q.top();
	}
};
int main()
{
	int k = 3;
	//int[] arr = [4, 5, 8, 2];
	vector<int> arr(4);
	arr = { 4, 5, 8, 2 };
	KthLargest *kthLargest = new KthLargest(3, arr);
	kthLargest->add(3);   // returns 4
	kthLargest->add(5);   // returns 5
	kthLargest->add(10);  // returns 5
	kthLargest->add(9);   // returns 8
	kthLargest->add(4);   // returns 8
}