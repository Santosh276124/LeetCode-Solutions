class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;
    int n;
    void solve(int ind, int prev, vector<int> &nums)
    {
        if(ind == n)
        {
            if(temp.size() >= 2) 
                ans.insert(temp);
            
            return;
        }
        
        solve(ind + 1, prev, nums);
        
        //take
        if(nums[ind] >= prev){
            temp.push_back(nums[ind]);
            solve(ind+1, nums[ind], nums);
            
            temp.pop_back();
            
        }
        
        return;
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
         n = nums.size();
        
        solve(0, -101, nums);
        
        vector<vector<int>> res;
        
        for(auto s : ans)
        {
            res.push_back(s);
        }
        
        return res;
        
    }
};