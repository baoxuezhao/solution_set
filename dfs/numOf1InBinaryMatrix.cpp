#include <iostream>
#include <vector>
#include <queue>

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
int numOfConnectedOneDFS(vector<vector<int> > &matrix, int i, int j)
{
	const int m = matrix.size();
	const int n = matrix[0].size();

	int count = 0;
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	dfs(matrix, visit, i, j, count);
	return count;
}


int numOfConnectedOneBFS(vector<vector<int> > &matrix, int i, int j)
{
	const int m = matrix.size();
	const int n = matrix[0].size();

	int count = 0;
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	queue<pair<int,int> > Q;
	Q.push(make_pair(i, j));

	while(!Q.empty())
	{
		pair<int, int> p = Q.front();
		Q.pop();
		if(p.first >= m || p.first < 0 || p.second >= n || p.second < 0)
			continue;
		if(visit[p.first][p.second] || matrix[p.first][p.second] == 0)
			continue;

		count++;
		visit[p.first][p.second] = true;

		Q.push(make_pair(p.first, p.second+1));
		Q.push(make_pair(p.first, p.second-1));
		Q.push(make_pair(p.first-1, p.second));
		Q.push(make_pair(p.first+1, p.second));
	}

	return count;
}

int numOfConnectedOneBFS_Parallel(vector<vector<int> > &matrix, int i, int j)
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

	cout << numOfConnectedOneDFS(matrix, 0, 0) << endl;
	cout << numOfConnectedOneBFS(matrix, 0, 0) << endl;

	cout << numOfConnectedOneDFS(matrix, 0, 1) << endl;
	cout << numOfConnectedOneBFS(matrix, 0, 1) << endl;

	cout << numOfConnectedOneDFS(matrix, 1, 1) << endl;
	cout << numOfConnectedOneBFS(matrix, 1, 1) << endl;

	cout << numOfConnectedOneDFS(matrix, 8, 8) << endl;
	cout << numOfConnectedOneBFS(matrix, 8, 8) << endl;

	cout << numOfConnectedOneDFS(matrix, 3, 4) << endl;
	cout << numOfConnectedOneBFS(matrix, 3, 4) << endl;

	cout << numOfConnectedOneDFS(matrix, 4, 4) << endl;
	cout << numOfConnectedOneBFS(matrix, 4, 4) << endl;

	cout << numOfConnectedOneDFS(matrix, 2, 0) << endl;
	cout << numOfConnectedOneBFS(matrix, 2, 0) << endl;

	return 0;
}
