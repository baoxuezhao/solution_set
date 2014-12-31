class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {
        if(numerator1 == 0)
            return "0";
        
        bool sign = (numerator1 >= 0) ^ (denominator1 >= 0);
        string res;
        if(sign) res += "-";
        
        long long numerator = numerator1; //???
        long long denominator = denominator1; //???
        
        numerator = abs(numerator); 
        denominator = abs(denominator);
        
        res += itoa(numerator/denominator);
        numerator %= denominator;
        
        if(numerator == 0)
            return res;
        
        res += ".";
        unordered_map<int, int> hash;
        
        while(numerator)
        {
            if(hash.find(numerator) != hash.end())
            {
                string result;
                int pos = hash[numerator];
                result += res.substr(0, pos);
                result += "(";
                result += res.substr(pos, res.size()-pos);
                result += ")";
                return result;
            }
            
            hash[numerator] = res.size();
            numerator *= 10;
            res += (numerator/denominator + '0');
            numerator %= denominator;
        }
        return res;
    }
    
    string itoa(long long n) //???
    {
        if(n == 0)
            return "0"; ///???
            
        string res;
        while(n)
        {
            res += (n%10 + '0');
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
