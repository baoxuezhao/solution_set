#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &matrix, 
	vector<vector<bool> > &visit, int i, int j, int &count)
{
	const int m = matrix.size();
	const int n = matrix[0].size();

	if(i<0 || i>=m || j<0 || j>=n)
		return;
	if(visit[i][j] || matrix[i][j] == 0)
		return;

	count++;
	visit[i][j] = true;
	dfs(matrix, visit, i-1, j  , count);
	dfs(matrix, visit, i  , j-1, count);
	dfs(matrix, visit, i  , j+1, count);
	dfs(matrix, visit, i+1, j  , count);
	visit[i][j] = false;
}

//assume four-connection
int numOfConnectedOne(vector<vector<int> > &matrix, int i, int j)
{
	const int m = matrix.size();
	const int n = matrix[0].size();

	int count = 0;
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	dfs(matrix, visit, i, j, count);
	return count;
}

int main()
{
	vector<vector<int> > matrix = 
	{
		{1, 0, 1, 1, 1},
		{0, 1, 1, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0},
		{0, 0, 1, 1, 1}
	};

	cout << numOfConnectedOne(matrix, 0, 0) << endl;
	cout << numOfConnectedOne(matrix, 0, 1) << endl;
	cout << numOfConnectedOne(matrix, 1, 1) << endl;
	cout << numOfConnectedOne(matrix, 8, 8) << endl;
	cout << numOfConnectedOne(matrix, 4, 4) << endl;
	cout << numOfConnectedOne(matrix, 2, 0) << endl;
	return 0;
}
