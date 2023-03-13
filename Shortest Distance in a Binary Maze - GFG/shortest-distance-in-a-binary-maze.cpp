//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        dist[source.first][source.second] = 0;
        
        pq.push({0, {source.first, source.second}});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int nodeDist = top.first;
            int nodeX = top.second.first;
            int nodeY = top.second.second;
            
            if(nodeX == dest.first && nodeY == dest.second)
                return nodeDist;
                
            for(int i = 0; i < 4 ; i++)
            {
                int nx = nodeX + dx[i];
                int ny = nodeY + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    if(nodeDist + 1 < dist[nx][ny])
                    {
                        dist[nx][ny] = 1 + nodeDist;
                        
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
            
        }
        
        return -1;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends