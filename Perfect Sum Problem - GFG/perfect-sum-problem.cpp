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
       if(ind == 0)
       {
           if(tar == 0 && arr[0] == 0) return 2;
           if(tar == 0 || arr[0] == tar) return 1;
           else return 0;
       }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        //not peak
        int excl = solveMem(arr, n, ind-1, tar, dp);
        
        //peak
        int  incl = 0;
        if(arr[ind] <= tar)
           incl = solveMem(arr, n, ind-1, tar-arr[ind], dp);
           
        return dp[ind][tar] = (incl%mod+excl%mod)%mod;
    }
    
    int solveTab(int arr[], int n, int tar)
    {
        vector<vector<int>> dp(n + 1, vector<int>(tar+1, 0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        //arr[0] = 0;
       if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;
      
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 0; target <= tar; target++)
            {
                
                 int excl = dp[ind-1][target];
                
                int incl = 0;
                if(arr[ind] <= target)
                    incl = dp[ind-1][target-arr[ind]];
                
                  
                   
                dp[ind][target] = (incl+excl)%mod;
            }
        }
        
        return dp[n-1][tar]%mod;
    }
    
    int solveSpace(int arr[], int n, int tar)
    {
       vector<int> prev(tar+1, 0), curr(tar+1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        //arr[0] = 0;
       if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;
      
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 0; target <= tar; target++)
            {
                
                 int excl = prev[target];
                
                int incl = 0;
                if(arr[ind] <= target)
                    incl = prev[target-arr[ind]];
                
                  
                   
                curr[target] = (incl+excl)%mod;
            }
            prev = curr;
        }
        
        return prev[tar]%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   // int ans = solve(arr, n, n-1, sum);
	   
	   //vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    //     return solveMem(arr, n, n-1, sum, dp);
        
    
        // return solveTab(arr, n, sum);
        
        return solveSpace(arr, n, sum);
        
        
      
        
        
        
        
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