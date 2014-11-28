// A C++ program to find the deepest left leaf in a given binary tree
#include <stdio.h>
#include <iostream>
using namespace std;
 
struct Node
{
    int val;
    struct Node *left, *right;
};
 
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}


void deepestRightUtil(Node *root, int curdepth, int &deepest, Node* &result)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        if(curdepth >= deepest)
        {
            deepest = curdepth;
            result = root;
        }
    }
    deepestRightUtil(root->left, curdepth+1, deepest, result);
    deepestRightUtil(root->right, curdepth+1, deepest, result);
}

// A wrapper over deepestLeftLeafUtil().
Node* deepestRight(Node *root)
{
    Node *res;
    int deepest = -1;
    deepestRightUtil(root, 0, deepest, res);
    return res;
}
 
// Driver program to test above function
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->left = newNode(10);
    root->right->right->right->right = newNode(11);
 
    Node *result = deepestRight(root);
    if (result)
        cout << "The deepest rightmost child is " << (result->val) << endl;
    else
        cout << "There is no left leaf in the given tree" << endl;
 
    return 0;
}
