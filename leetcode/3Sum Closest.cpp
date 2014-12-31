class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        const int n = num.size();
        if(n < 3) return -1;
        int res;
        int gap = INT_MAX;
        
        sort(num.begin(), num.end());
        for(int i=0; i+2<n; i++)
        {
            int left = i+1, right = n-1;
            while(left < right)
            {
                int sum = num[i] + num[left] + num[right];
                if(abs(sum-target) < gap)
                {
                    res = sum;
                    gap = abs(sum-target);
                }
                
                if(sum > target)
                    right--;
                else if(sum < target)
                    left++;
                else
                    return target;
            }
        }
        return res;
    }
};
