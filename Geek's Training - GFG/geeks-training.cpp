//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int ind, int prev, vector<vector<int>>& points, int n)
  {
      if(ind == 0)
      {
          int maxi = 0;
          for(int i = 0; i < 3; i++)
          {
              if(i != prev) 
                 maxi = max(maxi, points[ind][i]);
          }
          return maxi;
      }
      
      int maxPoint = 0;
      for(int i = 0; i < 3; i++)
      {
          if(i != prev)
          {
              int take = points[ind][i] + solve(ind-1, i, points, n); 
              maxPoint = max(maxPoint, take);
          }
      }
      
      return maxPoint;
  }
  int solveMem(int ind, int prev, vector<vector<int>>& points, int n, vector<vector<int>>& dp)
  {
      if(ind == 0)
      {
          int maxi = 0;
          for(int i = 0; i < 3; i++)
          {
              if(i != prev) 
                 maxi = max(maxi, points[ind][i]);
          }
          return maxi;
      }
      
      if(dp[ind][prev] != -1) return dp[ind][prev];
      
      int maxPoint = 0;
      for(int i = 0; i < 3; i++)
      {
          if(i != prev)
          {
              int take = points[ind][i] + solveMem(ind-1, i, points, n, dp); 
              maxPoint = max(maxPoint, take);
              
          }
      }
      
      return dp[ind][prev] = maxPoint;
  }
   int solveTab(vector<vector<int>>& points, int n)
  {
     vector<vector<int>> dp(n+1, vector<int>(4, 0));
     
     dp[0][0] = max(points[0][1], points[0][2]);
     dp[0][1] = max(points[0][0], points[0][2]);
     dp[0][2] = max(points[0][0], points[0][1]);
     dp[0][3] = max(points[0][1], max( points[0][2], points[0][0]));
     
     for(int ind = 1; ind < n; ind++)
     {
         for(int prev = 0; prev < 4; prev++)
         {
             int maxPoint = 0;
              for(int i = 0; i < 3; i++)
              {
                  if(i != prev)
                  {
                      int take = points[ind][i] + dp[ind-1][i]; 
                      maxPoint = max(maxPoint, take);
                      
                  }
              }
              
               dp[ind][prev] = maxPoint;
         }
     }
     
     return dp[n-1][3];
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here 
        // vector<vector<int>> dp(n+1, vector<int>(4, -1));
        // return solveMem(n-1, 3, points, n, dp);
        
        return solveTab(points, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends