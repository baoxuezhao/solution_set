class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rows[9];
        int cols[9];
        int cells[3][3];
        
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(cells,0, sizeof(cells));
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.') continue;
                int v = (board[i][j] - '1');
                
                if(rows[i] & (1 << v)) return false;
                rows[i] |= (1 << v);
                
                if(cols[j] & (1 << v)) return false;
                cols[j] |= (1 << v);
                
                if(cells[i/3][j/3] & (1 << v)) return false;
                cells[i/3][j/3] |= (1 << v);
            }
        }
        return true;
    }
};
