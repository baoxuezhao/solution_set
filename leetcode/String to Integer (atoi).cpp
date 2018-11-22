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


/////////////
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool neg = false;
        int n = str.size();
        int idx = 0;
        while (idx < n && str[idx] == ' ') {
            idx++;
        }
        if (idx == n) {
            return 0;
        }
        if (str[idx] == '+') {
            idx++;
        } else if (str[idx] == '-') {
            neg = true;
            idx++;
        }
        for (; idx < n && str[idx] >= '0' && str[idx] <= '9'; ++idx) {
            if (res < INT_MAX/10 || (res == INT_MAX/10 && str[idx]-'0'<=7)) {
                res = res * 10 + str[idx] - '0';
            } else {
                if (neg) return INT_MIN;
                else return INT_MAX;
            }
        }
        if (neg) {
            return (0 - res);
        }
        return res;
        
    }
};
