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

typedef vector<TreeNode*>::iterator child_iter;

void root2LeafPath(TreeNode *root)
{
	if(root == NULL) return;
	string path;
	vector<pair<TreeNode*, child_iter> > stack;

	stack.push_back(make_pair(root, root->children.begin()));
	path.push_back(root->val);

	while(!stack.empty())
	{
		TreeNode *cur = stack.back().first;
		child_iter iter = stack.back().second;

		if(iter == cur->children.begin() && cur->children.size() == 0)
		{
			cout << path << endl;
		}

		if(iter != cur->children.end())
		{
			stack.back().second++;
			stack.push_back(make_pair(*iter, (*iter)->children.begin()));
			path.push_back((*iter)->val);
		}
		else
		{
			stack.pop_back();
			path.erase(path.size()-1);
		}
	}
}

void root2LeafPathDFS(TreeNode *root, string &path)
{
	if(root == NULL) return;

	path.push_back(root->val);
	if(root->children.size() == 0)
		cout << path << endl;

	for(int i=0; i<root->children.size(); i++)
	{
		root2LeafPathDFS(root->children[i], path);
	}

	path.erase(path.size()-1);
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

	root2LeafPath(na);
	cout << endl;
	
	string s;
	root2LeafPathDFS(na, s);
	return 0;
}
