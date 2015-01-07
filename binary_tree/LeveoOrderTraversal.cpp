#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int v) { val = v; }
};

bool printByLevel(TreeNode *root, int level)
{
	if(!root || level < 0) return false;
	if(level == 0)
	{
		cout << root->val << " ";
		return true;
	}
	else
	{
		bool l = printByLevel(root->left, level-1);
		bool r = printByLevel(root->right, level-1);
		return l || r;
	}
}

int getHeight(TreeNode *root)
{
	if(root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right))+1;
}

void levelTraversal1(TreeNode *root)
{
	int height = getHeight(root);
	for(int level=height-1; level>=0; level--)
	{
		if(!printByLevel(root, level)) break;
		cout << endl;
	}
}

void levelZigzag(TreeNode *root)
{
	if(root == NULL) return;
	stack<TreeNode*> s1, s2;
	s1.push(root);
	int level = 0;

	while(!s1.empty())
	{
		TreeNode *cur = s1.top();
		s1.pop();
		cout << cur->val << " ";

		if(level%2 == 0)
		{
			if(cur->left)  s2.push(cur->left);
			if(cur->right) s2.push(cur->right);
			
		}
		else
		{
			if(cur->right)  s2.push(cur->right);
			if(cur->left) s2.push(cur->left);	
		}

		if(s1.empty())
		{
			swap(s1, s2);
			cout << endl;
			level++;
		}
	}
}

int main()
{
	TreeNode *n1 = new TreeNode(1);
	n1->left = new TreeNode(2);
	n1->right = new TreeNode(3);
	n1->left->left = new TreeNode(4);
	n1->left->right = new TreeNode(5);
	n1->left->right->left = new TreeNode(7);
	n1->left->right->right = new TreeNode(8);
	n1->right->right = new TreeNode(6);

	levelTraversal1(n1);

	cout << endl;

	levelZigzag(n1);

	return 0;
}
