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

// new solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        
        int m_start = 0;
        int n_start = 0;
        
        int m_end = m - 1;
        int n_end = n - 1;
        
        while (m_end >= m_start && n_end >= n_start) {
            for (int i = n_start; i <= n_end; ++i) {
                res.push_back(matrix[m_start][i]);
            }
            for (int i = m_start+1; i <= m_end-1; ++i) {
                res.push_back(matrix[i][n_end]);
            }
            if (m_end > m_start) {
                for (int i = n_end; i >= n_start; --i) {
                    res.push_back(matrix[m_end][i]);
                }
            }
            if (n_end > n_start) {
                for (int i = m_end-1; i>=m_start+1; --i) {
                    res.push_back(matrix[i][n_start]);
                }
            }
            m_start += 1;
            n_start += 1;
            m_end -= 1;
            n_end -= 1;
        }
        return res;
    }
};
