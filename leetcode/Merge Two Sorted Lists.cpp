class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy.next;
    }
};
