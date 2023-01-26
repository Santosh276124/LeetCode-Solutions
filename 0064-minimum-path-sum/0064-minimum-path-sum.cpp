class Solution {
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>>& grid,  vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0 ) return 1e9;
        
        if(i == 0 && j == 0) return grid[0][0];
        
        if(dp[i][j] != -1) return  dp[i][j];
        
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        
        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
         n = grid.size();
         m = grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(n-1, m-1, grid, dp);
    }
};