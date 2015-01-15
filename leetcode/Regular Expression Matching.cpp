class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == 0) return *s == 0;
        
        if(*(p+1) != '*')
        {
            if((*p == '.' && *s != 0) || (*s == *p))  //??? becareful
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            while(true)
            {
                if(isMatch(s, p+2)) return true;
                if((*p == '.' && *s != 0) || (*s == *p))
                    s++;
                else
                    break;
            }
        }
        return false;
    }
};


//dynamic programming
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
            
        if (*p == 0) return *s == 0;  //empty
        
        const int n = strlen(s);
        const int m = strlen(p);
        
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        
        for(int i=1; i<=m; i++)
        {
            dp[0][i] = (i>=2 && p[i-1] == '*') && dp[0][i-2];
        }
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = dp[i][j] || ((s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1]);
                dp[i][j] = dp[i][j] || (j-2 >= 0 && p[j-1] == '*' && dp[i][j-2]);
                dp[i][j] = dp[i][j] || (j-2 >= 0 && p[j-1] == '*' && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};
