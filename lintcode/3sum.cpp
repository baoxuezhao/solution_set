class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        const int n=nums.size();
        if(n <= 2)  return res;
        
        for(int i=0; i<n-2; i++)
        {
            while(i>0 && nums[i] == nums[i-1]) i++;
            
            int left = i+1, right=n-1;
            while(left < right)
            {
                while(left > i+1 && nums[left] == nums[left-1]) left++;
                while(right < n-1 && nums[right] == nums[right+1]) right--;
                
                if(left >= right) break;
                
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0)
                {
                    vector<int> trip;
                    trip.push_back(nums[i]);
                    trip.push_back(nums[left]);
                    trip.push_back(nums[right]);
                    res.push_back(trip);
                    left++;
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};

