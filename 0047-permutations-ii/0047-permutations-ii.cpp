class Solution {
public:
    set<vector<int>> ans;
    void solve(int ind, vector<int> &nums){
        if(ind == nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int i = ind; i < nums.size(); i++){
            
            swap(nums[i], nums[ind]);
            
            solve(ind+1, nums);
            
            swap(nums[i], nums[ind]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        solve(0, nums);
        
        vector<vector<int>> res;
        
        for(auto s : ans)
            res.push_back(s);
        
        return res;
        
        
    }
};