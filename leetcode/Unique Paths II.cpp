class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = obstacleGrid[0][0]?0:1;
        for(int i=1; i<n; i++)
        {
            if(obstacleGrid[0][i] == 0)
                dp[i] = dp[i-1];
            else
                dp[i] = 0;
        }
        
        for(int i=1; i<m; i++)
        {
            dp[0] = obstacleGrid[i][0]? 0 : dp[0];
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[i][j])
                    dp[j] = 0;
                else
                    dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
