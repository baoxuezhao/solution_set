class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') i++;
                nums.push(stoi(s.substr(start, i-start)));
                i--;
            } else if (s[i] == '+' || s[i] == '-') {
                while (!ops.empty()) {
                    evaluate(ops, nums);
                }
                ops.push(s[i]);
            } else if (s[i] == '*' || s[i] == '/') {
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                    evaluate(ops, nums);
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            evaluate(ops, nums);
        }
        return nums.top();
    }
    
    void evaluate(stack<char> &op, stack<int> &num) {
        char _op = op.top();
        op.pop();
        int right = num.top();
        num.pop();
        int left = num.top();
        num.pop();
        if (_op == '+') {
            num.push(left + right);
        } else if (_op == '-') {
            num.push(left - right);
        } else if (_op == '*') {
            num.push(left * right);
        } else if (_op == '/') {
            num.push(left / right);
        }
    }
};
