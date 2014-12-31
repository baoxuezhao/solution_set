class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 0)
            return 0;
        
        int minp = prices[0];
        int curmax = 0;
        
        for(int i=1; i<prices.size(); i++)
        {
            curmax = max(curmax, prices[i]-minp);
            minp = min(minp, prices[i]);
        }
        return curmax;
    }
};
