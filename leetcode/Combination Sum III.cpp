class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int> > result;
        int sum = 0;
        dfs(k, n, path, result);
        return result;
    }
    
    void dfs(int k, int n, vector<int> &path, vector<vector<int> > &result) {
        int cur = path.size()==0?0:path.back();
        if (path.size()>=k && n > 0) {
            return;
        }
        if (n < 0) return;
        if (path.size() == k && n == 0) {
            result.push_back(path);
            return;
        }
        for(int i=cur+1; i<=9; i++) {
            if (n-i<0) continue;
            path.push_back(i);
            dfs(k, n-i, path, result);
            path.pop_back();
        }
    }
};
