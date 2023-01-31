class Solution {
public:
    int n;
    
//     int solve(int ind, int prev, vector<pair<int,int>>& arr, vector<vector<int>>& dp)
//     {
//         if(ind < 0) return 0;
        
//         if(prev != -1 && dp[ind][prev] != -1) return dp[ind][prev];
        
//         int inc = 0;
//         int excl = 0;
        
//         if( prev == -1 || arr[ind].second <= arr[prev].second)
//         {
//             inc = arr[ind].second + solve(ind-1, ind, arr, dp);
//         }
        
//         excl = 0 + solve(ind-1, prev, arr, dp);
        
//         return dp[ind][prev] = max(inc, excl);
//     }
    
    int solve(int ind, int prev, vector<pair<int,int>>& arr, vector<vector<int>>& dp)
    {
        if(ind < 0) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int inc = 0;
        int excl = 0;
        
        if( prev == -1 || arr[ind].second <= arr[prev].second)
        {
            inc = arr[ind].second + solve(ind-1, ind, arr, dp);
        }
        
        excl = 0 + solve(ind-1, prev, arr, dp);
        
        return dp[ind][prev+1] = max(inc, excl);
    }
   
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        n = scores.size();
        
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
        {
            arr.push_back({ages[i], scores[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(n-1, -1, arr, dp);
        
    }
};