//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int n;
    long long solve(int ind, int canbuy, vector<long long> &prices, vector<vector<long long>>& dp)
    {
        //base case
        if(ind == n)
        {
            return 0;
        }
        
        if(dp[ind][canbuy] != -1) return dp[ind][canbuy];
        
        long long profit = 0;
        
        //can buy
        if(canbuy)
        {
            /// if buy
            profit = max( -prices[ind] + solve(ind+1, 0, prices, dp) , solve(ind+1, 1, prices, dp) );
           
        }
        else //can not buy
        {
            //
            profit = max( prices[ind] + solve(ind+1, 1, prices, dp), solve(ind+1, 0, prices, dp) );
           
        }
        
        return dp[ind][canbuy] = profit;
    }
    
    long long Tab(vector<long long> &prices)
    {
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int canbuy = 0; canbuy <= 1; canbuy++)
            {
                long long profit = 0;
        
                //can buy
                if(canbuy)
                {
                    /// if buy
                    profit = max( -prices[ind] + dp[ind+1][0] , dp[ind+1][1] );
                   
                }
                else //can not buy
                {
                    //
                    profit = max( prices[ind] + dp[ind+1][1], dp[ind+1][0] );
                   
                }
                
                dp[ind][canbuy] = profit;
            }
        }
        
        return dp[0][1];
    }
    long long maximumProfit(vector<long long>&prices, int len) {
        // Code here
        n = len;
        // vector<vector<long long>> dp(n, vector<long long>(2, -1));
        // return solve(0, 1, prices, dp);
        
        return Tab(prices);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends