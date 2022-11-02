class Solution {
    int solve(vector<int> &nums, int tar)
    {
        if(tar < 0) return 0;
        if(tar == 0) return 1;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, tar-nums[i]);
        }
        return ans;
    }
    
    int solveMem(vector<int> &nums, int tar, vector<int> &dp)
    {
        if(tar < 0) return 0;
        if(tar == 0) return 1;
        
        if(dp[tar] != -1)
            return dp[tar];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += solveMem(nums, tar-nums[i], dp);
        }
        
        dp[tar] = ans;
        return dp[tar];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
         
        // return solve(nums, target);
        
        vector<int> dp(target+1, -1);
        
        return solveMem(nums, target, dp);
    }
};