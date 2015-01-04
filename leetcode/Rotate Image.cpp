class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int m = matrix.size();
        if(m == 0) return;
        const int n = matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n-i; j++)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
};
