//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int price[], int ind, int n)
    {
        //base case
        if(ind == 0)
        {
            return n*price[0];
        }
        
        int excl = solve(price, ind-1, n);
        int incl = INT_MIN;
        int rodLength = ind+1;
        if(rodLength <= n)
          incl = price[ind] + solve(price, ind, n-rodLength);
          
        return max(excl, incl);
    }
    
    int solveMem(int price[], int ind, int n, vector<vector<int>> &dp)
    {
        //base case
        if(ind == 0)
        {
            return n*price[0];
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        int excl = solveMem(price, ind-1, n, dp);
        int incl = INT_MIN;
        int rodLength = ind+1;
        if(rodLength <= n)
          incl = price[ind] + solveMem(price, ind, n-rodLength, dp);
          
        return dp[ind][n] = max(excl, incl);
    }
    
    int solveTab(int price[], int N)
    {
        //base case
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        
        for(int n = 0; n <= N; n++)
         dp[0][n] = n*price[0];
         
        for(int ind = 1; ind < N; ind++)
        {
            for(int n = 0; n <= N; n++)
            {
                int excl = dp[ind-1][n];
                int incl = INT_MIN;
                int rodLength = ind+1;
                if(rodLength <= n)
                  incl = price[ind] + dp[ind][n-rodLength];
                  
                dp[ind][n] = max(excl, incl);
            }
        }
        
        return dp[N-1][N];
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        
        // return solve(price, n-1, n);
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(price, n-1, n, dp);
        
        return solveTab(price, n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends