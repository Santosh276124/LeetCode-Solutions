class Solution {
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        //base case
        if(j < 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j])
        {
            return dp[i][j] = solve(i-1, j-1, s, t ,dp) + solve(i-1, j, s, t, dp);
        }
        else
            return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    int solveTab(string &s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(s[i-1] == t[j-1])
                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                     dp[i][j] = dp[i-1][j];
            }
        }
       return (int)dp[n][m];     
    }
    
    int solveSpace(string &s, string t)
    {
        int n = s.length();
        int m = t.length();
       vector<double> prev(m+1, 0), curr(m+1, 0);
        
       prev[0] = curr[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(s[i-1] == t[j-1])
                     curr[j] = prev[j-1] + prev[j];
                else
                     curr[j] = prev[j];
            }
            prev = curr;
        }
       return (int)curr[m];     
    }
    
    int solve1Dspace(string &s, string &t)
    {
        int n = s.length();
        int m = t.length();
       vector<double> prev(m+1, 0);
        
       prev[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = m; j >= 1; j--)
            {
                if(s[i-1] == t[j-1])
                     prev[j] = prev[j-1] + prev[j];
            }
        }
       return (int)prev[m];  
    }
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(n-1, m-1, s, t, dp);
        
        // return solveTab(s, t);
        
        return solve1Dspace(s, t);
    }
};