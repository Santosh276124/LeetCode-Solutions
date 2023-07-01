class Solution {
public:
    int n;
    // int ans = INT_MAX;
    int solve(int ind, vector<int>& nums, int k, vector<int>& kth_sum){
        
        if(ind >= n){
            int sum = INT_MIN;
            for(int i = 0; i < k; i++){
                sum = max(sum, kth_sum[i]);
            }
            
            return sum;
        }
        
       int ans = INT_MAX;
        for(int i = 0; i < k; i++){
            
            //give to ith child
            
            kth_sum[i] += nums[ind];
            
            
            int ith_sum = solve(ind+1, nums, k, kth_sum);
            
            kth_sum[i] -= nums[ind];
            
            ans = min(ans, ith_sum);
        }
        
        return ans;
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
         n = cookies.size();
        
         vector<int> kth_sum(k, 0);
        
         return solve(0, cookies, k, kth_sum);
        
        // return ans;
        
    }
};