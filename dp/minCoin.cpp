#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int minCoin(int A[], int k, int n)
{
	int dp[k+1][n+1];
	int prev[k+1][n+1][2];

	memset(dp, 0, sizeof(dp));
	memset(prev, 0, sizeof(prev));

	dp[1][1] = 1;
	prev[1][1][0] = 1;
	prev[1][1][1] = 1;

	for(int j=2; j<=n; j++)
	{
		dp[1][j] = j;
		prev[1][j][0] = 1;
		prev[1][j][0] = j-1;
	}

	for(int i=1; i<=k; i++)
	{
		dp[i][0] = 0;
		prev[i][0][0] = i;
		prev[i][0][1] = 0;
	}

	for(int i=2; i<=k; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j] = dp[i-1][j];
			
			prev[i][j][0] = i-1;
			prev[i][j][1] = j;

			if(j >= A[i-1])
			{
				if(dp[i][j-A[i-1]]+1 < dp[i][j])
				{
					dp[i][j] = dp[i][j-A[i-1]]+1;
					prev[i][j][0] = i;
					prev[i][j][1] = j-A[i-1];
				}
			}
		}
	}

	int i = k;
	int j = n;
	
	while(i != prev[i][j][0] || j != prev[i][j][1])
	{
		int newi = i;
		int newj = j;
		
		if(j != prev[i][j][1])
		{
			cout << j-prev[i][j][1] << " ";
		}

		i = prev[newi][newj][0];
		j = prev[newi][newj][1];
	}
	cout << endl;

	return dp[k][n];
}

int main()
{
	int A[] = {1, 5, 8};

	for(int i=1; i<=26; i++)
	{
		int res = minCoin(A, 3, i);
		cout << i << "\t" << res << endl;
	}
	return 0;
}
