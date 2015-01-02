class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        int n = 0;
        ListNode *cur = head;
        while(cur)
        {
            n++;
            cur = cur->next;
        }
        return convert(head, 0, n-1);
    }
    
    TreeNode *convert(ListNode *&head, int left, int right)
    {
        if(left > right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode *leftn = convert(head, left, mid-1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = leftn;
        root->right = convert(head, mid+1 ,right);
        return root;
    }
};
