#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
 struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* cur = new ListNode(0);
		ListNode * head = cur;
		while (l1 != NULL && l2 != NULL)
		{

			if (l1->val <= l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;

		}
		if (l1) cur->next = l1;
		if (l2) cur->next = l2;
		return head->next;
	}
};
int main()
{
	Solution sl;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode * res = sl.mergeTwoLists(l1,l2);
	return 0;

}