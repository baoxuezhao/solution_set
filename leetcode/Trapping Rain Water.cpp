class Solution {
public:
    int trap(int A[], int n) {
        int leftmax[n];
        int rightmax[n];
        
        leftmax[0] = 0;
        rightmax[n-1] = 0;
        
        for(int i=1; i<n; i++)
        {
            leftmax[i] = max(leftmax[i-1], A[i-1]);
        }
        for(int i=n-2; i>=0; i--)
        {
            rightmax[i] = max(rightmax[i+1], A[i+1]);
        }
        
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            if(min(leftmax[i], rightmax[i]) > A[i])
                sum += min(leftmax[i], rightmax[i]) - A[i];
        }
        return sum;
    }
};

//one pass algorithm with two pointers.
class Solution {
public:
    int trap(int A[], int n) {
        int sum = 0;
        if(n < 2) return 0;
        int l=1, r=n-2;
        int lmax = A[0], rmax = A[n-1];
        
        while(l <= r)
        {
            if(lmax <= rmax)
            {
                sum += max(0, min(lmax, rmax)-A[l]);
                lmax = max(lmax, A[l]);
                l++;
            }
            else
            {
                sum += max(0, min(lmax, rmax)-A[r]);
                rmax = max(rmax, A[r]);
                r--;
            }
        }
        return sum;
    }
};

