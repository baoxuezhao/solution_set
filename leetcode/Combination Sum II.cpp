class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(num.begin(), num.end());
        dfs(num, target, 0, path, res);
        return res;
    }
    
    void dfs(vector<int> &num, int target, int idx, vector<int> &path, vector<vector<int> > &res)
    {
        if(target == 0)
        {
            res.push_back(path);
        }
        else if(target > 0)
        {
            for(int i=idx; i<num.size(); i++)
            {
                if(i > idx && num[i] == num[i-1]) continue;
                if(num[i] > target) continue;
                path.push_back(num[i]);
                dfs(num, target-num[i], i+1, path, res);
                path.pop_back();
            }
        }
    }
};
