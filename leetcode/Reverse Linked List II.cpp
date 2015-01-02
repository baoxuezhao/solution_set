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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        
        int mm = m;
        while(--mm)
        {
            prev = cur;
            cur = cur->next;
        }
        
        int len = n-m+1;
        ListNode *pp = prev, *cc = cur, *next = cur->next;
        prev = NULL;
        
        for(; cur && len; len--, prev = cur, cur = next, next = next?next->next:NULL)
        {
            cur->next = prev;
        }
        
        pp->next = prev;
        cc->next = cur;
        
        return dummy.next;
    }
};
