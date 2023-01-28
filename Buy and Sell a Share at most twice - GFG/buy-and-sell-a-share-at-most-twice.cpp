//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int >>> & dp)
{
    if(ind == n || cap == 0) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if(buy)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1, 0, cap, prices, n, dp), 
                    0 + f(ind+1, 1, cap , prices, n, dp));
    }

    return dp[ind][buy][cap] = max(prices[ind] + f(ind+1, 1, cap-1, prices, n, dp), 
                0 + f(ind+1, 0, cap, prices, n , dp));
}
int Tab(vector<int> &prices, int n)
{
    vector<vector<vector<int >>> dp(n+1 ,vector<vector<int>>(2, vector<int>(3, 0)));
    
    // for(int ind = 0; ind < n; ind++)
    // {
    //     dp[ind][0][0] = 0;
    //     dp[ind][1][0] = 0;
    // }
    // for(int buy = 0; buy <= 1; buy++)
    // {
    //     for(int cap = 0; cap <= 2; cap++)
    //     {
    //         dp[n][buy][cap] = 0;
    //     }
    // }
    
    
    
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= 2; cap++)
            {
               
                if(buy)
                {
                   dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap] , 
                                0 + dp[ind+1][1][cap] );
                }
            
                else{
                    
                   dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1] , 
                            0 + dp[ind+1][0][cap] );
                }
            }
        }
    }
    
    return dp[0][1][2];
}

int maxProfit(vector<int>&price){
   
   int n = price.size();
//   vector<vector<vector<int >>> dp(n,vector<vector<int>>(2, vector<int>(3, -1)));
//     return f(0, 1, 2, price, n, dp);

     return Tab(price, n);
   
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends