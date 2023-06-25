class Solution {
public:
    int n;
    int offset = 5000;
    int solve(int ind, int diff, vector<int>& rods, vector<vector<int>>& dp){
        
        if(ind >= n){
            
            if(diff == 0)
                return 0;
            else
                return -1e9;
        }
        
        if(dp[ind][diff+offset] != -1)
            return dp[ind][diff+offset];
        
        //case 1 l1 me add kro
        int c1 = rods[ind] + solve(ind+1, diff+rods[ind], rods, dp);
        //case 2 l2 me add kro
        int c2 = rods[ind] + solve(ind+1, diff-rods[ind], rods, dp);
        //case 3 dono me mt add kro
        int c3 = solve(ind+1, diff, rods, dp);
        
        
        return dp[ind][diff+offset] = max( c1, max(c2, c3) );
        
    }
    int tallestBillboard(vector<int>& rods) {
        
        n = rods.size();
        
        vector<vector<int>> dp(n, vector<int>(2*5001, -1));
        
        int ans = solve(0, 0, rods, dp);
        
        return ans/2;
        
    }
};