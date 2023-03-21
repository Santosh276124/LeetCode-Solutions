//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int r, int c, vector<vector<int>>& board, int n){
        int utilr = r;
        int utilc = c;
        
        //left (col--)
        
        while(c >= 0){
            if(board[r][c] == 1)
                return false;
            c--;
        }
        
        r = utilr;
        c = utilc;
        //upper diagonal r--, col--
        
        while(r >= 0 && c >= 0){
            if(board[r][c] == 1)
                return false;
            c--;
            r--;
        }
        
        
        r = utilr;
        c = utilc;
        
        //lower diagnal r++, c--
        while(r < n && c >= 0){
            if(board[r][c] == 1)
                return false;
            c--;
            r++;
        }
        
        return true;
    }
    void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, int n){
        
        if(col >= n){
            
            vector<int> temp;
            
            for(int j = 0; j < n; j++){
                for(int i = 0; i < n; i++){
                    if(board[i][j] == 1){
                        temp.push_back(i+1);
                    }
                }
            }
            
            ans.push_back(temp);
            
            return;
        }
        
        for(int i = 0; i < n; i++){
            
            if(isSafe(i, col, board, n)){
                
                board[i][col] = 1;
                
                solve(col+1, board, ans, n);
                
                board[i][col] = 0;
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        
       vector<vector<int>> ans;
       
       vector<vector<int>> board(n, vector<int>(n, 0));
       
       solve(0, board, ans, n);
       
       return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends