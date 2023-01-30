//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int ind, int buy, int fee, int n, vector<long long > &prices, vector<vector<long long>>& dp)
    {
        if(ind >= n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy)
        {
            return dp[ind][buy] = max(-prices[ind] + solve(ind+1, 0, fee, n, prices, dp), solve(ind+1, 1, fee, n, prices, dp));
        }
        
        //if i am selling tehn i can not again buy the next day so ind+2;
        return dp[ind][buy] = max(prices[ind] - fee + solve(ind+1, 1, fee, n, prices, dp), solve(ind+1, 0, fee, n, prices, dp));
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        return solve(0, 1, fee, n, prices, dp);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends