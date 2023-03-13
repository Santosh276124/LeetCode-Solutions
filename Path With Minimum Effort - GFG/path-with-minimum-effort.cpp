//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        dist[0][0] = 0;
        
        pq.push({0, {0,0}});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int diff = top.first;
            int nodeX = top.second.first;
            int nodeY = top.second.second;
            
            // if(nodeX == n-1 && nodeY == m-1)
            //     pathEffort.push_back(effort);
                
            for(int i = 0; i < 4 ; i++)
            {
                int nx = nodeX + dx[i];
                int ny = nodeY + dy[i];
                
                
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int maxEffort = abs(grid[nx][ny] - grid[nodeX][nodeY]);
                    
                    maxEffort = max(maxEffort, diff);
                    
                    if(maxEffort < dist[nx][ny])
                    {
                        dist[nx][ny] = maxEffort;
                        
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
            
        }
        
        if(dist[n-1][m-1] == 1e9) return -1;
        
        return dist[n-1][m-1];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends