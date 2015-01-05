class Solution {
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int res = m+n;
        m--, n--, res--;
        while(m >= 0 && n >= 0)
        {
            if(A[m] > B[n])
                A[res--] = A[m--];
            else
                A[res--] = B[n--];
        }
        while(n >= 0)
        {
            A[res--] = B[n--];
        }
    }
};
