class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        const int m = board.size();
        if(m == 0) return false;
        const int n = board[0].size();
        
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs(board, word, i, j, 0, visit)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, string &word, int i, int j, int idx, vector<vector<bool> > &visit)
    {
        const int m = board.size();
        const int n = board[0].size();
        
        if(idx == word.size()) return true;
        
        if(i < 0 || i>=m || j<0 || j>=n || visit[i][j] || board[i][j] != word[idx]) 
            return false;
        
        visit[i][j] = true;
        bool res = dfs(board, word, i+1, j, idx+1, visit) ||
                     dfs(board, word, i-1, j, idx+1, visit) ||
                     dfs(board, word, i, j+1, idx+1, visit) ||
                     dfs(board, word, i, j-1, idx+1, visit);
        
        visit[i][j] = false;
        return res;
    }
};
