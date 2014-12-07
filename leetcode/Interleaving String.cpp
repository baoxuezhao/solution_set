class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if(n1 + n2 != n3) return false;
        
        bool f[n1+1][n2+1];
        memset(f, false, sizeof(f));
        
        f[0][0] = true;
        for(int i=1; i<=n1; i++)
            f[i][0] = f[i-1][0] && (s1[i-1] == s3[i-1]);
        
        for(int j=1; j<=n2; j++)
            f[0][j] = f[0][j-1] && (s2[j-1] == s3[j-1]);
        
        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(s3[i+j-1] == s1[i-1])
                    f[i][j] |= f[i-1][j];
                    
                if(s3[i+j-1] == s2[j-1])
                    f[i][j] |= f[i][j-1];
            }
        }
        return f[n1][n2];
    }
};
