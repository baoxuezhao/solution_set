class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que[cur].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (que[cur].size() > 1) {
            que[1-cur].push(que[cur].front());
            que[cur].pop();
        }
        que[cur].pop();
        cur = 1-cur;
    }

    // Get the top element.
    int top() {
        int val;
        while (que[cur].size() > 1) {
            que[1-cur].push(que[cur].front());
            que[cur].pop();
        }
        val = que[cur].front();
        que[cur].pop();
        que[1-cur].push(val);
        cur = 1-cur;
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que[cur].empty();
    }
    
private:
    queue<int> que[2];
    int cur = 0;
};
