class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        int ans = 0;
        
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                e = mid-1;
                // ans = mid;
               
            }
            
            else
            {
                s = mid+1;
                // ans = s;
            }
        }
        // if(ans == -1) return ans+1;
        // // else if(ans == nums.size()) return ans-1;
        // else
           return s;
    }
};