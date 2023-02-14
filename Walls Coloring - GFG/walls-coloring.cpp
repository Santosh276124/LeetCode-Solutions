//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int n;
int solve(int i, int j, vector<vector<int>> &color, vector<vector<int>> &dp)
{
    if(i < 0 || i >= n || j < 0 || j >= n) return 1e9;
    
    if( i == n-1) return color[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];

    int p = 1e9;
    int b = 1e9;
    int y = 1e9;
    
    if(j == 0)
    {
        p = color[i][j] + min( solve(i+1, 1, color, dp) , solve(i+1, 2, color, dp) );
    }
    if(j == 1)
    {
        b = color[i][j] + min( solve(i+1, 0, color, dp) , solve(i+1, 2, color, dp) );
    }
    if(j == 2)
    {
        y = color[i][j] + min( solve(i+1, 0, color, dp) , solve(i+1, 1, color, dp) );
    }
   
    
    return dp[i][j] = min(p, min(b, y));
}
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        n = N;
        int ans = 1e9;
        for(int i = 0; i < 3; i++)
        {
            vector<vector<int>> dp(n+1, vector<int>(4, -1));
            int price = solve(0, i, colors, dp);
            ans = min(ans, price);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends