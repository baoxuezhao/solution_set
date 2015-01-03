class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = lower_bound(A, n, target);
        int hig = upper_bound(A, n, target);
        
        if(low == hig)
            return vector<int>{-1, -1};
        else
            return vector<int>{low, hig-1};
    }
    
    int lower_bound(int A[], int n, int target)
    {
        int l = 0, r = n-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;
            if(A[m] >= target)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return r+1;
    }
    
    int upper_bound(int A[], int n, int target)
    {
        int l=0, r=n-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;
            if(A[m] > target)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return r+1;
    }
};
