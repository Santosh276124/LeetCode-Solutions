class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int s = 0, e = n-1;
        
        while(s < m && e >= 0)
        {
            int ele = mat[s][e];
            
            if(ele == target) return true;
            else if(ele < target) s++;
            else e--;
        }
        return false;
    }
};