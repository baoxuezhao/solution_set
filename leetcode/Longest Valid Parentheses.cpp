class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        int f[n+1];
        memset(f, 0, sizeof(f));
        
        f[0] = 0;
        for(int i=1; i<=n; i++)
        {
            if(s[i-1] == '(')
                f[i] = 0;
            else
            {
                int len = f[i-1];
                int mirror = i-len-1;
                if(mirror >= 1 && s[mirror-1] == '(')
                {
                    f[i] = f[i-1]+2;
                    if(mirror-1 >= 0)
                        f[i] += f[mirror-1];
                }
                else
                    f[i] = 0;
            }
        }
        
        int longest = 0;
        for(int i=0; i<=n; i++)
            longest = max(longest, f[i]);
        return longest;
    }
};
