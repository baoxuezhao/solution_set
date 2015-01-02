class Solution {
public:
    int maxProduct(int A[], int n) 
    {
        int maxP = A[0], minP = A[0];
        int res = maxP;
        for(int i=1; i<n; i++)
        {
            int t1 = A[i]*minP;  //tmp backup
            int t2 = A[i]*maxP;  //tmp backup
            maxP = max(A[i], max(t1, t2));
            minP = min(A[i], min(t1, t2));
            res = max(res, maxP);
        }
        return res;
    }
};
