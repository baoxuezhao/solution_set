#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val): value(val){};
};

class PreorderIterator
{
public:
    PreorderIterator(TreeNode* root)
    {
        stack1.push(root);
    }

    bool hasNext()
    {
        return !stack1.empty();
    }
    
    TreeNode *getNext()
    {
        if(!hasNext()) return NULL;

        TreeNode *cur = stack1.top();
        stack1.pop();

        if(cur->right)
            stack1.push(cur->right);
        if(cur->left)
            stack1.push(cur->left);

        return cur;
    }

private:
    stack<TreeNode*> stack1;
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

    PreorderIterator *iter = new PreorderIterator(root);
    TreeNode *cur = iter->getNext();
    while(cur)
    {
        cout << cur->value << endl;
        cur = iter->getNext();
    }
    return 0;
}
