//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp)
  {
      if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
      
      if(i == n-1){
          if(j1 == j2) return grid[i][j1];
          
          else return grid[i][j1] + grid[i][j2];
      }
      
      if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
      
      int maxi = 0;
      
      for(int k1 = -1; k1 <= 1; k1++) // direction for each dir of r1 we have 3 dir for r2
    //   i will remain same fr both robots
    // Only column will change
      {
          for(int k2 = -1; k2 <= 1; k2++)
          {
              if(j1 == j2)
              {
                  maxi = max(maxi, grid[i][j1] + solve(i+1, j1+k1, j2+k2, grid, n, m, dp));
              }
              else
              {
                  maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1+k1, j2+k2, grid, n, m, dp));
              }
          }
      }
      return dp[i][j1][j2] = maxi;
      
  }
  
  int Tab(vector<vector<int>>& grid, int n, int m)
  {
      
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, 0) ) );
        
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j1 = m-1; j1 >= 0; j1--)
            {
                for(int j2 = m-1; j2 >= 0; j2--)
                {
                    int maxi = -1e9;
                      
                      for(int k1 = -1; k1 <= 1; k1++) // direction for each dir of r1 we have 3 dir for r2
                      {
                          for(int k2 = -1; k2 <= 1; k2++)
                          {
                              int value = 0;
                              
                              if(j1 == j2)
                              {
                                  value += grid[i][j1];
                               
                              }
                              else
                              {
                                  value += grid[i][j1] + grid[i][j2];
                                 
                              }
                              
                              
                              if(j1+k1 >= 0 && j1+k1 <= m && j2+k2 >= 0 && j2+k2 < m)
                                  value += dp[i+1][j1+k1][j2+k2];
                                  
                              else value += -1e9;
                              
                              maxi = max(maxi, value);
                          }
                      }
                     
                      dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
      
  }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1) ) );
        // return solve(0, 0, m-1, grid, n, m, dp);  //r1(0, 0) and r2(0, m-1); i will be same in both case
        
        return Tab(grid, n, m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends