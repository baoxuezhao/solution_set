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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *lasttail = &dummy;
        
        while(lasttail->next)
        {
            int kk = k;
            ListNode *ghead = lasttail->next;
            ListNode *cur = ghead;
            while(--kk && cur)
                cur = cur->next;
            
            if(cur == NULL)
                break;
                
            ListNode *nexthead = cur->next;
            cur->next = NULL;
            cur = reverse(ghead);
            lasttail->next = ghead;
            cur->next = nexthead;
            lasttail = cur;
        }
        return dummy.next;
    }
    
    ListNode *reverse(ListNode *&head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *tail = head;
        
        ListNode *prev, *cur, *next;
        for(prev = NULL, cur = head, next = cur->next; cur; prev = cur, cur = next, next = next?next->next:NULL)
            cur->next = prev;
            
        head = prev;
        return tail;
    }
};
