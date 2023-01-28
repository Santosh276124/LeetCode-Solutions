class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mini_in_left_of_ith_day = prices[0];
 
        int profit = 0;
       
        int maxProfit = 0;
        
        for(int i = 1; i < n; i++)
        {
            profit = prices[i] - mini_in_left_of_ith_day;
           
            maxProfit  = max(maxProfit, profit);
            
            mini_in_left_of_ith_day = min(mini_in_left_of_ith_day, prices[i]);
            
            
        }
        return maxProfit;
    }
};