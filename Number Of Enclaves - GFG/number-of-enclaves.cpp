//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(grid[i][j] == 1){
                      q.push({i, j});
                      vis[i][j] = 1;
                    }
                }
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == 1)
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    ans++;
            }
        }
        
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends