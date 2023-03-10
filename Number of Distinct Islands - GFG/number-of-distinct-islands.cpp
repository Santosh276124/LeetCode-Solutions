//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int n;
  int m;
   void dfs(int i, int j, vector<vector<int>>& vis, int dx[], int dy[], vector<vector<int>>& grid, vector<pair<int,int>>& vec, int baser, int basec)
   {
       vis[i][j] = 1;
       
       vec.push_back({i-baser, j-basec});
       
       for(int k = 0; k < 4; k++)
       {
           int nx = i + dx[k];
           int ny = j + dy[k];
           
           if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == 1)
           {
               dfs(nx, ny, vis, dx, dy, grid, vec, baser, basec);
           }
       }
       
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
   
     
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
    
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        
        set< vector<pair<int,int>> > s;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            { 
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    
                    dfs(i, j, vis, dx, dy, grid, vec, i, j);
                    
                    s.insert(vec);
                    
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends