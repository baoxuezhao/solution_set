class Solution {
public:
    int findMin(vector<int> &num) {
        const int n = num.size();
        
        int l = 0, r = n-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(mid > 0 && num[mid] < num[mid-1])
                return num[mid];
            
            if(num[mid] < num[r])
                r = mid-1;
            else
                l = mid+1;
        }
        return num[0];
    }
};
