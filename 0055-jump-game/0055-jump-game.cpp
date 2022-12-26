class Solution {
    bool rec(int ind, vector<int> &nums, int n)
    {
        if(ind >= n) return false;
        
        if(ind == n-1) return true;
        
        int reachable = ind + nums[ind];
        
        for(int i = ind+1; i <= reachable; i++)
        {
            if(rec(i, nums, n))
                return true;
        }
        
      return false;  
        
    }
    
     bool Mem(int ind, vector<int> &nums, int n, vector<int> &dp)
    {
        if(ind >= n) return false;
        
        if(ind == n-1) return true;
         
         if(dp[ind] != -1) return dp[ind];
        
        int reachable = ind + nums[ind];
        
        for(int i = ind+1; i <= reachable; i++)
        {
            if(Mem(i, nums, n, dp))
                return dp[ind] = true;
        }
        
      return dp[ind] = false;  
        
    }
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        // return rec(0, nums, n);
        
        vector<int> dp(n+1, -1);
        return Mem(0, nums, n, dp);
    }
};