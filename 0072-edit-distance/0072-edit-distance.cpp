class Solution {
    int solve(int i, int j, string &s1, string &s2)
    {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(s1[i] == s2[j])
            return solve(i-1, j-1, s1, s2);
        
        int insert = 1 + solve(i, j-1 , s1, s2);  //insert imaginary char as s2[j] and move j
        int deletion = 1 + solve(i-1, j, s1, s2); //delete current s1[i] and move i to check further
        int replace = 1 + solve(i-1, j-1, s1, s2); // replace s1[i] with s2[j] and move both i and j
        
        return min({insert, deletion, replace});
       
    }

    // 1 Based indexing ---------
     int solveMem(int i, int j, string &s1, string &s2, vector<vector<int>>& dp)
    {
        if(i == 0) return j;
        if(j == 0) return i;
         
         if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = solveMem(i-1, j-1, s1, s2, dp);
        
        int insert = 1 + solveMem(i, j-1 , s1, s2, dp);
        int deletion = 1 + solveMem(i-1, j, s1, s2, dp);
        int replace = 1 + solveMem(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = min({insert, deletion, replace});
       
    }
    
     int solveTab(string &s1, string &s2)
     {
         int n = s1.length();
         int m = s2.length();
         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
         
         for(int j = 0; j<= m; j++) dp[0][j] = j;
         for(int i = 0; i <= n; i++)  dp[i][0] = i;
         
         for(int i = 1; i<= n; i++)
         {
             for(int j = 1; j <= m; j++)
             {
                 if(s1[i-1] == s2[j-1])
                     dp[i][j] = dp[i-1][j-1];
                 
                 else{
                    int insert = 1 + dp[i][j-1];
                    int deletion = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                      dp[i][j] = min({insert, deletion, replace});
                 }
             }
         }
         return dp[n][m];
     }
    
     int solveSpace(string &s1, string &s2)
     {
         int n = s1.length();
         int m = s2.length();
         
         vector<int> prev(m+1, 0), curr(m+1, 0);
         
         for(int j = 0; j<= m; j++) prev[j] = j;
         
         
         for(int i = 1; i<= n; i++)
         {
             curr[0] = i;
             for(int j = 1; j <= m; j++)
             {
                 if(s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1];
                 
                 else{
                    int insert = 1 + curr[j-1];
                    int deletion = 1 + prev[j];
                    int replace = 1 + prev[j-1];

                      curr[j] = min({insert, deletion, replace});
                 }
             }
             prev = curr;
         }
         return prev[m];
     }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        // return solve(n-1, m-1, word1, word2);
        
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMem(n, m, word1, word2, dp);
        
        // return solveTab(word1, word2);
        return solveSpace(word1, word2);
    }
};