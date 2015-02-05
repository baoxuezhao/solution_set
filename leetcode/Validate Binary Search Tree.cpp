/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        
        while(!s.empty() || cur)
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                //visit cur
                if(prev == NULL || cur->val > prev->val)
                    prev = cur;
                else
                    return false;
                
                cur = cur->right;
            }
        }
        return true;
    }
};


//recursion approach
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int prev = INT_MIN;
        bool first = true;
        return isValidBST(root, prev, first);
    }
    
    bool isValidBST(TreeNode *root, int &prev, bool &first)
    {
        if(!root) return true;
        if(!isValidBST(root->left, prev, first)) return false;
        if(!first && root->val <= prev) return false;
        first = false;
        prev = root->val;
        return isValidBST(root->right, prev, first);
    }
};
