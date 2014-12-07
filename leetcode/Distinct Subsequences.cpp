class Solution {
public:
    int numDistinct(string S, string T) {
        const int n1 = S.size();
        const int n2 = T.size();
        
        int f[n1+1][n2+1];
        f[0][0] = 1;
        
        for(int j=1; j<=n2; j++)
            f[0][j] = 0;
        
        for(int i=1; i<=n1; i++)
        {
            f[i][0] = 1;
            for(int j=1; j<=n2; j++)
            {
                f[i][j] = f[i-1][j];
                if(S[i-1] == T[j-1])
                    f[i][j] += f[i-1][j-1];
            }
        }
        return f[n1][n2];
    }
};
