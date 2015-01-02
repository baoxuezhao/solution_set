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
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int left, int right)
    {
        vector<TreeNode*> res;
        if(left > right) return vector<TreeNode*>{NULL};
        
        for(int i=left; i<=right; i++)
        {
            vector<TreeNode*> vecl = generate(left, i-1);
            vector<TreeNode*> vecr = generate(i+1, right);
            
            for(auto l: vecl)
            {
                for(auto r: vecr)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
