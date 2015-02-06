class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string path;
        dfs(digits, 0, path, result, map);
        return result;
    }
    
    void dfs(string &digits, int idx, string &path, vector<string> &result, string map[])
    {
        if(idx == digits.size())
        {
            result.push_back(path);
            return;
        }
        
        string comb = map[digits[idx]-'0'];
        for(int i=0; i<comb.size(); i++)
        {
            path.push_back(comb[i]);
            dfs(digits, idx+1, path, result, map);
            path.pop_back();
        }
    }
};


//iterative solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        
        for(int i=0; i<digits.size(); i++)
        {
            string str = map[digits[i]-'0'];
            int n = res.size();
            vector<string> res2;
            for(int j=0; j<n; j++)
                for(int k=0; k<str.size(); k++)
                    res2.push_back(res[j]+str[k]);
            res = res2;
        }
        return res;
    }
};
