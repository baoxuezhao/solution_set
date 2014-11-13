#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val): value(val){};
};

class InorderIterator
{
public:
    InorderIterator(TreeNode* root)
    {
        TreeNode *cur = root;
        while(cur)
        {
            stack1.push(cur);
            cur = cur->left;
        }
    }

    TreeNode *getNext()
    {
        if(stack1.empty())
            return NULL;

        TreeNode *cur = stack1.top();
        stack1.pop();

        TreeNode *cur1 = cur->right;
        while(cur1)
        {
            stack1.push(cur1);
            cur1 = cur1->left;
        }
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

    InorderIterator *iter = new InorderIterator(root);
    TreeNode *cur = iter->getNext();
    while(cur)
    {
        cout << cur->value << endl;
        cur = iter->getNext();
    }
    return 0;
}
