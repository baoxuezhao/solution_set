//find the change scheme with the sum NO LESS than n using a set of m coins,
//print the combination as well.
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int solve(int coin[], int m, int n)
{
	int dp[m+1][n+1];
	int usage[m+1][n+1][m];

	memset(dp, 0, sizeof(dp));
	memset(usage, 0, sizeof(usage));

	for(int i=0; i<=m; i++)
		dp[i][0] = 0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i == 1)
			{
				dp[i][j]=(j+coin[0]-1)/coin[0]*coin[0]; //only use the first coin
				usage[i][j][0] = dp[i][j]/coin[0];
			}
			else
			{
				int x = (j<coin[i-1])? 0:dp[i][j-coin[i-1]];
				int y = dp[i-1][j];

				if(x + coin[i-1] < y)
				{
					dp[i][j] = x + coin[i-1];
					usage[i][j][i-1] += 1;
					if(j >= coin[i-1])
					{
						for(int k=0; k<=i-1; k++)
							usage[i][j][k] += usage[i][j-coin[i-1]][k];
					}
				}
				else
				{
					dp[i][j] = y;
					for(int k=0; k<i-1; k++)
						usage[i][j][k] += usage[i-1][j][k];
				}
			}
		}
	}

	for(int i=0; i<m; i++)
		cout << usage[m][n][i] << " ";
	cout << endl;
	return dp[m][n];
}

int main()
{
	int coin[] = {7, 11, 23, 47};

	int res = solve(coin, 4, 248);
	cout << res << endl;

	return 0;
}
