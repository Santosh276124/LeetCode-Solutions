class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int currSum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            
            if(nums[i] == 0)
                currSum = 0;
            
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
        
    }
};