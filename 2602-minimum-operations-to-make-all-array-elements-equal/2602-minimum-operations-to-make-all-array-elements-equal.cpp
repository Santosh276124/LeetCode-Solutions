class Solution {
public:
    int binarySearch(vector<int>& nums, int tar){
        int l = 0;
        int h = nums.size()-1;
        
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            
            if(nums[mid] <= tar){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        
        return ans;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<long long> pref(n);
        
        long long totalSum = 0;
        
        long long curr = 0;
        for(int i =0; i < n; i++){
            curr += nums[i];
            pref[i] = curr;
            
            totalSum += nums[i];
        }
        
        vector<long long> ans;
        
        for(auto &q : queries){
            
            // long long ind = binarySearch(nums, q);
            
            long long ind = (lower_bound(nums.begin(), nums.end(), q) - nums.begin());
         
            long long low = (long long)q*ind - ((ind > 0) ? pref[ind-1]: 0);
            
            long long high = (totalSum - ((ind > 0) ? pref[ind-1] : 0) ) - (n-ind)*(long long)q;
            
            ans.push_back(low+high);
            
            
        }
        
        return ans;
        
    }
};