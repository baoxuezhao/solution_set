class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        
        dfs(root, sum, path, result);
        
        return result;
    }
    
    void dfs(TreeNode *root, int cur, vector<int> &path, vector<vector<int> > &result)
    {
        if(root == NULL) return;
        
        path.push_back(root->val);
        cur -= root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(cur == 0) result.push_back(path);
        }
        else
        {
            dfs(root->left, cur, path, result);
            dfs(root->right, cur, path, result);
        }
        path.pop_back();
    }
};
