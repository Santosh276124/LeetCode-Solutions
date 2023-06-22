class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0;
        int h = n-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            
            if(m % 2 == 0){
                if(m+1 < n && nums[m+1] == nums[m])
                    l = m+1;
                else
                    h = m-1;
            }
            else{
                if(m-1 >= 0 && nums[m] == nums[m-1])
                    l = m+1;
                else
                    h = m-1;
            }
            
        }
        
       return nums[l];
        
    }
};