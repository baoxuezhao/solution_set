#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int stamps[4] = {7, 11, 23, 47};

void choice(const int fee, int k)
{
	vector<int> dp(fee+1, INT_MAX);
	vector<int> trace(fee+1, -1);
	dp[0] = 0;
	trace[0] = 0;

	for(int i=0; i<k; i++)
	{
		dp[stamps[i]] = stamps[i];
		trace[stamps[i]] = 0;
	}

	for(int i=1; i<=fee; i++)
	{
		for(int j=0; j<k; j++)
		{
			if(i-stamps[j] >= 0)
			{
				if(dp[i-stamps[j]] + stamps[j] < dp[i])
				{
					dp[i] = dp[i-stamps[j]] + stamps[j];
					trace[i] = i-stamps[j];
				}
			}
			else
			{
				if(stamps[j] < dp[i])
				{
					dp[i] = stamps[j];
					trace[i] = 0;
				}
			}
		}
	}

	for(int cur=1; cur<=fee; cur++)
	{
		cout << cur << "-> " << dp[cur] << " : [";

		int i = cur;
		while(trace[i] != i)
		{
			cout << dp[i]-dp[trace[i]] << ", ";
			i = trace[i];
		}
		cout << "]" << endl;
	}
}


int main()
{
	choice(248, 4);
	return 0;
}
