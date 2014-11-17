//tree center with minimum path sum to other nodes.
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct TreeNode 
{
  int value;
  int childCount;
  vector<TreeNode*> child;
  TreeNode(int num): value(num) {
    childCount = 1;
  }
};

//sum: the path sum from root to other nodes
TreeNode* buildTree(const vector<pair<int,int> >& edges,
                   vector<int>& visited, 
                   int cur, 
                   int depth, 
                   int& sum) 
{                   
  int size = edges.size(), i;

  TreeNode *node = new TreeNode(cur);

  for (i = 0; i < size; ++i) 
  {
    if (visited[i] == 0 && (edges[i].first == cur || edges[i].second == cur)) 
    {
      visited[i] = 1;
      int next = edges[i].first == cur ? edges[i].second : edges[i].first;
      sum += depth+1;

      TreeNode* nextNode = buildTree(edges, visited, next, depth+1, sum);

      node->child.push_back(nextNode);
      node->childCount += nextNode->childCount;
    }
  }
  return node;
}

void dfs(TreeNode* root, int& minsum, TreeNode*& minroot, int cursum, int totalNode) 
{
  for (int i = 0; i < root->child.size(); ++i) 
  {
    int m = root->child[i]->childCount;
    int sum = cursum - m + (totalNode - m);

    cout << root->child[i]->value << "\t" << sum << endl;
    
    if (sum < minsum)
    {
      minsum = sum;
      minroot = root->child[i];
    }
    dfs(root->child[i], minsum, minroot, sum, totalNode);
  }  
}


int getNode(const vector<pair<int, int> >& edges) 
{
  int size = edges.size(), sum = 0;
  if (size == 0)
    return 0; 
  vector<int> edgevisited(size, 0);
  
  int rootid = edges[0].first;
  TreeNode *root = buildTree(edges, edgevisited, rootid, 0, sum);
  TreeNode *minroot;
  int minsum = sum;
  cout << "sum " << sum << endl;
  dfs(root, minsum, minroot, sum, root->childCount);
  return minroot->value;
}

int main() 
{
  vector<pair<int, int> > edges;
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(0,2));
  edges.push_back(make_pair(4,3));
  edges.push_back(make_pair(1,3));
  edges.push_back(make_pair(1,5));
  edges.push_back(make_pair(6,5));

  int res = getNode(edges);
  cout << res << endl;
  return 0;
}
