//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int n;
int m;
void dfs(int sr, int sc, int originalC, int newC, vector<vector<int>>& image, vector<vector<int>>& ans)
{
    if(sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != originalC || ans[sr][sc] == newC)
        return;
        
    ans[sr][sc] = newC;
    
    dfs(sr+1, sc, originalC, newC, image, ans);
    dfs(sr-1, sc, originalC, newC, image, ans);
    dfs(sr, sc+1, originalC, newC, image, ans);
    dfs(sr, sc-1, originalC, newC, image, ans);
        
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        n = image.size();
        m = image[0].size();
        
        vector<vector<int>>ans = image;
        
        int originalC = image[sr][sc];
        
        dfs(sr, sc, originalC, newColor, image, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends