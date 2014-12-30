class Solution {
public:
    int strStr(char *haystack, char *needle) {
        
        int m = strlen(needle);
        int n = strlen(haystack);
        int *next = new int[m];
        
        comp_next(needle, next);
        
        int i=0, j=0;
        while(i < n && j < m)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        delete next;
        if(j == m)
            return i-m;
        else
            return -1;
    }
    
    void comp_next(char *pat, int *next)
    {
        int n = strlen(pat);
        next[0] = -1;
        int k = -1;
        int j = 0;
        while(j < n-1)
        {
            if(k == -1 || pat[k] == pat[j])
            {
                k++;
                j++;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
    }
};
