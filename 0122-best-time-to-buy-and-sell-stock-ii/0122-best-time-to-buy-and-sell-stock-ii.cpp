class Solution {
public:
    int rec(int ind, int canBuy, vector<int> &prices)
    {
        if(ind == prices.size()) 
            return 0;
        
        //can buy
        int profit = 0;
        if(canBuy) //either buy or not buy
        {
            int buy1 = -prices[ind] + rec(ind+1, 0, prices);
            int notbuy1 = 0 + rec(ind+1, 1, prices);
            profit = max(buy1, notbuy1);
        }
        else  //either sell or not sell
        {
            int sell1 = +prices[ind] + rec(ind+1, 1, prices);
            int notsell1 = 0 + rec(ind+1, 0, prices);
            profit = max(sell1, notsell1);
        }
        
        return profit;
    }
    
    int Mem(int ind, int canBuy, vector<int> &prices, vector<vector<int>>& dp)
    {
        if(ind == prices.size()) 
            return 0;
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        //can buy
        int profit = 0;
        if(canBuy) //either buy or not buy
        {
            int buy1 = -prices[ind] + Mem(ind+1, 0, prices, dp);
            int notbuy1 = 0 + Mem(ind+1, 1, prices, dp);
            profit = max(buy1, notbuy1);
        }
        else  //either sell or not sell
        {
            int sell1 = +prices[ind] + Mem(ind+1, 1, prices, dp);
            int notsell1 = 0 + Mem(ind+1, 0, prices, dp);
            profit = max(sell1, notsell1);
        }
        
        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        
        // return rec(0, 1, prices);  //(ind, canBuy, prices)
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        //for buy we have only 2 options (0, 1)
        return Mem(0, 1, prices, dp);
    }
};