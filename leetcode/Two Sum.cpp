class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<num.size(); i++)
        {
            map[num[i]] = i;
        }
        
        for(int i=0; i<num.size(); i++)
        {
            if(map.find(target-num[i]) != map.end())
            {
                if(map[target-num[i]] != i)
                {
                    vector<int> res{i+1, map[target-num[i]]+1};
                    if(res[0] > res[1])
                        swap(res[0], res[1]);
                    
                    return res;
                }
            }
        }
    }
};
