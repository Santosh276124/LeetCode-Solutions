//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    bool dfs(vector<int> &arr, int i, int sum, vector<vector<int>> &dp)
    {
       if(sum == 0) return true;
       
       if(i == 0) return (arr[0] == sum);
        
        if(dp[i][sum] != -1)
         return dp[i][sum];
         
        bool excl = dfs(arr, i-1, sum, dp);
        
        bool incl = false;
        if(arr[i] <= sum)
            incl = dfs(arr, i-1, sum-arr[i], dp);
      
        
        return dp[i][sum] = (incl||excl);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        bool ans = dfs(arr, n-1, sum, dp);
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