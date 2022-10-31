//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   vector<int> temp = nums;
	   
	   int cnt = 0;
	   int n = nums.size();
	   sort(temp.begin(), temp.end());
	   
	   map<int,int> m;
	   
	   for(int i = 0; i < n; i++)
	   m[nums[i]] = i;
	   
	   for(int i = 0; i < n; i++)
	   {
	       if(nums[i] != temp[i])
	       {
	           cnt++;
	           
	           int val = nums[i];
	           int index = m[temp[i]];   //jis se swap karana hai uska index
	           swap(nums[i], nums[index]);
	           
	           //update index
	           m[val] = m[temp[i]];
	           m[temp[i]] = i;
	           
	       }
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends