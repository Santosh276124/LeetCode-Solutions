class Solution {
public:
    int solve(int ind, int prev, vector<int> &nums, vector<vector<int>>& dp){
        
        if(ind < 0) return 0;
        
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        
        //take
        long long take = 0;
        long long not_take = 0;
        if(prev == -1 || nums[ind] < nums[prev])
            take = 1 + solve(ind-1, ind, nums, dp);
        
        //nottake
        not_take = solve(ind-1, prev, nums, dp);
        
        return dp[ind][prev+1] = max(take, not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n-1, -1, nums, dp);
        
    }
};