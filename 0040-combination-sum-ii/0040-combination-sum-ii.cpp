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
        
          //include
        temp.push_back(nums[i]);
        solve(nums, target-nums[i], i+1);
        //backtrack
        temp.pop_back();
        
     
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        
           //ixclude
        solve(nums, target, i+1);
        
        
      
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        solve(nums, target, 0);
        

        return ans;
    }
};