//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int solve(int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        if(i == 0 || j == 0) return 1;
        
        int top = solve(i-1, j, n, m);
        int left = solve(i, j-1, n, m);
        
        return top + left;
    }
    int Mem(int i, int j, int n, int m, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        if(i == 0 || j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int top = Mem(i-1, j, n, m, dp);
        int left = Mem(i, j-1, n, m, dp);
        
        return dp[i][j] = top + left;
    }
    
    int Tab(int n, int m)
    {
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++) dp[0][j] = 1;
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                
                int top = dp[i-1][j];
                int left = dp[i][j-1];
                
                 dp[i][j] = top + left;
            }
        }
        
        return dp[n-1][m-1];
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int n, int m)
    {
        //code here
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return Mem(n-1, m-1, n, m, dp);
        
        return Tab(n, m);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends