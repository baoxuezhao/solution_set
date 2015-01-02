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
    void flatten(TreeNode *root) {
        preorder(root);
    }
    
    pair<TreeNode*, TreeNode*> preorder(TreeNode *root)
    {
        if(root == NULL)
            return make_pair(root, root);
        
        pair<TreeNode*, TreeNode*> left = preorder(root->left);
        pair<TreeNode*, TreeNode*> right = preorder(root->right);
        
        root->left = NULL;
        
        TreeNode *tail = root;
        
        if(left.first)
        {
            tail->right = left.first;
            tail = left.second;
        }
        if(right.first)
        {
            tail->right = right.first;
            tail = right.second;
        }
        return make_pair(root, tail);
    }
};
