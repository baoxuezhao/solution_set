class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int n = s1.size();
        if(n != s2.size()) return false;
        
        bool f[n][n][n+1];
        memset(f, false, sizeof(f));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s1[i] == s2[j]) f[i][j][1] = true;
            }
        }
        
        for(int len=2; len<=n; len++)
        {
            for(int i=0; i+len<=n; i++)
            {
                for(int j=0; j+len<=n; j++)
                {
                    for(int left=1; left<len; left++)
                    {
                        int right = len-left;
                        if(f[i][j][left] && f[i+left][j+left][right])
                        {
                            f[i][j][len] = true;
                            break;
                        }
                        if(f[i][j+right][left] && f[i+left][j][right])
                        {
                            f[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[0][0][n];
    }
};
