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
