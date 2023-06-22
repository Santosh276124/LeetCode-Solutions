class Solution {
public:
    int solve(int ind, int buy, vector<int> &nums, int &fee, vector<vector<int>> &dp){
        
        if(ind >= nums.size()){
            return 0;
        }
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy == 0){ // can buy
            
            profit += max( (- nums[ind]) + solve(ind+1, 1, nums, fee, dp), solve(ind+1, 0, nums, fee, dp) );
            
            
        }
        else{ //can sell
            
            profit += max( (nums[ind] - fee) + solve(ind+1, 0, nums, fee, dp), solve(ind+1, 1, nums, fee, dp) );
            
          
            
        }
        
        return dp[ind][buy] = profit;
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return solve(0, 0, prices, fee, dp);
        
        
        
    }
};