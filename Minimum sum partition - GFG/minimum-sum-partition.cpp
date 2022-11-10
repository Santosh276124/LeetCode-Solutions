//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  int dfs(int arr[], int n, int totalSum , int i, int currSum, vector<vector<int>> &dp)
  {
      if(i >= n)
      {
          return abs(totalSum - 2*currSum);
      }
      
      if(dp[i][currSum] != -1) return dp[i][currSum];
      
      int incl = dfs(arr, n, totalSum, i+1, currSum + arr[i], dp);
      int excl = dfs(arr, n, totalSum, i+1, currSum, dp);
      
      return dp[i][currSum] = min(incl, excl);
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum = 0;
	    for(int i = 0; i < n; i++)
	       totalSum += arr[i];
	       
	    vector<vector<int>> dp(n+1, vector<int>(totalSum + 1, -1));
	    
	    return dfs(arr, n, totalSum, 0, 0, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends