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
public:
    int minSideJumps(vector<int>& obstacles) {
        
        // return solve(obstacles, 2, 0);
        
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(obstacles, 2, 0, dp);
    }
};