class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fra(n+1, 1);
        frac(n, fra);
        k--;
        
        vector<int> digit(n);
        string res;
        for(int i=1; i<=n; i++)
            digit[i-1] = i;
        
        int size;
        while(digit.size())
        {
            size = digit.size();
            res.push_back('0' + (digit[k/fra[size-1]]));
            digit.erase(digit.begin() + k/fra[size-1]);
            k %= fra[size-1];
        }
        return res;
    }
    
    void frac(int n, vector<int> &res)
    {
        for(int i=1; i<=n; i++)
        {
            res[i] = i*res[i-1];
        }
    }
};
