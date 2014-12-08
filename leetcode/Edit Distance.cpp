class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.size();
        const int n2 = word2.size();
        
        int f[n1+1][n2+1];
        f[0][0] = 0;
        for(int i=1; i<=n1; i++)
            f[i][0] = i;
        
        for(int j=1; j<=n2; j++)
            f[0][j] = j;
        
        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    f[i][j] = f[i-1][j-1];
                }
                else
                {
                    f[i][j] = f[i-1][j-1]+1;
                    f[i][j] = min(f[i][j], f[i-1][j]+1);
                    f[i][j] = min(f[i][j], f[i][j-1]+1);
                }
            }
        }
        return f[n1][n2];
    }
};
