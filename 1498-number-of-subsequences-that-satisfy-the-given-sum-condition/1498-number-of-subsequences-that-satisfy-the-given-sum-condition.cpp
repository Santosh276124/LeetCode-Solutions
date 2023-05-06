class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int mod = 1e9 + 7;
        long long cnt = 0;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> power(n+1, 1);
        
        for(int i = 1; i <= n; i++){
            power[i] = (power[i-1]*2)%mod;
        }
        
        
        
        int i = 0;
        int j = nums.size() -1 ;
        
        while(i <= j){
            
            if(nums[i] + nums[j] <= target){
                
                cnt = ( cnt + power[j-i] )%mod;
                
                i++;
            }
            
            else{
                j--;
            }
            
        }
        
        return cnt % mod;
    }
};