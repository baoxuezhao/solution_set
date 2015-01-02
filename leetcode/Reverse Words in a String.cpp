class Solution {
public:
    void reverseWords(string &s) 
    {
        const int n = s.size();
        int i=0, j=0;
        while(i < n && s[i] ==' ') i++;
        
        if(i == n)
        {
            s.resize(0);
            return;
        }
        while(i < n)
        {
            int start = j;
            while(i < n && s[i] != ' ') s[j++] = s[i++];
            int end = j-1;
            
            reverse(s, start, end);
            
            while(i < n && s[i] == ' ') i++;
            if(i < n) s[j++] = ' ';
        }
        s.resize(j);
        reverse(s, 0, j-1);
    }
    
    void reverse(string &s, int l, int r)
    {
        while(l <= r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    
};
