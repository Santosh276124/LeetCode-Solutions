class Solution {
public:
    bool isSafe(int r, int c, vector<string>& temp, int n){
        
        int row = r;
        int col = c;
        //row check
        while(col >= 0){
            if(temp[row][col] == 'Q')
                return false;
            col--;
        }
        
        
        col = c;
        //upper left disgonal check
        
        while(row >= 0 && col >= 0){
            if(temp[row][col] == 'Q')
                return false;
            col--;
            row--;
        }
        
        col = c;
        row = r;
        //bottom left disgonal check
        
        while(row < n && col >= 0){
            if(temp[row][col] == 'Q')
                return false;
            col--;
            row++;
        }
        
        return true;
    }
    void solve(int col, vector<string>& temp, vector<vector<string>>& ans, int n){
        
        if(col >= n){
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n; row++){
            
            if(isSafe(row, col, temp, n)){
                
                
                temp[row][col] = 'Q';
                
                solve(col+1, temp, ans, n);
                
                temp[row][col] = '.';
                
                
            }
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        // vector<vector<int>> mat(n, vector<int>(n, 0));
        
        vector<string> temp(n, string(n, '.'));
        
        solve(0, temp, ans, n);
        
        
        return ans;
        
        
        
        
        
    }
};