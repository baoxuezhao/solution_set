//constant space
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
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        
        vector<int> result;
        while(cur)
        {
            if(cur->left == NULL)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *tmp = cur->left;
                while(tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
                
                if(tmp->right == NULL)
                {
                    tmp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    tmp->right = NULL;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
