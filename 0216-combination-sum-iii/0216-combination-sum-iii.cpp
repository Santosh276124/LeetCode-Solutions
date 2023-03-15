class Solution {
public:
    vector<vector<int>> ans;
    
    int findSum(vector<int> &temp){
        int sum = 0;
        for(auto el : temp)
            sum += el;
        
        return sum;
    }
    
    void solve(int ind, vector<int> &arr, vector<int> temp, int k, int tar)
    {
        if(ind > arr.size() || temp.size() > k)
            return;
        
        if(temp.size() == k){
            if(findSum(temp) == tar){
                ans.push_back(temp);
                return;
            } 
        }
        
        temp.push_back(arr[ind]);
        solve(ind+1, arr, temp, k, tar);
        
        temp.pop_back();
        
        solve(ind+1, arr, temp, k, tar);
        
       
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> arr;
        for(int i = 1; i <= 9; i++)
        {
            arr.push_back(i);
        }
        
        vector<int> temp;
        
        solve(0, arr, temp, k, n);
        
        return ans;
    }
};