class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, sum);
    }
    
    bool dfs(TreeNode *root, int sum)
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && root->val == sum)
            return true;
        
        return dfs(root->left, sum-root->val) || dfs(root->right, sum-root->val);
    }
};
