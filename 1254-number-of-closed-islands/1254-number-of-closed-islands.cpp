class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int dx[], int dy[]){
   
        
        vis[i][j] = 1;
        
        for(int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == 0){
                dfs(nx, ny, grid, vis, dx, dy);
            }
            
            
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        //dfs for boundary 0s
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(i == 0 || j == 0 || i == n-1  || j == m-1)
                    if(!vis[i][j] && grid[i][j] == 0){
                        dfs(i, j, grid, vis, dx, dy);
                    }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    ans++;
                    dfs(i, j, grid, vis, dx, dy);
                }
            }
        }
        return ans;
    }
};