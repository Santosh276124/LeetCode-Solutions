class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(int ind, vector<int> &nums)
    {
        if(ind >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        solve(ind+1, nums);
        temp.pop_back();
        
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1])
            ind++;
        
        solve(ind+1, nums);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
     
       // vector<vector<int>> res;
     
       sort(nums.begin(), nums.end());
       solve(0, nums);
        
        // for(auto arr : ans)
        // {
        //     res.push_back(arr);
        // }
          
        
        return ans;
    }
};