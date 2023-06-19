class Solution {
public:
    void solve(int ind, vector<int>&nums, vector<int> temp,vector<vector<int>>& ans, int tar ){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        
        if(ind >= nums.size())
        {          
            return;
        }
        
         //excl
        solve(ind+1, nums, temp, ans, tar);

 
        //incl
        temp.push_back(nums[ind]);
        if(nums[ind] <= tar){
  
            solve(ind, nums, temp, ans, tar-nums[ind]);

        }
        
        // temp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        solve(0, nums, temp, ans, tar);
        
        return ans;
    }
};