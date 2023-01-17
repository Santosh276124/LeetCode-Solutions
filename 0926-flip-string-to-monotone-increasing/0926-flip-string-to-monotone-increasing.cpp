class Solution {
public:
    int n;
   
    int dfs(int i, int prev, string &s, vector<vector<int>>& dp)
    {
        if(i >= n) return 0;
        
        
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int flip = INT_MAX;
        int no_flip = INT_MAX;
        
        
        
        if(s[i] == '0')
        {
            if(prev == 0)
            {
                flip = 1 + dfs(i+1, 1, s, dp);
                no_flip = dfs(i+1, 0, s, dp);
            }
            else
            {
                flip = 1 + dfs(i+1, 1, s, dp);
            }
        }
        else
        {
            if(prev == 0)
            {
                flip = 1 + dfs(i+1, 0, s, dp);
                no_flip = dfs(i+1, 1, s, dp);
            }
            else
            {
                no_flip = dfs(i+1, 1, s, dp);
            }
        }
    
       return dp[i][prev] = min(flip, no_flip); 
        
    }
    
    int minFlipsMonoIncr(string s) {

        n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return dfs(0, 0, s, dp);
    }
};