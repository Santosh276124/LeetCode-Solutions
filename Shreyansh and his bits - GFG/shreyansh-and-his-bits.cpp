//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 
    long long dp[64][64];
    
    long long nCr(int n, int r)
    {
        if(r > n) return 0;
        if(r == 0 || r == n) return 1;
        
        if(dp[n][r] != -1) return dp[n][r];
        
        return dp[n][r] = nCr(n-1, r-1)+nCr(n-1, r);
    }
    long long count(long long x) {
        
         long long pos = 0;
         long long ones = 0;
         long long ans = 0;
         
        
         for(int i = 0; i < 64; i++)
         {
             for(int j = 0; j < 64; j++)
             {
                 dp[i][j] = -1;
             }
         }
        
        while(x > 0)
        {
            if((x&1) == 1)
            {
                ones++;
                
                ans += nCr(pos, ones);
            }
            x = x>>1;
            pos++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends