class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        
        if(nums.size() <= 2) return false;
        

        int left = INT_MAX;
        int mid = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < left)
            {
                left = nums[i];
            }
            else if(nums[i] < mid && nums[i] > left)
            {
                mid = nums[i];
            }
            
            if( nums[i] > mid)
                return true;
        }
        return false;
        
    }
};