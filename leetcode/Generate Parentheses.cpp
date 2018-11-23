//Solution 1, dp. time efficient
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n+1];
        dp[0].push_back("");
        dp[1].push_back("()");
        
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                vector<string> inner = dp[j];
                vector<string> outter = dp[i-j-1];
                for(auto str1: inner)
                {
                    for(auto str2: outter)
                    {
                        dp[i].push_back("(" + str1 + ")" + str2);
                    }
                }
            }
        }
        
        return dp[n];
    }
};


//Solution 2, recursion. space efficient
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path(2*n, ' ');
        vector<string> res;
        generate(path, res, 0, 0, 0, n);
        return res;
    }
    
    void generate(string &s, vector<string> &res, int pos, int open, int close, int n)
    {
        if(pos == 2*n)
        {
            if(open == close)
                res.push_back(s);
        }
        else if(pos < 2*n)
        {
            if(open > close)
            {
                s[pos] = ')';
                generate(s, res, pos+1, open, close+1, n);
            }
            if(open < n)
            {
                s[pos] = '(';
                generate(s, res, pos+1, open+1, close, n);
            }
        }
    }
};

// precise solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        std::string cur;
        dfs(res, cur, 0, 0, n);
        return res;
    }
    
    void dfs(std::vector<string>& res, string cur, int left, int right, int max) {
        if (cur.size() == max * 2) {
            res.push_back(cur);
            return;
        }
        if (left < max) {
            dfs(res, cur + "(", left+1, right, max);
        }
        if (right < left) {
            dfs(res, cur + ")", left, right+1, max);
        }
    }
};
