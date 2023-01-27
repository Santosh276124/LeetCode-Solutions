//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n;
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        
        if( j < 0 || j >= n) return -1e9;
        
        if(i == 0) return mat[0][j];

        if(dp[i][j] != -1) return dp[i][j];
        
        int bottomRow = mat[i][j] + solve(i-1, j, mat, dp);
        int bottomRight = mat[i][j] + solve(i-1, j+1, mat, dp);
        int bottomLeft = mat[i][j] + solve(i-1, j-1, mat, dp);
        
        return dp[i][j] = max({bottomRow, bottomRight, bottomLeft});
    }
    int maximumPath(int len, vector<vector<int>> mat)
    {
        // code here
        n = len;
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(int j = 0; j < n; j++)
        {

            int colMax = solve(n-1, j, mat, dp);
            
            ans = max(ans, colMax);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends