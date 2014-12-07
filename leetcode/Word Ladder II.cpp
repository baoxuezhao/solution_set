class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        unordered_set<string> visited;
        unordered_set<string> queue1, queue2;
        unordered_map<string, vector<string> > f;
        
        bool flag = false;
                    
        queue1.insert(start);
        while(!queue1.empty() && !flag)
        {
            for(auto str: queue1)
            {
                visited.insert(str);
            }
            for(auto str: queue1)
            {
                for(int i=0; i<str.size(); i++)
                {
                    string old = str;
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == str[i]) continue;
                        
                        swap(str[i], c);
                        
                        if((dict.find(str) != dict.end() || str == end) 
                            && visited.find(str) == visited.end())
                        {
                            queue2.insert(str);
                            f[str].push_back(old);
                        }
                        if(str == end) flag = true;
                        swap(str[i], c);
                    }
                }
            }
            queue1.clear();
            swap(queue1, queue2);
        }
        vector<string> path;
        vector<vector<string> > result;
        if(flag)
        {
            path.push_back(end);
            dfs(f, path, result, start);
        }
        return result;
    }

    void dfs(unordered_map<string, vector<string> > &f, vector<string> &path, vector<vector<string> > &result, string start)
    {
        if(path.back() == start)
        {
            result.push_back(path);
            std::reverse(result.back().begin(), result.back().end());
            return;
        }
        
        string cur = path.back();
        vector<string> &fathers = f[cur];
        for(int i=0; i<fathers.size(); i++)
        {
            path.push_back(fathers[i]);
            dfs(f, path, result, start);
            path.pop_back();
        }
    }
};
