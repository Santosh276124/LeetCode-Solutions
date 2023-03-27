class Solution {
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i < 0 || i >= n || j < 0 || j >= m )
            return 1e9;
        
        if(i == 0 && j == 0) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + solve(i-1, j, grid ,dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(n-1, m-1, grid, dp);
    }
};