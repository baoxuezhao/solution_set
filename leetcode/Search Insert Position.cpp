//compute lower bound
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l=0, r=n-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;
            if(A[m] < target)
                l = m+1;
            else
                r = m-1;
        }
        return r+1;
    }
};
