class Solution {
public:
    int totalNQueens(int n) {
        vector<int> path;
        int result = 0;
        dfs(path, result, n);
        return result;
    }
    
    void dfs(vector<int> &path, int &result, int n)
    {
        if(path.size() == n)
        {
            result++;
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
};
