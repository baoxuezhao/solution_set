class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s == NULL && p == NULL) return true;
        if(s == NULL || p == NULL) return false;
        
        const char *ss = NULL, *pp = NULL;
        while(*s)
        {
            if((*p == '?' || *s == *p) && (*p != '*'))
            {
                s++;
                p++;
            }
            else if(*p == '*')
            {
                while(*p == '*') p++;
                pp = p;
                ss = s;
            }
            else if(ss != NULL)
            {
                s = ++ss;
                p = pp;
            }
            else
                break;
        }
        while(*p == '*') p++;
        return (*s == 0 && *p == 0);
    }
};
