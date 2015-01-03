class Solution {
public:
    string intToRoman(int num) 
    {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int size = sizeof(radix)/sizeof(int);
        
        string res;
        for(int i=0; i<size && num>0; i++)
        {
            int count = num/radix[i];
            num %= radix[i];
            for(int j=0; j<count; j++)
            {
                res += symbol[i];
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    string intToRoman(int num) 
    {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int size = sizeof(radix)/sizeof(int);
        
        string res;
        while(num)
        {
            for(int i=0; i<size; i++)
            {
                if(num >= radix[i])
                {
                    num -= radix[i];
                    res += symbol[i];
                    break;
                }
            }   
        }
        return res;
    }
};
