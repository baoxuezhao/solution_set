#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

void minimumSubstr(string s, string t)
{
	int m = s.size(), n = t.size();

	int midx = -1;
	int dp[m+1][n+1];
	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;
	for(int i=1; i<m; i++)
		dp[i][0] = 0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(s[i-1] == t[j-1] && dp[i-1][j-1] != -1)
				dp[i][j] = dp[i-1][j-1]+1;
			else if(dp[i-1][j] != -1)
				dp[i][j] = dp[i-1][j]+1;
		}
		if(dp[i][n] >= 0 && (midx == -1 || dp[i][n] < dp[midx][n]))
		{
			midx = i;
		}
	}
	cout << "min index " << midx-1 << "\t" << dp[midx][n] << endl;
	if(midx != -1)
		cout << s.substr(midx-dp[midx][n], dp[midx][n]) << endl;

}

int main()
{
	minimumSubstr("avvvvb", "ab");
	minimumSubstr("UAXXBAUB", "AB");
	minimumSubstr("UAXSSXSXAAUB", "XXA");
	return 0;
}
