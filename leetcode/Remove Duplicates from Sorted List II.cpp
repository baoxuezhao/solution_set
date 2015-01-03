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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        
        while(cur)
        {
            bool dup = false;
            while(cur->next && cur->next->val == cur->val)
            {
                cur->next = cur->next->next;
                dup = true;
            }
            if(dup) 
                prev->next = cur->next;
            else
                prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
