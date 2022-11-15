//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long int solveMem(int nums[], int ind, int tar, vector<vector<unsigned long long int>> &dp)
    {
        //base case
       
        
        if(ind == 0)
        {
            if(tar%nums[0] == 0) return 1;
            else return 0;
        }
         
         if(dp[ind][tar] != -1) return dp[ind][tar];
        
        unsigned long long excl = solveMem(nums, ind-1, tar, dp);
        unsigned long long incl = 0;
        if(nums[ind] <= tar)
            incl =  solveMem(nums, ind, tar-nums[ind], dp);
        
        return dp[ind][tar] = incl+excl;
    }
  public:
    long long int count(int coins[], int n, int amount) {

        // code here.
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, -1));
        
        return solveMem(coins, n-1, amount, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends