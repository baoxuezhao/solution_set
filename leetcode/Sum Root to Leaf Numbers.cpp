class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if(root == NULL)
            return 0;
        
        dfs(root, root->val, sum);
        return sum;
    }
    
    void dfs(TreeNode *root, int num, int &sum)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            sum += num;
            return;
        }
        if(root->left)
            dfs(root->left, num*10+root->left->val, sum);
        if(root->right)
            dfs(root->right,num*10+root->right->val, sum);
    }
};
