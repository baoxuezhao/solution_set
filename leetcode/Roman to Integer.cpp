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
