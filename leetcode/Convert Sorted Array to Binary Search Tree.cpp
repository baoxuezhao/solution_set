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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        const int n = num.size();
        return convert(num, 0, n-1);
    }
    
    TreeNode *convert(vector<int> &num, int left, int right)
    {
        if(left > right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = convert(num, left, mid-1);
        root->right = convert(num, mid+1, right);
        return root;
    }
};
