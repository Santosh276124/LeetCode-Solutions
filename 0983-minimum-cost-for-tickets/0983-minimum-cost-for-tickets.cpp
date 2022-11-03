class Solution {
    int solve(int n , vector<int> &days, vector<int> &costs, int index)
    {
        if(index >= n) return 0;
        
        //1 day pass
        int option1 = costs[0] + solve(n, days, costs, index+1);
        
        //7 day pass
        int i;
        for(i = index; i < n && days[i] < days[index]+7; i++);
        
        int option2 = costs[1] + solve(n, days, costs, i);
        
        //30 day pass
        for(i = index; i < n && days[i] < days[index]+30; i++);
        
        int option3 = costs[2] + solve(n, days, costs, i);
        
        return min(option1, min(option2, option3));     
        
    }
    
    int solveMem(int n , vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        if(index >= n) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        //1 day pass
        int option1 = costs[0] + solveMem(n, days, costs, index+1, dp);
        
        //7 day pass
        int i;
        for(i = index; i < n && days[i] < days[index]+7; i++);
        
        int option2 = costs[1] + solveMem(n, days, costs, i, dp);
        
        //30 day pass
        for(i = index; i < n && days[i] < days[index]+30; i++);
        
        int option3 = costs[2] + solveMem(n, days, costs, i, dp);
        
        dp[index] = min(option1, min(option2, option3));
        return dp[index];
        
    }
    
     int solveTab(int n , vector<int> &days, vector<int> &costs)
    {
      
         vector<int> dp(n+1, INT_MAX);
         
         dp[n] = 0;
         
         for(int k = n-1; k >= 0; k--)
         {
            //1 day pass
            int option1 = costs[0] + dp[k+1];

            //7 day pass
            int i;
            for(i = k; i < n && days[i] < days[k]+7; i++);

            int option2 = costs[1] + dp[i];

            //30 day pass
            for(i = k; i < n && days[i] < days[k]+30; i++);

            int option3 = costs[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
         }
         
         return dp[0];
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
//         return solve(n, days, costs, 0);
        
        // vector<int> dp(n+1, -1);
        // return solveMem(n, days, costs, 0, dp);
        
        return solveTab(n, days, costs);
    }
};