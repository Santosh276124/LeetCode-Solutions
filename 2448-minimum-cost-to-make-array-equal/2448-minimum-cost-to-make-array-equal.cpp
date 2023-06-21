class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        long long ans = 0;
        
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        
        while(l <= r){
            
            int mid = l+(r-l)/2;
            
            long long valueAtMid = 0;
            long long valAtMidNext = 0;
            
            for(int i = 0; i < nums.size(); i++){
                valueAtMid += 1L*abs(mid-nums[i])*cost[i];
                valAtMidNext += 1L*abs(mid+1 - nums[i])*cost[i];
            }
            
            if(valueAtMid <= valAtMidNext){
                ans = valueAtMid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
            
        }
        
        return ans;
        
        
    }
};