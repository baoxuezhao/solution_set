class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int l1 = version1.size();
        const int l2 = version2.size();
        
        int idx1 = 0, idx2 = 0;
        
        while(idx1 < l1 || idx2 < l2)
        {
            int prev1 = idx1;
            int prev2 = idx2;
            
            int num1, num2;
            
            if(idx1 < l1)
            {
                while(idx1 < l1 && version1[idx1] != '.') idx1++;
                num1 = atoi1(version1.substr(prev1, idx1-prev1));
            }
            else
                num1 = 0;
                
            if(idx2 < l2)
            {
                while(idx2 < l2 && version2[idx2] != '.') idx2++;
                num2 = atoi1(version2.substr(prev2, idx2-prev2));
            }
            else
                num2 = 0;
                
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            
            if(idx1 < l1 && version1[idx1] == '.') idx1++;
            if(idx2 < l2 && version2[idx2] == '.') idx2++;
            
        }
        return 0;
    }
    
    int atoi1(string str)
    {
        int res = 0;
        for(int i=0; i<str.size(); i++)
        {
            res = res*10 + (str[i]-'0');
        }
        return res;
    }
};
