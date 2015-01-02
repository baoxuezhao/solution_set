class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        
        while(cur)
        {
            while(cur && cur->val >= prev->val)
            {
                prev = cur;
                cur = cur->next;
            }
            if(cur)
            {
                prev->next = cur->next;
                ListNode *t = &dummy, *p;
                while(t && t->val <= cur->val) //??use <= in case the original list has INT_MIN value
                {
                    p = t;
                    t = t->next;
                }
                p->next = cur;
                cur->next = t;
                cur = prev->next; //update next cur
            }
        }
        return dummy.next;
    }
};
