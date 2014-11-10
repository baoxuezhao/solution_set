/**
*
给你一棵树的根， 比如节点A。
   A
   / \
  B*  C
 / \  |
D  E  F

要求删除树中的部分node。比如删除B，结果如下。
    A
  / | \
 D  E  C
          |
         F

给你的数据结构如下
Node {
    boolean shouldRemove(); // return true if this node needs to be removed    
}

剩下如何删除，需要什么method，自己讨论和定义。
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	char value;
	bool shouldRemove;
	vector<TreeNode*> child;

	TreeNode(char val, bool remove): value(val), shouldRemove(remove){};
};

vector<TreeNode*> remove(TreeNode *root)
{
	vector<TreeNode*> res;
	if(root == NULL) return res;

	vector<TreeNode*> child = root->child;

	for(int i=0; i<child.size(); i++)
	{
		vector<TreeNode*> cur = remove(child[i]);
		res.insert(res.end(), cur.begin(), cur.end());
	}

	if(root->shouldRemove)
		return res;
	else
	{
		vector<TreeNode*> self;
		self.push_back(root);
		root->child = res;
		return self;
	}
}

void print(TreeNode *root)
{
	cout << "current value " << root->value << endl;
	for(int i=0; i<root->child.size(); i++)
	{
		cout << "child of " << root->value << ": " << root->child[i]->value << endl;
	}

	for(int i=0; i<root->child.size(); i++)
	{
		print(root->child[i]);
	}
}

int main()
{
	TreeNode *nodeA = new TreeNode('A', false);
	TreeNode *nodeB = new TreeNode('B', true);
	TreeNode *nodeC = new TreeNode('C', false);
	TreeNode *nodeD = new TreeNode('D', false);
	TreeNode *nodeE = new TreeNode('E', false);
	TreeNode *nodeF = new TreeNode('F', false);
	TreeNode *nodeG = new TreeNode('G', false);
	TreeNode *nodeH = new TreeNode('H', false);

	nodeA->child.push_back(nodeB);
	nodeA->child.push_back(nodeC);
	nodeB->child.push_back(nodeD);
	nodeB->child.push_back(nodeE);
	nodeC->child.push_back(nodeF);
	nodeD->child.push_back(nodeG);
	nodeD->child.push_back(nodeH);

	vector<TreeNode*> res = remove(nodeA);

	cout << res.size() << endl;

	TreeNode *root = res[0];
	print(root);

	return 0;
}
