class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int level = triangle.size()-2; level >= 0; level--)
        {
            for(int r = 0; r<triangle[level].size(); r++)
            {
                triangle[level][r] += min(triangle[level+1][r], triangle[level+1][r+1]);
            }
        }
        return triangle[0][0];
    }
};
