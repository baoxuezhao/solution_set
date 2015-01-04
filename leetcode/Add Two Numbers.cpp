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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *res = &dummy;
        
        int carry = 0, v1, v2;
        while(l1 || l2 || carry)
        {
            v1 = l1? l1->val:0;
            v2 = l2? l2->val:0;
            
            res->next = new ListNode((v1+v2+carry)%10);
            carry = (v1+v2+carry)/10;
            res = res->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy.next;
    }
};
