class Solution {
    int mod = 1e9+7;
    int solve(int n)
    {
        if(n <= 1) return 1;
        if(n == 2) return 2;
        
        return ((2*solve(n-1)%mod)%mod + solve(n-3)%mod)%mod;
    }
    int solveMem(int n, vector<int> &dp)
    {
        if(n <= 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = ((2*solveMem(n-1, dp)%mod)%mod + solveMem(n-3, dp)%mod)%mod;
    }
    
    int solveTab(int n)
    {
     
        vector<int> dp(n+2, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++)
        {
            
            dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
            
            // dp[i]%=mod;
        }
        
        
        
        return dp[n]%mod;
        // return 0;
    }
public:
    int numTilings(int n) {
        
        
        // return solve(n);
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);
        
        return solveTab(n);
    }
};