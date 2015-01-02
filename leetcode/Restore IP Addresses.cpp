class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }
    
    void dfs(string &s, int pos, vector<string> &path, vector<string> &res)
    {
        if(pos == s.size())
        {
            if(path.size() == 4)
            {
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." +  path[3]);
            }
        }
        else
        {
            int len = (int)s.size()-pos;
            for(int i=1; i<=min(3,len); i++)
            {
                if(i > 1 && s[pos] == '0') continue;
                int v = atoi1(s.substr(pos, i));
                if(v <= 255 && v >= 0 && path.size() < 4)
                {
                    path.push_back(s.substr(pos, i));
                    dfs(s, pos+i, path, res);
                    path.pop_back();
                }
            }
        }
    }
    
    
    int atoi1(string s)
    {
        int v = 0;
        for(int i=0; i<s.size(); i++)
        {
            v = v*10 + (s[i]-'0');
        }
        return v;
    }
};
