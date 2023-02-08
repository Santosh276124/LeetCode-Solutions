class Solution {
public:
    int n;
    int solve(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind > n || (nums[ind] == 0 && ind != n-1)) return 1e9;
        if(ind == n-1) return 0;
        
        if(ind < n && dp[ind] != -1) return dp[ind];
        
        int mini = 1e9;
        
        for(int i = 1; i <= nums[ind]; i++)
        {
            int steps = 1e9;
            if(ind+i < n)
             steps = 1 + solve(ind+i, nums, dp);
            
            mini = min(mini, steps);
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        
        n = nums.size();
        if(nums[0] == 0) return 0;
        vector<int> dp(n+1, -1);
        return solve(0, nums, dp);
    }
};