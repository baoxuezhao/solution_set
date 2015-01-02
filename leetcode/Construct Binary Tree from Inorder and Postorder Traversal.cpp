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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() != postorder.size() || inorder.size() == 0)
            return NULL;
        
        return build(inorder, 0, postorder, 0, inorder.size());
    }
    
    TreeNode *build(vector<int> &in, int instart, vector<int> &post, int poststart, int len)
    {
        if(len == 0) return NULL;
        
        int r = post[poststart + len-1];
        int i;
        for(i=instart; i<instart+len; i++)
        {
            if(in[i] == r)
                break;
        }
        TreeNode *root = new TreeNode(r);
        int left_len = i-instart;
        int right_len = len-left_len-1;
        
        TreeNode *left = build(in, instart, post, poststart, left_len);
        TreeNode *right = build(in, i+1, post, poststart+left_len, right_len);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};
