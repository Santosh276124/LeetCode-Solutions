//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n = nums.size();
	    int cnt = 0;
	    for(int i = 0; i < n; i++)
	    {
	        int ele = nums[i];
	        int left = 0;
	        int right = 0;
	        for(int j = i-1; j >= 0; j--)
	        {
	            if(nums[j] < nums[i])
	              left++;
	        }
	        for(int k = i+1; k < n; k++)
	        {
	            if(nums[k] > nums[i])
	              right++;
	        }
	        
	        cnt += (left*right);
	    }
	    return cnt;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends