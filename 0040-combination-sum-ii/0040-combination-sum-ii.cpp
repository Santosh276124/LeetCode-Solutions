class Solution {
public:
      vector<vector<int>> ans;
      vector<int> temp;
    
    void solve(vector<int> &nums, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0 || i >= nums.size())
            return;
        
        for(int ind = i; ind < nums.size(); ind++)
        {
            if(nums[ind] > target) break;
            
            if(ind > i && nums[ind] == nums[ind-1]) continue;
            
            temp.push_back(nums[ind]);
            solve(nums, target-nums[ind], ind+1);
            temp.pop_back();
        }
        
        
      
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        solve(nums, target, 0);
        

        return ans;
    }
};