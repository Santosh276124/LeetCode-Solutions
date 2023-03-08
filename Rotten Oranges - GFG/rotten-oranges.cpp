//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair< pair<int,int> ,int> > q;
        
        int cntFresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] == 2;
                }
                if(grid[i][j] == 1)
                {
                   cntFresh++;
                }
            }
        }
        
        int minTime = 0;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        int cntOfFresh = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                
                int x = front.first.first;
                int y = front.first.second;
                int t = front.second;
                
                minTime = max(minTime, t);
                
                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 2 && grid[nx][ny] == 1)
                    {
                        q.push({{nx, ny}, t + 1});
                        vis[nx][ny] = 2;
                        cntOfFresh++;
                    }
                    
                }
            }
        }
        
        if(cntOfFresh != cntFresh) return -1;
        
        return minTime;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends