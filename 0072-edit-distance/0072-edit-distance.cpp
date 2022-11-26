class Solution {
    int solve(int i, int j, string &s1, string &s2)
    {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(s1[i] == s2[j])
            return solve(i-1, j-1, s1, s2);
        
        int insert = 1 + solve(i, j-1 , s1, s2);
        int deletion = 1 + solve(i-1, j, s1, s2);
        int replace = 1 + solve(i-1, j-1, s1, s2);
        
        return min({insert, deletion, replace});
       
    }
     int solveMem(int i, int j, string &s1, string &s2, vector<vector<int>>& dp)
    {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
         
         if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = solveMem(i-1, j-1, s1, s2, dp);
        
        int insert = 1 + solveMem(i, j-1 , s1, s2, dp);
        int deletion = 1 + solveMem(i-1, j, s1, s2, dp);
        int replace = 1 + solveMem(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = min({insert, deletion, replace});
       
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        // return solve(n-1, m-1, word1, word2);
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMem(n-1, m-1, word1, word2, dp);
    }
};