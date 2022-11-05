//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
    {
        // base cae
        if(i >= mat.size() || j >= mat[0].size())
        return 0;
        
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        if(mat[i][j] == 1) {
           int ans = 1 + min({right, diagonal, down});
           maxi = max(maxi, ans);
           return ans;
        }
        else
           return 0;
        
    }
    
    int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        // base cae
        if(i >= mat.size() || j >= mat[0].size())
        return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        if(mat[i][j] == 1) {
           dp[i][j] = 1 + min({right, diagonal, down});
           maxi = max(maxi, dp[i][j]);
           return dp[i][j];
        }
        else
           return dp[i][j] = 0;
        
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // int maxi = 0;
        // solve(mat, 0, 0, maxi);
        // return maxi;
        
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solveMem(mat, 0, 0, maxi, dp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends