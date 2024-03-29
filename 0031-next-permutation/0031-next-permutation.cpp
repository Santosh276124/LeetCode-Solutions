class Solution {
public:
    int findBreakPoint(vector<int> & nums){
        int n = nums.size();
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1])
                return i;
        }
        return -1;
    }
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        int breakInd = findBreakPoint(nums);
        
        if(breakInd == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int i = n-1;
        for( ; i > breakInd; i--){
            if(nums[i] > nums[breakInd]){
                swap(nums[i], nums[breakInd]);
                break;
            }
        }
        
        reverse(nums.begin()+breakInd+1, nums.end());
        
    }
};