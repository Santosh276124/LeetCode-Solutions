class Solution {
public:
    int n;
    
    int findNextInd(vector<vector<int>> &arr, int currInd, int tar)
    {
        int s = currInd + 1;
        int e = n-1;
        int ind = n+1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(arr[mid][0] >= tar)
            {
                ind = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ind;
    }
    
    int max_profit(vector<vector<int>> &arr, int currInd, vector<int> &dp)
    {
        //base case
        if(currInd >= n) return 0;
        
        if(dp[currInd] != -1) return dp[currInd];
        
        //
        int notTake = 0 + max_profit(arr, currInd + 1, dp);
        
        
        //
        int nextInd = findNextInd(arr, currInd, arr[currInd][1]);
        
        int take = arr[currInd][2] + max_profit(arr, nextInd, dp);
        
        //
        return dp[currInd] = max(notTake, take);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        n = startTime.size();
        vector<vector<int>> arr(n, vector<int>(3, 0));
        
        for(int i = 0; i < n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        
        //sort
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n+1, -1);
        
        return max_profit(arr, 0, dp);
    }
};