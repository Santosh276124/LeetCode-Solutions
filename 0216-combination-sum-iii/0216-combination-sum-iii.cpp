class Solution {
public:
    void solve(int start, int currSum, int tar, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(k == 0){
            if(currSum == tar)
                ans.push_back(temp);
            
            return;
        }
        
        for(int i = start; i <= 9; i++){
            currSum += i;
            temp.push_back(i);
            
            solve(i+1, currSum, tar, k-1, temp, ans);
            
            currSum -= i;
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(1, 0, n, k, temp, ans);
        
        return ans;
    }
};