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

// solution 3
class Solution {
public:
    string intToRoman(int num) {
        std::string res;
        while (num > 0) {
            while (num >= 1000) {
                res += "M";
                num -= 1000;
            }
            while (num >= 500) {
                if (num >= 900) {
                    res += "CM";
                    num -= 900;
                } else {
                    res += "D";
                    num -= 500;
                }
            }
            while (num >= 100) {
                if (num >= 400) {
                    res += "CD";
                    num -= 400;
                } else {
                    res += "C";
                    num -= 100;
                }
            }
            while (num >= 50) {
                if (num >= 90) {
                    res += "XC";
                    num -= 90;
                } else {
                    res += "L";
                    num -= 50;
                }
            }
            while (num >= 10) {
                if (num >= 40) {
                    res += "XL";
                    num -= 40;
                } else {
                    res += "X";
                    num -= 10;
                }
            }
            while (num >= 5) {
                if (num >= 9) {
                    res += "IX";
                    num -= 9;
                } else {
                    res += "V";
                    num -= 5;
                }
            }
            while (num >= 1) {
                if (num >= 4) {
                    res += "IV";
                    num -= 4;
                } else {
                    res += "I";
                    num -= 1;
                }

            }
        }
        return res;
    }
};
