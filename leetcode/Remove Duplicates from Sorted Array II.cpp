class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int k = 0;
        for(int i=0; i<n; i++)
        {
            if(k < 2 || A[i] != A[k-2])
            {
                A[k++] = A[i];
            }
        }
        return k;
    }
};
