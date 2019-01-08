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
 
 ListNode *CreatList(vector<int> &arr)
 {
	 if (arr.size() == 0) return  NULL;
	 ListNode *head = NULL, *p = NULL,*temp;
	 for (unsigned int i = 0; i < arr.size(); i++)
	 {
		 temp = new ListNode(arr[i]);
		 if(i > 0)  
			 p->next = temp;
		 p = temp;
		 if (i == 0) 
			 head = temp;
	 }
	 return head;
 }

class Solution {
public:
	ListNode * mergeList(ListNode* list1, ListNode* list2)
	{
		if (!list1) return list2;
		if (!list2) return list1;
		if (list1->val < list2->val)
		{
			list1->next = mergeList(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeList(list2->next, list1);
			return list2;
		}
	}
	ListNode * sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* fast = head, *slow = head, *pre = head;
		while (fast && fast->next)
		{
			pre = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		pre->next = NULL;//截断成两个链表
		
		return mergeList(sortList(head), sortList(slow));
	}
};
int main()
{
	vector<int> arr(5);
	arr = {3,2,4,1,5};
	ListNode *head = CreatList(arr);
	Solution sl;
	ListNode* sList = sl.sortList(head);
	return 0;
}