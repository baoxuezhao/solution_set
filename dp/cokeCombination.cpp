#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define NUM 3

int main()
{
	int low[3], high[3];
	int n;
	for(int i=0; i<NUM; i++)
	{
		scanf("%d%d", &low[i], &high[i]);
	}
	scanf("%d", &n);

	vector<bool> dp(n+1, false);

	dp[0] = true;

	for(int i=1; i<=n; i++)
	{
		if(dp[i]) continue;
		for(int j=0; j<i; j++)
		{
			int extra = i-j;
			if(!dp[j]) continue;

			for(int k=0; k<NUM; k++)
			{
				if(extra >= low[k] && extra <= high[k])
					dp[i] = true;
			}
		}
	}

	for(int i=0; i<=n; i++)
	{
		printf("%d\t%s\n", i, dp[i]?"true":"false");
	}
	return 0;
}
