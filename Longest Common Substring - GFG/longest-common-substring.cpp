//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int ans = 0;
    public:
    int solve(int i, int j, string s1, string s2)
    {
        if(i < 0 || j < 0) return 0;
        
        int incl = INT_MIN;
        if(s1[i] == s2[j]){
           incl = 1 + solve(i-1, j-1, s1, s2);
        //   ans = max(ans, incl);
        }
        
          int excl = 0 + solve(i-1, j-1, s1, s2);
          
        return max(incl, excl);
          
         
    }
    int solveTab(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1]){
                 dp[i][j] = 1 + dp[i-1][j-1];
                 ans = max(ans, dp[i][j]);
                }
                else
                  dp[i][j] = 0;
            }
        }
        return ans;
        
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
       return solveTab(S1, S2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends