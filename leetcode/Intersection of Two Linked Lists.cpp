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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = listLen(headA);
        int len2 = listLen(headB);
        
        ListNode *cur1, *cur2;
        int gap;
        
        if(len1 < len2)
        {
            gap = len2-len1;
            cur1 = headA;
            cur2 = headB;
        }
        else
        {
            gap = len1-len2;
            cur1 = headB;
            cur2 = headA;
        }
        while(gap--) cur2 = cur2->next;
        
        while(cur1 && cur2)
        {
            if(cur1 == cur2) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
    
    int listLen(ListNode *head)
    {
        int res = 0;
        while(head)
        {
            res++;
            head = head->next;
        }
        return res;
    }
};
