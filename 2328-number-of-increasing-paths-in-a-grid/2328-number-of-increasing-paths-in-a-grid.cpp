class Solution {
public:
    int n;
    int m;
    int mod = 1e9+7;
    int solve(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& dp){
        
        
        if(x < 0 || x >= n || y < 0 || y >= m )
            return 1;
        
        if(dp[x][y] != -1)
            return (dp[x][y])%mod;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        int maxi = 1;
        
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if( nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] < mat[x][y]){
                maxi = (maxi%mod + (solve(nx, ny, mat, dp))%mod)%mod ;
            }
        }
        
        return dp[x][y] = maxi%mod;
    }
    int countPaths(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        
        int ans = 0;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                int cnt = solve(i, j, mat, dp);
                
                ans = (ans%mod + cnt%mod)%mod;
                
            }
        }
        
        return ans;
    }
};