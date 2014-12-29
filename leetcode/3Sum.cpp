class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() < 3) return res;
        std::sort(num.begin(), num.end());
        
        for(int i=0; i+2<num.size(); i++)
        {
            if(i > 0 && num[i-1] == num[i]) continue;
            
            int left = i+1, right = num.size()-1;
            while(left < right)
            {
                if(left > i+1 && num[left] == num[left-1]) 
                {
                    left++;
                    continue;
                }
                if(right < num.size()-1 && num[right] == num[right+1])
                {
                    right--;
                    continue;
                }
                int sum = num[i] + num[left] + num[right];
                if(sum < 0)
                    left++;
                else if(sum > 0)
                    right--;
                else
                {
                    res.push_back(vector<int>{num[i], num[left], num[right]});
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
