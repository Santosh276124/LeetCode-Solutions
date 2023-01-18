class Solution {
public:
    int kadanes(vector<int> &nums)
    {
        int n = nums.size();
        
        int maxi = INT_MIN;
        int curr = 0;
        for(int i = 0; i < n; i++)
        {
            curr += nums[i];
            
            if(curr > maxi) maxi = curr;
            
            if(curr < 0) curr = 0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0;
    
        for(int i = 0; i < n; i++)
            totalSum += nums[i];   
        
//         case 1 -> max sum subaaray
        int case1 = kadanes(nums);
        
//         case2 -> min nikalo aur total me se minus krdo
        for(int i = 0; i < n; i++)
            nums[i] = -nums[i];
        
        int ans2 = kadanes(nums);
        
        ans2 = -ans2;
        
        int case2 = totalSum - ans2;
        
        return case1 > 0 ? max(case1, case2) : case1;

    }
};