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
    int maxProfit(int k, int n, int A[]) {
        // code here    
        
        vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
        
        return solve(0, 0, k, n, A, dp);
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