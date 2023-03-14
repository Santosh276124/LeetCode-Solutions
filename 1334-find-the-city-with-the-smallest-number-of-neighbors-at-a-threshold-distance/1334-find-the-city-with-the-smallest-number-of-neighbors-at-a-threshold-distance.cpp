class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        
        vector<vector<int>> mat(n, vector<int>(n, 1e6));
        
        for(int i = 0; i < n; i++)
            mat[i][i] = 0;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            mat[u][v] = wt;
            mat[v][u] = wt;
        
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        
        int minCity = 0;
        int maxVal = n;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
               if(i != j && mat[i][j] <= distanceThreshold)
               {
                   cnt++;
               }
            }
            
            if(cnt <= maxVal)
            {
                minCity = i;
                maxVal = cnt;
            }
        }
        
      
        
        return minCity;
    }
};