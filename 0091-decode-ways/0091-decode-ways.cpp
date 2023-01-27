class Solution {
public:
    int n;
	
	int solve(int ind, string &s, vector<int> &dp)
	{
	    if(ind == n) return 1;
	    
	    if(dp[ind] != -1) return dp[ind];
	    
	    int oneDigit = 0;
	   string tomp = s.substr(ind, 1);
	   
	    if( stoi(tomp) >= 1 && stoi(tomp) <= 9)
	     oneDigit = solve(ind+1, s, dp);
	    
	    
	    int twoDigit = 0;
	    
	    string temp = s.substr(ind, 2);
	    if(stoi(temp) >= 10 && stoi(temp) <= 26)
	     twoDigit = solve(ind+2, s, dp);
	    
	    return dp[ind] = oneDigit + twoDigit;
	}
    int numDecodings(string s) {
        n = s.length();
        
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);
    }
};