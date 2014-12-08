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
