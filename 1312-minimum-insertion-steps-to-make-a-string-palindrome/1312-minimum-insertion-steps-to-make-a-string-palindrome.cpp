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
    
//     int LPSTab(string &s1, string &s2){
            
//         vector<vector<int>> dp(n+1 , vector<int>(n+1, 0));
        
        
        
//     }
    int minInsertions(string s) {
        
         n = s.length();
        string s1 = s;
        
        reverse(s.begin(), s.end());
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));
        
        int lps = LPS(n, n, s1, s, dp);
        
        return n - lps;
        
    }
};