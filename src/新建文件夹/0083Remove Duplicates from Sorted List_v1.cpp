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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        int last = head->val;
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* ret = pre; 
        cur = cur->next;
        while(cur)
        {
            
            if(cur->val == last)
            {
                if(cur->next == NULL)
                    pre->next = NULL;
                else
                pre->next = pre->next->next;
                cur = pre->next;
            }
            else
            {
                last = cur->val;
                cur = cur->next;
                pre = pre->next;
            }
            
        }
        return ret;
    }
};