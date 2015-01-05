class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }
    
    int height(TreeNode *root)
    {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 || rh == -1 || abs(lh-rh) > 1) return -1;
        return max(lh, rh)+1;
    }
};
