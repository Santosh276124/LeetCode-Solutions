class Solution {
public:
    int n;
    int LPS(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){

        if(i == 0 || j == 0){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
 
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + LPS(i-1, j-1, s1, s2, dp);
        }
        
        return dp[i][j] = max( LPS(i-1, j, s1, s2, dp) , LPS(i, j-1, s1, s2, dp) );
        
    }
    
    int LPSTab(string &s1, string &s2){
            
        vector<vector<int>> dp(n+1 , vector<int>(n+1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1])
                     dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                     dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
            }
        }
        
        return dp[n][n];
        
    }
    int LPSSpace(string &s1, string &s2){
        
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i = 0; i <= n; i++)
            curr[0] = 0;
        for(int j = 0; j <= n; j++)
           prev[j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1])
                     curr[j] = 1 + prev[j-1];
                
                else
                     curr[j] = max( prev[j] , curr[j-1] );
            }
            
            prev = curr;
        }
        
        return curr[n];
        
    }
    int minInsertions(string s) {
        
         n = s.length();
        string s1 = s;
        
        reverse(s.begin(), s.end());
        
        // vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));
        
        // int lps = LPS(n, n, s1, s, dp);
        
        int lps = LPSSpace(s1, s);
        
        return n - lps;
        
    }
};