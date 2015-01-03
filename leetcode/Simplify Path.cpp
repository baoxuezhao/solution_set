class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0 || path[0] != '/')
            return "/";
        stack<string> s;
        int start = 1;
        for(int i=1; i<=path.size(); i++)
        {
            if(i == path.size() || path[i] == '/')
            {
                string sub = path.substr(start, i-start);
                if(sub == "..")
                {
                    if(!s.empty()) s.pop();
                }
                else if(sub == "." || sub == "")
                ;
                else
                {
                    s.push(sub);
                }
                start = i+1;
            }
        }
        string res;
        if(s.empty()) 
            return "/";
        while(!s.empty())
        {
            res = ("/" + s.top() + res);
            s.pop();
        }
        return res;
    }
};
