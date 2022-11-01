class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
       int m = mat.size();
        int n = mat[0].size();
        
        int s = 0, e = n*m-1;
        
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            
            int ele = mat[mid/n][mid%n];
            
            if(ele == target) return true;
            
            else if(ele < target) s = mid+1;
            
            else e = mid-1;
        }
      
       
        
        return false;
    }
};