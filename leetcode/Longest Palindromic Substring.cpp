class Solution {
public:
    string longestPalindrome(string s) {
        const int n=s.size();
        int start;
        int longest = -1;
        for(int i=0; i<n; i++)
        {
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if(right-left-1 > longest)
            {
                longest = right-left-1;
                start = left+1;
            }
            
            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if(right-left-1 > longest)
            {
                longest = right-left-1;
                start = left+1;
            }
        }
        return s.substr(start, longest);
    }
};
