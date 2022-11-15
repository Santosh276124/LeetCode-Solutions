class Solution {
    int solve(vector<int> &nums, int ind, int tar)
    {
        //base case
       
        
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
    
    int solveTab(vector<int> &nums, int tar)
    {  
       int n = nums.size(); 
        vector<vector<int>> dp(n+1, vector<int> (tar+1, 0));
        
       for(int target = 0; target <= tar; target++)
       {
            if(target % nums[0] == 0) dp[0][target] = 1;
            else dp[0][target] = 0; 
       }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 0; target <= tar; target++)
            {
                int excl = dp[ind-1][target];
                int incl = 0;
                if(nums[ind] <= target)
                    incl = dp[ind][target-nums[ind]];

               dp[ind][target] = incl+excl;
            }
        }
        
        return dp[n-1][tar];
    }
    
    int solveSpace(vector<int> &nums, int tar)
    {  
       int n = nums.size(); 
    
        vector<int> prev(tar+1, 0), curr(tar+1, 0);
        
       for(int target = 0; target <= tar; target++)
       {
            if(target % nums[0] == 0) prev[target] = 1;
            else prev[target] = 0; 
       }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 0; target <= tar; target++)
            {
                int excl = prev[target];
                int incl = 0;
                if(nums[ind] <= target)
                    incl = curr[target-nums[ind]];

               curr[target] = incl+excl;
            }
            prev = curr;
        }
        
        return prev[tar];
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        // return solve(coins, n-1, amount);
        
//         vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
//         return solveMem(coins, n-1, amount, dp);
        
        // return solveTab(coins, amount);
        
        return solveSpace(coins, amount);
        
    }
};