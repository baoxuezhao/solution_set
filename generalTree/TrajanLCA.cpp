#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 100

struct Node
{
	Node *left, *right;
	int val;
	Node(int v): val(v){};
};

int father[MAXN];
int rank[MAXN];
int anc[MAXN];
bool visited[MAXN] = {false};

void make_set(int x)
{
	father[x] = x;
	rank[x] = 0;
}

int find(int x)
{
	if(father[x] != x)
	{
		father[x] = find(father[x]);
	}
	return father[x];
}

void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)
		return;

	if(rank[fx] > rank[fy])
		father[fy] = fx;
	else if(rank[fx] < rank[fy])
		father[fx] = fy;
	else
	{
		father[fx] = fy;
		rank[fy]++;
	}
}

void LCATrajan(Node *root, vector<pair<Node*, Node*> > pairs)
{
	make_set(root->val);
	anc[find(root->val)] = root->val;
	if(root->left)
	{
		LCATrajan(root->left, pairs);
		Union(root->val, root->left->val);
		anc[find(root->left->val)] = root->val;
	}
	if(root->right)
	{
		LCATrajan(root->right, pairs);
		Union(root->val, root->right->val);
		anc[find(root->right->val)] = root->val;
	}

	visited[root->val] = true;
	
	for(int i=0; i<pairs.size(); i++)
	{
		if(pairs[i].first == root && visited[pairs[i].second->val])
		{
			cout << (pairs[i].first->val) << "\t" << (pairs[i].second->val) << "\t" << anc[find(pairs[i].second->val)] << endl;
		}
		else if(pairs[i].second == root && visited[pairs[i].first->val])
		{
			cout << (pairs[i].first->val) << "\t" << (pairs[i].second->val) << "\t" << anc[find(pairs[i].first->val)] << endl;	
		}
	}
}


int main()
{
	// Let us create binary tree given in the above example
	Node * root = new Node(1);

	Node *t2 = new Node(2);
	Node *t3 = new Node(3);
	Node *t4 = new Node(4);
	Node *t5 = new Node(5);
	Node *t6 = new Node(6);
	Node *t7 = new Node(7);

	root->left = t2;
	root->right = t3;
	root->left->left = t4;
	root->left->right = t5;
	root->right->left = t6;
	root->right->right = t7;

	vector<pair<Node*, Node*> > query;
	query.push_back(make_pair(t4, t5));
	query.push_back(make_pair(t4, t6));
	query.push_back(make_pair(t4, t3));
	query.push_back(make_pair(t2, t4));

	LCATrajan(root, query);
}
