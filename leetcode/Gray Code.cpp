class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> res(1, 0);
        for(int i=1; i<=n; i++)    
        {
            for(int j=res.size()-1; j>=0; j--)
            {
                res.push_back(res[j] | (1 << (i-1)));
            }
        }
        return res;
    }
};
