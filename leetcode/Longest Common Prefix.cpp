class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        if(strs.size() == 0)
            return "";
        
        vector<string> res;
        while(strs.size() > 1)
        {
            for(int i=0; i<strs.size(); i+=2)
            {
                if(i+1 < strs.size())
                    res.push_back(lcp(strs[i], strs[i+1]));
                else
                    res.push_back(strs[i]);
            }
            strs = res;
            res.clear();
        }
        return strs[0];
    }
    
    string lcp(string &s1, string &s2)
    {
        int i=0;
        for(; i<min(s1.size(), s2.size()); i++)
        {
            if(s1[i] != s2[i]) break;
        }
        return s1.substr(0, i);
    }
};
