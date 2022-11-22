class Solution {
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int LCS = solve(n-1, m-1, word1, word2, dp);
        // cout<<LCS<<" ";
        
        int deletion = n-LCS;
        int insertion = m-LCS;
        return deletion + insertion;
    }
};