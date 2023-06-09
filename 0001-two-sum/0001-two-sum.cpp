class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        
        int n = nums.size();
        
        for(int i =0; i < n; i++)
            mp[nums[i]] = i;
        
        for(int i = 0; i < n; i++){
            
            int rem = target - nums[i];
            
            if(mp.count(rem) && mp[rem] != i)
                return {i, mp[rem]};
        }
        
        return {};
        
    }
};