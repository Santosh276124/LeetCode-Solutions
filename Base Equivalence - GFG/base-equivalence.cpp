//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
       int val = n;
        for(int i = 2; i <= 32; i++)
        {
            n = val;
             vector<int> ans;
             while(n)
            {
                int rem = n%i;
                ans.push_back(rem);
                n = n/i;
            }
            
            if(ans.size() == m)
            return "Yes";
        }
        return "No";
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends