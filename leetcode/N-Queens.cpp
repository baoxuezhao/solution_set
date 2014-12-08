class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> path;
        
        dfs(path, result, n);
        return result;
    }
    
    void dfs(vector<int> &path, vector<vector<string> > &result, int n)
    {
        if(path.size() == n)
        {
            result.push_back(gen(path, n));
            return;
        }
        int curline = path.size();
        
        for(int i=0; i<n; i++)
        {
            bool valid = true;
            for(int j=0; j<path.size(); j++)
            {
                if(path[j] == i || abs(path[j]-i) == abs(curline-j))
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                path.push_back(i);
                dfs(path, result, n);
                path.pop_back();
            }
        }
    }
    
    vector<string> gen(vector<int> &path, int n)
    {
        vector<string> res;
        for(int i=0; i<n; i++)
        {
            string line(n, '.');
            line[path[i]] = 'Q';
            res.push_back(line);
        }
        return res;
    }
};
