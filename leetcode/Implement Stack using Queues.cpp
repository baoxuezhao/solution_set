class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!queue1.empty()) {
            queue1.push_back(x);
        } else {
            queue2.push_back(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (queue1.empty()) {
            while (queue2.size() > 1) {
                queue1.push_back(queue2.front());
                queue2.pop_front();
            }
            queue2.pop_front();
        } else {
            while (queue1.size() > 1) {
                queue2.push_back(queue1.front());
                queue1.pop_front();
            }
            queue1.pop_front();
        }
    }

    // Get the top element.
    int top() {
        int val;
        if (queue1.empty()) {
            while (queue2.size() > 1) {
                queue1.push_back(queue2.front());
                queue2.pop_front();
            }
            val = queue2.front();
            queue1.push_back(val);
            queue2.pop_front();
        } else {
            while (queue1.size() > 1) {
                queue2.push_back(queue1.front());
                queue1.pop_front();
            }
            val = queue1.front();
            queue2.push_back(val);
            queue1.pop_front();
        }
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
    
private:
    deque<int> queue1;
    deque<int> queue2;
};

