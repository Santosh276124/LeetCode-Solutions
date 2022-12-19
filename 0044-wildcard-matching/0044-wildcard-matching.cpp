class Solution {
    bool Mem(int i, int j, string &pattern, string &str, vector<vector<int>>&dp)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0)
        {
            for(int k = 0; k <= i; k++)
            {
                if(pattern[k] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == str[j] || pattern[i] == '?')
          return dp[i][j] = Mem(i-1, j-1, pattern, str, dp);
        
        if(pattern[i] == '*')
          return dp[i][j] = (Mem(i-1, j, pattern, str, dp) | Mem(i, j-1, pattern, str, dp));
         
        return dp[i][j] = false; 
        
    }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return Mem(n-1, m-1, p, s, dp);
    }
};