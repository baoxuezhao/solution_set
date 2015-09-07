//1. O(k) algorithm

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        TreeNode *target = NULL;
        inorder(root, val, k, target);
        return target->val;
    }
    
    void inorder(TreeNode *root, int &val, int k, TreeNode *&target) {
        if (root == NULL || target != NULL) return;
        inorder(root->left, val, k, target);
        val++;
        if (val == k) {
            target = root;
        }
        inorder(root->right, val, k, target);
    }
};

//2. order statistics O(logn)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int total = get_count(root);
        TreeNode *cur = root;
    
        while (cur) {
            int ll = (cur->left)?node_count[cur->left]:0;
            if (k == ll + 1) {
                return cur->val;
            } else if (k < ll + 1) {
                cur = cur->left;
            } else {
                cur = cur->right;
                k = k-ll-1;
            }   
        }
        return -1;
    }
    
    int get_count(TreeNode* root) {
        if (root == NULL) return 0;
        int ll = get_count(root->left);
        int rr = get_count(root->right);
        node_count[root] = ll + rr + 1;
        return ll + rr + 1;
    }
    
    unordered_map<TreeNode*, int> node_count;
};


