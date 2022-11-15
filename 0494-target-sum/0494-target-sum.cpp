class Solution {
    int solve(vector<int> &nums, int ind, int tar)
    {
        if(ind == 0)
        {
            if(tar == 0 && nums[0] == 0) return 2;
            else if(tar == 0 || nums[0] == tar) return 1;
            else return 0;
        }
        
        int excl = solve(nums, ind-1, tar);
        int incl = 0;
        if(nums[ind] <= tar)
           incl = solve(nums, ind-1, tar-nums[ind]);
        
        return incl+excl;
    }
    
    int solveTab(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));
        
        if(nums[0] == 0)
            dp[0][0] = 2; 
        else
            dp[0][0] = 1;
        
        if(nums[0] != 0 && nums[0] <= tar) 
            dp[0][nums[0]] = 1;
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 0; target <= tar; target++)
            {
                int excl = dp[ind-1][target];
                int incl = 0;
                if(nums[ind] <= target)
                   incl = dp[ind-1][target-nums[ind]];

                dp[ind][target] = incl+excl;
            }
        }
        
        return dp[n-1][tar];
    }
public:
    int findTargetSumWays(vector<int>& A, int target) {
        
         int n = A.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += A[i];
        
        if(totalSum-target < 0) return 0;
        if((totalSum-target) % 2 != 0) return 0;
        
        int tar = (totalSum-target)/2;
        
        // return solve(A, n-1, tar);
        
        return solveTab(A, tar);
    }
};