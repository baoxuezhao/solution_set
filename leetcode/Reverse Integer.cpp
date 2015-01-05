class Solution {
public:
    int reverse(int x) {
        if(x < 0) 
        {
            if(x == INT_MIN) return 0;
            int val = reverse(0-x);
            if(val == 0)
                return 0;
            else
                return 0-val;
        }
        
        int res = 0;
        while(x)
        {
            int v = x%10;
            if(res < INT_MAX/10 || (res == INT_MAX/10 && v <= INT_MAX%10))
            {
                res = res*10 + v;
                x = x/10;
            }
            else
                return 0;
        }
        return res;
    }
};
