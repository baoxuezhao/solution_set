//using dfs
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        const int n = num.size();
        if(n == 0) return result;
        
        std::sort(num.begin(), num.end());
        dfs(num, result, 0);
        
        std::sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
    
    void dfs(vector<int> &num, vector<vector<int> > &result, int idx)
    {
        if(idx == num.size())
        {
            result.push_back(num);
            return;
        }
        else
        {
            for(int i=idx; i<num.size(); i++)
            {
                if(i>idx && num[i] == num[i-1]) continue;
                swap(num[i], num[idx]);
                dfs(num, result, idx+1);
                swap(num[i], num[idx]);
            }
        }
    }
};
