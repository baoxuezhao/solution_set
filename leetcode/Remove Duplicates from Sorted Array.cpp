class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0, j=0;
        for(int i=0; i<n; i++)
        {
            if(j == 0 || A[i] != A[j-1])
                A[j++] = A[i];
        }
        return j;
    }
};
