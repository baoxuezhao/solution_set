class Solution {
public:
    int sqrt(int x) 
    {
        if(x < 2) return x;
        
        int l = 1, r = x/2+1;
        int prev;
        
        while(l <= r)
        {
            long long m = l+(r-l)/2;
            long long cur = m*m;
            if(cur == x)
                return m;
            else if(cur < x)
            {
                l = m+1;
                prev = m;
            }
            else if(cur > x)
            {
                r = m-1;
            }
        }
        return prev;
    }
};
