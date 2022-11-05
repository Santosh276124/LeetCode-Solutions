class Solution {
    bool dfs(int i, int j, vector<vector<char>> &board, string word, int ind, vector<vector<int>> &vis)
    {
        //base case
        if(ind == word.length())
            return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[ind] || vis[i][j] == 1)
            return false;
        
        vis[i][j] = 1;
        
        bool ans =  dfs(i+1, j, board, word, ind+1, vis)||
                    dfs(i, j+1, board, word, ind+1, vis)||
                    dfs(i-1, j, board, word, ind+1, vis)||
                    dfs(i, j-1, board, word, ind+1, vis);
        
        vis[i][j] = 0;
        
        return ans;
                   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int n = board.size();
        int m = board[0].size();
       vector<vector<int>> vis(n, vector<int>(m, 0));
  
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0] && vis[i][j] == 0)
                {
                    bool ans = dfs(i, j, board, word, 0, vis);
                        if(ans) return true;
                }
            }
        }
        
        return false;
    
    }
};