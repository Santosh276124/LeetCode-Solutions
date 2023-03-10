//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int n;
  int m;
   void dfs(int i, int j,  vector<vector<int>>& vis, int dx[], int dy[], vector<vector<char>>& grid)
   {
       vis[i][j] = 1;
       
       for(int k = 0; k < 8; k++)
       {
           int nx = i + dx[k];
           int ny = j + dy[k];
           
           if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == '1')
           {
               dfs(nx, ny, vis, dx, dy, grid);
           }
       }
       
   }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int ans = 0;
        
        int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, vis, dx, dy, grid);
                    
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends