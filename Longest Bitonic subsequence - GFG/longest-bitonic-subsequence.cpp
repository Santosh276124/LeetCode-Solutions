//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   void LIS_form_front(int n, vector<int> &a, vector<int> &dp)
   {

        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(a[prev] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        }
   }
   
   void LIS_form_back(int n, vector<int> &a, vector<int> &dp)
   {

        for(int i = n-1; i >= 0; i--)
        {
            for(int prev = n-1; prev > i; prev--)
            {
                if(a[prev] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        }
   }
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    
	    vector<int> dp1(n, 1), dp2(n, 1);
	    
	    LIS_form_front(n, nums, dp1);
	    
	    LIS_form_back(n, nums, dp2);
	    
	    int maxi = 0;
	    for(int i = 0; i < n; i++)
	    {
	        maxi = max(maxi , dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends