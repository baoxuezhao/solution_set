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


//the dp solution
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(p);
        int n = strlen(s);
        
        //the edge case must be processed, otherwise the dp solution will be timeout
        int pl = 0;  
        for (int i = 0; i < m; i++) {  
            if (p[i] != '*') {  
                pl++;  
            }
        }
        if (pl > n) {  
            return false;  
        }  
        if (n == 0 && pl == 0) {  
            return true;  
        }
           
        bool dp0[n+1];
        bool dp1[n+1];
        memset(dp0, false, sizeof(dp0));
        memset(dp1, false, sizeof(dp1));
        
        dp0[0] = true;
        
        for(int i=1; i<=m; i++)
        {
            dp1[0] = (dp0[0] && p[i-1] == '*');
            
            for(int j=1; j<=n; j++)
            {
                if(p[i-1] == '?' || p[i-1]==s[j-1])
                    dp1[j] = dp0[j-1];
                else if(p[i-1] == '*')
                    dp1[j] = (dp1[j-1] || dp0[j]);
            }
            memcpy(dp0, dp1, sizeof(dp1));
            memset(dp1, false, sizeof(dp1));
        }
        return dp0[n];
    }
};
