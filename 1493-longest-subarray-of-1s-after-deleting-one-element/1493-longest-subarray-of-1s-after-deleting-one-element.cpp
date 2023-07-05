class Solution {
public:
    int n;
    int longestSubarray(vector<int>& nums) {
        
        n = nums.size();
        
        int ans = 0;
        
        int zero = 0;
        
        int j = 0;
        for(int i =0; i < n; i++){
            
            if(nums[i] == 0)
            {
                zero++;
            }
            
            while(j < n && zero > 1){
                
                if(j < n && nums[j] == 0)
                    zero--;
                j++;
                
            }

            ans = max(ans, i-j);
            
            
            
            
        }
        
        return ans;
    }
};