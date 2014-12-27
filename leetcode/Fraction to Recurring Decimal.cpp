class Solution {
public:

    string fractionToDecimal(int numerator1, int denominator1) {
        long long numerator = numerator1;
        long long denominator = denominator1;
        
        if(numerator == 0) return "0";
        
        string res;
        if(numerator < 0 ^ denominator < 0) 
            res += "-";
        
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        long long integer = numerator/denominator;
        do
        {
            res += integer%10 + '0';
            integer /= 10;
        }while(integer);
        
        if(res[0] == '-')
            reverse(res.begin()+1, res.end());
        else
            reverse(res.begin(), res.end());
        
        numerator %= denominator;
        if(numerator == 0)
            return res;
        res += ".";

        unordered_map<long, int> map;
        
        long long rem = numerator*10;
        while(rem != 0)
        {
            if(map.find(rem) != map.end())
            {
                string part1 = res.substr(0, map[rem]);
                string part2 = res.substr(map[rem], res.length()-map[rem]);
                return part1 + "(" + part2 + ")";
            }
            
            map[rem] = res.length();
            res += ('0'+rem / denominator);
            rem = (rem % denominator)*10;
        }
        
        return res;
    }
};
