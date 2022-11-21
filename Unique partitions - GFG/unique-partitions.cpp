//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    	void getAns(int curr, int&rem, vector<int>&arr , vector<int>&temp, vector<vector<int>>&ans){
	    
	    if(rem ==0){
	        ans.push_back(temp);
	        return;
	    }
	    
	    if(curr>=arr.size())
	        return;
	        
	   if(arr[curr]<=rem){
	       temp.push_back(arr[curr]);
	       rem-=arr[curr];
	       getAns(curr,rem,arr,temp,ans);
	       temp.pop_back();
	       rem+=arr[curr];
	   }
	   
	   getAns(curr+1,rem,arr,temp,ans);
	   return;
	}
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        vector<vector<int>>ans;
        vector<int>arr,temp;
        
        for(int i=n;i>=1;i--)
            arr.push_back(i);    
            
        getAns(0,n,arr,temp,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends