class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n-1;
        while(l <= r)
        {
            int m = l+(r-l)/2;
            if(A[m] == target) return true;
            
            if(A[m] < A[r])
            {
                if(target > A[m] && target <= A[r])
                    l = m+1;
                else
                    r = m-1;
            }
            else if(A[m] > A[r])
            {
                if(target >= A[l] && target < A[m])
                    r = m-1;
                else
                    l = m+1;
            }
            else r--;
        }
        return false;
    }
};
