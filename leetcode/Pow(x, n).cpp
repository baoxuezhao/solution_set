//be careful when (x < 0)

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0) 
            return 1.0/power(x, 0-n);
        else
            return power(x, n); 
    }
    
    double power(double x, int n)
    {
        if(n == 0) return 1;
        double p = power(x, n/2);
        if(n % 2 == 0)
            return p*p;
        else
            return p*p*x;
    }
};
