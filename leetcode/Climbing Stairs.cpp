class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int pp = 1, p = 1, cur;
        for(int i=2; i<=n; i++)
        {
            cur = pp + p;
            pp = p;
            p = cur;
        }
        return cur;
    }
};
