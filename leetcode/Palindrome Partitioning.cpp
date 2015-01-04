//dp + dfs
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        
        for(int len=2; len<=n; len++)
        {
            for(int start = 0; start+len <=n; start++)
            {
                int end = start+len-1;
                dp[start][end] = (len == 2)? (s[start] == s[end]): (dp[start+1][end-1] && s[start] == s[end]);
            }
        }
        
        vector<int> prev[n+1];
        bool dp2[n+1];
        memset(dp2, false, sizeof(dp2));
        dp2[0] = true;
        
        for(int i=0; i<n; i++)
        {
            for(int j=-1; j<i; j++)
            {
                if(dp2[j+1] && dp[j+1][i])
                {
                    prev[i+1].push_back(j);
                    dp2[i+1] = true;
                }
            }
        }
        
        vector<vector<string> > res;
        vector<string> path;
        dfs(n-1, res, prev, path, s);
        return res;
    }
    
    void dfs(int idx, vector<vector<string> > &res, vector<int> prev[], vector<string> &path, string &s)
    {
        if(idx == -1)
        {
            res.push_back(path);
            reverse(res.back().begin(), res.back().end());
        }
        else
        {
            vector<int> &p = prev[idx+1];
            for(int i=0; i<p.size(); i++)
            {
                string sub = s.substr(p[i]+1, idx-p[i]);
                path.push_back(sub);
                dfs(p[i], res, prev, path, s);
                path.pop_back();
            }
        }
    }
};
