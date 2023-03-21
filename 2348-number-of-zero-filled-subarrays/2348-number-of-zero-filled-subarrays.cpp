class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0;
        
        int n = nums.size();
        int j = 0;
        int i = 0;
        for(i = 0; i < n; i++){
            
            if(nums[i] == 0){
                continue;
            }
            else{
                long long len = i-j;
                ans += (len + len*(len-1)/2);
                
                j = i+1;
            }
        }
        
        long long len = i-j;
        ans += (len + len*(len-1)/2);

        
        return ans;
        
    }
};