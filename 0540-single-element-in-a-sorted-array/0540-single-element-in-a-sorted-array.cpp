class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0;
        int h = n-1;
        
//         while(l < h){
//             int m = l + (h-l)/2;
            
//             if(nums[m] != nums[m+1] )
//         }
        
        int xr  = 0;
        for(auto el : nums)
            xr ^= el;
        
        return xr;
        
    }
};