class Solution {
    int solve(vector<int> &nums, int ind, int tar)
    {
        //base case
        if(tar == 0) return 1;
        
        if(ind == 0)
        {
            if(tar%nums[0] == 0) return 1;
            else return 0;
        }
        
        int excl = solve(nums, ind-1, tar);
        int incl = 0;
        if(nums[ind] <= tar)
            incl =  solve(nums, ind, tar-nums[ind]);
        
        return incl+excl;
    }
    
     int solveMem(vector<int> &nums, int ind, int tar, vector<vector<int>> &dp)
    {
        //base case
        if(tar == 0) return 1;
        
        if(ind == 0)
        {
            if(tar%nums[0] == 0) return 1;
            else return 0;
        }
         
         if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int excl = solveMem(nums, ind-1, tar, dp);
        int incl = 0;
        if(nums[ind] <= tar)
            incl =  solveMem(nums, ind, tar-nums[ind], dp);
        
        return dp[ind][tar] = incl+excl;
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        // return solve(coins, n-1, amount);
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
        return solveMem(coins, n-1, amount, dp);
        
    }
};