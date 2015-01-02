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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(preorder.size() != inorder.size() || inorder.size() == 0)
            return NULL;
            
        return build(inorder, 0, preorder, 0, inorder.size());  
    }

    
    TreeNode *build(vector<int> &in, int instart, vector<int> &pre, int prestart, int len)
    {
        if(len == 0) return NULL;
        int r = pre[prestart];
        int i;
        for(i=instart; i<instart+len; i++)
        {
            if(in[i] == r)
                break;
        }
        TreeNode *root = new TreeNode(r);
        int left_len = i-instart;
        int right_len = len-left_len-1;
        
        TreeNode *left = build(in, instart, pre, prestart+1, left_len);
        TreeNode *right = build(in, i+1, pre, prestart+left_len+1, right_len);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};
