/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL==head)
            return head;   
        ListNode* p1= head, *p2 = head;
        while(n-- && p1 != NULL)
        {
            p1 = p1->next;
        }
        if(p1 == NULL)
            return head->next;
         p1 = p1->next;
        while(NULL != p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};