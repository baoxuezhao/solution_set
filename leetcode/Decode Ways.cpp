class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1)
            return s[0] > '0'?1:0;
            
        int pp = 1, p = s[0] > '0'?1:0;
        int cur = 0;
        for(int i=1; i<s.size(); i++)
        {
            cur = 0;
            if(s[i] > '0')
                cur += p;
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                cur += pp;
            
            pp = p;
            p = cur;
        }
        return cur;
    }
};
