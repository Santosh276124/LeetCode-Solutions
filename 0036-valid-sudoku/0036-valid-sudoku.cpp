class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
        int n = board.size();

        for(int i = 0;  i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(board[i][j] != '.'){
                    
                    char val = board[i][j];
                    
                    for(int ind = 0; ind < 9; ind++){
                        //row check
                        if(i != ind && board[ind][j] == val) return false;
                        
                        //col ceheck
                        if(j != ind && board[i][ind] == val) return false;
                        
                        //box check
                        if(i != (3 * (i/3) + (ind/3)) && j != (3 * (j/3) + (ind%3)) && 
                           board[3 * (i/3) + (ind/3)][3 * (j/3) + (ind%3)] == val) return false;
                    }
                        
                        
                        
                    }
                }
            }
            return true;
  
    }
};