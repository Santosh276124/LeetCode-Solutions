class Solution {
    bool dfs(vector<int> &nums, int i, int k, vector<vector<int>> &dp)
    {
        if(k == 0) return true;
      
        if(i == 0)
        {
            if(nums[0] == k) return true;
             return false;
        }
        
        if(dp[i][k] != -1) return dp[i][k];
        // if(sum == k-sum) return true;
        
        
        bool excl = dfs(nums, i-1, k, dp);
        
        bool incl = false;
        if(nums[i] <= k)
            incl = dfs(nums, i-1, k-nums[i], dp);
        
        dp[i][k] = (excl||incl);
        return dp[i][k];
            
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return false;
        
        int totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }
        
        if(totalSum %2 != 0) return false;
        
        vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
        
        return dfs(nums, n-1, totalSum/2, dp);
        
       
    }
};