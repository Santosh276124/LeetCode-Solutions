//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        // code here
        int mod = 1e8;
        
        if(n == 1) return n;
        
        int prev1 = 2;
        int prev2 = 1;
        
        for(int i = 0; i < n-2; i++)
        {
            int ans = (prev1%mod + prev2%mod)%mod;
            
            prev2 = prev1;
            prev1 = ans;
            
        }
        
        return prev1%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends