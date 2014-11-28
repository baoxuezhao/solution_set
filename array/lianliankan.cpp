//合法条件一,没有可以消掉的宝石,合法条件二,做一次操作后就有宝石可以消掉.
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0,  0, 1, -1};

int check(vector<vector<int> > &board, int i, int j, int k)
{
	const int m = board.size();
	const int n = board[0].size();

	for(int r = max(i-k+1,0); r <= i; r++)
	{
		bool canEliminate = true;
		for(int x=r; x<r+k; x++)
		{
			if(x >= m)
			{
				canEliminate = false;
				break;
			}
			if(x > r && board[x][j] != board[x-1][j])
			{
				canEliminate = false;
				break;
			}
		}
		if(canEliminate) return true;
	}

	for(int c = max(j-k+1,0); c <= j; c++)
	{
		bool canEliminate = true;
		for(int x=c; x<c+k; x++)
		{
			if(x >= n)
			{
				canEliminate = false;
				break;
			}
			if(x > c && board[i][x] != board[i][x-1])
			{
				canEliminate = false;
				break;
			}
		}
		if(canEliminate) return true;
	}
	return false;
}

void print(vector<vector<int> > &board)
{
	const int m = board.size();
	const int n = board[0].size();

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%3d", board[i][j]);
		}
		cout << endl;
	}
}

int canEliminate(vector<vector<int> > &board, int k)
{
	const int m = board.size();
	const int n = board[0].size();

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(check(board, i, j, k))
			{
				cout << i << " " << j << endl;
				return false;
			}
		}
	}

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int t=0; t<4; t++)
			{
				int ii = i+dx[t];
				int jj = j+dy[t];
				if(ii < 0 || ii >= m || jj < 0 || jj >= n)
					continue;
				swap(board[i][j], board[ii][jj]);
				if(check(board, i, j, k))
				{
					cout << i << " " << j << endl;
					print(board);
					return true;
				}
				swap(board[i][j], board[ii][jj]);
			}
		}
	}
	return false;
}

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<int> > board(m, vector<int>(n, 0));

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			board[i][j] = rand()%5;
		}
	}
	print(board);

	int res = canEliminate(board, k);
	cout << res << endl;
	return 0;
}
