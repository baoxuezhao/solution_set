class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &can, int target) {
        sort(can.begin(), can.end());
        vector<int> path;
        vector<vector<int> > res;
        dfs(can, 0, target, path, res);
        return res;
    }
    
    void dfs(vector<int> &can, int idx, int target, vector<int> &path, vector<vector<int> > &res)
    {
        if(target == 0)
            res.push_back(path);
        else
        {
            for(int i=idx; i<can.size(); i++)
            {
                if(can[i] > target) break;
                path.push_back(can[i]);
                dfs(can, i, target-can[i], path, res);
                path.pop_back();
            }
        }
    }
};
