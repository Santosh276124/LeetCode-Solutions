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
public:
    int numTilings(int n) {
        
        
        // return solve(n);
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};