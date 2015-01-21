class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        const int n = num.size();
        if(n == 0) return result;
        
        bool visited[n] = {false};
        
        std::sort(num.begin(), num.end());
        dfs(num, result, visited, 0);
        
        //std::sort(result.begin(), result.end());
        //result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
    
    bool nonswap(int k, int i, vector<int> &num)
    {
        for (int j=k; j<i; j++) {
            if (num[j]==num[i]){
                return true;
            }
        }
        return false;
    }
    
    void dfs(vector<int> &num, vector<vector<int> > &result, bool visited[], int idx)
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
                if(nonswap(idx, i, num)) continue;
                swap(num[i], num[idx]);
                dfs(num, result, visited, idx+1);
                swap(num[i], num[idx]);
            }
        }
    }
};
