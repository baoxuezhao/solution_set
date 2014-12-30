class Solution {
public:
    int divide(int dividend, int divisor) {
        return divide1(dividend, divisor);
    }
    
    int divide1(int va, int vb)
    {
    	long long a = va;
    	long long b = vb;
    	bool sign = (a > 0) ^ (b > 0);
    	a = abs(a);
    	b = abs(b);
    
    	if(b == 0) return INT_MAX;
    	long long res = 0;
    
    	long long total = 0;
    	while(a >= total+b)
    	{
    		long long sh = 1;
    		long long bb = b;
    		while(a >= bb+bb+total)
    		{
    			bb += bb;
    			sh += sh;
    		}
    		total += bb;
    		res += sh;
    	}
    	if(sign)
    	    res = ~res + 1;
    	
    	if(res > INT_MAX || res < INT_MIN)
    	    return INT_MAX;
    	else
    	    return res;
    }

};
