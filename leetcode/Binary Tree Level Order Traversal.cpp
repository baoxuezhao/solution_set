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

//DFS solution 2, each node is traversed multiple times.
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        int height = getHeight(root);
        vector<vector<int> > res;
        for(int level = 1; level <= height; level++)
        {
            vector<int> vec;
            printLevel(root, level, vec);
            res.push_back(vec);
        }
        return res;
    }
    
    void printLevel(TreeNode *root, int level, vector<int> &vec)
    {
        if(root == NULL) return;
        if(level == 1)
        {
            vec.push_back(root->val);
        }
        else
        {
            printLevel(root->left, level-1, vec);
            printLevel(root->right, level-1, vec);
        }
    }
    
    int getHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
};
