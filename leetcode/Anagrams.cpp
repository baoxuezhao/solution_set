class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > map;
        
        for(auto str: strs)
        {
            string str1 = str;
            sort(str1.begin(), str1.end());
            map[str1].push_back(str);
        }
        
        vector<string> res;
        for(auto &pair: map)
        {
            if(pair.second.size() < 2) continue;
            
            for(auto &str: pair.second)
            {
                res.push_back(str);
            }
        }
        return res;
    }
};
