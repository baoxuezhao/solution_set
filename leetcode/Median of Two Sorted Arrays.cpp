class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m + n;
        if(sum % 2 == 0)
            return double(findkth(A,m,B,n,sum/2) + findkth(A,m,B,n,sum/2+1))/2.0;
        else
            return findkth(A,m,B,n,sum/2+1);
    }
    
    int findkth(int A[], int m, int B[], int n, int k)
    {
        if(m > n) return findkth(B, n, A, m, k);
        if(m == 0) 
            return B[k-1];
        if(k == 1)
            return min(A[0], B[0]);
        
        int aa = min(m, k/2);
        int bb = k - aa;
        
        if(A[aa-1] < B[bb-1])
            findkth(A+aa, m-aa, B, n, k-aa);
        else if(A[aa-1] > B[bb-1])
            findkth(A, m, B+bb, n-bb, k-bb);
        else
            return A[aa-1];
    }
};
