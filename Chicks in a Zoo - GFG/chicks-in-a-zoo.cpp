//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	   
	  long long int dp[n+1];
	   dp[1] = 1;
	    
	    long long int ans = 1;
	    
	    for(int i = 2; i <= n; i++)
	    {
	        if(i > 6)
	        {
	            ans -= dp[i-6];
	        }
	        
	        dp[i] = ans*2;
	        ans += dp[i];
	      
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends