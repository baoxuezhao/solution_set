reference: http://www.cnblogs.com/skysand/p/4179099.html

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        int minv = INT_MAX, maxv = INT_MIN;
        int n = num.size();
                
        for(int i=0; i<n; i++)
        {
            minv = min(minv, num[i]);
            maxv = max(maxv, num[i]);
        }
        
        int avggap = ceil((maxv-minv+0.0)/(n-1));
        int count = ceil((maxv-minv+0.0)/avggap);
        
        
        vector<int> maxb(count, INT_MIN);
        vector<int> minb(count, INT_MAX);
                
        for(int i=0; i<n; i++)
        {
            if(num[i]==maxv || num[i]==minv) continue;
            int bid = (num[i]-minv)/avggap;
            
            if(maxb[bid] < num[i])
                maxb[bid] = num[i];
            if(minb[bid] > num[i])
                minb[bid] = num[i];
        }
        
        int lastMax = minv;
        int maxgap = INT_MIN;
        for(int i=0; i<count; i++)
        {
            if(maxb[i] == INT_MIN) continue;
            maxgap = max(maxgap, minb[i]-lastMax);
            lastMax = maxb[i];
        }
        maxgap = max(maxgap, maxv-lastMax);
        return maxgap;
    }
};
