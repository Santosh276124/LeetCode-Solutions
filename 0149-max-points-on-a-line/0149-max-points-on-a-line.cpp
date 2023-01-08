class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n == 1) return 1;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            unordered_map<double,int> mp;  //map<theeta,cnt>
            for(int j =  0; j < n; j++)
            {
                if(i == j) continue;
                
                // theeta = tan inverse(dy/dx) => atan2(y,x)
                int dy = points[j][1]-points[i][1];
                int dx = points[j][0]-points[i][0];
                
                double angle = atan2(dy, dx);
                
                mp[angle]++;
                
            }
            
            for(auto k : mp)
            {
                ans = max(ans, k.second);
            }
        }
        return ans+1;
        
    }
};