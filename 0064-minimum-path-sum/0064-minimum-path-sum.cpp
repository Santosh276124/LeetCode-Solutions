class Solution {
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i < 0 || j < 0 )
            return 1e9;
        
        if(i == 0 && j == 0) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + solve(i-1, j, grid ,dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
     int solveTab(vector<vector<int>>& grid){
        
         // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
         vector<int> prev(m, 0), curr(m, 0);
         
         
         
         curr[0] = grid[0][0];
         
         for(int i = 0; i < n; i++)
         {
             for(int j = 0; j < m; j++){
                 
                 if(i == 0 && j == 0) continue;
                 
                 int up = 1e9;
                 int left = 1e9;
                 
                 if(i-1 >= 0 )
                     up =  prev[j];
              
                     
                 if(j-1 >= 0)
                    left = curr[j-1];
                 
                 curr[j] = grid[i][j] + min(up, left);
             }
             prev = curr;
         }
         
         return prev[m-1];
         
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        // return solve(n-1, m-1, grid, dp);
        return solveTab(grid);
    }
};