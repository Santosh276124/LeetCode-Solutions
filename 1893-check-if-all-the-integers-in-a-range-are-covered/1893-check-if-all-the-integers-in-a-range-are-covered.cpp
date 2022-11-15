class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
       
        
        for(int i = left; i <= right; i++)
        {
             bool flag = false;
            for(auto j : ranges)
            {
                if(i >= j[0] && i <= j[1])
                    flag = true;
            }
            
            if(flag == false) return false;
        }
        return true;

    }
};