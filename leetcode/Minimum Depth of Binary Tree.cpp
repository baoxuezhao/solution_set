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
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        
        q.push(root);
        int level = 1, n1 = 1, n2 = 0;
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            n1--;
            if(cur->left == NULL && cur->right == NULL)
                return level;
            
            if(cur->left)
            {
                q.push(cur->left);
                n2++;
            }
            if(cur->right)
            {
                q.push(cur->right);
                n2++;
            }
            if(n1 == 0)
            {
                level++;
                swap(n1, n2);
            }
        }
    }
};
