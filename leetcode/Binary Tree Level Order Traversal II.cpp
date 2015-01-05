class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int height = maxDepth(root);
        vector<vector<int> > res(height);
        dfs(root, 0, res, height);
        return res;
    }
    
    void dfs(TreeNode *root, int level, vector<vector<int> > &res, int maxh)
    {
        if(!root) return;
        res[maxh-level-1].push_back(root->val);
        
        dfs(root->left, level+1, res, maxh);
        dfs(root->right, level+1, res, maxh);
    }
    
    
    int maxDepth(TreeNode *root)
    {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
