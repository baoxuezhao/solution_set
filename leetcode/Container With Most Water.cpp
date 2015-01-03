class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size()-1;
        int maxh = -1;
        while(l < r)
        {
            maxh = max(maxh, min(height[r], height[l])*(r-l));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxh;
    }
};
