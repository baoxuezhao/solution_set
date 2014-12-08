class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        const int m = matrix.size();
        if(m == 0) return 0;
        
        const int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int largest = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            largest = max(largest, area);
        }
        return largest;
    }
    
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
