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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *other = slow;
        other = reverse(other);
        while (head && other) {
            if (head->val != other->val) {
                return false;
            }
            head = head->next;
            other = other->next;
        }
        return true;
    }
    
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = NULL;
        ListNode *cur  = NULL;
        ListNode *next = NULL;
        for(cur = head, next=cur->next; cur; prev=cur, cur=next, next=next?next->next:NULL) {
            cur->next = prev;
        }
        return prev;
    }
};
