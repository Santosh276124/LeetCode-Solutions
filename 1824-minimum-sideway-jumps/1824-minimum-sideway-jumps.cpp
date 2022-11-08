class Solution {
     int solve(vector<int>& obs, int currLane, int currPos){
        int n = obs.size()-1;
        //base case
        if(currPos == n) return 0;
        
        
        if(obs[currPos+1] != currLane)  //seedha jayenge bc no obs present at next pos
            return solve(obs, currLane, currPos+1);
        else
        {
            //sidewqys jump karenge
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++)
            {
                if(currLane != i && obs[currPos] != i)
                    ans = min(ans, 1 + solve(obs, i, currPos));
            }
           
            return ans;
        }
    }
    
    
    int solveMem(vector<int>& obs, int currLane, int currPos, vector<vector<int>> &dp){
        int n = obs.size()-1;
        //base case
        if(currPos == n) return 0;
        
        if( dp[currLane][currPos] != -1) return  dp[currLane][currPos];
        
        if(obs[currPos+1] != currLane)  //seedha jayenge bc no obs present at next pos
            return solveMem(obs, currLane, currPos+1, dp);
        else
        {
            //sidewqys jump karenge
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++)
            {
                if(currLane != i && obs[currPos] != i)
                    ans = min(ans, 1 + solveMem(obs, i, currPos, dp));
            }
            dp[currLane][currPos] = ans;
            return  dp[currLane][currPos];
        }
    }
    
     int solveTab(vector<int>& obs){
        int n = obs.size()-1;
       
         vector<vector<int>> dp(4, vector<int>(obs.size(), 1e9));
         
         dp[0][n] = 0;
         dp[1][n] = 0;
         dp[2][n] = 0;
         dp[3][n] = 0;
         
         for(int currPos = n-1; currPos >= 0; currPos--)
         {
             for(int currLane = 1; currLane <= 3; currLane++)
             {
                 if(obs[currPos+1] != currLane)  //seedha jayenge bc no obs present at next pos
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                else
                {
                    //sidewqys jump karenge
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++)
                    {
                        if(currLane != i && obs[currPos] != i)
                            ans = min(ans, 1 + dp[i][currPos+1]);
                    }
                    dp[currLane][currPos] = ans;
                    
                }
             }
         }
       return min({dp[2][0], 1+dp[1][0], 1+dp[3][0]});
    }
    
public:
    int minSideJumps(vector<int>& obstacles) {
        
        // return solve(obstacles, 2, 0);
        
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(obstacles, 2, 0, dp);
        
        return solveTab(obstacles);
    }
};