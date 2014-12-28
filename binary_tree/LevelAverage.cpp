#include <iostream>
#include <queue>
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

void levelAverage(Node *root)
{
	queue<Node*> q;
	int num1 = 0, num2 = 0;
	q.push(root);
	num1++;

	int sum = 0;
	int count = 0;
	while(!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		num1--;

		sum += cur->val;
		count++;

		if(cur->left)
		{
			q.push(cur->left);
			num2++;
		}
		if(cur->right)
		{
			q.push(cur->right);
			num2++;
		}

		if(num1 == 0)
		{
			cout << sum << "\t" << count << endl;
			sum = 0;
			count = 0;
			swap(num1, num2);
			num2 = 0;
		}
	}
}

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
 
 	levelAverage(root);
 
    return 0;
}
