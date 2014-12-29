//using DFS
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        int height = getHeight(root);
        vector<vector<int> > res(height, vector<int>());
        helper(root, res, 0);
        return res;
    }
    
    void helper(TreeNode *root, vector<vector<int> > &res, int level)
    {
        if(root == NULL)
            return;
        res[level].push_back(root->val);
        helper(root->left, res, level+1);
        helper(root->right,res, level+1);
    }
    
    int getHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
};
