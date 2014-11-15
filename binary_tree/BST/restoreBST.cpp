#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v){}
};

TreeNode *restore(int min, int max, int &idx, vector<int> array)
{
	if(idx >= array.size())
		return NULL;

	int val = array[idx];
	if(val > min && val < max)
	{
		idx++;
		TreeNode *cur = new TreeNode(val);
		cur->left = restore(min, val, idx, array);
		cur->right = restore(val, max, idx, array);
		return cur;
	}
	return NULL;
}

int main()
{
	int A[] = {30, 20, 10, 40, 35, 50};
	vector<int> array(A, A+6);
	int idx = 0;
	TreeNode *root = restore(INT_MIN, INT_MAX, idx, array);

	cout << root->val << endl;
	cout << root->left->val << endl;;
	cout << root->left->left->val << endl;

	cout << root->right->val << endl;
	cout << root->right->left->val << endl;
	cout << root->right->right->val << endl;
	return 0;
}
