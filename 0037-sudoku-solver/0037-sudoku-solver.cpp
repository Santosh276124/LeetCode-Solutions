class Solution {
public:
    bool isValid(int r, int c, char k, vector<vector<char>>& board){
        
        for(int i = 0; i < 9; i++){
            
            //row check
            if(board[r][i] == k) return false;
            
            //col check
            if(board[i][c] == k) return false;
            
            //box check
            if(board[3 * (r/3) + (i/3)][3 * (c/3) + (i%3)] == k) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                        
                        if(isValid(i, j, k, board)){
                            
                            board[i][j] = k;
                            
                            if(solve(board))
                                return true;
                            
                            else
                                board[i][j] = '.';
                                
                        }
                    }
                           
                    return false;
                }
            }
        }
                           
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};