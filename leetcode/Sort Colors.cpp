class Solution {
public:
    void sortColors(int A[], int n) 
    {
        int left = 0, mid = 0, right = n-1;
        while(mid <= right)
        {
            if(A[mid] == 0)
            {
                swap(A[mid], A[left]);
                left++;
                mid++;
            }
            else if(A[mid] == 1)
                mid++;
            else
            {
                swap(A[mid], A[right]);
                right--;
            }
        }
    }
};
