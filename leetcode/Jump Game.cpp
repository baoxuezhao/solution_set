class Solution {
public:
    bool canJump(int A[], int n) {
        int maxr = 0, i=0;
        for(; i<n && i<=maxr; i++)
            maxr = max(maxr, i+A[i]);
        if(i == n)
            return true;
        else
            return false;
    }
};
