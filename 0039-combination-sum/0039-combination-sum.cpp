class Solution {
      vector<vector<int>> ans;
      vector<int> temp;
    
    void solve(vector<int> &nums, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(target < 0 || i == nums.size()) 
        {
             return;
        }
           
    
//         exclude
        solve(nums, target, i+1);
        
//         Include
        temp.push_back(nums[i]);
        
        solve(nums, target-nums[i], i);
        //Backrack
        temp.pop_back();
  
        
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
      
      solve(nums, target, 0);
        
      return ans;
        
    }
};