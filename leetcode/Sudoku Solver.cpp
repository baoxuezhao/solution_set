class Solution {
public:
    int row[9];
    int col[9];
    int cell[3][3];
        
    void solveSudoku(vector<vector<char> > &board) {
        
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cell,0, sizeof(cell));
        
        vector<pair<int,int> > empty;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                    empty.push_back(make_pair(i, j));
                else    
                    set(i, j, board[i][j]-'1');
            }
        }
        dfs(board, empty, 0);
    }
    
    bool dfs(vector<vector<char> > &board, vector<pair<int,int> > &empty, int idx)
    {
        if(idx == empty.size())
        {
            return true;
        }
        int x = empty[idx].first;
        int y = empty[idx].second;
        
        for(int i=0; i<9; i++)
        {
            if(isvalid(x, y, i))
            {
                board[x][y] = ('1'+i);
                set(x, y, i);
                bool res1 = dfs(board, empty, idx+1);
                if(res1) return true;
                reset(x, y, i);
                board[x][y] = '.';
            }
        }
        return false;
    }
    
    
    bool isvalid(int i, int j, int val)
    {
        if((row[i] >> val) & 1) return false;
        if((col[j] >> val) & 1) return false;
        if((cell[i/3][j/3] >> val) & 1) return false;
        return true;
    }
    
    void set(int i, int j, int val)
    {
        row[i] |= (1 << val);
        col[j] |= (1 << val);
        cell[i/3][j/3] |= (1 << val);
    }
    
    void reset(int i, int j, int val)
    {
        row[i] &= ~(1 << val);
        col[j] &= ~(1 << val);
        cell[i/3][j/3] &= ~(1 << val);
    }
};
