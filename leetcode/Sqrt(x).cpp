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

//Newton algorithm
class Solution {
public:
    int sqrt(int x) {
    
        double p = 2, pp = 1;
        while(abs(pp-p) > 1e-6)
        {
            pp = p;
            p = p/2.0 + x/(2.0*p);
        }
        return (int)pp;
    }
};


//another binary search using doubles
class Solution {
public:
    int sqrt(int x) {
        
    	double EPS = 0.00001;
    	double left = 0.0, right = max(1, x), mid;
    	while(left + EPS < right)
    	{
    		mid = (left+right)/2.0;
    		if(mid*mid > x)
    			right = mid;
    		else
    			left = mid;
    	}
    	return (int)right;
    }
};
