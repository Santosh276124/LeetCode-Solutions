class Solution {
public:
    int  n;
    int m;
    bool solve(int x, int y, int ind, vector<vector<char>>& board, string word, 
              vector<vector<int>>& vis, int dx[], int dy[])
    {
        if(ind == word.length())
            return true;
        
        if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[ind]|| vis[x][y] == 1)
            return false;
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            bool ans = solve(nx, ny, ind+1, board, word , vis, dx, dy);
            
            if(ans) return true;
        }
        
        vis[x][y] = 0;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        n = board.size();
        m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int dx[] = {-1, 0, 1, 0};
        int dy[]= {0, -1, 0, 1};
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                
                if(board[i][j] == word[0] && vis[i][j] == 0){
                    
                    bool ans = solve(i, j, 0, board, word, vis, dx, dy);
                    if(ans)
                        return true;
                }
            }
        }
        
        return false;
    }
};