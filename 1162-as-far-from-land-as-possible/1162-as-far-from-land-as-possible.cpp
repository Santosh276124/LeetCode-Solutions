class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        
        // vector<pair<int,int>> ds = {(0, -1), (-1, 0), (0, 1), (1, 0)};
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        int cnt  = 0;
        while(!q.empty())
        {
            cnt++;
            int len = q.size();
            
            for(int i = 0; i < len; i++)
            {
                auto front = q.front();
                q.pop();
                
                int x = front.first;
                int y = front.second;
                
                for(int j = 0; j < 4; j++)
                {
                    int newx = x + dx[j];
                    int newy = y + dy[j];
                    
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 0)
                    {
                        
                        q.push({newx, newy});
                        grid[newx][newy] = 1;
                    }
                }
            }
            
            
        }
        
        return cnt > 1 ? cnt-1 : -1;
    }
};