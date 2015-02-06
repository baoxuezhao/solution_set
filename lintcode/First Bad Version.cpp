class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        
        int start = 1, end = n;
        while(start <= end)
        {
            int m = start+(end-start)/2;
            if(VersionControl::isBadVersion(m))
                end = m-1;
            else
                start = m+1;
        }
        return end+1;
    }
};

