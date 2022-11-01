class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        vector<int> temp;
        
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                temp.push_back(mat[i][j]);
            }
        }
        
      
        
        int s = 0;
        int e = temp.size()-1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(temp[mid] == target)
                return true;
            else if(temp[mid] < target)
                s = mid+1;
            else
                e = mid-1;
        }
        
        return false;
    }
};