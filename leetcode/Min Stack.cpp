class MinStack {
public:
    void push(int x) {
        s.push(x);
        if(m.empty() || x <= m.top()) 
            m.push(x);
    }

    void pop() {
        if(s.top() == m.top()) m.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }

private:
    stack<int> s;
    stack<int> m;
};
