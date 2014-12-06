//idea from:
//http://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
//http://www.cs.usfca.edu/~brooks/S04classes/cs245/lectures/lecture11.pdf
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
	char val;
	vector<TreeNode*> children;

	TreeNode(char c)
	{ val = c; }
};

void serialization(TreeNode *root, string &seq)
{
	if(root == NULL) return;
	seq.push_back(root->val);

	for(int i=0; i<root->children.size(); i++)
	{
		serialization(root->children[i], seq);
	}
	seq.push_back(')');
}

TreeNode *deserialization(string &seq, int& idx)
{
	char cur = seq[idx++];
	if(cur != ')')
	{
		TreeNode *root = new TreeNode(cur);
		TreeNode *ch;
		while((ch = deserialization(seq, idx)) != NULL)
		{
			root->children.push_back(ch);
		}
		return root;
	}
	else
	{
		return NULL;
	}
}


void print(TreeNode *root)
{
	if(root == NULL) return;

	cout << root->val << ": ";
	for(int i=0; i<root->children.size(); i++)
		cout << root->children[i]->val << " ";
	cout << endl;

	for(int i=0; i<root->children.size(); i++)
		print(root->children[i]);
}

int main()
{
	TreeNode *na = new TreeNode('A');
	TreeNode *nb = new TreeNode('B');
	TreeNode *nc = new TreeNode('C');
	TreeNode *nd = new TreeNode('D');
	TreeNode *ne = new TreeNode('E');
	TreeNode *nf = new TreeNode('F');
	TreeNode *ng = new TreeNode('G');
	TreeNode *nh = new TreeNode('H');
	TreeNode *ni = new TreeNode('I');
	TreeNode *nj = new TreeNode('J');
	TreeNode *nk = new TreeNode('K');

	na->children.push_back(nb);
	na->children.push_back(nc);
	na->children.push_back(nd);

	nb->children.push_back(ne);
	nb->children.push_back(nf);

	nd->children.push_back(ng);
	nd->children.push_back(nh);
	nd->children.push_back(ni);
	nd->children.push_back(nj);

	nf->children.push_back(nk);

	//serialization
	string seq;
	serialization(na, seq);

	cout << seq << endl;

	//deserialization
	int idx = 0;
	TreeNode *cur = deserialization(seq, idx);

	print(cur);

	return 0;
}
