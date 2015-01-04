//solution 1, O(1) space and O(logn) time

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
        cur = leftmost(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int val = cur->val;
        if(cur->right)
            cur = leftmost(cur->right);
        else
        {
            TreeNode *p = root, *pp = NULL;
            while(p)
            {
                if(p->val < cur->val)
                    p = p->right;
                else if(p->val > cur->val)
                {
                    pp = p;
                    p = p->left;
                }
                else
                    break;
            }
            cur = pp;
        }
        return val;
    }
    
    TreeNode *leftmost(TreeNode *r)
    {
        if(!r) return NULL;
        while(r->left) r = r->left;
        return r;
    }

private:
    TreeNode *root;
    TreeNode *cur;
};
 
 
 //solution 2, O(logN) space and O(1) time
 
 class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushleft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = s.top();
        s.pop();
        pushleft(cur->right);
        return cur->val;
    }
    
    void pushleft(TreeNode *r)
    {
        while(r)
        {
            s.push(r);
            r = r->left;
        }
    }

private:
    stack<TreeNode*> s;
};
