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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(-1), dummy2(-1);
        ListNode *s = &dummy1, *el = &dummy2;
        while(head)
        {
            if(head->val < x)
            {
                s->next = head;
                s = s->next;
            }
            else
            {
                el->next = head;
                el=el->next;
            }
            head=head->next;
        }
        s->next=dummy2.next;
        el->next = NULL; //???
        return dummy1.next;
    }
};
