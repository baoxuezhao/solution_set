#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	int count;
	TreeNode(int val){ this->val = val; count = 1;}
};

TreeNode* buildbst_util(vector<int> &vec, int l, int r)
{
	if(l > r) return NULL;
	int mid = l + (r-l)/2;
	TreeNode *root = new TreeNode(vec[mid]);
	root->left = buildbst_util(vec, l, mid-1);
	root->right = buildbst_util(vec, mid+1, r);
	
	if(root->left)
		root->count += root->left->count;
	if(root->right)
		root->count += root->right->count;

	return root;
}

TreeNode* build(vector<int> &vec)
{
	return buildbst_util(vec, 0, vec.size()-1);
}

int rank(TreeNode *root, int v)
{
	int res = 0;
	TreeNode *cur = root;
	while(cur)
	{
		if(v < cur->val)
		{
			cur = cur->left;
		}
		else
		{
			res += (cur->left?cur->left->count: 0)+1;
			if(v == cur->val) break;
			cur = cur->right;
		}
	}
	return res;
}

TreeNode *select(TreeNode *root, int k)
{
	if(root == NULL) return NULL;
	
	int r = root->left?root->left->count : 0;
	if(k == r)
		return root;
	else if(k < r)
		return select(root->left, k);
	else
		return select(root->right, k-(r+1));
}

int main()
{
	vector<int> array;
	for(int i=1; i<100; i+=3)
		array.push_back(i);

	TreeNode *root = build(array);

	for(int i=1; i<100; i+=3)
	{
		//cout << rank(root, i) << endl;
	}

	for(int i=0; i<33; i++)
	{
		cout << select(root, i)->val << endl;
	}
	return 0;
}
