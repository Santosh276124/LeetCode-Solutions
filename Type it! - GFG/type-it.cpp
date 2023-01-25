//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n = s.length();
        
        int ans = 1e9;
        
        string temp = "";
        
        for(int i = 0; i < n; i++)
        {
            temp += s[i];
            int len = temp.size();
            
            string st = s.substr(i+1, len);
            
            if(st == temp)
            {
                int cnt = len + (n-len-len+1);
                
                ans = min(ans, cnt);
            }
        }
        if(ans == 1e9) return n;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends