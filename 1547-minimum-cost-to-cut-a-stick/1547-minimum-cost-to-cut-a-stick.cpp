class Solution {
public:
    int m;
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
    
    int Tab(int n, vector<int> &cuts)
    {
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        
        for(int i = m; i >= 1; i--)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i > j) continue;
                
                int mini = 1e9;
                for(int ind = i; ind <= j; ind++)
                {
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];

                    mini = min(mini, cost);

                }
               dp[i][j] = mini;
            }
        }
        
        return dp[1][m];
    }
    int minCost(int n, vector<int>& cuts) {
        
        m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
//         vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        
//         return solve(1, m, cuts, dp);
        
        return Tab(n, cuts);
    }
};