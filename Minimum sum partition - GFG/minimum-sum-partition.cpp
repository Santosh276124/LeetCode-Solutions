//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
	int minDifference(int nums[], int n)  { 
	 
	         int totalSum = 0;
        for(int i=0;i<n;i++)totalSum+=nums[i];
        
        vector<vector<bool>> dp(n+1,vector<bool>(totalSum+1,false));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        dp[0][nums[0]] = true;
        
        // 0 is already covered in the base case
        for(int ind=1;ind<n;ind++) //in the recursion call we went from n-1 to 0
        {
            // 0 is already covered in the base case
            for(int target = 1 ; target<=totalSum; target++)  //in the recur call we went from sum to 0
            {
                // copy the recurrance
                bool take = false;
                if(target>=nums[ind])
                {
                    take = dp[ind-1][target-nums[ind]];
                }
                
                bool notTake = dp[ind-1][target];
                
                dp[ind][target] = take || notTake;
            }
        }
        
        // int the last row of dp , we have the info whether that sum is possible or not
        int ans = 1e9;
        for(int j=0;j<=(totalSum)/2;j++)
        {
            if(dp[n-1][j] == true)  //that sum is possible
            {
                int sum1 = j;
                int sum2 = totalSum-j;
                ans = min(ans,abs(sum1-sum2));
            }
        }
        
        return ans;
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