class Solution {
public:
    bool isPossible(int size, vector<int>& nums, int target){
        
        int n = nums.size();
        
        int curr = 0;
        
        int j = 0;
        for(int i = 0; i < n; i++){
            
            curr += nums[i];            
            while(i-j+1 > size){
                curr -= nums[j];
                
                j++;           
            }  
            
            if(curr >= target) 
                return true;
        }
        
        return false;
        
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        
        int l = 1;
        int h = n;
        
        while(l <= h){
            
            int mid = l+(h-l)/2;
            
            if(isPossible(mid, nums, target)){
                
                ans = mid;
                h = mid-1;
                
            }
            else
                l = mid+1;
            
        }
        
        return ans == INT_MAX ? 0 : ans;
        
    }
};