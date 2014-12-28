#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;
	Node(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
};

typedef Node TreeNode;

void serialization(Node *root, stringstream &str)
{
	if(root == NULL)
	{
		str << '#' << ' ';
		return;
	}
	str << root->val << ' ';
	serialization(root->left, str);
	serialization(root->right, str);
}

void deserialization(Node *&root, stringstream &in)
{
	char ch;
	
	if (!(in>>ch)) 
		return;
	if(ch == '#')
	{
		root == NULL;
		return;
	}
	else
	{
		in.putback(ch);
		int val;
		in >> val;
		root = new Node(val);
		deserialization(root->left, in);
		deserialization(root->right, in);	
	}
}

int main()
{
	TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    stringstream ss;
    serialization(root, ss);
    cout << ss.str() << endl;
    
    TreeNode *root1;
    deserialization(root1, ss);
    cout << root1->val << endl;
    cout << root1->left->val << endl;
    cout << root1->right->val << endl;
    cout << root1->left->left->val << endl;
    cout << root1->left->right->val << endl;
    cout << root1->right->right->val << endl;
    cout << root1->right->right->right->val << endl;
    return 0;
}
