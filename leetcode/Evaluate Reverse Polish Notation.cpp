class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(auto str: tokens)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
                oper(s, str);
            else
                s.push(atoi(str.c_str()));
        }
        return s.top();
    }
    
    void oper(stack<int> &s,  string op)
    {
        int r = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        
        if(op == "+")
            s.push(l+r);
        else if(op == "-")
            s.push(l-r);
        else if(op == "*")
            s.push(l*r);
        else
            s.push(l/r);
    }

};
