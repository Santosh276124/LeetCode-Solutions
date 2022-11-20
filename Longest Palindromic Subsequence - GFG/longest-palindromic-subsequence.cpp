//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int LCS(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
         return dp[i][j] = 1 + LCS(i-1, j-1, s1, s2, dp);
          
        return dp[i][j] = max(LCS(i-1, j, s1, s2, dp), LCS(i, j-1, s1, s2, dp));
        
       
    }
  public:
    int longestPalinSubseq(string A) {
        //code here
        string s1 = A;
        reverse(A.begin(), A.end());
        int n = s1.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return LCS(n-1, n-1, s1, A, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends