//solution 1
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S, path, res, 0);
        return res;
    }
    
    void dfs(vector<int> &S, vector<int> &path, vector<vector<int> > &res, int idx)
    {
        res.push_back(path);
        if(idx >= S.size()) return;
        
        for(int i=idx; i<S.size(); i++)
        {
            if(i > idx && S[i] == S[i-1]) continue;
            path.push_back(S[i]);
            dfs(S, path, res, i+1);
            path.pop_back();
        }
    }
};

//solution 2
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res(1);
        
        int prev_size = 0;
        for(int i=0; i<S.size(); i++)
        {
            const int size = res.size();
            for(int j=0; j<size; j++)
            {
                if(i == 0 || S[i] != S[i-1] || j >= prev_size)
                {
                    res.push_back(res[j]);
                    res.back().push_back(S[i]);
                }
            }
            prev_size = size;
        }
        return res;
    }
};
