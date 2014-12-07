class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        
        int left_max[n];
        int right_max[n];

        left_max[0] = 0;        
        int curmax = 0;
        for(int i=1; i<n; i++)
        {
            int diff = prices[i]-prices[i-1];
            curmax = max(diff, curmax + diff);
            left_max[i] = std::max(left_max[i-1], curmax);
        }
    
        right_max[n-1] = 0;
        curmax = 0;
        for(int i=n-2; i>=0; i--)
        {
            int diff = prices[i+1] - prices[i];
            curmax = max(diff, curmax + diff);
            right_max[i] = std::max(right_max[i+1], curmax);
        }
        
        int maxv = 0;
        for(int i=0; i<n; i++)
        {
            maxv = max(maxv, left_max[i]+right_max[i]);
        }
        
        return maxv;
    }
};
