class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        
        TreeNode *cur = root;
        TreeNode dummy(INT_MIN);
        TreeNode *prev = &dummy;
        
        pair<TreeNode*, TreeNode*> brokens(NULL, NULL);
        
        while(cur)
        {
            if(cur->left == NULL)
            {
                visit(prev, cur, brokens);
                prev = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode *tmp = cur->left;
                while(tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
                if(tmp->right == NULL)
                {
                    tmp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    tmp->right = NULL;
                    visit(prev, cur, brokens);
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swap(brokens.first->val, brokens.second->val);
    }
    
    void visit(TreeNode *prev, TreeNode *cur, pair<TreeNode*, TreeNode*> &brokens)
    {
        if(prev->val <= cur->val) return;
        
        if(brokens.first == NULL)
            brokens.first = prev;
        brokens.second = cur;
    }
};
