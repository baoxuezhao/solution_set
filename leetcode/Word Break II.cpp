class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        vector<vector<int> > f(n+1, vector<int>());
        
        for(int i=0; i<n; i++)
        {
            for(int len=1; len <= i+1; len++)
            {
                int start = i-len+1;
                if(dict.find(s.substr(start, len)) != dict.end())
                {
                    f[i].push_back(start-1);
                }
            }
        }
        
        vector<string> result;
        dfs(s, n-1, f, "", result);
        return result;
    }
    
    void dfs(string &s, int idx, vector<vector<int> > &f, string path, vector<string> &result)
    {
        if(idx == -1)
        {
            path.pop_back(); //pop the last " "
            result.push_back(path);
            return;
        }
        vector<int> &vec = f[idx];
        for(int i=0; i<vec.size(); i++)
        {
            string str = s.substr(vec[i]+1, (idx-vec[i]));
            dfs(s, vec[i], f, (str + " " + path), result);
        }
    }
};
