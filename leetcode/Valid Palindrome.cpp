//be careful fo the conditional case in the while
class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();
        if(n == 0) return true;
        
        int l = 0, r = n-1;
        while(l <= r)
        {
            if(!isalphanum(s[l])) 
                l++;
            else if(!isalphanum(s[r])) 
                r--;
            else if(l <= r)
            {
                if(::tolower(s[l]) == ::tolower(s[r]))
                {
                    l++;
                    r--;
                }
                else
                    return false;
            }
        }
        return true;
    }
    
    bool isalphanum(char c)
    {
        if(c >= '0' && c <= '9') return true;
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') return true;
        return false;
    }
};
