class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        for(int i = 0; i < n; i++){
            
            if(i-1 >= 0 && nums[i] == nums[i-1])
                continue;
            else if(i+1 < n && nums[i] == nums[i+1])
                continue;
            else
                return nums[i];
            
        }
        
        return -1;
    }
};