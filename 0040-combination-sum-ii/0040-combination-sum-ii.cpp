class Solution {
public:
    void solve(int ind, vector<int>&nums, vector<int> temp,vector<vector<int>>& ans, int tar ){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        
        if(tar < 0 || ind >= nums.size())
        {          
            return;
        }
        

        for(int i = ind; i < nums.size(); i++){
            if(nums[i] > tar)
                break;
            
            if(i > ind && nums[i] == nums[i-1])
                continue;
    
            temp.push_back(nums[i]);

            solve(i+1, nums, temp, ans, tar-nums[i]);
     
            temp.pop_back();
            
        }
 

        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        solve(0, nums, temp, ans, tar);
        
        return ans;
    }
};