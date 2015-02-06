class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    long long atoi1(string s)
    {
        long long res = 0;
        for(int i=0; i<s.size(); i++)
        {
            res = res*10 + (s[i]-'0');
        }
        return res;
    }
    
    string binaryRepresentation(string n) {
        // wirte your code here
        int pos = n.size();
        for(int i=0; i<n.size(); i++)
        {
            if(n[i] == '.')
            {
                pos = i;
                break;
            }
        }
        long long part1 = atoi1(n.substr(0, pos));
        double part2 = strtod(n.substr(pos, n.size()-pos).c_str(), NULL);
        string res1, res2;
        while(part1)
        {
            res1 += (part1%2 + '0');
            part1 /= 2;
        }
        if(res1.size() == 0) res1 = "0";
        reverse(res1.begin(), res1.end());
        
        if(abs(part2) <=1e-7 ) return res1;
    
        while(part2 > 0)
        {
            part2 *= 2;
            if(part2 >= 1.0)
            {
                res2 += '1';
                part2 -= 1.0;
            }
            else
            {
                res2 += '0';
            }
            if(res2.size() > 32)
                return "ERROR";
        }
        return res1+"."+res2;
    }
};

