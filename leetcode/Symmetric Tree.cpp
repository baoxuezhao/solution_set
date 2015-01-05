//recursion algo.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        return (r1->val == r2->val 
            && isSymmetric(r1->left, r2->right) 
            && isSymmetric(r1->right, r2->left));
    }
};

//iteration algo.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        
        if(!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        TreeNode *left, *right;
        
        while(!s.empty())
        {
            left = s.top(); s.pop();
            right= s.top(); s.pop();
            
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            
            s.push(left->left);
            s.push(right->right);
            
            s.push(left->right);
            s.push(right->left);
        }
        return true;
    }
};
