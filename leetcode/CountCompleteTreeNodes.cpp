/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int ld = 0;
        int rd = 0;

        TreeNode *p = root->left;
        while (p) {
            ld++;
            p = p->left;
        }
        p = root->right;
        while (p) {
            rd++;
            p = p->right;
        }
        if (ld == rd) {
            return (1 << (ld+1)) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
