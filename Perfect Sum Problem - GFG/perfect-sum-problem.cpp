//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9+7;
    
    int solve(int arr[], int n, int ind, int tar)
    {
        //base case
        // if(tar == 0) return 1;
        
        if(ind < 0) return tar == 0;
        
        //not peak
        int excl = solve(arr, n, ind-1, tar);
        
        //peak
        int  incl = 0;
        if(arr[ind] <= tar)
           incl = solve(arr, n, ind-1, tar-arr[ind]);
           
        return (incl%mod+excl%mod)%mod;
    }
    
    int solveMem(int arr[], int n, int ind, int tar,  vector<vector<int>> &dp)
    {
        //base case
        // if(tar == 0) return 1;
        
        if(ind < 0) return tar == 0;
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        //not peak
        int excl = solveMem(arr, n, ind-1, tar, dp);
        
        //peak
        int  incl = 0;
        if(arr[ind] <= tar)
           incl = solveMem(arr, n, ind-1, tar-arr[ind], dp);
           
        return dp[ind][tar] = (incl%mod+excl%mod)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   // int ans = solve(arr, n, n-1, sum);
	   
	   vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return solveMem(arr, n, n-1, sum, dp);
        
        
        
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends