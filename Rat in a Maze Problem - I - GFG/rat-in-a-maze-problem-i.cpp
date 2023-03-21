//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row, int col, vector<vector<int>> &board, vector<vector<int>> &vis
    , int n, string &path, vector<string> &ans){
        
        if(row < 0 || row >= n || col < 0 || col >= n || board[row][col] == 0 || vis[row][col] == 1){
            return;
        }
        
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            
            return;
        }
        
        
        //up
        path += 'U';
        vis[row][col] = 1;
        solve(row-1, col, board, vis, n, path, ans);
        path.pop_back();
        
        
        
        //down
        path += 'D';
        vis[row][col] = 1;
        solve(row+1, col, board, vis, n, path, ans);
        path.pop_back();
        
        //left
        path += 'L';
        vis[row][col] = 1;
        solve(row, col-1, board, vis, n, path, ans);
        path.pop_back();
        
        //right
        path += 'R';
        vis[row][col] = 1;
        solve(row, col+1, board, vis, n, path, ans);
        path.pop_back();
        
        vis[row][col] = 0;
        
        
        
        
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &board, int n) {
        
        if(board[0][0] == 0) return {"-1"};
        
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        string path = "";
        
        vector<string> ans;
        
        solve(0, 0, board, vis, n, path, ans);
        
        return ans;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends