class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for(int i=0; i<n; i++)
            dp[i] = 1;
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                dp[j] += dp[j-1];
        }
        return dp[n-1];
    }
};

// 组合解法，注意溢出
class Solution {
public:
    int uniquePaths(int m, int n) {
        return (int)combination(m+n-2, min(n-1,m-1));
    }
    
    long long combination(int m, int n) {
        long long times = 1;
        for (int i=1; i<=n; ++i) {
            times *= (m - i + 1);
            times /= i;
        }
        return times;
    }
};
