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
    
    // 思路：https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
    void recoverTree(TreeNode* root) {
        std::pair<TreeNode*, TreeNode*> pair1(nullptr, nullptr);
        std::pair<TreeNode*, TreeNode*> pair2(nullptr, nullptr);
        TreeNode* prev = nullptr;
        inorder(root, prev, pair1, pair2);
        if (pair2.first == nullptr && pair2.second == nullptr) {
            swap(pair1.first->val, pair1.second->val);
        } else {
            swap(pair1.first->val, pair2.second->val);
        }
        return;
    }
    
    void inorder(TreeNode* root, TreeNode*& prev,
        std::pair<TreeNode*, TreeNode*>& pair1, 
        std::pair<TreeNode*, TreeNode*>& pair2) {
        
        if (root == nullptr) {
            return;
        }
        inorder(root->left, prev, pair1, pair2);
        if (prev != nullptr && root->val < prev->val) {
            if (pair1.first == nullptr) {
                pair1.first = prev;
                pair1.second = root;
            } else {
                pair2.first = prev;
                pair2.second = root;   
            }
        }
        prev = root;
        inorder(root->right, prev, pair1, pair2);
    }
    
    void visit(TreeNode *prev, TreeNode *cur, pair<TreeNode*, TreeNode*> &brokens)
    {
        if(prev->val <= cur->val) return;
        
        if(brokens.first == NULL)
            brokens.first = prev;
        brokens.second = cur;
    }
};
