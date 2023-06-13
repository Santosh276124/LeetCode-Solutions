class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(n == 1) return 1;
        
        map< vector<int>, int > mp;
      
        
        for(int i = 0; i < n; i++){
            
            vector<int> col;
            for(int j = 0; j < n; j++){
                
                col.push_back(grid[j][i]);
                
            }
            
            mp[col]++;
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(mp.count(grid[i]))
                cnt += mp[grid[i]];
        }
        
        return cnt;
        
    }
};