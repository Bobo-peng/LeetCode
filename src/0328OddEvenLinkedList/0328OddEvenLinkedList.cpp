
#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode * CreatList(vector<int> &arr)
	{
		if (arr.size() == 0) return  NULL;
		ListNode *head = NULL, *p = NULL, *temp;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			temp = new ListNode(arr[i]);
			if (i > 0)
				p->next = temp;
			p = temp;
			if (i == 0)
				head = temp;
		}
		return head;
	}
	ListNode * oddEvenList(ListNode* head) {
		if (!head)
			return head;
		ListNode* oddHead = head;
		ListNode* evenHead = head->next ? head->next : NULL;
		ListNode* evenCur = evenHead;
		while (head && head->next && head->next->next)
		{
				head->next = head->next->next;
				head = head->next;
				evenCur->next = head->next;
				evenCur = evenCur->next;
		}
		head->next = evenHead;
		return  oddHead;
	}
};
//int main()
//{
//	
//	vector<int> arr(5);
//	arr = { 1,2,3,4,5 };
//	Solution sl;
//	ListNode *head = sl.CreatList(arr);
//	ListNode* pos = sl.oddEvenList(head);
//	return 0;
//}