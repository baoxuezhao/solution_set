class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        if(n <= 1) return 0;
        
        vector<vector<bool> > f(n, vector<bool>(n, false));
        
        for(int len=1; len<=n; len++)
        {
            for(int start=0; start+len-1<n; start++)
            {
                int end = start+len-1;
                f[start][end] = (len == 1) || 
                                (len == 2 && s[start] == s[end]) || 
                                (s[start] == s[end] && f[start+1][end-1]);
            }
        }
        
        vector<int> mincut(n, INT_MAX);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(!f[j][i]) continue;
                
                mincut[i] = (j==0)?0:min(mincut[i], mincut[j-1]+1);
            }
        }
        return mincut[n-1];
    }
};
