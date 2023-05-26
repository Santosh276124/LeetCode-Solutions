class Solution {
public:
    int n;
    int solve(int ind, int  m, int alice, vector<int> &piles, vector<vector<vector<int>>>& dp){
        
        if(ind >= n) return 0;
        
        if(dp[ind][m][alice] != -1) return dp[ind][m][alice];
        
        int currSum = 0;
        
        int res = alice == 1 ? -1 : 1e6;
        
        for(int x = 1; x <= min(2*m, n-ind); x++){
            
            currSum += piles[ind+x-1];
            
            if(alice){
                res = max(res, currSum + solve(ind+x, max(x, m), !alice, piles , dp));
                
            }
            
            else{
                res = min(res, 0 + solve(ind+x, max(m, x), !alice, piles, dp));
            }
   
        }
        
        return dp[ind][m][alice] = res;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        n = piles.size();
        
        if(n == 1) return piles[0];
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        return solve(0, 1, 1, piles, dp);
        
        
    }
};