class Solution {
    
    int solve3(int n)
    {
        int prev2 = 1;
        int prev1 = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    
    int solve2(int n)
    {
        vector<int> dp(n+1);
        
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n] ;
    }
    int solve(int n, vector<int> &dp)
    {
           
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        
        if(dp[n] != -1) return dp[n];
        //RC
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        
        return dp[n];
    }
public:
    int climbStairs(int n) {
     
        // vector<int> dp(n+1, -1);
        // int ans = solve(n, dp);
        // return ans;
        
        // return solve2(n);

        return solve3(n);
    }
};