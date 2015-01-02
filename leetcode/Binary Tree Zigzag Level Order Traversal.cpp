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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> level;
        
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int n1 = 1, n2 = 0;
        int flag = false;
        
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            n1--;
            
            level.push_back(cur->val);
            
            if(cur->left)  q.push(cur->left), n2++;
            if(cur->right) q.push(cur->right), n2++;
            
            if(n1 == 0)
            {
                if(flag) reverse(level.begin(), level.end());
                res.push_back(level);
                level.clear();
                swap(n1, n2);
                flag = !flag;
            }
        }
        return res;
    }
};
