//be careful when (x < 0)

class Solution {
public:
    double pow(double x, int n) {
        return power(x, n);
    }
    
    double power(double x, long long n)
    {
        if(n < 0) return 1.0/power(x, 0-n);
        if(n == 0) return 1;
        
        double half = power(x, n/2);
        if(n%2 == 0)
            return half*half;
        else
            return half*half*x;
    }
};
