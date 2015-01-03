class Solution {
public:
    int singleNumber(int A[], int n) {
        int map[sizeof(int)*8];
        memset(map, 0, sizeof(map));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<sizeof(int)*8; j++)
            {
                if(A[i] & (1 << j))
                {
                    map[j]++;
                    map[j] %= 3;
                }
            }
        }
        
        int res = 0;
        for(int j=0; j<sizeof(int)*8; ++j)
        {
            if(map[j] == 1) res |= (1 << j);
        }
        return res;
    }
};
