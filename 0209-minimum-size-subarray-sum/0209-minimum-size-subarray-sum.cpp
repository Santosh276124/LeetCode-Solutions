class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        int curr = 0;
        
        int j = 0;
        for(int i = 0; i < n; i++){
            
            curr += nums[i];
            
            if(curr >= target)
                ans = min(ans, i-j+1);
            
            
            while(curr >= target){
                curr -= nums[j];
                
                ans = min(ans, i-j+1);
                j++;
                
                
            }
  
        }
        
        return ans == INT_MAX ? 0 : ans;
        
    }
};