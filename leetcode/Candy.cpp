class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> val(n, 1);
        
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
                val[i] = max(val[i], val[i-1]+1);
        }
        
        int sum = val[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
                val[i] = max(val[i], val[i+1]+1);
            sum += val[i];
        }
        return sum;
    }
};
