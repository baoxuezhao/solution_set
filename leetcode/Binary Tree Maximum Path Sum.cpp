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
    int maxPathSum(TreeNode *root) {
        int curmax = INT_MIN;
        postorder(root, curmax);
        return curmax;
    }
    
    int postorder(TreeNode *root, int &curmax)
    {
        if(root == NULL) return 0;
        
        int leftsum = postorder(root->left, curmax);
        int rightsum= postorder(root->right, curmax);
        
        int sum = root->val;
        if(leftsum > 0) sum += leftsum;
        if(rightsum > 0) sum += rightsum;
        curmax = max(curmax, sum);
        
        int m = max(leftsum, rightsum);
        if(m > 0)
            return root->val + m;
        else
            return root->val;
    }
};
