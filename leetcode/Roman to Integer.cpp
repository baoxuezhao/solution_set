class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<string, int> map;
        map["M"]  = 1000;
        map["CM"] = 900;
        map["D"]  = 500;
        map["CD"] = 400;
        map["C"]  = 100;
        map["XC"] = 90;
        map["L"]  = 50;
        map["XL"] = 40;
        map["X"]  = 10;
        map["IX"] = 9;
        map["V"]  = 5;
        map["IV"] = 4;
        map["I"]  = 1;
        
        int idx = 0;
        int res = 0;
        while(idx < s.size())
        {
            string sub2 = s.substr(idx, 2);
            string sub1 = s.substr(idx, 1);
            
            if(idx <= s.size()-2 && map.find(sub2) != map.end())
            {
                res += map[sub2];
                idx += 2;
            }
            else if(map.find(sub1) != map.end())
            {
                res += map[sub1];
                idx++;
            }
        }
        return res;
    }
};

// solution 2:
class Solution {
public:
    int romanToInt(string s) {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int size = sizeof(radix)/sizeof(int);
        
        int n = s.size();
        int idx = 0;
        int res = 0;
        while (idx < n) {
            for (int i = 0; i < size; ++i) {
                while (idx < n && symbol[i].size() == 1 && s[idx] == symbol[i][0]) {
                    res += radix[i];
                    idx++;
                }
                while (idx < n && symbol[i].size() == 2 && s.substr(idx, 2) == symbol[i])  {
                    res += radix[i];
                    idx+=2;
                }
            }
        }
        return res;
    }
};
