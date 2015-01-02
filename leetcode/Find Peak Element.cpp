class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        const int n = num.size();
        int l = 0, r = n-1;
        
        while(l <= r)
        {
            int m = l + (r-l)/2;
            if((m == 0 || num[m-1] < num[m]) && (m == n-1 || num[m] > num[m+1]))
                return m;
            
            if(m > 0 && num[m-1] > num[m])
            {
                r = m-1;
            }
            else if(m < n-1 && num[m+1] > num[m])
            {
                l = m+1;
            }
        }
    }
};
