//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(int ind, int transaction, int k, int n, int a[], vector<vector<int>>& dp)
  {
      if(ind == n || transaction >= 2*k) return 0;
      
      if(dp[ind][transaction] != -1) return dp[ind][transaction];
      
      if(transaction % 2 == 0) // can buy
      {
          return dp[ind][transaction] = max( -a[ind] + solve(ind + 1, transaction+1, k, n, a, dp), 
                                             0 + solve(ind+1 , transaction, k, n , a, dp));
      }
      
      return dp[ind][transaction] = max( a[ind] + solve(ind + 1, transaction+1, k, n, a, dp), 
                                         0 + solve(ind + 1, transaction, k, n, a, dp));
  }
  
  int Tab(int k, int n, int a[])
  {
      vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
      
      for(int ind = n-1; ind >= 0; ind--)
      {
          for(int transaction = 2*k-1; transaction >= 0; transaction--)
          {
              if(transaction % 2 == 0) // can buy
              {
                 dp[ind][transaction] = max( -a[ind] + dp[ind + 1][transaction+1] , 
                                                     0 + dp[ind+1][transaction]);
              }
              else {
                 dp[ind][transaction] = max( a[ind] + dp[ind + 1][transaction+1] , 
                                         0 + dp[ind + 1][transaction] );
              }
          }
      }
      
      return dp[0][0];
      
  }
  
  int Space(int k, int n, int a[])
  {
      vector<int> next(2*k+1, 0);
      vector<int> curr(2*k+1, 0);
      
      for(int ind = n-1; ind >= 0; ind--)
      {
          for(int transaction = 2*k-1; transaction >= 0; transaction--)
          {
              if(transaction % 2 == 0) // can buy
              {
                curr[transaction] = max( -a[ind] +next[transaction+1] , 
                                                     0 + next[transaction]);
              }
              else {
                curr[transaction] = max( a[ind] + next[transaction+1] , 
                                         0 + next[transaction] );
              }
          }
          
          next = curr;
      }
      
      return curr[0];
      
  }
    int maxProfit(int k, int n, int A[]) {
        // code here    
        
        // vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
        
        // return solve(0, 0, k, n, A, dp);
        
        return Space(k, n, A);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends