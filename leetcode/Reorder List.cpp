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
    void reorderList(ListNode *head) {
        if(!head || !(head->next)) return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *l2 = slow->next, *cur;
        slow->next = NULL;
        l2 = reverse(l2);
        
        ListNode dummy(-1);
        cur = &dummy;
        
        while(l1 && l2)
        {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
            
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
    }
    
    ListNode* reverse(ListNode *head)
    {
        if(!head || !(head->next)) return head;
        ListNode *prev = NULL, *cur = head, *next = cur->next;
        
        for(; cur; prev = cur, cur = next, next = next?next->next : NULL)
            cur->next = prev;
        
        return prev;
    }
};
