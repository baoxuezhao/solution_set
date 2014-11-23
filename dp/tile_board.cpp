#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_W 12
#define MAX_H 12

int width, height;
long long dp[MAX_H][(1<<MAX_W)];

bool firstLineOK(int status)
{
	int idx = 0;
	while(idx < width)
	{
		if(status & (0x1 << idx))
		{
			if(idx+1 >= width || !(status & (0x1 << (idx+1))))
				return false;
			else
				idx += 2;
		}
		else
		{
			idx += 1;
		}
	}
	return true;
}


bool testCapability(int status1, int status2)
{
	int idx = 0;

	while(idx < width)
	{
		if((status1 & (1 << idx)) == 0)
		{
			if((status2 & (1 << idx)) == 0)
				return false;
			else
				idx++;
		}
		else
		{
			if((status2 & (1 << idx)) == 0)
			{
				idx++;
			}
			else
			{
				if(idx < width-1 && (status1 & (1 << (idx+1))) && (status2 & (1 << (idx+1))))
				{
					idx += 2;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}


int main()
{
	cin >> width >> height;

	int allStatus = (1<<width);
	memset(dp, 0, sizeof(dp));

	vector<vector<int> > result[height];

	for(int i=0; i<allStatus; i++)
	{
		if(firstLineOK(i))
		{
			vector<int> vec;
			vec.push_back(i);
			result[0].push_back(vec);

			dp[0][i] = 1;
		}
		else
			dp[0][i] = 0;

	}

	for(int h = 1; h < height; h++)
	{
		vector<vector<int> > &lastLevel = result[h-1];

		for(int i = 0; i<lastLevel.size(); i++)
		{
			int laststatus = lastLevel[i][h-1];

			for(int j=0; j<allStatus; j++)
			{
				if(testCapability(j, laststatus))
				{
					dp[h][j] += 1;//dp[h-1][laststatus];
					vector<int> curlevel(lastLevel[i].begin(), lastLevel[i].end());
					curlevel.push_back(j);
					result[h].push_back(curlevel);
				}
			}
		}
	}

	cout << dp[height-1][allStatus-1] << endl;

	int count = 0;
	for(int i=0; i<result[height-1].size(); i++)
	{
		if(result[height-1][i][height-1] != allStatus-1)
			continue;

		count++;

		for(int j=0; j<height; j++)
		{
			for(int k=0; k<width; k++)
			{
				cout << ((result[height-1][i][j] & (1 << k)) != 0) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << count << endl;
	return 0;
}
