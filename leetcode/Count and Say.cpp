class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n)
        {
            s = getnext(s);
        }
        return s;
    }
    
    string getnext(string &s)
    {
        string res;
        int start = 0;
        for(int i=1; i<=s.size(); i++)
        {
            if(i == s.size() || s[i] != s[i-1])
            {
                int count = i-start;
                res += itoa(count);
                res += itoa(s[start]-'0');
                start = i;
            }
        }
        return res;
    }
    
    string itoa(int v)
    {
        string res;
        while(v)
        {
            res.push_back(v%10+'0');
            v /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
