//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int solveTab(vector<int>& height)
  {
      int n = height.size();
      vector<int> dp(n+1, 0);
      
    
      
      for(int ind = 1; ind < n; ind++)
      {
          int one = INT_MAX;
          if(ind-1 >= 0)
           one = abs(height[ind]-height[ind-1])+ dp[ind-1];
          
          int two = INT_MAX;
          if(ind-2 >= 0)
           two = abs(height[ind]-height[ind-2])+ dp[ind-2];
          
          dp[ind] = min(one, two);
      }
      
      return dp[n-1];
  }
  
  int solve(int ind, vector<int> &height, vector<int> &dp)
  {
      if(ind  < 0) return 0;
      
      if(ind == 0) return 0;
      
      if(dp[ind] != -1) return dp[ind];
      
      int one = INT_MAX;
      if(ind-1 >= 0)
       one = abs(height[ind]-height[ind-1])+ solve(ind-1, height, dp);
      
      int two = INT_MAX;
      if(ind-2 >= 0)
       two = abs(height[ind]-height[ind-2])+solve(ind-2, height, dp);
      
      return dp[ind] = min(one, two);
      
      
  }
    int minimumEnergy(vector<int>& height, int n) {
        
        // Code here
        
        // vector<int> dp(n+1, -1);
        
        // return solve(n-1 , height, dp);
        
        return solveTab(height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends