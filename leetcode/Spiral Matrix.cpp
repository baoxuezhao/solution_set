class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m == 0) return vector<int>();
        
        int n = matrix[0].size();
        int x = 0, y = 0;
        
        vector<int> res;
        
        while(m >= 1 && n >= 1)
        {
            for(int j=0; j<n; j++)
                res.push_back(matrix[x][y+j]);
            
            for(int i=1; i<m-1; i++)
                res.push_back(matrix[x+i][y+n-1]);
            
            if(m > 1)
            {
                for(int j=n-1; j>=0; j--)
                    res.push_back(matrix[x+m-1][y+j]);   
            }
            if(n > 1)
            {
                for(int i=m-2; i>=1; i--)
                    res.push_back(matrix[x+i][y]);   
            }
            
            x++;
            y++;
            
            m -= 2;
            n -= 2;
        }
        return res;
    }
};
