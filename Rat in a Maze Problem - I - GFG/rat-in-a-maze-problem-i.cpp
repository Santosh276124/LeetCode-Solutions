//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    
    bool isValid(int i, int j, int n, vector<vector<int>> &mat){
        if(i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0)
            return false;
            
        return true;
    }
    
    void solve(int i, int j, vector<vector<int>> &mat, int n, string &temp,
    vector<string> &ans, vector<vector<int>> &vis){
        
        if(i == n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        vis[i][j] = 1;
        
        //Down
        if(isValid(i+1, j, n, mat) && !vis[i+1][j]){
  
        temp += "D";
        solve(i+1, j, mat, n, temp, ans, vis);
        temp.pop_back();
        
        }
        
        //right
        
        if(isValid(i, j+1, n, mat) && !vis[i][j+1]){
        temp += "R";
        solve(i, j+1, mat, n, temp, ans, vis);
        temp.pop_back();
        }
        
        
        //up
        if(isValid(i-1, j, n, mat) && !vis[i-1][j]){
        
        temp += "U";
        solve(i-1, j, mat, n, temp, ans, vis);
        temp.pop_back();
        }
        
        
        //left
        if(isValid(i, j-1, n, mat) && !vis[i][j-1]){
        temp += "L";
        solve(i, j-1, mat, n, temp, ans, vis);
        temp.pop_back();
        
        }
        
        vis[i][j] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        
        if(mat[0][0] != 1)
            return {"-1"};
        
        vector<string> ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
         
        string temp = "";
        
        solve(0,0, mat, n, temp, ans, vis);
                    
           
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