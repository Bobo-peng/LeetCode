#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *CreatList(vector<int> &arr, int pos)
{
	if (arr.size() == 0) return  NULL;
	ListNode *head = NULL, *p = NULL, *pCycle = NULL, *temp;
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		temp = new ListNode(arr[i]);
		if (i > 0)
			p->next = temp;
		p = temp;
		if (i == 0)
			head = temp;
		if (i == pos)
			pCycle = p;
	}
	p->next = pCycle;
	return head;
}
class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		ListNode* fast = head, *slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				if (slow == head)//完全是个环，只可能在头相遇
					return head;
				while (1)
				{
					head = head->next;
					slow = slow->next;
					if (head == slow)
						return slow;
				}
			}
		}

	}
};

int main()
{
	vector<int> arr(5);
	arr = { 3,2,4,1,5 };
	ListNode *head = CreatList(arr,2);
	Solution cy;
	ListNode* pos = cy.detectCycle(head);
	return 0;
}