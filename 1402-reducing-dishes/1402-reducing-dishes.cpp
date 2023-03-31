class Solution {
public:
    int n;
    int solve(int ind, int time, vector<int>& satisfaction, vector<vector<int>>& dp){
        if(ind >= n) return 0;
        
        if(dp[ind][time] != -1) return dp[ind][time];
        
        int incl = satisfaction[ind]*time + solve(ind+1, time+1, satisfaction, dp);
        
        int excl = solve(ind+1, time, satisfaction, dp);
        
        return dp[ind][time] = max(incl, excl);
    }
    int solveTab(vector<int>& satisfaction){
        
        vector<vector<int>> dp(n+1, vector<int> (n+2, 0));
        
        for(int ind = n-1; ind >= 0 ; ind--){
            for(int time = 1; time <= n; time++ ){
                int incl = satisfaction[ind]*time + dp[ind+1][time+1];
        
                int excl = dp[ind+1][time];

                 dp[ind][time] = max(incl, excl);
            }
        }
        
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
         n = satisfaction.size();
        
        sort(satisfaction.begin(), satisfaction.end());
        
//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        // return solve(0, 1, satisfaction, dp);
        
        return solveTab(satisfaction);
    }
};