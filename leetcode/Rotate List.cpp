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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *cur = head;
        int len = 0;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        k %= len;
        if(k == 0) return head; //special case
        
        ListNode *slow = head, *fast = head;
        int kk = k;
        while(kk--)
        {
            fast = fast->next;
        }
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = head;
        ListNode *res = slow->next;
        slow->next = NULL;
        return res;
    }
};
