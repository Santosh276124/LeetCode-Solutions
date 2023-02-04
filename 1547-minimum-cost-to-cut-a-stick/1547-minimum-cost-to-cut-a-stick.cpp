class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>>&dp)
    {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        
        for(int ind = i; ind <= j; ind++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) + solve(i, ind-1, cuts, dp) + solve(ind+1, j, cuts, dp);
            
            mini = min(mini, cost);
            
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        
        return solve(1, m, cuts, dp);
    }
};