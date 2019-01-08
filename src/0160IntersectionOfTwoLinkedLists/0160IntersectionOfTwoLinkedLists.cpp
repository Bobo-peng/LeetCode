#include"stdafx.h"
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	int getListLen(ListNode* head)
	{
		int cnt = 0;
		while (head)
		{
			++cnt;
			head = head->next;
		}
		return cnt;
	}	
	//1.获取两个链表的长度；2.先让长的链表的指针先走两者长度的差值步；3.然后同步走，相等则是交点
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		int lenA = getListLen(headA);
		int lenB = getListLen(headB);
		if (lenA < lenB)
		{
			for (int i = 0; i < lenB - lenA; ++i)
				headB = headB->next;
		}
		else
		{
			for (int i = 0; i < lenA - lenB; ++i)
				headA = headA->next;
		}
		while (headA && headB && !(headA == headB))
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
	//1.两个链表同时走，假如A链表走到尾时，指向B链表的头，然后继续走；B链表走到尾时，指向A链表的头，然后继续走；
	//2.当二者相等时，为交叉点（因为此时两者正好走的步数相等）
	ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB)
	{
		if (!headA || !headB) return NULL;
		ListNode *listA = headA, *listB = headB;
		while (!(listA == listB))
		{
			listA = !listA ? headB : listA->next;
			listB = !listB ? headA : listB->next;
		}
		return listA;
	}
};