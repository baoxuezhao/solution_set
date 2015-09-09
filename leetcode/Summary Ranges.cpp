class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int start = -1, end = -1;
        
        for(int i=0; i<nums.size(); ++i) {
            if (i == 0) {
                start = nums[i];
            } else if (nums[i-1] < nums[i]-1) {
                end = nums[i-1];
                stringstream ss;
                if (end-start != 0) {
                    ss << start << "->" << end;
                } else {
                    ss << start;
                }
                res.push_back(ss.str());
                start = nums[i];   
            }
        }
        end = nums[nums.size()-1];
        stringstream ss;
        if (end-start != 0) {
            ss << start << "->" << end;
        } else {
            ss << start;
        }
        res.push_back(ss.str());
        return res;
    }
};
