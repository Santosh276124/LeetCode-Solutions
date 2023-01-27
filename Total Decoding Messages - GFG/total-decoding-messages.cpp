//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int n;
	int mod = 1e9+7;
	int solve(int ind, string &s, vector<int> &dp)
	{
	    if(ind == n) return 1;
	    
	    if(dp[ind] != -1) return dp[ind]%mod;
	    
	    int oneDigit = 0;
	   string tomp = s.substr(ind, 1);
	   
	    if( stoi(tomp) >= 1 && stoi(tomp) <= 9)
	     oneDigit = solve(ind+1, s, dp);
	    
	    
	    int twoDigit = 0;
	    
	    string temp = s.substr(ind, 2);
	    if(stoi(temp) >= 10 && stoi(temp) <= 26)
	     twoDigit = solve(ind+2, s, dp);
	    
	    return dp[ind] = (oneDigit%mod + twoDigit%mod) %mod;
	}
		int CountWays(string str){
		    // Code here
		    
		  //  No. of valid substring
		  
		  n = str.length();
		  
		  vector<int> dp(n+1, -1);
		  return solve(0, str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends