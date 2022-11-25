class Solution {
    
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int ind, vector<int> &nums)
    {
        if(ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        solve(ind+1, nums);
        
        temp.push_back(nums[ind]);
        solve(ind+1, nums);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        solve(0, nums);
        return ans;
    }
};