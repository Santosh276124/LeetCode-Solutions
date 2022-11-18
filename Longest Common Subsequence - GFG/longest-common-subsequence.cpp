//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int solve(int i, int j, string s1, string s2)
    {
        if(i < 0 || j < 0) return 0;
        
        //if matches
        if(s1[i] == s2[j])
          return 1 + solve(i-1, j-1, s1, s2);
        
        return max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
    }
    
    int solveMem(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        //if matches
        if(s1[i] == s2[j])
          return dp[i][j] = 1 + solveMem(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = max(solveMem(i-1, j, s1, s2, dp), solveMem(i, j-1, s1, s2, dp));
        
    }
    
    int solveTab(int i, int j, string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])  //since we have shifted the indexes so i-1 and j-1
                   dp[i][j] = 1 + dp[i-1][j-1];
                else
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int solveSpace(int i, int j, string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        
        for(int j = 0; j <= m; j++) prev[j] = 0;
       
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])  //since we have shifted the indexes so i-1 and j-1
                   dp[i][j] = 1 + prev[j-1];
                else
                   dp[i][j] = max(prev[j], curr[j-1]);
            }
        }
        return dp[n][m];
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // return solve(x-1, y-1, s1, s2);
        
        // vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
        // return solveMem(x-1, y-1, s1, s2, dp);
        
        
       return solveTab(x, y, s1, s2);   //right shft the indexes for base case 
       /// so send index as n and m
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends