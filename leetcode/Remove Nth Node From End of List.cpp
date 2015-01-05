class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        int nn = n;
        while(nn--)
        {
            fast = fast->next;
        }
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};
