class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        const int n = height.size();
        stack<int> s;
        
        int maxarea = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s.empty()||height[s.top()] <= height[i])
                s.push(i);
            else
            {
                pop_large(s, height, i, maxarea);
                s.push(i);
            }
        }
        pop_large(s, height, n, maxarea);

        return maxarea;
    }
    
    void pop_large(stack<int> &s, vector<int> &height, int right, int &maxarea)
    {
        int rightheight = (right == height.size())?-1 : height[right];
        
        while(!s.empty() && height[s.top()] > rightheight)
        {
            int curheight = height[s.top()];
            while(!s.empty() && height[s.top()] == curheight)
                s.pop();
            int left = s.empty()?(-1):(s.top());
            
            int curarea = (right-left-1)*curheight;
            maxarea = max(maxarea, curarea);
        }
    }
};
