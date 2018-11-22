class Solution {
public:
    int reverse(int x) {
        if(x < 0) 
        {
            if(x == INT_MIN) return 0;
            return 0-reverse(0-x);
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

// solution2
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int y = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && y > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && y < -8)) {
                return 0;
            }
            res = res * 10 + y;
        }
        return res;
    }
};
