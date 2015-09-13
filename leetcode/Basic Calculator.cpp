nclude <stack>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        int len = s.size();
        for (int i=0; i<len; ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '(') {
                ops.push('(');
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    evaluate(vals, ops);
                }
                ops.pop();
            } else if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                vals.push(stoi(s.substr(start, i-start)));
                i--;
            } else if (s[i] == '+' || s[i] == '-') {
                while (!ops.empty() && ops.top() != '(') {
                    evaluate(vals, ops);
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            evaluate(vals, ops);
        }
        return vals.top();
    }

    void evaluate(stack<int> &vals, stack<char> &ops) {
        char op = ops.top();
        ops.pop();

        int right = vals.top();
        vals.pop();
        int left = vals.top();
        vals.pop();
        if (op == '+') {
            vals.push(left+right);
        } else if (op == '-') {
            vals.push(left-right);
        }
    }
};

int main() {
    Solution sol;
    std::cout << sol.calculate("(4+9)") << std::endl;
    return 0;
}
