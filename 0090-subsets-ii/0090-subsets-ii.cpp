class Solution {
public:
    void solve(int ind, vector<int> temp, vector<int> &arr, int n, set<vector<int>>& ans){
        
        if(ind >= n)
        {
            ans.insert(temp);
            return;
        }
        
        //exclude
        solve(ind+1, temp, arr, n, ans);
            
        //include
        temp.push_back(arr[ind]);

        solve(ind+1, temp, arr, n, ans);
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> ans;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> temp;
        
        solve(0, temp, nums, n, ans);
        
        vector<vector<int>> res;
        
        for(auto s : ans)
            res.push_back(s);
        
        return res;
    }
};