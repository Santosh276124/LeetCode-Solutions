class Solution {
    int solve(vector<int> &nums, int ind, int tar)
    {
        if(ind == 0)
        {
            if(tar == 0 && nums[0] == 0) return 2;
            else if(tar == 0 || nums[0] == tar) return 1;
            else return 0;
        }
        
        int excl = solve(nums, ind-1, tar);
        int incl = 0;
        if(nums[ind] <= tar)
           incl = solve(nums, ind-1, tar-nums[ind]);
        
        return incl+excl;
    }
public:
    int findTargetSumWays(vector<int>& A, int target) {
        
         int n = A.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += A[i];
        
        if(totalSum-target < 0) return 0;
        if((totalSum-target) % 2 != 0) return 0;
        
        int tar = (totalSum-target)/2;
        
        return solve(A, n-1, tar);
    }
};