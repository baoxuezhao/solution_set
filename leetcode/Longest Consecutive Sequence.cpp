class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> hash;
        
        for(int i=0; i<num.size(); i++)
        {
            hash[num[i]] = true;
        }
        
        int max_len = -1;
        for(auto p: hash)
        {
            if(!p.second) continue;
            
            int left = p.first-1;
            int len = 1;
            while(hash.find(left) != hash.end() && hash[left])
            {
                hash[left] = false;
                left--;
                len++;
            }
            
            int right = p.first+1;
            while(hash.find(right) != hash.end() && hash[right])
            {
                hash[right] = false;
                right++;
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
