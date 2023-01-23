//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int dfs(int ind, vector<int> &height, int k)
  {
      if(ind == 0) return 0;
      
      int minCost = INT_MAX;
      
      for(int j = 1; j <= k; j++)
      {
          
          if(ind-j >= 0) {
              int jumpCost = abs(height[ind]-height[ind-j]) + dfs(ind-j, height, k);
              
              minCost = min(minCost, jumpCost);
          }
      }
      
      return minCost;
  }
  // O(n)*k
  // O(n)
  int memo(int ind, vector<int> &height, int k, vector<int> &dp)
  {
      if(ind == 0) return 0;
      
      if(dp[ind] != -1) return dp[ind];
      
      int minCost = INT_MAX;
      
      for(int j = 1; j <= k; j++)
      {
          
          if(ind-j >= 0) {
              int jumpCost = abs(height[ind]-height[ind-j]) + memo(ind-j, height, k, dp);
              
              minCost = min(minCost, jumpCost);
          }
      }
      
      return dp[ind] = minCost;
  }
  // O(n)*k   - O(n) + O(n)
  
   int Tab(vector<int> &height, int k)
  {
      int n = height.size();
      vector<int> dp(n+1, 0);
      
      dp[0] = 0;
      
      for(int ind = 1; ind < n; ind++)
      {
          int minCost = INT_MAX;
      
          for(int j = 1; j <= k; j++)
          {
              
              if(ind-j >= 0) {
                  int jumpCost = abs(height[ind]-height[ind-j]) + dp[ind-j];
                  
                  minCost = min(minCost, jumpCost);
              }
          }
          
          dp[ind] = minCost;
      }
      return dp[n-1];
  }
    int minimizeCost(vector<int>& height, int n, int k) {
   
        
        // return dfs(n-1, height, k);
        
        // vector<int> dp(n+1, -1);
        
        // return memo(n-1, height, k, dp);
        
        return Tab(height, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends