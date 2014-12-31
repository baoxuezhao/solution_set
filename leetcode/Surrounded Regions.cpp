class Solution {
public:
    void solve(vector<vector<char>> &board) {
        const int m = board.size();
        if(m == 0) return;
        
        int n = board[0].size();
        
        for(int i=0; i<m; i++)
        {
            bfs(board, i, 0);
            bfs(board, i, n-1);
        }
        
        for(int j=0; j<n; j++)
        {
            bfs(board, 0, j);
            bfs(board, m-1, j);
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
    
    void bfs(vector<vector<char>> &board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
        
            if(board[x][y] != 'O')
                continue;
            
            board[x][y] = '*';
            
            q.push(make_pair(x, y+1));
            q.push(make_pair(x, y-1));
            q.push(make_pair(x+1, y));
            q.push(make_pair(x-1, y));
        }
    }
};
