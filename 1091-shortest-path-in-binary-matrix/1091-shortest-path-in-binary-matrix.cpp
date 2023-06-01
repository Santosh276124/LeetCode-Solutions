class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        queue<pair<int,pair<int,int>> > q;
        
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        q.push({1, {0, 0}});
        
        vis[0][0] = 1;
        
        while(!q.empty()){
            
            auto top = q.front();
            
            int dist = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            q.pop();
            
            if(x == n-1 && y == n-1)
                return dist;
            
            for(int i = 0; i < 8; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && vis[nx][ny] == 0){
                    
                    vis[nx][ny] = 1;
                    
                    q.push({dist+1, {nx, ny}});
                    
                }
            }
            
        }
        
        return -1;
    }
};