class Solution {
    set<vector<int>> ans;
    vector<int> temp;
    
    void solve(int ind, vector<int> &nums)
    {
        if(ind >= nums.size())
        {
            ans.insert(temp);
            return;
        }
        
        solve(ind+1, nums);
        
        temp.push_back(nums[ind]);
        solve(ind+1, nums);
        temp.pop_back();
        
        // for(int i = ind; i < nums.size(); i++)
        // {
        //     if(nums[i] != nums[i-1])
        //     {
        //         temp.push_back(nums[ind]);
        //         solve(ind+1, nums);
        //         temp.pop_back();
        //     }
        // }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
     
    vector<vector<int>> res;
     
       sort(nums.begin(), nums.end());
       solve(0, nums);
        
        for(auto arr : ans)
        {
            res.push_back(arr);
        }
          
        // sort(ans.begin(), ans.end());
        return res;
    }
};