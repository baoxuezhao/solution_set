class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == 0) return *s == 0;
        
        if(*(p+1) != '*')
        {
            if((*p == '.' && *s != 0) || (*s == *p))
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            while(true)
            {
                if(isMatch(s, p+2)) return true;
                if((*p == '.' && *s != 0) || (*s == *p))
                    s++;
                else
                    break;
            }
        }
        return false;
    }
};
