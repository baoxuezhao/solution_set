class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(map.find(target-nums[i]) != map.end())
            {
                int r = map[target-nums[i]];
                if(r == i) continue;
                
                vector<int> res;
                res.push_back(min(i, r)+1);
                res.push_back(max(i, r)+1);
                return res;
            }
        }
    }
};
