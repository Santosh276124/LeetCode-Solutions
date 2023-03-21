//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*
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
    void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, vector<int>& temp, int n){
        
        if(col >= n){
            
            ans.push_back(temp);
            
            return;
        }
        
        for(int i = 0; i < n; i++){
            
            if(isSafe(i, col, board, n)){
                
                temp.push_back(i+1);
                
                board[i][col] = 1;
                
                solve(col+1, board, ans, temp, n);
                
                board[i][col] = 0;
                
                temp.pop_back();
            }
        }
        
    }
    
    */
    
      
    void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, vector<int>& temp, int n,
    vector<int>& rowHash,vector<int>& upperdiaHash, vector<int>& lowerDiaHash ){
        
        if(col >= n){
            
            ans.push_back(temp);
            
            return;
        }
        
        for(int i = 0; i < n; i++){
            
            // isSafe(i, col, board, n)
            
            if(rowHash[i] == 0 && upperdiaHash[i + col] == 0 && lowerDiaHash[n-1 + col - i] == 0){
                
                temp.push_back(i+1);
                
                board[i][col] = 1;
                
                rowHash[i] = 1;
                upperdiaHash[i + col] = 1;
                lowerDiaHash[n-1+col-i] = 1;
                
                solve(col+1, board, ans, temp, n, rowHash, upperdiaHash, lowerDiaHash);
                
                board[i][col] = 0;
                
                rowHash[i] = 0;
                upperdiaHash[i + col] = 0;
                lowerDiaHash[n-1+col-i] = 0;
                
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        
       vector<vector<int>> ans;
       
       vector<int> temp;
       
       vector<vector<int>> board(n, vector<int>(n, 0));
       
       vector<int> rowHash(n, 0);
       vector<int> upperdiaHash(2*n-1, 0);
       vector<int> lowerDiaHash(2*n-1, 0);
       
       solve(0, board, ans, temp, n, rowHash, upperdiaHash, lowerDiaHash);
       
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