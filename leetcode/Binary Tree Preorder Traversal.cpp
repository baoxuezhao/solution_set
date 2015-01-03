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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while(!s.empty() || cur)
        {
            if(cur) {
                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
