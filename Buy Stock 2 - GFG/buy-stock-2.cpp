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
    long long maximumProfit(vector<long long>&prices, int len) {
        // Code here
        n = len;
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 1, prices, dp);
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