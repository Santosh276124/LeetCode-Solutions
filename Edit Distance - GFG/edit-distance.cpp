//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
      int solveMem(int i, int j, string &s1, string &s2, vector<vector<int>>& dp)
    {
        if(i == 0) return j;
        if(j == 0) return i;
         
         if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = solveMem(i-1, j-1, s1, s2, dp);
        
        int insert = 1 + solveMem(i, j-1 , s1, s2, dp);
        int deletion = 1 + solveMem(i-1, j, s1, s2, dp);
        int replace = 1 + solveMem(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = min({insert, deletion, replace});
       
    }
  public:
    int editDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMem(n, m, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends