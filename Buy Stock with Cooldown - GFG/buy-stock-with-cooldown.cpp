//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int ind, int buy, int n, vector<long long > &prices, vector<vector<long long>>& dp)
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
    
    long long Tab(int n, vector<long long > &prices)
    {
        vector<vector<long long>> dp(n+2, vector<long long>(2, 0));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                if(buy)
                {
                     dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                
                //if i am selling tehn i can not again buy the next day so ind+2;
                else dp[ind][buy] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
            }
        }
        
        return dp[0][1];
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        
        // vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        // return solve(0, 1, n, prices, dp);
        
        return Tab(n, prices);
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