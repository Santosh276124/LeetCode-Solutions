class Solution {
public:
    int n;
    int m;
    int cnt = 0;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int dx[], int dy[]){
        
        vis[i][j] = 1;
        cnt++;
        
        for(int k = 0; k < 4; k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            
            if(nx >= 0 && nx < n && ny>= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 1){
                
                dfs(nx, ny, grid, vis, dx, dy);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
         n = grid.size();
         m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
          int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        int totalOnes = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(!vis[i][j] && grid[i][j] == 1)
                        dfs(i, j, grid, vis, dx, dy);
                }
                
                if(grid[i][j] == 1)
                    totalOnes++;
            }
        }
        
        cout<<cnt<<" ";
        
        
      
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                     if(!vis[i][j] && grid[i][j] == 1){
//                         // cnt++;
//                         dfs(i, j, grid, vis, dx, dy);
                        
//                     }
                        
//             }
//         }
        
        return totalOnes - cnt;
        
    }
};