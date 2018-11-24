class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int left = 0, right = n-1;
        while(left <= right)
        {
            while(A[left] <= 0) left++;
            while(A[right] > 0) right--;
            
            if(left <= right)
            {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        }
        if(left >= n) return 1;
        
        int *B = A + left;
        int len = n-left;
        
        for(int i=0; i<len; i++)
        {
            if(abs(B[i]) <= len && B[abs(B[i])-1] > 0)
            {
                B[abs(B[i])-1] = 0-B[abs(B[i])-1];
            }
        }
        for(int i=0; i<len; i++)
        {
            if(B[i] > 0) return i+1;
        }
        return len+1;
    }
};

// new solution
// http://www.cnblogs.com/grandyang/p/4395963.html
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
