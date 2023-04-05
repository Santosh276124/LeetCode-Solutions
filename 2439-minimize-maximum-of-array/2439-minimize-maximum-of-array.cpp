class Solution {
public:
    bool valid(int maxi, vector<int>& nums){
        
        vector<long long > arr(nums.begin(), nums.end());
        
        for(int i = 0; i < arr.size()-1; i++){
            
             long long  buffer = 0LL + (maxi - arr[i]) ;
            
            if(arr[i] > maxi){
                return false;
            }
        
            arr[i+1] -= buffer;
            
        }
        
        return  arr[arr.size()-1] <= maxi;
    }
    int minimizeArrayValue(vector<int>& nums) {
        
        int s = nums[0];
        int maxi = INT_MIN;
        
        for(auto el : nums)
            maxi = max(maxi, el);
        
       int e = maxi;
        
        int ans = maxi;
      
        while(s <= e){
           int mid =  s + (e-s)/2;
            
            if(valid(mid, nums))
            {
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
        
    }
};