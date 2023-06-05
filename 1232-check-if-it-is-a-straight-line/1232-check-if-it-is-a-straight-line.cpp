class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int slope = 1;
        
            int x1 = coordinates[0][0];
            int y1 = coordinates[0][1];
            
            int x2 = coordinates[1][0];
            int y2 = coordinates[1][1];
        
        int y = y2-y1;
        int x = x2-x1;
        
        // slope = (y2-y1)/(x2-x1);
        
        for(int i = 2; i < coordinates.size(); i++){
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            
            int Y = y3-y1;
            int X = x3-x1;
            
            if(y*X != x*Y)
                return false;
        }
        

        
        return true;
        
    }
};