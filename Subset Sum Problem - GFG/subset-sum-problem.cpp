//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    bool dfs(vector<int> &arr, int i, int sum, vector<vector<int>> &dp)
    {
        //base case
        if(i == arr.size())
        {
            if(sum == 0)
             return true;
            else
             return false;
        }
        
        if(dp[i][sum] != -1)
         return dp[i][sum];
        
        bool incl = dfs(arr, i+1, sum-arr[i], dp);
        bool excl = dfs(arr, i+1, sum, dp);
        
        return dp[i][sum] = (incl||excl);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        bool ans = dfs(arr, 0, sum, dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends