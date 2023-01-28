class Solution {
    int LCS(string s1, string s2)
    {
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int Space(string s1, string s2)
    {
        int n = s1.length();
       vector<int> prev(n+1, 0);
       vector<int> curr(n+1, 0);
        
       
        
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            
            prev = curr;
        }
        return prev[n];
    }
public:
    int longestPalindromeSubseq(string s) {
        
        string s1 = s;
        reverse(s.begin(), s.end());
        
       return Space(s1, s);
    }
};