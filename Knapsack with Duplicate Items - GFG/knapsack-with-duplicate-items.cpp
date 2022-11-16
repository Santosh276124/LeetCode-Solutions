//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int wt[], int ind, int val[], int W)
    {
        if(ind == 0)
        {
            if(wt[0] <= W) return (W/wt[0])*val[0];
            else return 0;
        }
        
        int excl = solve(wt, ind-1, val, W);
        int incl = INT_MIN;
        if(wt[ind] <= W)
           incl = val[ind] + solve(wt, ind, val, W-wt[ind]);
           
        return max(incl, excl);
    }
    
    int solveMem(int wt[], int ind, int val[], int W, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(wt[0] <= W) return (W/wt[0])*val[0];
            else return 0;
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int excl = solveMem(wt, ind-1, val, W, dp);
        int incl = INT_MIN;
        if(wt[ind] <= W)
           incl = val[ind] + solveMem(wt, ind, val, W-wt[ind], dp);
           
        return dp[ind][W] = max(incl, excl);
    }
    
    int solveTab(int wt[],int n, int val[], int W)
    {
         
         vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
         
         for(int w = wt[0]; w <= W; w++)
           dp[0][w] = (w/wt[0])*val[0];
           
         for(int ind = 1; ind < n; ind++)
         {
             for(int weight = 0; weight <= W; weight++)
             {
                int excl = dp[ind-1][weight];
                int incl = INT_MIN;
                if(wt[ind] <= weight)
                   incl = val[ind] + dp[ind][weight-wt[ind]];
                   
                dp[ind][weight] = max(incl, excl);
             }
         }
         
         return dp[n-1][W];
         
    }
    
    int solveSpace(int wt[],int n, int val[], int W)
    {
         
        
         vector<int> prev(W+1, 0), curr(W+1, 0);
         
         for(int w = wt[0]; w <= W; w++)
           prev[w] = (w/wt[0])*val[0];
           
         for(int ind = 1; ind < n; ind++)
         {
             for(int weight = 0; weight <= W; weight++)
             {
                int excl = prev[weight];
                int incl = INT_MIN;
                if(wt[ind] <= weight)
                   incl = val[ind] + curr[weight-wt[ind]];
                   
                curr[weight] = max(incl, excl);
             }
             prev = curr;
         }
         
         return prev[W];
         
    }
    
    int solveSpaceTOoneArray(int wt[],int n, int val[], int W)
    {
         
        
         vector<int> prev(W+1, 0);
         
         for(int w = wt[0]; w <= W; w++)
           prev[w] = (w/wt[0])*val[0];
           
         for(int ind = 1; ind < n; ind++)
         {
             for(int weight = 0; weight <= W; weight++)
             {
                int excl = prev[weight];
                int incl = INT_MIN;
                if(wt[ind] <= weight)
                   incl = val[ind] + prev[weight-wt[ind]];
                   
                prev[weight] = max(incl, excl);
             }
            
         }
         
         return prev[W];
         
    }
    
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        
        // return solve(wt, n-1, val , W);
        
        
        // vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        // return solveMem(wt, n-1, val , W, dp);
        
        // return solveTab(wt,n, val, W);
        
        
        // return solveSpace(wt, n, val, W);
        
        return solveSpaceTOoneArray(wt, n, val, W);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends