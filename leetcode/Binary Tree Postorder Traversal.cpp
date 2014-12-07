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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        
        stack<TreeNode*> s;
        
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
                if(cur->right != NULL && cur->right != prev)
                {
                    cur = cur->right;
                }
                else
                {
                    s.pop();
                    res.push_back(cur->val);
                    prev = cur;
                    cur = NULL;
                }
            }
        }
        return res;
    }
};
