class Solution {
public:
    int atoi(const char *s) {
        int res = 0;
        int idx = 0;
        while(s[idx] == ' ') idx++;
        
        int sign = 1;
        
        if(s[idx] == '-')
        {
            idx++;
            sign = -1;
        }
        else if(s[idx] == '+')
        {
            idx++;
            sign = 1;
        }
        while(s[idx] >= '0' && s[idx] <= '9')
        {
            if(res > INT_MAX/10 || (res == INT_MAX/10 && s[idx]-'0' > INT_MAX%10))
                return (sign == 1)? INT_MAX: INT_MIN;
            res = res*10 + s[idx]-'0';
            idx++;
        }
        return sign*res;
    }
};
