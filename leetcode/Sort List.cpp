/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //solution 1, need to find the middle node at each round.
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

//solution 2, buttom up, without need to find the middle point at each round.
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        int len = 0;
        ListNode *cur = head;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        return sortutil(head, 0, len-1);
    }
    
    ListNode *sortutil(ListNode *&head, int left, int right)
    {
        if(left > right) return NULL;
        if(left == right)
        {
            ListNode *ret = head;
            head = head->next;
            ret->next = NULL;
            return ret;
        }
        int mid = left+(right-left)/2;
        
        ListNode *lch = sortutil(head, left, mid);
        ListNode *rch = sortutil(head, mid+1, right);
        
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(lch && rch)
        {
            if(lch->val < rch->val)
            {
                cur->next = lch;
                lch = lch->next;
            }
            else
            {
                cur->next = rch;
                rch = rch->next;
            }
            cur = cur->next;
        }
        while(lch)
        {
            cur->next = lch;
            lch = lch->next;
            cur = cur->next;
        }
        while(rch)
        {
            cur->next = rch;
            rch = rch->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
