class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0];
        int curmax = A[0];
        
        for(int i=1; i<n; i++)
        {
            curmax = max(A[i], A[i]+curmax);
            sum = max(curmax, sum);
        }
        return sum;
    }
};
