#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val): value(val){};
};

class PostorderIterator
{
public:
    PostorderIterator(TreeNode *root)
    {
        findNextLeaf(root);
    }
    
    bool hasNext()
    {
        return !s.empty();    
    }
    
    TreeNode *getNext()
    {
        if(!hasNext()) return NULL;
        TreeNode *cur = s.top();

        s.pop();
        
        if(!s.empty())
        {
            if(cur == s.top()->left)
                findNextLeaf(s.top()->right);
        }
        return cur;
    }
    
    void findNextLeaf(TreeNode *root)
    {
        while(root != NULL)
        {
            s.push(root);
            if(root->left)
                root = root->left;
            else
                root = root->right;
        }
    }
private:
    stack<TreeNode*> s;
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    PostorderIterator *iter = new PostorderIterator(root);
    TreeNode *cur = iter->getNext();
    while(cur)
    {
        cout << cur->value << endl;
        cur = iter->getNext();
    }
    return 0;
}
