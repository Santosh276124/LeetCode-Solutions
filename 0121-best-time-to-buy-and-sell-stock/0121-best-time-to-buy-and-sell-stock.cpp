class Solution {
public:
    int n;
//     int solve(int ind, int canBuy, vector<int> &prices)
//     {
//         if(ind >= n) return 0;
        
//         if(canBuy)
//         {
//             return max( -prices[ind] + solve(ind+1, 0, prices),
//                          0 + solve(ind+1, 1, prices));
//         }
        
//         return max( prices[ind] + solve(ind+1, 1, prices),
//                     0 + solve(ind+1, 0, prices));
//     }
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();
        
        // return solve(0, 1, prices);
        
        int maxProfit = 0;
        
        int currProfit = 0;
        int currCost = prices[0];
        
        for(int i = 0; i < n; i++)
        {
            currProfit = prices[i] - currCost;
            
            if(currProfit < 0)
                currProfit = 0;
            
            maxProfit = max(maxProfit, currProfit);
            
            currCost = min(currCost, prices[i]);
        }
        
        return maxProfit;
        
    }
};