//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int solve(int ind, int W, int wt[], int val[])
    {
        //base case
        if(ind == 0)
        {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        int excl = 0 + solve(ind-1, W, wt, val);
        int incl = INT_MIN;
        if(wt[ind] <= W)
           incl = val[ind] + solve(ind-1, W-wt[ind], wt, val);
           
        return max(incl, excl);
    }
    
    int solveMem(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        //base case
        if(ind == 0)
        {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int excl = 0 + solveMem(ind-1, W, wt, val, dp);
        int incl = INT_MIN;
        if(wt[ind] <= W)
           incl = val[ind] + solveMem(ind-1, W-wt[ind], wt, val, dp);
           
        return dp[ind][W] = max(incl, excl);
    }
    
    int solveTab(int W, int wt[], int val[], int n)
    {
       //base case
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
       
       for(int i = wt[0]; i <= W; i++)
         dp[0][i] = val[0];
         
        for(int ind = 1; ind < n; ind++)
        {
            for(int weight = 0; weight <= W; weight++)
            {
                int excl = 0 + dp[ind-1][weight];
                int incl = INT_MIN;
                if(wt[ind] <= weight)
                   incl = val[ind] + dp[ind-1][weight-wt[ind]];
                   
                dp[ind][weight] = max(incl, excl);
            }
        }
       
       return dp[n-1][W];
       
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
        // return solve(n-1, W, wt, val);
        
        
        // vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        // return solveMem(n-1, W, wt, val, dp);
       
       
       return solveTab(W, wt, val, n);
       
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends