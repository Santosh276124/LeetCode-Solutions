class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        
        // ans[0].push_back({1});
        // ans[1].push_back({1, 1});
        
        for(int i = 0; i < n; i++){       
            
            vector<int> curr(i+1, 1);
            
            // ans.push_back(curr);
       
            for(int j = 1; j < i; j++){
                curr[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};