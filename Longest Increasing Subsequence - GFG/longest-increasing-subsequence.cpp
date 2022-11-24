//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int solve(int ind, int prevInd, int n, int a[])
    {
       //base case
      if(ind == n) return 0;
       
      int excl = 0 + solve(ind+1, prevInd, n, a);
      int incl = 0;
      if(prevInd == -1 || ( a[ind] > a[prevInd]) )
            incl = 1 + solve(ind+1, ind, n, a);
            
      return max(excl, incl);
    }
    
    int solveMem(int ind, int prevInd, int n, int a[], vector<vector<int>> &dp)
    {
       //base case
      if(ind == n) return 0;
      
      if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
       
      int excl = 0 + solveMem(ind+1, prevInd, n, a, dp);
      int incl = 0;
      if(prevInd == -1 || a[ind] > a[prevInd] )
            incl = 1 + solveMem(ind+1, ind, n, a, dp);
            
      return dp[ind][prevInd+1] = max(excl, incl);
    }
    
    int solveTab(int n, int a[])
    {
       vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
       
          
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int prevInd = ind-1; prevInd >= -1; prevInd--)
            {
                  int excl = 0 + dp[ind+1][prevInd+1];
                  int incl = 0;
                  if(prevInd == -1 || a[ind] > a[prevInd] )
                        incl = 1 + dp[ind+1][ind+1];
                        
                   dp[ind][prevInd+1] = max(excl, incl);
            }
        }
        return dp[0][-1+1];
    }
    
    int solveSpace(int n, int a[])
    {
       vector<int> next(n+1, 0), curr(n+1, 0);
       
          
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int prevInd = ind-1; prevInd >= -1; prevInd--)
            {
                  int excl = 0 + next[prevInd+1];
                  int incl = 0;
                  if(prevInd == -1 || a[ind] > a[prevInd] )
                        incl = 1 + next[ind+1];
                        
                   curr[prevInd+1] = max(excl, incl);
            }
            next = curr;
        }
        return curr[-1+1];
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   return solve(0, -1, n, a);
    
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));  //right shift for prevInd
        // return solveMem(0, -1, n, a, dp);
        
        // return solveTab(n, a);
        
        // return solveSpace(n, a);
        
        //approach 5;
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(a[prev] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends