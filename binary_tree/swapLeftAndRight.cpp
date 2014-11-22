#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int value;
	TreeNode(int val): value(val){};
};

bool isOK(TreeNode *root1, TreeNode *root2)
{
	if(!root1 && !root2)
		return true;
	if(!root1 || !root2)
		return false;

	if(root1->value != root2->value)
		return false;

	bool res1 = isOK(root1->left, root2->left) && isOK(root1->right, root2->right);
	bool res2 = isOK(root1->left, root2->right) && isOK(root1->right, root2->left);

	return (res1 || res2);
}

int main()
{
	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);
	root1->left->left = new TreeNode(4);
	root1->left->right= new TreeNode(5);

	TreeNode *root2 = new TreeNode(1);
	root2->left = new TreeNode(3);
	root2->right = new TreeNode(2);
	root2->right->left = new TreeNode(5);
	root2->right->right= new TreeNode(4);

	cout << isOK(root1, root2) << endl;
	cout << isOK(root1, NULL) << endl;
	cout << isOK(NULL, NULL) << endl;

	TreeNode *root3 = new TreeNode(1);
	TreeNode *root4 = new TreeNode(1);
	root3->left = new TreeNode(5);
	root4->right = new TreeNode(5);
	
	cout << isOK(root3, root4) << endl;
	return 0;
}
