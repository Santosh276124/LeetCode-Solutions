class Solution {
    bool isPresent(int i, int j, vector<vector<char>>& board, string &word,  vector<vector<bool>>& vis, int ind)
    {
        int n = board.size();
        int m = board[0].size();
        //base case
        if(ind == word.length())
            return true;
        
        if(i < 0 || j < 0|| i >= n || j >= m || vis[i][j] == true || board[i][j] != word[ind]) return false;
        
        vis[i][j] = true;
        
    bool down = isPresent(i+1, j, board, word, vis, ind+1);
    bool up = isPresent(i-1, j, board, word, vis, ind+1);
    bool right = isPresent(i, j+1, board, word, vis, ind+1);
    bool left = isPresent(i, j-1, board, word, vis, ind+1);
        
        vis[i][j] = false;
        
        return (down||up||right||left);
        
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j< m; j++)
            {
                if(board[i][j] == word[0] && vis[i][j] == false)
                {
                    bool ans = isPresent(i, j, board, word, vis, 0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};