class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int end = len-1;
        while(end >= 0 && s[end] == ' ')
            end--;
        if(end == -1) return 0;
        
        int start = end;
        while(start >= 0 && s[start] != ' ')
            start--;
        
        return end-start;
    }
};
