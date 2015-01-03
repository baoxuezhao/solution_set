class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i; j>=0; j--)
            {
                if(dp[j] && dict.find(s.substr(j, i-j+1)) != dict.end())
                {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
