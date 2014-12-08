1. using DFS
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        const int n = num.size();
        std::sort(num.begin(), num.end());
        
        dfs(num, result, 0);
        
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
                swap(num[idx], num[i]);
                dfs(num, result, idx+1);
                swap(num[idx], num[i]);
            }
        }
    }
};

//////////////////////
2. using next_permutation function

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        const int n = num.size();
        std::sort(num.begin(), num.end());
        
        do
        {
            result.push_back(num);
        }
        while(next_permutation(num));
        
        return result;
    }
    
    bool next_permutation(vector<int> &num)
    {
        const int n = num.size();
        int i;
        for(i = n-2; i>=0; i--)
        {
            if(num[i] < num[i+1])
                break;
        }
        if(i == -1) return false;
        
        int left = i;
        for(i=n-1; i>left; i--)
        {
            if(num[i] > num[left]) 
            {
                swap(num[left], num[i]);
                break;
            }
        }
        
        left++;
        int right = n-1;
        while(left <= right)
        {
            swap(num[left], num[right]);
            left++;
            right--;
        }
        return true;
    }
};
