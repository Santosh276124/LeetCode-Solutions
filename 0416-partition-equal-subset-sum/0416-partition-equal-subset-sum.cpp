class Solution {
    bool dfs(vector<int> &nums, int i, int k,int sum, vector<vector<int>> &dp)
    {
      
        if(i >= nums.size())
        {
            if(sum == k-sum) return true;
             return false;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        // if(sum == k-sum) return true;
        
        
        bool excl = dfs(nums, i+1, k,  sum, dp);
        
        
       
        bool  incl = dfs(nums, i+1, k,  sum+nums[i], dp);
        
        dp[i][sum] = (excl||incl);
        return dp[i][sum];
            
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
        
        vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
        
        return dfs(nums, 0, totalSum, 0, dp);
        
       
    }
};