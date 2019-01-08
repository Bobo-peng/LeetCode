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
	//1.��ȡ��������ĳ��ȣ�2.���ó��������ָ���������߳��ȵĲ�ֵ����3.Ȼ��ͬ���ߣ�������ǽ���
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
	//1.��������ͬʱ�ߣ�����A�����ߵ�βʱ��ָ��B�����ͷ��Ȼ������ߣ�B�����ߵ�βʱ��ָ��A�����ͷ��Ȼ������ߣ�
	//2.���������ʱ��Ϊ����㣨��Ϊ��ʱ���������ߵĲ�����ȣ�
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