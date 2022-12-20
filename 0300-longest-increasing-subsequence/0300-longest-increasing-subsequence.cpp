class Solution {
    int mem(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        //not take
        int excl = 0 + mem(ind+1, prev, nums , dp);
        //take
        int incl = 0;
        if(prev == -1 || nums[ind] > nums[prev])
            incl = 1+ mem(ind+1, ind , nums, dp);
         
        return dp[ind][prev + 1] = max(incl, excl);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return mem(0, -1, nums, dp);
    }
};