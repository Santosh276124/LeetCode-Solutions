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
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(source.first == dest.first && source.second == dest.second) return 0;
        
        vector<vector<int>>dist(n, vector<int>(m, 1e9));  //1,0  -1,0  0,1  0 , -1
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            int dis = top.first;
            int r = top.second.first;
            int c = top.second.second;
            
            for(int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis +1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;
                    
                    if(newr == dest.first && newc == dest.second)
                       return 1 + dis;
                       
                    q.push({1 + dis, {newr, newc}});
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