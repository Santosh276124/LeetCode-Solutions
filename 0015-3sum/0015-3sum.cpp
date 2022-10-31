class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        unordered_map<int,int> m;   //sum, index
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 0) return {};
        
        for(int i = 0; i < n; i++)
            m[nums[i]] = i;
        
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;  //for duplicates
            
            if(nums[i] > 0) return ans;
            
            for(int j = i+1; j < n; j++)
            {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                
                int sum = -(nums[i] + nums[j]);
                
                if(m.count(sum) && m[sum] > j)
                    ans.push_back({nums[i], nums[j], sum});
                
            }
        }
        
        return ans;
    }
};