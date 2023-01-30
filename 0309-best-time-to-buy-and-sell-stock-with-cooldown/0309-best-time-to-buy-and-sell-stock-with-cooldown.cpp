class Solution {
public:
    int solve(int ind, int buy, int n, vector<int > &prices, vector<vector<int>>& dp)
    {
        if(ind >= n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy)
        {
            return dp[ind][buy] = max(-prices[ind] + solve(ind+1, 0, n, prices, dp), solve(ind+1, 1, n, prices, dp));
        }
        
        //if i am selling tehn i can not again buy the next day so ind+2;
        return dp[ind][buy] = max(prices[ind] + solve(ind+2, 1, n, prices, dp), solve(ind+1, 0, n, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, n, prices, dp);
        
    //     int sold = 0, hold = INT_MIN, rest = 0;
    // for (int i=0; i<prices.size(); ++i)
    // {
    //     int prvSold = sold;
    //     sold = hold + prices[i];
    //     hold = max(hold, rest-prices[i]);
    //     rest = max(rest, prvSold);
    // }
    // return max(sold, rest);

    }
};