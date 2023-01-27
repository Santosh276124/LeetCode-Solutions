//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int n;
  int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
  {
      if(i == n-1) return triangle[n-1][j];
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int down = triangle[i][j] + solve(i+1, j, triangle, dp);
      int downRight = triangle[i][j] + solve(i+1, j+1, triangle, dp);
      
      return dp[i][j] = min(down, downRight);
      
      
  }
  
  int Tab(vector<vector<int>>& triangle)
  {
      vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
      
      for(int j = 0; j < n; j++) 
          dp[n-1][j] = triangle[n-1][j];
          
      for(int i = n-2; i >= 0; i--)
      {
          for(int j = n-1; j >= 0; j--)
          {
              int down = triangle[i][j] + dp[i+1][j];
              int downRight = triangle[i][j] + dp[i+1][j+1];
              
              dp[i][j] = min(down, downRight);
          }
      }
      
      return dp[0][0];
  }
    int minimizeSum(int size, vector<vector<int>>& triangle) {
        // Code here
        n = size;
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(0, 0, triangle, dp);
        
        return Tab(triangle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends