class Solution {
public:
    void solve(int ind, vector<int>& temp, vector<int> &arr, int n, vector<vector<int>>& ans){
        
        ans.push_back(temp);
        
        
        for(int i = ind; i < n; i++){
            
            if(i != ind && arr[i] == arr[i-1])
                continue;
            
            temp.push_back(arr[i]);
            
            solve(i+1, temp, arr, n, ans);
            
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> temp;
        
        solve(0, temp, nums, n, ans);
        
        
        return ans;
    }
};