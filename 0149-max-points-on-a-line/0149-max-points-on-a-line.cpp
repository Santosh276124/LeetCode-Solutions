class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 0;
        
        if(n == 1) return 1;
        //first point
        for(int i = 0; i < n; i++)
        {     
            //second point
            for(int j = i+1; j < n; j++)
            {
                int cnt = 2;
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dy = y2-y1;
                int dx = x2-x1;
                /*
                  dy/dx = dy'/dx' => dx*dy' = dy*dx'
                */
                
                //third point
                for(int k = 0; k < n; k++)
                {
                    if(k != i && k != j)
                    {
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        
                        int dy1 = y3-y1;
                        int dx1 = x3-x1;
                        
                        if(dx*dy1 == dy*dx1)
                            cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
            
        }
        return ans;
    }
};