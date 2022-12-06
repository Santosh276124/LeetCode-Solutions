//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	     int n =grid.size() ;

  int m = grid[0].size(); 

  vector<int>dr={-1 ,0 , 1 ,0 } ;

  vector<int>dc = {0 , 1 , 0 , -1} ;

  

  vector<vector<int>>vis(n, vector<int>(m ,0 )) ;

  vector<vector<int>>dis(n, vector<int>(m ,0 )) ;

     

     queue<pair<pair<int ,int > ,int >> q ;

     for(int i=0 ;i<n ;i++ )

     {

         for(int j=0; j<m; j++ )

         {

             if(grid[i][j]==1)

             q.push({{i ,j }, 0 }) ,vis[i][j]=1 ; 

         }

     }

     

     while(!q.empty())

     {

         int x = q.front().first.first ;

         int y =q.front().first.second; 

         int d = q.front().second ;

         q.pop() ;

         for(int k =0 ; k<4 ;k++ )

         {

             int nx = x+dr[k] ;

             int ny= y+dc[k]; 

             if(nx>=0  && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 && !vis[nx][ny])

             {

                 dis[nx][ny] = d+1 ;

                 q.push({{nx ,ny } ,d+1} ); 

                 vis[nx][ny]=1;

             }

         }

     }

   return dis; 
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends