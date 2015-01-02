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
    ListNode *sortList(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *slow = head, *fast = head, *prev;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode *part1 = sortList(head);
        ListNode *part2 = sortList(slow);
        
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(part1 || part2)
        {
            int val1 = part1? part1->val: INT_MAX;
            int val2 = part2? part2->val: INT_MAX;
            if(val1 <= val2)
            {
                cur->next = part1;
                part1 = part1->next;
            }
            else
            {
                cur->next = part2;
                part2 = part2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
