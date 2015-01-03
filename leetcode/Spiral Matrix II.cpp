class Solution {
public:
    vector<vector<int> > generateMatrix(int n) 
    {
        vector<vector<int> > res(n, vector<int>(n, -1));
     
        int width = n;
        int x = 0, y = 0;
        int global = 1;
        while(width > 0)
        {
            for(int i=0; i<width; i++)
                res[x][y+i] = global++;
            
            if(width > 1) //??? be careful
            {
                for(int i=1; i<width-1; i++)
                    res[x+i][y+width-1] = global++;
            
                for(int i=width-1; i>=0; i--)
                    res[x+width-1][y+i] = global++;
                
                for(int i=width-2; i>=1; i--)
                    res[x+i][y] = global++;
            }
            
            width -= 2;
            x++;
            y++;
        }
        return res;
    }
};
