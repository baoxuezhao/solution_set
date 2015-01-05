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
        ListNode *cur = head;
        while(cur)
        {
            while(cur->next && cur->next->val == cur->val)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};
