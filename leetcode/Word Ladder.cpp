class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_set<string> visited;
    
        q.push(start);
        visited.insert(start);
        
        int level = 1;
        int num1 = 1, num2 = 0;
        
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            num1--;
            
            for(int i=0; i<cur.size(); i++)
            {
                for(char k = 'a'; k<='z'; k++)
                {
                    if(k == cur[i]) continue;
                    
                    swap(cur[i], k);
                    
                    if(cur == end)
                        return level+1;
                    
                    if(dict.find(cur) != dict.end() && visited.find(cur) == visited.end())
                    {
                        q.push(cur);
                        visited.insert(cur);
                        num2++;
                    }
                    swap(cur[i], k);
                }
            }
            if(num1 == 0)
            {
                level++;
                swap(num1, num2);
            }
        }
        return 0;
    }
};
