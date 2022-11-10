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
    
    bool dfsTab(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, 0));
        
        for(int i = 0; i < n; i++) 
           dp[i][0] = true;
           
        dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++)
        {
            for(int target = 1; target <= sum; target++ )
            {
                bool excl = dp[i-1][target];
                
                bool incl = false;
                if(arr[i] <= target)
                    incl = dp[i-1][target-arr[i]];
      
        
                dp[i][target] = (incl||excl);
            }
        }
        
        return dp[n-1][sum];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // int n = arr.size();
        // vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // bool ans = dfs(arr, n-1, sum, dp);
        // return ans;
        
        return dfsTab(arr, sum);
        
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