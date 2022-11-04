class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int s = 0, e = n-1;
        
        while(s < e)
        {
            int mid = s+(e-s)/2;
            
            if(nums[s] <= nums[mid])
            {
                if(nums[s] < nums[e])
                    e = mid-1;
                else
                    s = mid+1;
            }
            else
            {
                e = mid;
            }
        }
        return nums[s];
    }
};